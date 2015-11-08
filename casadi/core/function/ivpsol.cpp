/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010-2014 Joel Andersson, Joris Gillis, Moritz Diehl,
 *                            K.U. Leuven. All rights reserved.
 *    Copyright (C) 2011-2014 Greg Horn
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#include "ivpsol.hpp"
#include "../std_vector_tools.hpp"

using namespace std;
namespace casadi {

  Ivpsol::Ivpsol(const std::string& name, const XProblem& dae)
    : FunctionInternal(name), dae_(dae) {

    // Additional options
    addOption("print_stats", OT_BOOLEAN, false, "Print out statistics after integration");
    addOption("t0", OT_REAL, 0.0, "Beginning of the time horizon");
    addOption("tf", OT_REAL, 1.0, "End of the time horizon");
    addOption("grid", OT_REALVECTOR, GenericType(), "Time grid");
    addOption("augmented_options", OT_DICT, GenericType(),
              "Options to be passed down to the augmented integrator, if one is constructed.");
    addOption("output_t0", OT_BOOLEAN, false, "Output the state at the initial time");

    if (dae.is_sx) {
      f_ = get_f<SX>();
      g_ = get_g<SX>();
    } else {
      f_ = get_f<MX>();
      g_ = get_g<MX>();
    }

    // Negative number of parameters for consistancy checking
    np_ = -1;

    ischeme_ = Function::ivpsol_in();
    oscheme_ = Function::ivpsol_out();
  }

  Ivpsol::~Ivpsol() {
  }

  template<typename MatType>
  Function Ivpsol::get_f() const {
    vector<MatType> dae_in(DAE_NUM_IN), dae_out(DAE_NUM_OUT);
    const Problem<MatType>& dae = this->dae_;
    dae_in[DAE_T]=dae.in[DE_T];
    dae_in[DAE_X]=dae.in[DE_X];
    dae_in[DAE_Z]=dae.in[DE_Z];
    dae_in[DAE_P]=dae.in[DE_P];
    dae_out[DAE_ODE]=dae.out[DE_ODE];
    dae_out[DAE_ALG]=dae.out[DE_ALG];
    dae_out[DAE_QUAD]=dae.out[DE_QUAD];
    return Function("dae", dae_in, dae_out);
  }

  template<typename MatType>
  Function Ivpsol::get_g() const {
    vector<MatType> rdae_in(RDAE_NUM_IN), rdae_out(RDAE_NUM_OUT);
    const Problem<MatType>& dae = this->dae_;
    rdae_in[RDAE_T]=dae.in[DE_T];
    rdae_in[RDAE_X]=dae.in[DE_X];
    rdae_in[RDAE_Z]=dae.in[DE_Z];
    rdae_in[RDAE_P]=dae.in[DE_P];
    rdae_in[RDAE_RX]=dae.in[DE_RX];
    rdae_in[RDAE_RZ]=dae.in[DE_RZ];
    rdae_in[RDAE_RP]=dae.in[DE_RP];
    rdae_out[RDAE_ODE]=dae.out[DE_RODE];
    rdae_out[RDAE_ALG]=dae.out[DE_RALG];
    rdae_out[RDAE_QUAD]=dae.out[DE_RQUAD];
    return Function("rdae", rdae_in, rdae_out);
  }

  Sparsity Ivpsol::get_sparsity_in(int ind) const {
    switch (static_cast<IvpsolInput>(ind)) {
    case IVPSOL_X0:
      return f_.input(DAE_X).sparsity();
    case IVPSOL_P:
      return f_.input(DAE_P).sparsity();
    case IVPSOL_Z0:
      return f_.input(DAE_Z).sparsity();
    case IVPSOL_RX0:
      return g_.isNull() ? Sparsity() : g_.input(RDAE_RX).sparsity();
    case IVPSOL_RP:
      return g_.isNull() ? Sparsity() : g_.input(RDAE_RP).sparsity();
    case IVPSOL_RZ0:
      return g_.isNull() ? Sparsity() : g_.input(RDAE_RZ).sparsity();
    case IVPSOL_NUM_IN: break;
    }
    return Sparsity();
  }

  Sparsity Ivpsol::get_sparsity_out(int ind) const {
    switch (static_cast<IvpsolOutput>(ind)) {
    case IVPSOL_XF:
      return get_sparsity_in(IVPSOL_X0);
    case IVPSOL_QF:
      return f_.output(DAE_QUAD).sparsity();
    case IVPSOL_ZF:
      return get_sparsity_in(IVPSOL_ZF);
    case IVPSOL_RXF:
      return get_sparsity_in(IVPSOL_RX0);
    case IVPSOL_RQF:
      return g_.isNull() ? Sparsity() : g_.output(RDAE_QUAD).sparsity();
    case IVPSOL_RZF:
      return get_sparsity_in(IVPSOL_RZ0);
    case IVPSOL_NUM_OUT: break;
    }
    return Sparsity();
  }

  void Ivpsol::evalD(const double** arg, double** res, int* iw, double* w, void* mem) {
    // Reset solver, take time to t0
    reset(arg, res, iw, w);

    // Integrate forward
    advance(ngrid_-1);

    // If backwards integration is needed
    if (nrx_>0) {

      // Integrate backward
      resetB();

      // Proceed to t0
      retreat(0);
    }

    // Print statistics
    if (print_stats_) printStats(userOut());

    // Get the outputs
    for (int i=0; i<n_out(); ++i) {
      if (res[i] != 0) getOutputNZ(res[i], i);
    }
  }

  void Ivpsol::init() {

    // Initialize the functions
    casadi_assert(!f_.isNull());

    // Get dimensions for the forward integration
    casadi_assert_message(f_.n_in()==DAE_NUM_IN,
                          "Wrong number of inputs for the DAE callback function");
    casadi_assert_message(f_.n_out()==DAE_NUM_OUT,
                          "Wrong number of outputs for the DAE callback function");
    nx_ = f_.input(DAE_X).nnz();
    nz_ = f_.input(DAE_Z).nnz();
    nq_ = f_.output(DAE_QUAD).nnz();
    np_  = f_.input(DAE_P).nnz();

    // Initialize and get dimensions for the backward integration
    if (g_.isNull()) {
      // No backwards integration
      nrx_ = nrz_ = nrq_ = nrp_ = 0;
    } else {
      casadi_assert_message(g_.n_in()==RDAE_NUM_IN,
                            "Wrong number of inputs for the backwards DAE callback function");
      casadi_assert_message(g_.n_out()==RDAE_NUM_OUT,
                            "Wrong number of outputs for the backwards DAE callback function");
      nrx_ = g_.input(RDAE_RX).nnz();
      nrz_ = g_.input(RDAE_RZ).nnz();
      nrp_ = g_.input(RDAE_RP).nnz();
      nrq_ = g_.output(RDAE_QUAD).nnz();
    }

    // Allocate space for inputs
    ibuf_.resize(IVPSOL_NUM_IN);
    x0()  = DMatrix::zeros(f_.input(DAE_X).sparsity());
    p()   = DMatrix::zeros(f_.input(DAE_P).sparsity());
    z0()   = DMatrix::zeros(f_.input(DAE_Z).sparsity());
    if (!g_.isNull()) {
      rx0()  = DMatrix::zeros(g_.input(RDAE_RX).sparsity());
      rp()  = DMatrix::zeros(g_.input(RDAE_RP).sparsity());
      rz0()  = DMatrix::zeros(g_.input(RDAE_RZ).sparsity());
    }

    // Allocate space for outputs
    obuf_.resize(IVPSOL_NUM_OUT);
    xf() = x0();
    qf() = DMatrix::zeros(f_.output(DAE_QUAD).sparsity());
    zf() = z0();
    if (!g_.isNull()) {
      rxf()  = rx0();
      rqf()  = DMatrix::zeros(g_.output(RDAE_QUAD).sparsity());
      rzf()  = rz0();
    }

    // Warn if sparse inputs (was previously an error)
    casadi_assert_warning(f_.input(DAE_X).is_dense(),
                          "Sparse states in integrators are experimental");

    // Consistency checks
    casadi_assert_message(f_.output(DAE_ODE).size()==x0().size(),
                          "Inconsistent dimensions. Expecting DAE_ODE output of shape "
                          << x0().size() << ", but got "
                          << f_.output(DAE_ODE).size() << " instead.");
    casadi_assert(f_.output(DAE_ODE).sparsity()==x0().sparsity());
    casadi_assert_message(f_.output(DAE_ALG).size()==z0().size(),
                          "Inconsistent dimensions. Expecting DAE_ALG output of shape "
                          << z0().size() << ", but got "
                          << f_.output(DAE_ALG).size() << " instead.");
    casadi_assert(f_.output(DAE_ALG).sparsity()==z0().sparsity());
    if (!g_.isNull()) {
      casadi_assert(g_.input(RDAE_P).sparsity()==p().sparsity());
      casadi_assert(g_.input(RDAE_X).sparsity()==x0().sparsity());
      casadi_assert(g_.input(RDAE_Z).sparsity()==z0().sparsity());
      casadi_assert(g_.output(RDAE_ODE).sparsity()==rx0().sparsity());
      casadi_assert(g_.output(RDAE_ALG).sparsity()==rz0().sparsity());
    }

    // Call the base class method
    FunctionInternal::init();

    {
      std::stringstream ss;
      ss << "Ivpsol dimensions: nx=" << nx_ << ", nz="<< nz_
         << ", nq=" << nq_ << ", np=" << np_;
      log("Ivpsol::init", ss.str());
    }

    // read options
    if (hasSetOption("grid")) {
      grid_ = option("grid");
    } else {
      grid_ = vector<double>{option("t0"), option("tf")};
    }
    ngrid_ = grid_.size();
    print_stats_ = option("print_stats");
    output_t0_ = option("output_t0");

    // Form a linear solver for the sparsity propagation
    linsol_f_ = Function::linsol("linsol_f", "none", spJacF(), 1);
    if (!g_.isNull()) {
      linsol_g_ = Function::linsol("linsol_g", "none", spJacG(), 1);
    }

    // Allocate sufficiently large work vectors
    size_t sz_w = f_.sz_w();
    alloc(f_);
    if (!g_.isNull()) {
      alloc(g_);
      sz_w = max(sz_w, g_.sz_w());
    }
    sz_w = max(sz_w, static_cast<size_t>(nx_+nz_));
    sz_w = max(sz_w, static_cast<size_t>(nrx_+nrz_));
    alloc_w(sz_w + nx_ + nz_ + nrx_ + nrz_);
  }

