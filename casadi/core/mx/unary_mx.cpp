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


#include "unary_mx.hpp"
#include <vector>
#include <sstream>
#include "../std_vector_tools.hpp"
#include "../casadi_options.hpp"

using namespace std;

namespace casadi {

  UnaryMX::UnaryMX(Operation op, MX x) : op_(op) {
    // Put a densifying node in between if necessary
    if (!operation_checker<F00Checker>(op_)) {
      x.makeDense();
    }

    setDependencies(x);
    setSparsity(x->sparsity());
  }

  UnaryMX* UnaryMX::clone() const {
    return new UnaryMX(*this);
  }

  std::string UnaryMX::print(const std::vector<std::string>& arg) const {
    stringstream ss;
    casadi_math<double>::printPre(op_, ss);
    ss << arg.at(0);
    casadi_math<double>::printPost(op_, ss);
    return ss.str();
  }

  void UnaryMX::evalD(const double** arg, double** res, int* iw, double* w) {
    double dummy = numeric_limits<double>::quiet_NaN();
    casadi_math<double>::fun(op_, arg[0], dummy, res[0], nnz());
  }

  void UnaryMX::evalSX(const SXElement** arg, SXElement** res,
                       int* iw, SXElement* w) {
    SXElement dummy = 0;
    casadi_math<SXElement>::fun(op_, arg[0], dummy, res[0], nnz());
  }

  void UnaryMX::evalMX(const std::vector<MX>& arg, std::vector<MX>& res) {
    MX dummy;
    casadi_math<MX>::fun(op_, arg[0], dummy, res[0]);
  }

  void UnaryMX::evalFwd(const std::vector<std::vector<MX> >& fseed,
                     std::vector<std::vector<MX> >& fsens) {
    // Get partial derivatives
    MX pd[2];
    MX dummy; // Function value, dummy second argument
    casadi_math<MX>::der(op_, dep(), dummy, shared_from_this<MX>(), pd);

    // Propagate forward seeds
    for (int d=0; d<fsens.size(); ++d) {
      fsens[d][0] = pd[0]*fseed[d][0];
    }
  }

  void UnaryMX::evalAdj(const std::vector<std::vector<MX> >& aseed,
                     std::vector<std::vector<MX> >& asens) {
    // Get partial derivatives
    MX pd[2];
    MX dummy; // Function value, dummy second argument
    casadi_math<MX>::der(op_, dep(), dummy, shared_from_this<MX>(), pd);

    // Propagate adjoint seeds
    for (int d=0; d<aseed.size(); ++d) {
      asens[d][0] += pd[0]*aseed[d][0];
    }
  }

  void UnaryMX::spFwd(const bvec_t** arg,
                      bvec_t** res, int* iw, bvec_t* w) {
    copyFwd(arg[0], res[0], nnz());
  }

  void UnaryMX::spAdj(bvec_t** arg,
                      bvec_t** res, int* iw, bvec_t* w) {
    copyAdj(arg[0], res[0], nnz());
  }

  void UnaryMX::generate(const std::vector<int>& arg, const std::vector<int>& res,
                         CodeGenerator& g) const {
    string r, x;
    g.body << "  ";
    if (nnz()==1) {
      // Scalar assignment
      r = g.workel(res[0]);
      x = g.workel(arg[0]);
    } else {
      // Vector assignment
      g.body << "for (i=0, rr=" << g.work(res[0], nnz()) << ", cs=" << g.work(arg[0], nnz())
             << "; i<" << sparsity().nnz() << "; ++i) ";
      r = "*rr++";
      x = "(*cs++)";
    }

    // Output the operation
    g.body << r << " = ";
    casadi_math<double>::printPre(op_, g.body);
    g.body << x;
    casadi_math<double>::printPost(op_, g.body);
    g.body << ";" << endl;
  }

  MX UnaryMX::getUnary(int op) const {
    if (!CasadiOptions::simplification_on_the_fly) return MXNode::getUnary(op);

    switch (op_) {
    case OP_NEG:
      if (op==OP_NEG) return dep();
      else if (op==OP_SQ) return dep()->getUnary(OP_SQ);
      else if (op==OP_FABS) return dep()->getUnary(OP_FABS);
      else if (op==OP_COS) return dep()->getUnary(OP_COS);
      break;
    case OP_SQRT:
      if (op==OP_SQ) return dep();
      else if (op==OP_FABS) return shared_from_this<MX>();
      break;
    case OP_SQ:
      if (op==OP_SQRT) return dep()->getUnary(OP_FABS);
      else if (op==OP_FABS) return shared_from_this<MX>();
      break;
    case OP_EXP:
      if (op==OP_LOG) return dep();
      else if (op==OP_FABS) return shared_from_this<MX>();
      break;
    case OP_LOG:
      if (op==OP_EXP) return dep();
      break;
    case OP_FABS:
      if (op==OP_FABS) return shared_from_this<MX>();
      else if (op==OP_SQ) return dep()->getUnary(OP_SQ);
      else if (op==OP_COS) return dep()->getUnary(OP_COS);
      break;
    case OP_INV:
      if (op==OP_INV) return dep();
      break;
    default: break; // no rule
    }

    // Fallback to default implementation
    return MXNode::getUnary(op);
  }

  MX UnaryMX::getBinary(int op, const MX& y, bool scX, bool scY) const {
    switch (op_) {
    case OP_NEG:
      if (op==OP_ADD) return y->getBinary(OP_SUB, dep(), scY, scX);
      else if (op==OP_MUL) return -dep()->getBinary(OP_MUL, y, scX, scY);
      else if (op==OP_DIV) return -dep()->getBinary(OP_DIV, y, scX, scY);
      break;
    case OP_TWICE:
      if (op==OP_SUB && isEqual(y, dep(), maxDepth())) return dep();
      break;
    case OP_SQ:
      if (op==OP_ADD && y.getOp()==OP_SQ) /*sum of squares:*/
        if ((dep().getOp()==OP_SIN && y->dep().getOp()==OP_COS) ||
           (dep().getOp()==OP_COS && y->dep()->getOp()==OP_SIN)) /* sin^2(x)+sin^2(y) */
          if (isEqual(dep()->dep(), y->dep()->dep(), maxDepth())) /*sin^2(x) + cos^2(x) */
            return MX::ones(y.sparsity());
      break;
    default: break; // no rule
    }

    // Fallback to default implementation
    return MXNode::getBinary(op, y, scX, scY);
  }

} // namespace casadi
