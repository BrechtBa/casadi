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


#include "dle_to_lr_dle.hpp"
#include "../core/std_vector_tools.hpp"
#include "../core/function/mx_function.hpp"
#include "../core/function/sx_function.hpp"

#include <cassert>
#include <numeric>

INPUTSCHEME(DLEInput)

using namespace std;
namespace casadi {

  extern "C"
  int CASADI_DLESOLVER_LRDLE_EXPORT
  casadi_register_dlesolver_lrdle(DleInternal::Plugin* plugin) {
    plugin->creator = DleToLrDle::creator;
    plugin->name = "lrdle";
    plugin->doc = DleToLrDle::meta_doc.c_str();
    plugin->version = 23;
    plugin->adaptorHasPlugin = LrDleSolver::hasPlugin;
    return 0;
  }

  extern "C"
  void CASADI_DLESOLVER_LRDLE_EXPORT casadi_load_dlesolver_lrdle() {
    DleInternal::registerPlugin(casadi_register_dlesolver_lrdle);
  }

  DleToLrDle::DleToLrDle(const std::map<std::string, Sparsity>& st) : DleInternal(st) {

    // set default options
    setOption("name", "unnamed_lr_dle_to_dle"); // name of the function

    Adaptor<DleToLrDle, LrDleInternal>::addOptions();
  }

  DleToLrDle::~DleToLrDle() {

  }

  void DleToLrDle::init() {
    // Initialize the base classes
    DleInternal::init();

    MX A = MX::sym("A", A_);
    MX V = MX::sym("V", V_);

    // Solver options
    Dict options;
    if (hasSetOption(optionsname())) {
      options = getOption(optionsname());
    }

    // Create an LrDleSolver instance
    solver_ = LrDleSolver("solver", getOption(solvername()),
                          make_map("a", A_, "v", V_), options);

    MX P = solver_(make_map("a", A, "v", V)).at("y");

    f_ = MXFunction(name_, dleIn("a", A, "v", V), dleOut("p", P));

    Wrapper<DleToLrDle>::checkDimensions();

  }

  void DleToLrDle::evaluate() {
    Wrapper<DleToLrDle>::evaluate();
  }

  Function DleToLrDle
  ::getDerForward(const std::string& name, int nfwd, Dict& opts) {
    return f_.derForward(nfwd);
  }

  Function DleToLrDle
  ::getDerReverse(const std::string& name, int nadj, Dict& opts) {
    return f_.derReverse(nadj);
  }

  void DleToLrDle::deepCopyMembers(
      std::map<SharedObjectNode*, SharedObject>& already_copied) {
    DleInternal::deepCopyMembers(already_copied);
  }

  DleToLrDle* DleToLrDle::clone() const {
    // Return a deep copy
    DleToLrDle* node =
      new DleToLrDle(make_map("a", st_[Dle_STRUCT_A], "v", st_[Dle_STRUCT_V]));
    node->setOption(dictionary());
    return node;
  }


} // namespace casadi