  template<typename MatType>
  map<string, MatType> Ivpsol::aug_fwd(int nfwd, AugOffset& offset) {
    log("Ivpsol::aug_fwd", "call");

    // // Cast to right type
    // map<string, MatType> dae = dae_;

    // // Augmented DAE
    // map<string, vector<MatType>> aug;
    // for (auto&& i : dae) {
    //   aug[i.first].push_back(i.second);
    // }


    // Return object
    map<string, MatType> ret;

    // Calculate offsets
    offset = getAugOffset(nfwd, 0);

    // Create augmented problem
    MatType aug_t = MatType::sym("aug_t", f_.input(DAE_T).sparsity());
    MatType aug_x = MatType::sym("aug_x", x0().size1(), offset.x.back());
    MatType aug_z = MatType::sym("aug_z", std::max(z0().size1(), rz0().size1()), offset.z.back());
    MatType aug_p = MatType::sym("aug_p", std::max(p().size1(), rp().size1()), offset.p.back());
    MatType aug_rx = MatType::sym("aug_rx", x0().size1(), offset.rx.back());
    MatType aug_rz = MatType::sym("aug_rz", std::max(z0().size1(), rz0().size1()),
                                  offset.rz.back());
    MatType aug_rp = MatType::sym("aug_rp", std::max(qf().size1(), rp().size1()),
                                  offset.rp.back());

    // Split up the augmented vectors
    vector<MatType> aug_x_split = horzsplit(aug_x, offset.x);
    auto aug_x_split_it = aug_x_split.begin();
    vector<MatType> aug_z_split = horzsplit(aug_z, offset.z);
    auto aug_z_split_it = aug_z_split.begin();
    vector<MatType> aug_p_split = horzsplit(aug_p, offset.p);
    auto aug_p_split_it = aug_p_split.begin();
    vector<MatType> aug_rx_split = horzsplit(aug_rx, offset.rx);
    auto aug_rx_split_it = aug_rx_split.begin();
    vector<MatType> aug_rz_split = horzsplit(aug_rz, offset.rz);
    auto aug_rz_split_it = aug_rz_split.begin();
    vector<MatType> aug_rp_split = horzsplit(aug_rp, offset.rp);
    auto aug_rp_split_it = aug_rp_split.begin();

    // Temporary vector
    vector<MatType> tmp;

    // Zero with the dimension of t
    MatType zero_t = DMatrix::zeros(aug_t.sparsity());

    // The DAE being constructed
    vector<MatType> f_ode, f_alg, f_quad, g_ode, g_alg, g_quad;

    // Forward derivatives of f
    Function d = f_.derivative(nfwd, 0);
    vector<MatType> f_arg;
    f_arg.reserve(d.n_in());
    tmp.resize(DAE_NUM_IN);
    fill(tmp.begin(), tmp.end(), MatType());

    // Collect arguments for calling d
    for (int dir=-1; dir<nfwd; ++dir) {
      tmp[DAE_T] = dir<0 ? aug_t : zero_t;
      if ( nx_>0) tmp[DAE_X] = *aug_x_split_it++;
      if ( nz_>0) tmp[DAE_Z] = *aug_z_split_it++;
      if ( np_>0) tmp[DAE_P] = *aug_p_split_it++;
      f_arg.insert(f_arg.end(), tmp.begin(), tmp.end());
    }

    // Call d
    vector<MatType> res = d(f_arg);
    auto res_it = res.begin();

    // Collect right-hand-sides
    tmp.resize(DAE_NUM_OUT);
    fill(tmp.begin(), tmp.end(), MatType());
    for (int dir=-1; dir<nfwd; ++dir) {
      copy(res_it, res_it+tmp.size(), tmp.begin());
      res_it += tmp.size();
      if ( nx_>0) f_ode.push_back(tmp[DAE_ODE]);
      if ( nz_>0) f_alg.push_back(tmp[DAE_ALG]);
      if ( nq_>0) f_quad.push_back(tmp[DAE_QUAD]);
    }

    // Consistency check
    casadi_assert(res_it==res.end());

    vector<MatType> g_arg;
    if (!g_.isNull()) {

      // Forward derivatives of g
      d = g_.derivative(nfwd, 0);
      g_arg.reserve(d.n_in());
      tmp.resize(RDAE_NUM_IN);
      fill(tmp.begin(), tmp.end(), MatType());

      // Reset iterators
      aug_x_split_it = aug_x_split.begin();
      aug_z_split_it = aug_z_split.begin();
      aug_p_split_it = aug_p_split.begin();

      // Collect arguments for calling d
      for (int dir=-1; dir<nfwd; ++dir) {
        tmp[RDAE_T] = dir<0 ? aug_t : zero_t;
        if ( nx_>0) tmp[RDAE_X] = *aug_x_split_it++;
        if ( nz_>0) tmp[RDAE_Z] = *aug_z_split_it++;
        if ( np_>0) tmp[RDAE_P] = *aug_p_split_it++;
        if (nrx_>0) tmp[RDAE_RX] = *aug_rx_split_it++;
        if (nrz_>0) tmp[RDAE_RZ] = *aug_rz_split_it++;
        if (nrp_>0) tmp[RDAE_RP] = *aug_rp_split_it++;
        g_arg.insert(g_arg.end(), tmp.begin(), tmp.end());
      }

      // Call d
      res = d(g_arg);
      res_it = res.begin();

      // Collect right-hand-sides
      tmp.resize(RDAE_NUM_OUT);
      fill(tmp.begin(), tmp.end(), MatType());
      for (int dir=-1; dir<nfwd; ++dir) {
        copy(res_it, res_it+tmp.size(), tmp.begin());
        res_it += tmp.size();
        if (nrx_>0) g_ode.push_back(tmp[RDAE_ODE]);
        if (nrz_>0) g_alg.push_back(tmp[RDAE_ALG]);
        if (nrq_>0) g_quad.push_back(tmp[RDAE_QUAD]);
      }

      // Consistency check
      casadi_assert(res_it==res.end());
    }

    // Form the augmented forward integration
    ret["t"] = aug_t;
    ret["x"] = aug_x;
    ret["z"] = aug_z;
    ret["p"] = aug_p;
    if (!f_ode.empty()) ret["ode"] = densify(horzcat(f_ode));
    if (!f_alg.empty()) ret["alg"] = densify(horzcat(f_alg));
    if (!f_quad.empty()) ret["quad"] = densify(horzcat(f_quad));

    // Form the augmented backward integration function
    if (!g_ode.empty()) {
      ret["rx"] = aug_rx;
      ret["rz"] = aug_rz;
      ret["rp"] = aug_rp;
      if (!g_ode.empty()) ret["rode"] = densify(horzcat(g_ode));
      if (!g_alg.empty()) ret["ralg"] = densify(horzcat(g_alg));
      if (!g_quad.empty()) ret["rquad"] = densify(horzcat(g_quad));
    }

    // Consistency check
    casadi_assert(aug_x_split_it == aug_x_split.end());
    casadi_assert(aug_z_split_it == aug_z_split.end());
    casadi_assert(aug_p_split_it == aug_p_split.end());
    casadi_assert(aug_rx_split_it == aug_rx_split.end());
    casadi_assert(aug_rz_split_it == aug_rz_split.end());
    casadi_assert(aug_rp_split_it == aug_rp_split.end());

    // Return functions
    return ret;
  }

