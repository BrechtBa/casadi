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


#include "stabilized_qp_solver_internal.hpp"

INPUTSCHEME(StabilizedQpSolverInput)
OUTPUTSCHEME(QpSolverOutput)

using namespace std;
namespace casadi {

  // Constructor
  StabilizedQpSolverInternal::
  StabilizedQpSolverInternal(const std::map<std::string, Sparsity> &st) {
    st_.resize(QP_STRUCT_NUM);
    for (std::map<std::string, Sparsity>::const_iterator i=st.begin(); i!=st.end(); ++i) {
      if (i->first=="a") {
        st_[QP_STRUCT_A]=i->second;
      } else if (i->first=="h") {
        st_[QP_STRUCT_H]=i->second;
      } else {
        casadi_error("Unrecognized field in QP structure: " << i->first);
      }
    }

    // Get structure
    const Sparsity& A = st_[QP_STRUCT_A];
    const Sparsity& H = st_[QP_STRUCT_H];

    // Dimensions
    n_ = H.size2();
    nc_ = A.isNull() ? 0 : A.size1();

    addOption("defaults_recipes",    OT_STRINGVECTOR, GenericType(), "",
                                                       "qp", true);

    // Check consistency
    casadi_assert_message(A.isNull() || A.size2()==n_,
      "Got incompatible dimensions.   min          x'Hx + G'x s.t.   LBA <= Ax <= UBA :"
       << std::endl <<
      "H: " << H.dimString() << " - A: " << A.dimString() << std::endl <<
      "We need: H.size2()==A.size2()" << std::endl);

    casadi_assert_message(H.issymmetric(),
      "Got incompatible dimensions.   min          x'Hx + G'x" << std::endl <<
      "H: " << H.dimString() <<
      "We need H square & symmetric" << std::endl);

    // IO sparsities
    Sparsity x_sparsity = Sparsity::dense(n_, 1);
    Sparsity a_sparsity = Sparsity::dense(nc_, 1);

    // Input arguments
    ibuf_.resize(STABILIZED_QP_SOLVER_NUM_IN);
    input(STABILIZED_QP_SOLVER_X0)  =  DMatrix::zeros(x_sparsity);
    input(STABILIZED_QP_SOLVER_H)   =  DMatrix::zeros(H);
    input(STABILIZED_QP_SOLVER_G)   =  DMatrix::zeros(x_sparsity);
    input(STABILIZED_QP_SOLVER_A)   =  DMatrix::zeros(A);
    input(STABILIZED_QP_SOLVER_LBA) = -DMatrix::inf(a_sparsity);
    input(STABILIZED_QP_SOLVER_UBA) =  DMatrix::inf(a_sparsity);
    input(STABILIZED_QP_SOLVER_LBX) = -DMatrix::inf(x_sparsity);
    input(STABILIZED_QP_SOLVER_UBX) =  DMatrix::inf(x_sparsity);
    input(STABILIZED_QP_SOLVER_MUR) =  0.0;
    input(STABILIZED_QP_SOLVER_MUE) =  DMatrix::zeros(a_sparsity);
    input(STABILIZED_QP_SOLVER_MU)  =  DMatrix::zeros(a_sparsity);

    // Output arguments
    obuf_.resize(QP_SOLVER_NUM_OUT);
    output(QP_SOLVER_X)             =  DMatrix::zeros(x_sparsity);
    output(QP_SOLVER_COST)          =  0.0;
    output(QP_SOLVER_LAM_X)         =  DMatrix::zeros(x_sparsity);
    output(QP_SOLVER_LAM_A)         =  DMatrix::zeros(a_sparsity);

    // IO scheme
    ischeme_ = IOScheme(SCHEME_StabilizedQpSolverInput);
    oscheme_ = IOScheme(SCHEME_QpSolverOutput);
  }

  void StabilizedQpSolverInternal::init() {
    // Call the init method of the base class
    FunctionInternal::init();
  }

  StabilizedQpSolverInternal::~StabilizedQpSolverInternal() {
  }

  void StabilizedQpSolverInternal::evaluate() {
    throw CasadiException("StabilizedQpSolverInternal::evaluate: Not implemented");
  }

  void StabilizedQpSolverInternal::solve() {
    throw CasadiException("StabilizedQpSolverInternal::solve: Not implemented");
  }

  void StabilizedQpSolverInternal::checkInputs() const {
    // Check box constraints
    const vector<double>& lbx = input(STABILIZED_QP_SOLVER_LBX).data();
    const vector<double>& ubx = input(STABILIZED_QP_SOLVER_UBX).data();
    for (int i=0; i<lbx.size(); ++i) {
      casadi_assert_message(lbx.at(i)<=ubx.at(i),
                            "LBX[" << i << "]== <= UBX[" << i << "] was violated. "
                            "Got LBX["<<i<<"]=" << lbx.at(i)
                            << " and UBX[" << i << "]=" << ubx.at(i));
    }

    // Check linear constraint bounds
    const vector<double>& lba = input(STABILIZED_QP_SOLVER_LBA).data();
    const vector<double>& uba = input(STABILIZED_QP_SOLVER_UBA).data();
    for (int i=0; i<lba.size(); ++i) {
      casadi_assert_message(lba.at(i)<=uba.at(i),
                            "LBA[" << i << "]== <= UBA[" << i << "] was violated. "
                            "Got LBA["<<i<<"]=" << lba.at(i)
                            << " and UBA[" << i << "]=" << uba.at(i));
    }
  }

  std::map<std::string, StabilizedQpSolverInternal::Plugin> StabilizedQpSolverInternal::solvers_;

  const std::string StabilizedQpSolverInternal::infix_ = "stabilizedqpsolver";


} // namespace casadi
