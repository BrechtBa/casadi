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


#include "assertion.hpp"

using namespace std;

namespace casadi {

  Assertion::Assertion(const MX& x, const MX& y, const std::string & fail_message)
      : fail_message_(fail_message) {
    casadi_assert_message(y.isscalar(),
                          "Assertion:: assertion expression y must be scalar, but got "
                          << y.dimString());
    setDependencies(x, y);
    setSparsity(x.sparsity());
  }

  std::string Assertion::print(const std::vector<std::string>& arg) const {
    return "assertion(" + arg.at(0) + ", " + arg.at(1) + ")";
  }

  void Assertion::evalMX(const std::vector<MX>& arg, std::vector<MX>& res) {
    res[0] = arg[0].attachAssert(arg[1], fail_message_);
  }

  void Assertion::evalFwd(const std::vector<std::vector<MX> >& fseed,
                     std::vector<std::vector<MX> >& fsens) {
    for (int d=0; d<fsens.size(); ++d) {
      fsens[d][0] = fseed[d][0];
    }
  }

  void Assertion::evalAdj(const std::vector<std::vector<MX> >& aseed,
                     std::vector<std::vector<MX> >& asens) {
    for (int d=0; d<aseed.size(); ++d) {
      asens[d][0] += aseed[d][0];
    }
  }

  void Assertion::evalSX(const SXElement** arg, SXElement** res,
                             int* iw, SXElement* w) {
    if (arg[0]!=res[0]) {
      copy(arg[0], arg[0]+nnz(), res[0]);
    }
  }

  void Assertion::evalD(const double** arg, double** res,
                        int* iw, double* w) {
    if (arg[1][0]!=1) {
      casadi_error("Assertion error: " << fail_message_);
    }

    if (arg[0]!=res[0]) {
      copy(arg[0], arg[0]+nnz(), res[0]);
    }
  }

  void Assertion::spFwd(const bvec_t** arg,
                        bvec_t** res, int* iw, bvec_t* w) {
    if (arg[0]!=res[0]) {
      copy(arg[0], arg[0]+nnz(), res[0]);
    }
  }

  void Assertion::spAdj(bvec_t** arg,
                        bvec_t** res, int* iw, bvec_t* w) {
    bvec_t *a = arg[0];
    bvec_t *r = res[0];
    int n = nnz();
    if (a != r) {
      for (int i=0; i<n; ++i) {
        *a++ |= *r;
        *r++ = 0;
      }
    }
  }

  void Assertion::generate(const std::vector<int>& arg, const std::vector<int>& res,
                           CodeGenerator& g) const {
    // Generate assertion
    g.body << "  if (" << g.workel(arg[1]) << "!=1.) {" << endl
           << "    /* " << fail_message_ << " */" << endl
           << "    return 1;" << endl
           << "  }" << endl;

    // Copy if not inplace
    if (arg[0]!=res[0]) {
      g.body << "  " << g.copy_n(g.work(arg[0], nnz()), nnz(),
                                 g.work(res[0], nnz())) << endl;
    }
  }

} // namespace casadi