  template<typename MatType>
  map<string, MatType> Ivpsol::aug_adj(int nadj, AugOffset& offset) {
    log("Ivpsol::aug_adj", "call");

    // // Cast to right type
    // map<string, MatType> dae = dae_;

    // // Augmented DAE
    // map<string, vector<MatType>> aug;
    // for (auto&& i : dae) {
    //   aug[i.first].push_back(i.second);
    // }



    // Return object
    map<string, MatType> ret;

    // Calculate offsets
    offset = getAugOffset(0, nadj);

    // Create augmented problem
    MatType aug_t = MatType::sym("aug_t", f_.input(DAE_T).sparsity());
    MatType aug_x = MatType::sym("aug_x", x0().size1(), offset.x.back());
    MatType aug_z = MatType::sym("aug_z", std::max(z0().size1(), rz0().size1()), offset.z.back());
    MatType aug_p = MatType::sym("aug_p", std::max(p().size1(), rp().size1()), offset.p.back());
    MatType aug_rx = MatType::sym("aug_rx", x0().size1(), offset.rx.back());
    MatType aug_rz = MatType::sym("aug_rz", std::max(z0().size1(), rz0().size1()),
                                  offset.rz.back());
    MatType aug_rp = MatType::sym("aug_rp", std::max(qf().size1(), rp().size1()),
                                  offset.rp.back());

    // Split up the augmented vectors
    vector<MatType> aug_x_split = horzsplit(aug_x, offset.x);
    auto aug_x_split_it = aug_x_split.begin();
    vector<MatType> aug_z_split = horzsplit(aug_z, offset.z);
    auto aug_z_split_it = aug_z_split.begin();
    vector<MatType> aug_p_split = horzsplit(aug_p, offset.p);
    auto aug_p_split_it = aug_p_split.begin();
    vector<MatType> aug_rx_split = horzsplit(aug_rx, offset.rx);
    auto aug_rx_split_it = aug_rx_split.begin();
    vector<MatType> aug_rz_split = horzsplit(aug_rz, offset.rz);
    auto aug_rz_split_it = aug_rz_split.begin();
    vector<MatType> aug_rp_split = horzsplit(aug_rp, offset.rp);
    auto aug_rp_split_it = aug_rp_split.begin();

    // Temporary vector
    vector<MatType> tmp;

    // Zero with the dimension of t
    MatType zero_t = DMatrix::zeros(aug_t.sparsity());

    // The DAE being constructed
    vector<MatType> f_ode, f_alg, f_quad, g_ode, g_alg, g_quad;

    // Forward derivatives of f
    Function d = f_.derivative(0, 0);
    vector<MatType> f_arg;
    f_arg.reserve(d.n_in());
    tmp.resize(DAE_NUM_IN);
    fill(tmp.begin(), tmp.end(), MatType());

    // Collect arguments for calling d
    tmp[DAE_T] = aug_t;
    if ( nx_>0) tmp[DAE_X] = *aug_x_split_it++;
    if ( nz_>0) tmp[DAE_Z] = *aug_z_split_it++;
    if ( np_>0) tmp[DAE_P] = *aug_p_split_it++;
    f_arg.insert(f_arg.end(), tmp.begin(), tmp.end());

    // Call d
    vector<MatType> res = d(f_arg);
    auto res_it = res.begin();

    // Collect right-hand-sides
    tmp.resize(DAE_NUM_OUT);
    fill(tmp.begin(), tmp.end(), MatType());
    copy(res_it, res_it+tmp.size(), tmp.begin());
    res_it += tmp.size();
    if ( nx_>0) f_ode.push_back(tmp[DAE_ODE]);
    if ( nz_>0) f_alg.push_back(tmp[DAE_ALG]);
    if ( nq_>0) f_quad.push_back(tmp[DAE_QUAD]);

    // Consistency check
    casadi_assert(res_it==res.end());

    vector<MatType> g_arg;
    if (!g_.isNull()) {

      // Forward derivatives of g
      d = g_.derivative(0, 0);
      g_arg.reserve(d.n_in());
      tmp.resize(RDAE_NUM_IN);
      fill(tmp.begin(), tmp.end(), MatType());

      // Reset iterators
      aug_x_split_it = aug_x_split.begin();
      aug_z_split_it = aug_z_split.begin();
      aug_p_split_it = aug_p_split.begin();

      // Collect arguments for calling d
      tmp[RDAE_T] = aug_t;
      if ( nx_>0) tmp[RDAE_X] = *aug_x_split_it++;
      if ( nz_>0) tmp[RDAE_Z] = *aug_z_split_it++;
      if ( np_>0) tmp[RDAE_P] = *aug_p_split_it++;
      if (nrx_>0) tmp[RDAE_RX] = *aug_rx_split_it++;
      if (nrz_>0) tmp[RDAE_RZ] = *aug_rz_split_it++;
      if (nrp_>0) tmp[RDAE_RP] = *aug_rp_split_it++;
      g_arg.insert(g_arg.end(), tmp.begin(), tmp.end());

      // Call d
      res = d(g_arg);
      res_it = res.begin();

      // Collect right-hand-sides
      tmp.resize(RDAE_NUM_OUT);
      fill(tmp.begin(), tmp.end(), MatType());
      copy(res_it, res_it+tmp.size(), tmp.begin());
      res_it += tmp.size();
      if (nrx_>0) g_ode.push_back(tmp[RDAE_ODE]);
      if (nrz_>0) g_alg.push_back(tmp[RDAE_ALG]);
      if (nrq_>0) g_quad.push_back(tmp[RDAE_QUAD]);

      // Consistency check
      casadi_assert(res_it==res.end());
    }

    // Adjoint derivatives of f
    d = f_.derivative(0, nadj);
    f_arg.resize(DAE_NUM_IN);
    f_arg.reserve(d.n_in());

    // Collect arguments for calling d
    tmp.resize(DAE_NUM_OUT);
    fill(tmp.begin(), tmp.end(), MatType());
    for (int dir=0; dir<nadj; ++dir) {
      if ( nx_>0) tmp[DAE_ODE] = *aug_rx_split_it++;
      if ( nz_>0) tmp[DAE_ALG] = *aug_rz_split_it++;
      if ( nq_>0) tmp[DAE_QUAD] = *aug_rp_split_it++;
      f_arg.insert(f_arg.end(), tmp.begin(), tmp.end());
    }

    // Call der
    res = d(f_arg);
    res_it = res.begin() + DAE_NUM_OUT;

    // Record locations in augg for later
    int g_ode_ind = g_ode.size();
    int g_alg_ind = g_alg.size();
    int g_quad_ind = g_quad.size();

    // Collect right-hand-sides
    tmp.resize(DAE_NUM_IN);
    for (int dir=0; dir<nadj; ++dir) {
      copy(res_it, res_it+tmp.size(), tmp.begin());
      res_it += tmp.size();
      if ( nx_>0) g_ode.push_back(tmp[DAE_X]);
      if ( nz_>0) g_alg.push_back(tmp[DAE_Z]);
      if ( np_>0) g_quad.push_back(tmp[DAE_P]);
    }

    // Consistency check
    casadi_assert(res_it==res.end());

    if (!g_.isNull()) {

      // Adjoint derivatives of g
      d = g_.derivative(0, nadj);
      g_arg.resize(RDAE_NUM_IN);
      g_arg.reserve(d.n_in());

      // Collect arguments for calling der
      tmp.resize(RDAE_NUM_OUT);
      fill(tmp.begin(), tmp.end(), MatType());
      for (int dir=0; dir<nadj; ++dir) {
        if (nrx_>0) tmp[RDAE_ODE] = *aug_x_split_it++;
        if (nrz_>0) tmp[RDAE_ALG] = *aug_z_split_it++;
        if (nrq_>0) tmp[RDAE_QUAD] = *aug_p_split_it++;
        g_arg.insert(g_arg.end(), tmp.begin(), tmp.end());
      }

      // Call der
      res = d(g_arg);
      res_it = res.begin() + RDAE_NUM_OUT;

      // Collect right-hand-sides
      tmp.resize(RDAE_NUM_IN);
      for (int dir=0; dir<nadj; ++dir) {
        copy(res_it, res_it+tmp.size(), tmp.begin());
        res_it += tmp.size();
        if ( nx_>0) g_ode[g_ode_ind++] += tmp[RDAE_X];
        if ( nz_>0) g_alg[g_alg_ind++] += tmp[RDAE_Z];
        if ( np_>0) g_quad[g_quad_ind++] += tmp[RDAE_P];
      }

      // Consistency check
      casadi_assert(g_ode_ind == g_ode.size());
      casadi_assert(g_alg_ind == g_alg.size());
      casadi_assert(g_quad_ind == g_quad.size());

      // Remove the dependency of rx, rz, rp in the forward integration (see Joel's thesis)
      if (nrx_>0) g_arg[RDAE_RX] = MatType::zeros(g_arg[RDAE_RX].sparsity());
      if (nrz_>0) g_arg[RDAE_RZ] = MatType::zeros(g_arg[RDAE_RZ].sparsity());
      if (nrp_>0) g_arg[RDAE_RP] = MatType::zeros(g_arg[RDAE_RP].sparsity());

      // Call der again
      res = d(g_arg);
      res_it = res.begin() + RDAE_NUM_OUT;

      // Collect right-hand-sides and add contribution to the forward integration
      tmp.resize(RDAE_NUM_IN);
      for (int dir=0; dir<nadj; ++dir) {
        copy(res_it, res_it+tmp.size(), tmp.begin());
        res_it += tmp.size();
        if (nrx_>0) f_ode.push_back(tmp[RDAE_RX]);
        if (nrz_>0) f_alg.push_back(tmp[RDAE_RZ]);
        if (nrp_>0) f_quad.push_back(tmp[RDAE_RP]);
      }

      // Consistency check
      casadi_assert(res_it==res.end());
    }

    // Form the augmented forward integration
    ret["t"] = aug_t;
    ret["x"] = aug_x;
    ret["z"] = aug_z;
    ret["p"] = aug_p;
    if (!f_ode.empty()) ret["ode"] = densify(horzcat(f_ode));
    if (!f_alg.empty()) ret["alg"] = densify(horzcat(f_alg));
    if (!f_quad.empty()) ret["quad"] = densify(horzcat(f_quad));

    // Form the augmented backward integration function
    if (!g_ode.empty()) {
      ret["rx"] = aug_rx;
      ret["rz"] = aug_rz;
      ret["rp"] = aug_rp;
      if (!g_ode.empty()) ret["rode"] = densify(horzcat(g_ode));
      if (!g_alg.empty()) ret["ralg"] = densify(horzcat(g_alg));
      if (!g_quad.empty()) ret["rquad"] = densify(horzcat(g_quad));
    }

    // Consistency check
    casadi_assert(aug_x_split_it == aug_x_split.end());
    casadi_assert(aug_z_split_it == aug_z_split.end());
    casadi_assert(aug_p_split_it == aug_p_split.end());
    casadi_assert(aug_rx_split_it == aug_rx_split.end());
    casadi_assert(aug_rz_split_it == aug_rz_split.end());
    casadi_assert(aug_rp_split_it == aug_rp_split.end());

    // Return functions
    return ret;
  }

