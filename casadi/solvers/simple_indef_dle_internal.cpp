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


#include "simple_indef_dle_internal.hpp"

#include "../core/std_vector_tools.hpp"
#include "../core/function/mx_function.hpp"
#include "../core/function/sx_function.hpp"

#include <cassert>
#include <numeric>

INPUTSCHEME(DLEInput)
OUTPUTSCHEME(DLEOutput)

using namespace std;
namespace casadi {

  extern "C"
  int CASADI_DLESOLVER_SIMPLE_EXPORT
  casadi_register_dlesolver_simple(DleInternal::Plugin* plugin) {
    plugin->creator = SimpleIndefDleInternal::creator;
    plugin->name = "simple";
    plugin->doc = SimpleIndefDleInternal::meta_doc.c_str();
    plugin->version = 23;
    return 0;
  }

  extern "C"
  void CASADI_DLESOLVER_SIMPLE_EXPORT casadi_load_dlesolver_simple() {
    DleInternal::registerPlugin(casadi_register_dlesolver_simple);
  }

  SimpleIndefDleInternal::
  SimpleIndefDleInternal(const std::map<std::string, Sparsity>& st) : DleInternal(st) {

    // set default options
    setOption("name", "unnamed_simple_indef_dle_solver"); // name of the function

    addOption("compressed_solve",         OT_BOOLEAN, true,
              "When a system with sparse rhs arises, compress to"
              "a smaller system with dense rhs.");
    addOption("linear_solver",            OT_STRING, GenericType(),
              "User-defined linear solver class. Needed for sensitivities.");
    addOption("linear_solver_options",    OT_DICT,   GenericType(),
              "Options to be passed to the linear solver.");

  }

  SimpleIndefDleInternal::~SimpleIndefDleInternal() {

  }

  void SimpleIndefDleInternal::init() {

    DleInternal::init();

    casadi_assert_message(!pos_def_,
      "pos_def option set to True: Solver only handles the indefinite case.");

    n_ = A_.size1();

    MX As = MX::sym("A", A_);
    MX Vs = MX::sym("V", V_);

    MX Vss = (Vs+Vs.T())/2;

    MX A_total = DMatrix::eye(n_*n_) - kron(As, As);

    MX Pf = A_total.zz_solve(vec(Vss), getOption("linear_solver"));

    MX P = reshape(Pf, n_, n_);

    f_ = MXFunction(name_, dleIn("a", As, "v", Vs),
                    dleOut("p", MX(P(output().sparsity()))));

    casadi_assert(nOut()==f_.nOut());
    for (int i=0;i<nIn();++i) {
      casadi_assert_message(input(i).sparsity()==f_.input(i).sparsity(),
        "Sparsity mismatch for input " << i << ":" <<
        input(i).dimString() << " <-> " << f_.input(i).dimString() << ".");
    }
    for (int i=0;i<nOut();++i) {
      casadi_assert_message(output(i).sparsity()==f_.output(i).sparsity(),
        "Sparsity mismatch for output " << i << ":" <<
        output(i).dimString() << " <-> " << f_.output(i).dimString() << ".");
    }
  }



  void SimpleIndefDleInternal::evaluate() {
    for (int i=0;i<nIn();++i) {
      std::copy(input(i).begin(), input(i).end(), f_.input(i).begin());
    }
    f_.evaluate();
    for (int i=0;i<nOut();++i) {
      std::copy(f_.output(i).begin(), f_.output(i).end(), output(i).begin());
    }
  }

  Function SimpleIndefDleInternal
  ::getDerForward(const std::string& name, int nfwd, Dict& opts) {
    return f_.derForward(nfwd);
  }

  Function SimpleIndefDleInternal
  ::getDerReverse(const std::string& name, int nadj, Dict& opts) {
    return f_.derReverse(nadj);
  }

  void SimpleIndefDleInternal::deepCopyMembers(
      std::map<SharedObjectNode*, SharedObject>& already_copied) {
    DleInternal::deepCopyMembers(already_copied);
  }

  SimpleIndefDleInternal* SimpleIndefDleInternal::clone() const {
    // Return a deep copy
    SimpleIndefDleInternal* node =
      new SimpleIndefDleInternal(make_map("a", st_[Dle_STRUCT_A],
                                          "v", st_[Dle_STRUCT_V]));
    node->setOption(dictionary());
    return node;
  }


} // namespace casadi


