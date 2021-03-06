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


#include "reshape.hpp"
#include "../std_vector_tools.hpp"
#include "../function/sx_function.hpp"

using namespace std;

namespace casadi {

  Reshape::Reshape(const MX& x, Sparsity sp) {
    casadi_assert(x.nnz()==sp.nnz());
    setDependencies(x);
    setSparsity(sp);
  }

  Reshape* Reshape::clone() const {
    return new Reshape(*this);
  }

  void Reshape::evalD(const double** arg, double** res, int* iw, double* w) {
    evalGen<double>(arg, res, iw, w);
  }

  void Reshape::evalSX(const SXElement** arg, SXElement** res, int* iw, SXElement* w) {
    evalGen<SXElement>(arg, res, iw, w);
  }

  template<typename T>
  void Reshape::evalGen(const T** arg, T** res, int* iw, T* w) {
    if (arg[0]!=res[0]) copy(arg[0], arg[0]+nnz(), res[0]);
  }

  void Reshape::spFwd(const bvec_t** arg, bvec_t** res, int* iw, bvec_t* w) {
    copyFwd(arg[0], res[0], nnz());
  }

  void Reshape::spAdj(bvec_t** arg, bvec_t** res, int* iw, bvec_t* w) {
    copyAdj(arg[0], res[0], nnz());
  }

  std::string Reshape::print(const std::vector<std::string>& arg) const {
    // For vectors, reshape is also a transpose
    if (dep().isvector() && sparsity().isvector()) {
      // Print as transpose: X'
      return arg.at(0) + "'";
    } else {
      // Print as reshape(X) or vec(X)
      if (sparsity().iscolumn()) {
        return "vec(" + arg.at(0) + ")";
      } else {
        return "reshape(" + arg.at(0) + ")";
      }
    }
  }

  void Reshape::evalMX(const std::vector<MX>& arg, std::vector<MX>& res) {
    res[0] = reshape(arg[0], shape());
  }

  void Reshape::evalFwd(const std::vector<std::vector<MX> >& fseed,
                        std::vector<std::vector<MX> >& fsens) {
    for (int d = 0; d<fsens.size(); ++d) {
      fsens[d][0] = reshape(fseed[d][0], shape());
    }
  }

  void Reshape::evalAdj(const std::vector<std::vector<MX> >& aseed,
                        std::vector<std::vector<MX> >& asens) {
    for (int d=0; d<aseed.size(); ++d) {
      asens[d][0] += reshape(aseed[d][0], dep().shape());
    }
  }

  void Reshape::generate(const std::vector<int>& arg, const std::vector<int>& res,
                         CodeGenerator& g) const {
    if (arg[0]==res[0]) return;
    g.body << "  " << g.copy_n(g.work(arg[0], nnz()), nnz(),
                               g.work(res[0], nnz())) << endl;
  }

  MX Reshape::getReshape(const Sparsity& sp) const {
    return reshape(dep(0), sp);
  }

  MX Reshape::getTranspose() const {
    // For vectors, reshape is also a transpose
    if (dep().isvector() && sparsity().isvector()) {
      return dep();
    } else {
      return MXNode::getTranspose();
    }
  }

  bool Reshape::isValidInput() const {
    if (!dep()->isValidInput()) return false;
    return true;
  }

  int Reshape::numPrimitives() const {
    return dep()->numPrimitives();
  }

  void Reshape::getPrimitives(std::vector<MX>::iterator& it) const {
    dep()->getPrimitives(it);
  }

  void Reshape::splitPrimitives(const MX& x, std::vector<MX>::iterator& it) const {
    dep()->splitPrimitives(reshape(x, dep().shape()), it);
  }

  MX Reshape::joinPrimitives(std::vector<MX>::const_iterator& it) const {
    return reshape(dep()->joinPrimitives(it), shape());
  }

  bool Reshape::hasDuplicates() {
    return dep()->hasDuplicates();
  }

  void Reshape::resetInput() {
    dep()->resetInput();
  }

} // namespace casadi