  void Ivpsol::spFwd(const bvec_t** arg, bvec_t** res, int* iw, bvec_t* w, void* mem) {
    log("Ivpsol::spFwd", "begin");

    // Work vectors
    bvec_t *tmp_x = w; w += nx_;
    bvec_t *tmp_z = w; w += nz_;
    bvec_t *tmp_rx = w; w += nrx_;
    bvec_t *tmp_rz = w; w += nrz_;

    // Propagate through f
    const bvec_t** arg1 = arg+n_in();
    fill(arg1, arg1+DAE_NUM_IN, static_cast<bvec_t*>(0));
    arg1[DAE_X] = arg[IVPSOL_X0];
    arg1[DAE_P] = arg[IVPSOL_P];
    bvec_t** res1 = res+n_out();
    fill(res1, res1+DAE_NUM_OUT, static_cast<bvec_t*>(0));
    res1[DAE_ODE] = tmp_x;
    res1[DAE_ALG] = tmp_z;
    f_(arg1, res1, iw, w, 0);
    if (arg[IVPSOL_X0]) {
      const bvec_t *tmp = arg[IVPSOL_X0];
      for (int i=0; i<nx_; ++i) tmp_x[i] |= *tmp++;
    }

    // "Solve" in order to resolve interdependencies (cf. Nlsol)
    copy(tmp_x, tmp_x+nx_+nz_, w);
    fill_n(tmp_x, nx_+nz_, 0);
    casadi_assert(!linsol_f_.isNull());
    linsol_f_.linsol_spsolve(tmp_x, w, false);

    // Get xf and zf
    if (res[IVPSOL_XF])
      copy(tmp_x, tmp_x+nx_, res[IVPSOL_XF]);
    if (res[IVPSOL_ZF])
      copy(tmp_z, tmp_z+nz_, res[IVPSOL_ZF]);

    // Propagate to quadratures
    if (nq_>0 && res[IVPSOL_QF]) {
      arg1[DAE_X] = tmp_x;
      arg1[DAE_Z] = tmp_z;
      res1[DAE_ODE] = res1[DAE_ALG] = 0;
      res1[DAE_QUAD] = res[IVPSOL_QF];
      f_(arg1, res1, iw, w, 0);
    }

    if (!g_.isNull()) {
      // Propagate through g
      fill(arg1, arg1+RDAE_NUM_IN, static_cast<bvec_t*>(0));
      arg1[RDAE_X] = tmp_x;
      arg1[RDAE_P] = arg[IVPSOL_P];
      arg1[RDAE_Z] = tmp_z;
      arg1[RDAE_RX] = arg[IVPSOL_X0];
      arg1[RDAE_RX] = arg[IVPSOL_RX0];
      arg1[RDAE_RP] = arg[IVPSOL_RP];
      fill(res1, res1+RDAE_NUM_OUT, static_cast<bvec_t*>(0));
      res1[RDAE_ODE] = tmp_rx;
      res1[RDAE_ALG] = tmp_rz;
      g_(arg1, res1, iw, w, 0);
      if (arg[IVPSOL_RX0]) {
        const bvec_t *tmp = arg[IVPSOL_RX0];
        for (int i=0; i<nrx_; ++i) tmp_rx[i] |= *tmp++;
      }

      // "Solve" in order to resolve interdependencies (cf. Nlsol)
      copy(tmp_rx, tmp_rx+nrx_+nrz_, w);
      fill_n(tmp_rx, nrx_+nrz_, 0);
      casadi_assert(!linsol_g_.isNull());
      linsol_g_.linsol_spsolve(tmp_rx, w, false);

      // Get rxf and rzf
      if (res[IVPSOL_RXF])
        copy(tmp_rx, tmp_rx+nrx_, res[IVPSOL_RXF]);
      if (res[IVPSOL_RZF])
        copy(tmp_rz, tmp_rz+nrz_, res[IVPSOL_RZF]);

      // Propagate to quadratures
      if (nrq_>0 && res[IVPSOL_RQF]) {
        arg1[RDAE_RX] = tmp_rx;
        arg1[RDAE_RZ] = tmp_rz;
        res1[RDAE_ODE] = res1[RDAE_ALG] = 0;
        res1[RDAE_QUAD] = res[IVPSOL_RQF];
        g_(arg1, res1, iw, w, 0);
      }
    }
    log("Ivpsol::spFwd", "end");
  }

