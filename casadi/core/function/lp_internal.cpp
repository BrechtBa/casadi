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


#include "lp_internal.hpp"

INPUTSCHEME(LpSolverInput)
OUTPUTSCHEME(LpSolverOutput)

using namespace std;
namespace casadi {

  // Constructor
  LpSolverInternal::LpSolverInternal(const std::map<std::string, Sparsity> &st) {
    st_.resize(LP_STRUCT_NUM);
    for (std::map<std::string, Sparsity>::const_iterator i=st.begin(); i!=st.end(); ++i) {
      if (i->first=="a") {
        st_[LP_STRUCT_A]=i->second;
      } else {
        casadi_error("Unrecognized field in LP structure: " << i->first);
      }
    }

    const Sparsity& A = st_[LP_STRUCT_A];

    n_ = A.size2();
    nc_ = A.size1();


    // Input arguments
    ibuf_.resize(LP_SOLVER_NUM_IN);
    input(LP_SOLVER_A) = DMatrix::zeros(A);
    input(LP_SOLVER_C) = DMatrix::zeros(n_);
    input(LP_SOLVER_LBA) = -DMatrix::inf(nc_);
    input(LP_SOLVER_UBA) = DMatrix::inf(nc_);
    input(LP_SOLVER_LBX) = -DMatrix::inf(n_);
    input(LP_SOLVER_UBX) = DMatrix::inf(n_);

    // Output arguments
    obuf_.resize(LP_SOLVER_NUM_OUT);
    output(LP_SOLVER_X) = DMatrix::zeros(n_);
    output(LP_SOLVER_COST) = 0.0;
    output(LP_SOLVER_LAM_X) = DMatrix::zeros(n_);
    output(LP_SOLVER_LAM_A) = DMatrix::zeros(nc_);

    ischeme_ = IOScheme(SCHEME_LpSolverInput);
    oscheme_ = IOScheme(SCHEME_LpSolverOutput);
  }

  void LpSolverInternal::init() {
    // Call the init method of the base class
    FunctionInternal::init();
  }

  LpSolverInternal::~LpSolverInternal() {
  }

  void LpSolverInternal::evaluate() {
    throw CasadiException("LpSolverInternal::evaluate: Not implemented");
  }

  void LpSolverInternal::solve() {
    throw CasadiException("LpSolverInternal::solve: Not implemented");
  }

  void LpSolverInternal::checkInputs() const {
    for (int i=0;i<input(LP_SOLVER_LBX).nnz();++i) {
      casadi_assert_message(input(LP_SOLVER_LBX).at(i)<=input(LP_SOLVER_UBX).at(i),
                            "LBX[i] <= UBX[i] was violated for i=" << i
                            << ". Got LBX[i] " << input(LP_SOLVER_LBX).at(i)
                            << " and UBX[i] " << input(LP_SOLVER_UBX).at(i));
    }
    for (int i=0;i<input(LP_SOLVER_LBA).nnz();++i) {
      casadi_assert_message(input(LP_SOLVER_LBA).at(i)<=input(LP_SOLVER_UBA).at(i),
                            "LBA[i] <= UBA[i] was violated for i=" << i
                            << ". Got LBA[i] " << input(LP_SOLVER_LBA).at(i)
                            << " and UBA[i] " << input(LP_SOLVER_UBA).at(i));
    }
  }

  std::map<std::string, LpSolverInternal::Plugin> LpSolverInternal::solvers_;

  const std::string LpSolverInternal::infix_ = "lpsolver";

  double LpSolverInternal::defaultInput(int ind) const {
    switch (ind) {
    case LP_SOLVER_LBX:
    case LP_SOLVER_LBA:
      return -std::numeric_limits<double>::infinity();
    case LP_SOLVER_UBX:
    case LP_SOLVER_UBA:
      return std::numeric_limits<double>::infinity();
    default:
      return 0;
    }
  }

} // namespace casadi
