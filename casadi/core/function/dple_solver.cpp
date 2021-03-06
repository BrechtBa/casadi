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


#include "dple_solver.hpp"
#include "dple_internal.hpp"

using namespace std;
namespace casadi {

  DpleSolver::DpleSolver() {

  }

  DpleSolver  DpleSolver::clone() const {
    DpleSolver ret;
    if (!isNull()) ret.assignNode((*this)->clone());
    return ret;
  }

  void DpleSolver::printStats(ostream &stream) const {
    (*this)->printStats(stream);
  }

  DpleInternal* DpleSolver::operator->() {
    return static_cast<DpleInternal*>(Function::operator->());
  }

  const DpleInternal* DpleSolver::operator->() const {
    return static_cast<const DpleInternal*>(Function::operator->());
  }

  bool DpleSolver::testCast(const SharedObjectNode* ptr) {
    return dynamic_cast<const DpleInternal*>(ptr)!=0;
  }

  bool DpleSolver::hasPlugin(const std::string& name) {
    return DpleInternal::hasPlugin(name);
  }

  void DpleSolver::loadPlugin(const std::string& name) {
    DpleInternal::loadPlugin(name);
  }

  std::string DpleSolver::doc(const std::string& name) {
    return DpleInternal::getPlugin(name).doc;
  }

  DpleSolver::DpleSolver(const std::string& name, const std::string& solver,
                         const std::map<std::string, std::vector<Sparsity> >& st,
                         const Dict& opts) {
    assignNode(DpleInternal::instantiatePlugin(solver, st));
    setOption("name", name);
    setOption(opts);
    init();
  }

#ifdef WITH_DEPRECATED_FEATURES
  DpleSolver::DpleSolver(const std::string& solver,
                         const std::map<std::string, std::vector<Sparsity> >& st) {
    assignNode(DpleInternal::instantiatePlugin(solver, st));
  }
#endif // WITH_DEPRECATED_FEATURES

  void DpleSolver::periodic_schur(const std::string& name,
                                  const std::vector< Matrix<double> > & A,
                                  std::vector< Matrix<double> > & T,
                                  std::vector< Matrix<double> > & Z,
                                  std::vector<double> &eig_real,
                                  std::vector<double> &eig_imag,
                                  double num_zero) {
    check_exposed(DpleInternal::getPlugin(name).exposed.periodic_shur)
      (A, T, Z, eig_real, eig_imag, num_zero);
  }

} // namespace casadi