  void Ivpsol::spAdj(bvec_t** arg, bvec_t** res, int* iw, bvec_t* w, void* mem) {
    log("Ivpsol::spAdj", "begin");

    // Work vectors
    bvec_t** arg1 = arg+n_in();
    bvec_t** res1 = res+n_out();
    bvec_t *tmp_x = w; w += nx_;
    bvec_t *tmp_z = w; w += nz_;

    // Shorthands
    bvec_t* x0 = arg[IVPSOL_X0];
    bvec_t* p = arg[IVPSOL_P];
    bvec_t* xf = res[IVPSOL_XF];
    bvec_t* zf = res[IVPSOL_ZF];
    bvec_t* qf = res[IVPSOL_QF];

    // Propagate from outputs to state vectors
    if (xf) {
      copy_n(xf, nx_, tmp_x);
      fill_n(xf, nx_, 0);
    } else {
      fill_n(tmp_x, nx_, 0);
    }
    if (zf) {
      copy_n(zf, nz_, tmp_z);
      fill_n(zf, nz_, 0);
    } else {
      fill_n(tmp_z, nz_, 0);
    }

    if (!g_.isNull()) {
      // Work vectors
      bvec_t *tmp_rx = w; w += nrx_;
      bvec_t *tmp_rz = w; w += nrz_;

      // Shorthands
      bvec_t* rx0 = arg[IVPSOL_RX0];
      bvec_t* rp = arg[IVPSOL_RP];
      bvec_t* rxf = res[IVPSOL_RXF];
      bvec_t* rzf = res[IVPSOL_RZF];
      bvec_t* rqf = res[IVPSOL_RQF];

      // Propagate from outputs to state vectors
      if (rxf) {
        copy_n(rxf, nrx_, tmp_rx);
        fill_n(rxf, nrx_, 0);
      } else {
        fill_n(tmp_rx, nrx_, 0);
      }
      if (rzf) {
        copy_n(rzf, nrz_, tmp_rz);
        fill_n(rzf, nrz_, 0);
      } else {
        fill_n(tmp_rz, nrz_, 0);
      }

      // Get dependencies from backward quadratures
      fill(res1, res1+RDAE_NUM_OUT, static_cast<bvec_t*>(0));
      fill(arg1, arg1+RDAE_NUM_IN, static_cast<bvec_t*>(0));
      res1[RDAE_QUAD] = rqf;
      arg1[RDAE_X] = tmp_x;
      arg1[RDAE_Z] = tmp_z;
      arg1[RDAE_P] = p;
      arg1[RDAE_RX] = tmp_rx;
      arg1[RDAE_RZ] = tmp_rz;
      arg1[RDAE_RP] = rp;
      g_.rev(arg1, res1, iw, w, 0);

      // Propagate interdependencies
      casadi_assert(!linsol_g_.isNull());
      fill_n(w, nrx_+nrz_, 0);
      linsol_g_.linsol_spsolve(w, tmp_rx, true);
      copy(w, w+nrx_+nrz_, tmp_rx);

      // Direct dependency rx0 -> rxf
      if (rx0) for (int i=0; i<nrx_; ++i) rx0[i] |= tmp_rx[i];

      // Indirect dependency via g
      res1[RDAE_ODE] = tmp_rx;
      res1[RDAE_ALG] = tmp_rz;
      res1[RDAE_QUAD] = 0;
      arg1[RDAE_RX] = rx0;
      arg1[RDAE_RZ] = 0; // arg[IVPSOL_RZ0] is a guess, no dependency
      g_.rev(arg1, res1, iw, w, 0);
    }

    // Get dependencies from forward quadratures
    fill(res1, res1+DAE_NUM_OUT, static_cast<bvec_t*>(0));
    fill(arg1, arg1+DAE_NUM_IN, static_cast<bvec_t*>(0));
    res1[DAE_QUAD] = qf;
    arg1[DAE_X] = tmp_x;
    arg1[DAE_Z] = tmp_z;
    arg1[DAE_P] = p;
    if (qf && nq_>0) f_.rev(arg1, res1, iw, w, 0);

    // Propagate interdependencies
    casadi_assert(!linsol_f_.isNull());
    fill_n(w, nx_+nz_, 0);
    linsol_f_.linsol_spsolve(w, tmp_x, true);
    copy(w, w+nx_+nz_, tmp_x);

    // Direct dependency x0 -> xf
    if (x0) for (int i=0; i<nx_; ++i) x0[i] |= tmp_x[i];

    // Indirect dependency through f
    res1[DAE_ODE] = tmp_x;
    res1[DAE_ALG] = tmp_z;
    res1[DAE_QUAD] = 0;
    arg1[DAE_X] = x0;
    arg1[DAE_Z] = 0; // arg[IVPSOL_Z0] is a guess, no dependency
    f_.rev(arg1, res1, iw, w, 0);

    log("Ivpsol::spAdj", "end");
  }

  Ivpsol::AugOffset Ivpsol::getAugOffset(int nfwd, int nadj) {
    // Form return object
    AugOffset ret;
    ret.x.resize(1, 0);
    ret.z.resize(1, 0);
    ret.q.resize(1, 0);
    ret.p.resize(1, 0);
    ret.rx.resize(1, 0);
    ret.rz.resize(1, 0);
    ret.rq.resize(1, 0);
    ret.rp.resize(1, 0);

    // Count nondifferentiated and forward sensitivities
    for (int dir=-1; dir<nfwd; ++dir) {
      if ( nx_>0) ret.x.push_back(x0().size2());
      if ( nz_>0) ret.z.push_back(z0().size2());
      if ( nq_>0) ret.q.push_back(qf().size2());
      if ( np_>0) ret.p.push_back(p().size2());
      if (nrx_>0) ret.rx.push_back(rx0().size2());
      if (nrz_>0) ret.rz.push_back(rz0().size2());
      if (nrq_>0) ret.rq.push_back(rqf().size2());
      if (nrp_>0) ret.rp.push_back(rp().size2());
    }

    // Count adjoint sensitivities
    for (int dir=0; dir<nadj; ++dir) {
      if ( nx_>0) ret.rx.push_back(x0().size2());
      if ( nz_>0) ret.rz.push_back(z0().size2());
      if ( np_>0) ret.rq.push_back(p().size2());
      if ( nq_>0) ret.rp.push_back(qf().size2());
      if (nrx_>0) ret.x.push_back(rx0().size2());
      if (nrz_>0) ret.z.push_back(rz0().size2());
      if (nrp_>0) ret.q.push_back(rp().size2());
      if (nrq_>0) ret.p.push_back(rqf().size2());
    }

    // Get cummulative offsets
    for (int i=1; i<ret.x.size(); ++i) ret.x[i] += ret.x[i-1];
    for (int i=1; i<ret.z.size(); ++i) ret.z[i] += ret.z[i-1];
    for (int i=1; i<ret.q.size(); ++i) ret.q[i] += ret.q[i-1];
    for (int i=1; i<ret.p.size(); ++i) ret.p[i] += ret.p[i-1];
    for (int i=1; i<ret.rx.size(); ++i) ret.rx[i] += ret.rx[i-1];
    for (int i=1; i<ret.rz.size(); ++i) ret.rz[i] += ret.rz[i-1];
    for (int i=1; i<ret.rq.size(); ++i) ret.rq[i] += ret.rq[i-1];
    for (int i=1; i<ret.rp.size(); ++i) ret.rp[i] += ret.rp[i-1];

    // Return the offsets
    return ret;
  }

