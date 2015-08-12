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


#include "repmat.hpp"
#include "../std_vector_tools.hpp"
#include "../function/sx_function.hpp"

using namespace std;

namespace casadi {

  HorzRepmat::HorzRepmat(const MX& x, int n) : n_(n) {
    setDependencies(x);
    setSparsity(repmat(x.sparsity(), 1, n));
  }

  std::string HorzRepmat::print(const std::vector<std::string>& arg) const {
    std::stringstream ss;
    ss << "repmat("  << arg.at(0) << ", " << n_ << ")";
    return ss.str();
  }

  template<typename T>
    void HorzRepmat::evalGen(const T** arg, T** res, int* iw, T* w) {
    int nnz = dep(0).nnz();
    for (int i=0;i<n_;++i) {
      std::copy(arg[0], arg[0]+nnz, res[0]+i*nnz);
    }
  }

  void HorzRepmat::evalD(const double** arg, double** res,
                                int* iw, double* w) {
    evalGen<double>(arg, res, iw, w);
  }

  void HorzRepmat::evalSX(const SXElement** arg, SXElement** res,
                                int* iw, SXElement* w) {
    evalGen<SXElement>(arg, res, iw, w);
  }

  void HorzRepmat::evalMX(const std::vector<MX>& arg, std::vector<MX>& res) {
    res[0] = arg[0]->getRepmat(1, n_);
  }

  static bvec_t Orring(bvec_t x, bvec_t y) { return x | y; }

  void HorzRepmat::spFwd(const bvec_t** arg, bvec_t** res, int* iw, bvec_t* w) {
    int nnz = dep(0).nnz();
    std::fill(res[0], res[0]+nnz, 0);
    evalGen<bvec_t>(arg, res, iw, w);
  }

  void HorzRepmat::spAdj(bvec_t** arg, bvec_t** res, int* iw, bvec_t* w) {
    int nnz = dep(0).nnz();
    for (int i=0;i<n_;++i) {
      std::transform(res[0]+i*nnz, res[0]+(i+1)*nnz, arg[0], arg[0], &Orring);
    }
    std::fill(res[0], res[0]+nnz, 0);
  }

  void HorzRepmat::evalFwd(const std::vector<std::vector<MX> >& fseed,
                          std::vector<std::vector<MX> >& fsens) {
    for (int d=0; d<fsens.size(); ++d) {
      fsens[d][0] = fseed[d][0]->getRepmat(1, n_);
    }
  }

  void HorzRepmat::evalAdj(const std::vector<std::vector<MX> >& aseed,
                          std::vector<std::vector<MX> >& asens) {
    for (int d=0; d<asens.size(); ++d) {
      asens[d][0] += aseed[d][0]->getRepsum(1, n_);
    }
  }

  void HorzRepmat::generate(const std::vector<int>& arg, const std::vector<int>& res,
                           CodeGenerator& g) const {
    int nnz = dep(0).nnz();
    g.body << "  for (i=0;i<" << n_ << ";++i) {" << endl;
    g.body << "    copy_n(" << g.work(arg[0], dep(0).nnz()) << ", " << nnz<< ", "
      << g.work(res[0], sparsity().nnz()) << "+ i*" << nnz << ");" << endl;
    g.body << "  }" << endl;
  }

  HorzRepsum::HorzRepsum(const MX& x, int n) : n_(n) {
    casadi_assert(x.size2() % n == 0);
    x.sparsity().spy();
    std::vector<Sparsity> sp = horzsplit(x.sparsity(), x.size2()/n);
    Sparsity block = sp[0];
    for (int i=1;i<sp.size();++i) {
      block = block+sp[i];
    }
    Sparsity goal = repmat(block, 1, n);
    setDependencies(project(x, goal));
    setSparsity(block);
  }

  std::string HorzRepsum::print(const std::vector<std::string>& arg) const {
    std::stringstream ss;
    ss << "repsum("  << arg.at(0) << ", " << n_ << ")";
    return ss.str();
  }

  template<typename T, typename R>
    void HorzRepsum::evalGen(const T** arg, T** res, int* iw, T* w,
      R reduction) {
    int nnz = sparsity().nnz();
    fill_n(res[0], nnz, 0);
    for (int i=0;i<n_;++i) {
      std::transform(arg[0]+i*nnz, arg[0]+(i+1)*nnz, res[0], res[0], reduction);
    }
  }

  void HorzRepsum::evalD(const double** arg, double** res,
                                int* iw, double* w) {
    evalGen<double>(arg, res, iw, w, std::plus<double>());
  }

  void HorzRepsum::evalSX(const SXElement** arg, SXElement** res,
                                int* iw, SXElement* w) {
    evalGen<SXElement>(arg, res, iw, w, std::plus<SXElement>());
  }

  void HorzRepsum::evalMX(const std::vector<MX>& arg, std::vector<MX>& res) {
    res[0] = arg[0]->getRepsum(1, n_);
  }

  void HorzRepsum::spFwd(const bvec_t** arg, bvec_t** res, int* iw, bvec_t* w) {
    int nnz = sparsity().nnz();
    std::fill(res[0], res[0]+nnz, 0);
    evalGen<bvec_t>(arg, res, iw, w, &Orring);
  }

  void HorzRepsum::spAdj(bvec_t** arg, bvec_t** res, int* iw, bvec_t* w) {
    int nnz = sparsity().nnz();
    for (int i=0;i<n_;++i) {
      std::transform(res[0], res[0]+nnz, arg[0]+i*nnz, arg[0]+i*nnz, &Orring);
    }
    std::fill(res[0], res[0]+nnz, 0);
  }

  void HorzRepsum::evalFwd(const std::vector<std::vector<MX> >& fseed,
                          std::vector<std::vector<MX> >& fsens) {
    for (int d=0; d<fsens.size(); ++d) {
      fsens[d][0] = fseed[d][0]->getRepsum(1, n_);
    }
  }

  void HorzRepsum::evalAdj(const std::vector<std::vector<MX> >& aseed,
                          std::vector<std::vector<MX> >& asens) {
    for (int d=0; d<asens.size(); ++d) {
      asens[d][0] += aseed[d][0]->getRepmat(1, n_);
    }
  }

  void HorzRepsum::generate(const std::vector<int>& arg, const std::vector<int>& res,
                           CodeGenerator& g) const {
    int nnz = sparsity().nnz();
    g.body << "  " << g.fill_n(g.work(res[0], nnz), nnz, "0") << endl;
    g.body << "  for (i=0;i<" << n_ << ";++i) {" << endl;
    g.body << "    for (j=0;j<" << nnz << ";++j) {" << endl;
    g.body << "      " << g.work(res[0], nnz)<< "[j] += " <<
      g.work(arg[0], dep(0).nnz()) << "[j+i*" << nnz << "];" << endl;
    g.body << "    }" << endl;
    g.body << "  }" << endl;
  }

} // namespace casadi
