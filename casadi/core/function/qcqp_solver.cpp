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


#include "qcqp_solver_internal.hpp"

using namespace std;
namespace casadi {

  QcqpSolver::QcqpSolver() {
  }

  QcqpSolverInternal* QcqpSolver::operator->() {
    return static_cast<QcqpSolverInternal*>(Function::operator->());
  }

  const QcqpSolverInternal* QcqpSolver::operator->() const {
    return static_cast<const QcqpSolverInternal*>(Function::operator->());
  }

  bool QcqpSolver::testCast(const SharedObjectNode* ptr) {
    return dynamic_cast<const QcqpSolverInternal*>(ptr)!=0;
  }

  QcqpSolver::QcqpSolver(const std::string& name, const std::string& solver,
                         const std::map<std::string, Sparsity>& st, const Dict& opts) {
    assignNode(QcqpSolverInternal::instantiatePlugin(solver, st));
    setOption("name", name);
    setOption(opts);
    init();
  }

#ifdef WITH_DEPRECATED_FEATURES
  QcqpSolver::QcqpSolver(const std::string& solver,
                         const std::map<std::string, Sparsity>& st) {
    assignNode(QcqpSolverInternal::instantiatePlugin(solver, st));
  }
#endif // WITH_DEPRECATED_FEATURES

  bool QcqpSolver::hasPlugin(const std::string& name) {
    return QcqpSolverInternal::hasPlugin(name);
  }

  void QcqpSolver::loadPlugin(const std::string& name) {
    QcqpSolverInternal::loadPlugin(name);
  }

  std::string QcqpSolver::doc(const std::string& name) {
    return QcqpSolverInternal::getPlugin(name).doc;
  }

} // namespace casadi