  Function Ivpsol::get_forward(const std::string& name, int nfwd, Dict& opts) {
    log("Ivpsol::get_forward", "begin");

    // Ivpsol options
    Dict aug_opts = getDerivativeOptions(true);
    if (hasSetOption("augmented_options")) {
      Dict aug_opts_user = option("augmented_options");
      for (auto&& i : aug_opts_user) {
        aug_opts[i.first] = i.second;
      }
    }

    // Temp stringstream
    stringstream ss;
    ss << "aug_f" << nfwd << name_;

    // Create integrator for augmented DAE
    Function integrator;
    AugOffset offset;
    if (f_.is_a("sxfunction")) {
      SXDict aug_dae = aug_fwd<SX>(nfwd, offset);
      integrator = Function::ivpsol(ss.str(), plugin_name(), aug_dae, aug_opts);
    } else {
      casadi_assert(f_.is_a("mxfunction"));
      MXDict aug_dae = aug_fwd<MX>(nfwd, offset);
      integrator = Function::ivpsol(ss.str(), plugin_name(), aug_dae, aug_opts);
    }

    // All inputs of the return function
    vector<MX> ret_in;
    ret_in.reserve(IVPSOL_NUM_IN*(1+nfwd) + IVPSOL_NUM_OUT);

    // Augmented state
    vector<MX> x0_augv, p_augv, z0_augv, rx0_augv, rp_augv, rz0_augv;

    // Inputs or forward/adjoint seeds in one direction
    vector<MX> dd;

    // Add nondifferentiated inputs and forward seeds
    dd.resize(IVPSOL_NUM_IN);
    for (int dir=-1; dir<nfwd; ++dir) {

      // Differential state
      ss.clear();
      ss << "x0";
      if (dir>=0) ss << "_" << dir;
      dd[IVPSOL_X0] = MX::sym(ss.str(), x0().sparsity());
      x0_augv.push_back(dd[IVPSOL_X0]);

      // Parameter
      ss.clear();
      ss << "p";
      if (dir>=0) ss << "_" << dir;
      dd[IVPSOL_P] = MX::sym(ss.str(), p().sparsity());
      p_augv.push_back(dd[IVPSOL_P]);

      // Initial guess for algebraic variable
      ss.clear();
      ss << "r0";
      if (dir>=0) ss << "_" << dir;
      dd[IVPSOL_Z0] = MX::sym(ss.str(), z0().sparsity());
      z0_augv.push_back(dd[IVPSOL_Z0]);

      // Backward state
      ss.clear();
      ss << "rx0";
      if (dir>=0) ss << "_" << dir;
      dd[IVPSOL_RX0] = MX::sym(ss.str(), rx0().sparsity());
      rx0_augv.push_back(dd[IVPSOL_RX0]);

      // Backward parameter
      ss.clear();
      ss << "rp";
      if (dir>=0) ss << "_" << dir;
      dd[IVPSOL_RP] = MX::sym(ss.str(), rp().sparsity());
      rp_augv.push_back(dd[IVPSOL_RP]);

      // Initial guess for backward algebraic variable
      ss.clear();
      ss << "rz0";
      if (dir>=0) ss << "_" << dir;
      dd[IVPSOL_RZ0] = MX::sym(ss.str(), rz0().sparsity());
      rz0_augv.push_back(dd[IVPSOL_RZ0]);

      // Add to input vector
      ret_in.insert(ret_in.end(), dd.begin(), dd.end());

      // Make space for dummy outputs
      if (dir==-1) ret_in.resize(ret_in.size() + IVPSOL_NUM_OUT);
    }

    // Call the integrator
    vector<MX> ivpsol_in(IVPSOL_NUM_IN);
    ivpsol_in[IVPSOL_X0] = horzcat(x0_augv);
    ivpsol_in[IVPSOL_P] = horzcat(p_augv);
    ivpsol_in[IVPSOL_Z0] = horzcat(z0_augv);
    ivpsol_in[IVPSOL_RX0] = horzcat(rx0_augv);
    ivpsol_in[IVPSOL_RP] = horzcat(rp_augv);
    ivpsol_in[IVPSOL_RZ0] = horzcat(rz0_augv);
    vector<MX> ivpsol_out = integrator(ivpsol_in);

    // Augmented results
    vector<MX> xf_aug = horzsplit(ivpsol_out[IVPSOL_XF], offset.x);
    vector<MX> qf_aug = horzsplit(ivpsol_out[IVPSOL_QF], offset.q);
    vector<MX> zf_aug = horzsplit(ivpsol_out[IVPSOL_ZF], offset.z);
    vector<MX> rxf_aug = horzsplit(ivpsol_out[IVPSOL_RXF], offset.rx);
    vector<MX> rqf_aug = horzsplit(ivpsol_out[IVPSOL_RQF], offset.rq);
    vector<MX> rzf_aug = horzsplit(ivpsol_out[IVPSOL_RZF], offset.rz);
    vector<MX>::const_iterator xf_aug_it = xf_aug.begin();
    vector<MX>::const_iterator qf_aug_it = qf_aug.begin();
    vector<MX>::const_iterator zf_aug_it = zf_aug.begin();
    vector<MX>::const_iterator rxf_aug_it = rxf_aug.begin();
    vector<MX>::const_iterator rqf_aug_it = rqf_aug.begin();
    vector<MX>::const_iterator rzf_aug_it = rzf_aug.begin();

    // Add dummy inputs (outputs of the nondifferentiated funciton)
    dd.resize(IVPSOL_NUM_OUT);
    dd[IVPSOL_XF]  = MX::sym("xf_dummy", Sparsity(xf().size()));
    dd[IVPSOL_QF]  = MX::sym("qf_dummy", Sparsity(qf().size()));
    dd[IVPSOL_ZF]  = MX::sym("zf_dummy", Sparsity(zf().size()));
    dd[IVPSOL_RXF]  = MX::sym("rxf_dummy", Sparsity(rxf().size()));
    dd[IVPSOL_RQF]  = MX::sym("rqf_dummy", Sparsity(rqf().size()));
    dd[IVPSOL_RZF]  = MX::sym("rzf_dummy", Sparsity(rzf().size()));
    std::copy(dd.begin(), dd.end(), ret_in.begin()+IVPSOL_NUM_IN);

    // All outputs of the return function
    vector<MX> ret_out;
    ret_out.reserve(IVPSOL_NUM_OUT*nfwd);

    // Collect the forward sensitivities
    fill(dd.begin(), dd.end(), MX());
    for (int dir=-1; dir<nfwd; ++dir) {
      if ( nx_>0) dd[IVPSOL_XF]  = *xf_aug_it++;
      if ( nq_>0) dd[IVPSOL_QF]  = *qf_aug_it++;
      if ( nz_>0) dd[IVPSOL_ZF]  = *zf_aug_it++;
      if (nrx_>0) dd[IVPSOL_RXF] = *rxf_aug_it++;
      if (nrq_>0) dd[IVPSOL_RQF] = *rqf_aug_it++;
      if (nrz_>0) dd[IVPSOL_RZF] = *rzf_aug_it++;
      if (dir>=0) // Nondifferentiated output ignored
        ret_out.insert(ret_out.end(), dd.begin(), dd.end());
    }
    log("Ivpsol::get_forward", "end");

    // Create derivative function and return
    return Function(name, ret_in, ret_out, opts);
  }

  Function Ivpsol::get_reverse(const std::string& name, int nadj, Dict& opts) {
    log("Ivpsol::get_reverse", "begin");

    // Ivpsol options
    Dict aug_opts = getDerivativeOptions(false);
    if (hasSetOption("augmented_options")) {
      Dict aug_opts_user = option("augmented_options");
      for (auto&& i : aug_opts_user) {
        aug_opts[i.first] = i.second;
      }
    }

    // Temp stringstream
    stringstream ss;
    ss << "aug_r" << nadj << name_;

    // Create integrator for augmented DAE
    Function integrator;
    AugOffset offset;
    if (f_.is_a("sxfunction")) {
      SXDict aug_dae = aug_adj<SX>(nadj, offset);
      integrator = Function::ivpsol(ss.str(), plugin_name(), aug_dae, aug_opts);
    } else {
      casadi_assert(f_.is_a("mxfunction"));
      MXDict aug_dae = aug_adj<MX>(nadj, offset);
      integrator = Function::ivpsol(ss.str(), plugin_name(), aug_dae, aug_opts);
    }

    // All inputs of the return function
    vector<MX> ret_in;
    ret_in.reserve(IVPSOL_NUM_IN + IVPSOL_NUM_OUT*(1+nadj));

    // Augmented state
    vector<MX> x0_augv, p_augv, z0_augv, rx0_augv, rp_augv, rz0_augv;

    // Inputs or forward/adjoint seeds in one direction
    vector<MX> dd;

    // Add nondifferentiated inputs and forward seeds
    dd.resize(IVPSOL_NUM_IN);
    fill(dd.begin(), dd.end(), MX());

    // Differential state
    dd[IVPSOL_X0] = MX::sym("x0", x0().sparsity());
    x0_augv.push_back(dd[IVPSOL_X0]);

    // Parameter
    dd[IVPSOL_P] = MX::sym("p", p().sparsity());
    p_augv.push_back(dd[IVPSOL_P]);

    // Initial guess for algebraic variable
    dd[IVPSOL_Z0] = MX::sym("r0", z0().sparsity());
    z0_augv.push_back(dd[IVPSOL_Z0]);

    // Backward state
    dd[IVPSOL_RX0] = MX::sym("rx0", rx0().sparsity());
    rx0_augv.push_back(dd[IVPSOL_RX0]);

    // Backward parameter
    dd[IVPSOL_RP] = MX::sym("rp", rp().sparsity());
    rp_augv.push_back(dd[IVPSOL_RP]);

    // Initial guess for backward algebraic variable
    dd[IVPSOL_RZ0] = MX::sym("rz0", rz0().sparsity());
    rz0_augv.push_back(dd[IVPSOL_RZ0]);

    // Add to input vector
    ret_in.insert(ret_in.end(), dd.begin(), dd.end());

    // Add dummy inputs (outputs of the nondifferentiated funciton)
    dd.resize(IVPSOL_NUM_OUT);
    dd[IVPSOL_XF]  = MX::sym("xf_dummy", Sparsity(xf().size()));
    dd[IVPSOL_QF]  = MX::sym("qf_dummy", Sparsity(qf().size()));
    dd[IVPSOL_ZF]  = MX::sym("zf_dummy", Sparsity(zf().size()));
    dd[IVPSOL_RXF]  = MX::sym("rxf_dummy", Sparsity(rxf().size()));
    dd[IVPSOL_RQF]  = MX::sym("rqf_dummy", Sparsity(rqf().size()));
    dd[IVPSOL_RZF]  = MX::sym("rzf_dummy", Sparsity(rzf().size()));
    ret_in.insert(ret_in.end(), dd.begin(), dd.end());

    // Add adjoint seeds
    dd.resize(IVPSOL_NUM_OUT);
    fill(dd.begin(), dd.end(), MX());
    for (int dir=0; dir<nadj; ++dir) {

      // Differential states become backward differential state
      ss.clear();
      ss << "xf" << "_" << dir;
      dd[IVPSOL_XF] = MX::sym(ss.str(), xf().sparsity());
      rx0_augv.push_back(dd[IVPSOL_XF]);

      // Quadratures become backward parameters
      ss.clear();
      ss << "qf" << "_" << dir;
      dd[IVPSOL_QF] = MX::sym(ss.str(), qf().sparsity());
      rp_augv.push_back(dd[IVPSOL_QF]);

      // Algebraic variables become backward algebraic variables
      ss.clear();
      ss << "zf" << "_" << dir;
      dd[IVPSOL_ZF] = MX::sym(ss.str(), zf().sparsity());
      rz0_augv.push_back(dd[IVPSOL_ZF]);

      // Backward differential states becomes forward differential states
      ss.clear();
      ss << "rxf" << "_" << dir;
      dd[IVPSOL_RXF] = MX::sym(ss.str(), rxf().sparsity());
      x0_augv.push_back(dd[IVPSOL_RXF]);

      // Backward quadratures becomes (forward) parameters
      ss.clear();
      ss << "rqf" << "_" << dir;
      dd[IVPSOL_RQF] = MX::sym(ss.str(), rqf().sparsity());
      p_augv.push_back(dd[IVPSOL_RQF]);

      // Backward differential states becomes forward differential states
      ss.clear();
      ss << "rzf" << "_" << dir;
      dd[IVPSOL_RZF] = MX::sym(ss.str(), rzf().sparsity());
      z0_augv.push_back(dd[IVPSOL_RZF]);

      // Add to input vector
      ret_in.insert(ret_in.end(), dd.begin(), dd.end());
    }

    // Call the integrator
    vector<MX> ivpsol_in(IVPSOL_NUM_IN);
    ivpsol_in[IVPSOL_X0] = horzcat(x0_augv);
    ivpsol_in[IVPSOL_P] = horzcat(p_augv);
    ivpsol_in[IVPSOL_Z0] = horzcat(z0_augv);
    ivpsol_in[IVPSOL_RX0] = horzcat(rx0_augv);
    ivpsol_in[IVPSOL_RP] = horzcat(rp_augv);
    ivpsol_in[IVPSOL_RZ0] = horzcat(rz0_augv);
    vector<MX> ivpsol_out = integrator(ivpsol_in);

    // Augmented results
    vector<MX> xf_aug = horzsplit(ivpsol_out[IVPSOL_XF], offset.x);
    vector<MX> qf_aug = horzsplit(ivpsol_out[IVPSOL_QF], offset.q);
    vector<MX> zf_aug = horzsplit(ivpsol_out[IVPSOL_ZF], offset.z);
    vector<MX> rxf_aug = horzsplit(ivpsol_out[IVPSOL_RXF], offset.rx);
    vector<MX> rqf_aug = horzsplit(ivpsol_out[IVPSOL_RQF], offset.rq);
    vector<MX> rzf_aug = horzsplit(ivpsol_out[IVPSOL_RZF], offset.rz);
    vector<MX>::const_iterator xf_aug_it = xf_aug.begin();
    vector<MX>::const_iterator qf_aug_it = qf_aug.begin();
    vector<MX>::const_iterator zf_aug_it = zf_aug.begin();
    vector<MX>::const_iterator rxf_aug_it = rxf_aug.begin();
    vector<MX>::const_iterator rqf_aug_it = rqf_aug.begin();
    vector<MX>::const_iterator rzf_aug_it = rzf_aug.begin();

    // All outputs of the return function
    vector<MX> ret_out;
    ret_out.reserve(IVPSOL_NUM_IN*nadj);

    // Collect the nondifferentiated results and forward sensitivities
    dd.resize(IVPSOL_NUM_OUT);
    fill(dd.begin(), dd.end(), MX());
    for (int dir=-1; dir<0; ++dir) {
      if ( nx_>0) dd[IVPSOL_XF]  = *xf_aug_it++;
      if ( nq_>0) dd[IVPSOL_QF]  = *qf_aug_it++;
      if ( nz_>0) dd[IVPSOL_ZF]  = *zf_aug_it++;
      if (nrx_>0) dd[IVPSOL_RXF] = *rxf_aug_it++;
      if (nrq_>0) dd[IVPSOL_RQF] = *rqf_aug_it++;
      if (nrz_>0) dd[IVPSOL_RZF] = *rzf_aug_it++;
      //ret_out.insert(ret_out.end(), dd.begin(), dd.end());
    }

    // Collect the adjoint sensitivities
    dd.resize(IVPSOL_NUM_IN);
    fill(dd.begin(), dd.end(), MX());
    for (int dir=0; dir<nadj; ++dir) {
      if ( nx_>0) dd[IVPSOL_X0]  = *rxf_aug_it++;
      if ( np_>0) dd[IVPSOL_P]   = *rqf_aug_it++;
      if ( nz_>0) dd[IVPSOL_Z0]  = *rzf_aug_it++;
      if (nrx_>0) dd[IVPSOL_RX0] = *xf_aug_it++;
      if (nrp_>0) dd[IVPSOL_RP]  = *qf_aug_it++;
      if (nrz_>0) dd[IVPSOL_RZ0] = *zf_aug_it++;
      ret_out.insert(ret_out.end(), dd.begin(), dd.end());
    }
    log("Ivpsol::getDerivative", "end");

    // Create derivative function and return
    return Function(name, ret_in, ret_out, opts);
  }

  void Ivpsol::reset(const double** arg, double** res, int* iw, double* w) {
    log("Ivpsol::reset", "begin");

    // Pass the inputs to the function
    for (int i=0; i<n_in(); ++i) {
      if (arg[i] != 0) {
        setInputNZ(arg[i], i);
      } else {
        setInput(0., i);
      }
    }

    // Go to the start time
    t_ = grid_.front();

    // Initialize output
    xf().set(x0());
    zf().set(z0());

    // Reset summation states
    qf().set(0.0);

    // Read inputs
    x0_ = arg[IVPSOL_X0];
    p_ = arg[IVPSOL_P];
    z0_ = arg[IVPSOL_Z0];
    rx0_ = arg[IVPSOL_RX0];
    rp_ = arg[IVPSOL_RP];
    rz0_ = arg[IVPSOL_RZ0];

    // Read outputs
    xf_ = res[IVPSOL_XF];
    qf_ = res[IVPSOL_QF];
    zf_ = res[IVPSOL_ZF];
    rxf_ = res[IVPSOL_RXF];
    rqf_ = res[IVPSOL_RQF];
    rzf_ = res[IVPSOL_RZF];

    // Work vectors
    arg1_ = arg + IVPSOL_NUM_IN;
    res1_ = res + IVPSOL_NUM_OUT;
    iw_ = iw;
    w_ = w;

    log("Ivpsol::reset", "end");
  }

  void Ivpsol::resetB() {
    log("Ivpsol::resetB", "begin");

    // Go to the end time
    t_ = grid_.back();

    // Initialize output
    rxf().set(rx0());
    rzf().set(rz0());

    // Reset summation states
    rqf().set(0.0);

    log("Ivpsol::resetB", "end");
  }

  Dict Ivpsol::getDerivativeOptions(bool fwd) {
    // Copy all options
    return dictionary();
  }

  Sparsity Ivpsol::spJacF() {
    // Start with the sparsity pattern of the ODE part
    Sparsity jac_ode_x = f_.sparsity_jac(DAE_X, DAE_ODE);

    // Add diagonal to get interdependencies
    jac_ode_x = jac_ode_x + Sparsity::diag(nx_);

    // Quick return if no algebraic variables
    if (nz_==0) return jac_ode_x;

    // Add contribution from algebraic variables and equations
    Sparsity jac_ode_z = f_.sparsity_jac(DAE_Z, DAE_ODE);
    Sparsity jac_alg_x = f_.sparsity_jac(DAE_X, DAE_ALG);
    Sparsity jac_alg_z = f_.sparsity_jac(DAE_Z, DAE_ALG);
    return blockcat(jac_ode_x, jac_ode_z,
                    jac_alg_x, jac_alg_z);
  }

  Sparsity Ivpsol::spJacG() {
    // Start with the sparsity pattern of the ODE part
    Sparsity jac_ode_x = g_.sparsity_jac(RDAE_RX, RDAE_ODE);

    // Add diagonal to get interdependencies
    jac_ode_x = jac_ode_x + Sparsity::diag(nrx_);

    // Quick return if no algebraic variables
    if (nrz_==0) return jac_ode_x;

    // Add contribution from algebraic variables and equations
    Sparsity jac_ode_z = g_.sparsity_jac(RDAE_RZ, RDAE_ODE);
    Sparsity jac_alg_x = g_.sparsity_jac(RDAE_RX, RDAE_ALG);
    Sparsity jac_alg_z = g_.sparsity_jac(RDAE_RZ, RDAE_ALG);
    return blockcat(jac_ode_x, jac_ode_z,
                    jac_alg_x, jac_alg_z);
  }

  std::map<std::string, Ivpsol::Plugin> Ivpsol::solvers_;

  const std::string Ivpsol::infix_ = "ivpsol";

  void Ivpsol::setStopTime(double tf) {
    casadi_error("Ivpsol::setStopTime not defined for class "
                 << typeid(*this).name());
  }

  FixedStepIvpsol::FixedStepIvpsol(const std::string& name, const XProblem& dae)
    : Ivpsol(name, dae) {
    addOption("number_of_finite_elements",     OT_INTEGER,  20, "Number of finite elements");
  }

  FixedStepIvpsol::~FixedStepIvpsol() {
  }

  void FixedStepIvpsol::init() {
    // Call the base class init
    Ivpsol::init();

    // Number of finite elements and time steps
    nk_ = option("number_of_finite_elements");
    casadi_assert(nk_>0);
    h_ = (grid_.back() - grid_.front())/nk_;

    // Setup discrete time dynamics
    setupFG();

    // Get discrete time dimensions
    Z_ = F_.input(DAE_Z);
    nZ_ = Z_.nnz();
    RZ_ = G_.isNull() ? DMatrix() : G_.input(RDAE_RZ);
    nRZ_ =  RZ_.nnz();

    // Allocate tape if backward states are present
    if (nrx_>0) {
      x_tape_.resize(nk_+1, vector<double>(nx_));
      Z_tape_.resize(nk_, vector<double>(nZ_));
    }
  }

  void FixedStepIvpsol::advance(int k) {
    // Get discrete time sought
    int k_out = std::ceil((grid_.at(k) - grid_.front())/h_);
    k_out = std::min(k_out, nk_); //  make sure that rounding errors does not result in k_out>nk_
    casadi_assert(k_out>=0);

    // Explicit discrete time dynamics
    Function& F = getExplicit();

    // Take time steps until end time has been reached
    while (k_<k_out) {
      // Take step
      F.input(DAE_T).set(t_);
      F.input(DAE_X).set(output(IVPSOL_XF));
      F.input(DAE_Z).set(Z_);
      F.input(DAE_P).set(input(IVPSOL_P));
      F.evaluate();
      F.output(DAE_ODE).get(output(IVPSOL_XF));
      F.output(DAE_ALG).get(Z_);
      copy(Z_->end()-nz_, Z_->end(), output(IVPSOL_ZF)->begin());
      transform(F.output(DAE_QUAD)->begin(),
                F.output(DAE_QUAD)->end(),
                output(IVPSOL_QF)->begin(),
                output(IVPSOL_QF)->begin(),
                std::plus<double>());

      // Tape
      if (nrx_>0) {
        output(IVPSOL_XF).getNZ(x_tape_.at(k_+1));
        Z_.getNZ(Z_tape_.at(k_));
      }

      // Advance time
      k_++;
      t_ = grid_.front() + k_*h_;
    }
  }

  void FixedStepIvpsol::retreat(int k) {
    // Get discrete time sought
    int k_out = std::floor((grid_.at(k) - grid_.front())/h_);
    k_out = std::max(k_out, 0); //  make sure that rounding errors does not result in k_out>nk_
    casadi_assert(k_out<=nk_);

    // Explicit discrete time dynamics
    Function& G = getExplicitB();

    // Take time steps until end time has been reached
    while (k_>k_out) {
      // Advance time
      k_--;
      t_ = grid_.front() + k_*h_;

      // Take step
      G.input(RDAE_T).set(t_);
      G.input(RDAE_X).setNZ(x_tape_.at(k_));
      G.input(RDAE_Z).setNZ(Z_tape_.at(k_));
      G.input(RDAE_P).set(input(IVPSOL_P));
      G.input(RDAE_RX).set(output(IVPSOL_RXF));
      G.input(RDAE_RZ).set(RZ_);
      G.input(RDAE_RP).set(input(IVPSOL_RP));
      G.evaluate();
      G.output(RDAE_ODE).get(output(IVPSOL_RXF));
      G.output(RDAE_ALG).get(RZ_);
      copy(RZ_->end()-nrz_, RZ_->end(), output(IVPSOL_RZF)->begin());
      transform(G.output(RDAE_QUAD)->begin(),
                G.output(RDAE_QUAD)->end(),
                output(IVPSOL_RQF)->begin(),
                output(IVPSOL_RQF)->begin(),
                std::plus<double>());
    }
  }

  void FixedStepIvpsol::reset(const double** arg, double** res, int* iw, double* w) {
    // Reset the base classes
    Ivpsol::reset(arg, res, iw, w);

    // Bring discrete time to the beginning
    k_ = 0;

    // Get consistent initial conditions
    calculateInitialConditions();

    // Add the first element in the tape
    if (nrx_>0) {
      output(IVPSOL_XF).getNZ(x_tape_.at(0));
    }
  }

  void FixedStepIvpsol::resetB() {
    // Reset the base classes
    Ivpsol::resetB();

    // Bring discrete time to the end
    k_ = nk_;

    // Get consistent initial conditions
    calculateInitialConditionsB();
  }

  void FixedStepIvpsol::calculateInitialConditions() {
    Z_.set(numeric_limits<double>::quiet_NaN());
  }

  void FixedStepIvpsol::calculateInitialConditionsB() {
    RZ_.set(numeric_limits<double>::quiet_NaN());
  }

  ImplicitFixedStepIvpsol::
  ImplicitFixedStepIvpsol(const std::string& name, const XProblem& dae)
    : FixedStepIvpsol(name, dae) {
    addOption("implicit_solver",               OT_STRING,  GenericType(),
              "An implicit function solver");
    addOption("implicit_solver_options",       OT_DICT, GenericType(),
              "Options to be passed to the NLP Solver");
  }

  ImplicitFixedStepIvpsol::~ImplicitFixedStepIvpsol() {
  }

  void ImplicitFixedStepIvpsol::init() {
    // Call the base class init
    FixedStepIvpsol::init();

    // Get the NLP creator function
    std::string implicit_function_name = option("implicit_solver");

    // Options
    Dict implicit_solver_options;
    if (hasSetOption("implicit_solver_options")) {
      implicit_solver_options = option("implicit_solver_options");
    }
    implicit_solver_options["implicit_input"] = DAE_Z;
    implicit_solver_options["implicit_output"] = DAE_ALG;

    // Allocate a solver
    implicit_solver_ =
      F_.nlsol(name_ + "_implicit_solver", implicit_function_name,
                    implicit_solver_options);

    // Allocate a root-finding solver for the backward problem
    if (nRZ_>0) {

      // Get the NLP creator function
      std::string backward_implicit_function_name = option("implicit_solver");

      // Options
      Dict backward_implicit_solver_options;
      if (hasSetOption("implicit_solver_options")) {
        backward_implicit_solver_options = option("implicit_solver_options");
      }
      backward_implicit_solver_options["implicit_input"] = RDAE_RZ;
      backward_implicit_solver_options["implicit_output"] = RDAE_ALG;

      // Allocate an NLP solver
      backward_implicit_solver_ =
        G_.nlsol(name_+ "_backward_implicit_solver", backward_implicit_function_name,
                      backward_implicit_solver_options);
    }
  }

} // namespace casadi