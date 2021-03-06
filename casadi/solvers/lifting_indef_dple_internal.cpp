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


#include "lifting_indef_dple_internal.hpp"
#include "../core/std_vector_tools.hpp"
#include "../core/function/mx_function.hpp"
#include "../core/function/sx_function.hpp"

#include <cassert>
#include <numeric>

INPUTSCHEME(DPLEInput)
OUTPUTSCHEME(DPLEOutput)

using namespace std;
namespace casadi {

  extern "C"
  int CASADI_DPLESOLVER_LIFTING_EXPORT
  casadi_register_dplesolver_lifting(DpleInternal::Plugin* plugin) {
    plugin->creator = LiftingIndefDpleInternal::creator;
    plugin->name = "lifting";
    plugin->doc = LiftingIndefDpleInternal::meta_doc.c_str();
    plugin->version = 23;
    plugin->adaptorHasPlugin = DleSolver::hasPlugin;
    return 0;
  }

  extern "C"
  void CASADI_DPLESOLVER_LIFTING_EXPORT casadi_load_dplesolver_lifting() {
    DpleInternal::registerPlugin(casadi_register_dplesolver_lifting);
  }

  LiftingIndefDpleInternal::LiftingIndefDpleInternal(const std::map<std::string,
                                                     std::vector<Sparsity> > & st)
    : DpleInternal(st) {

    // set default options
    setOption("name", "unnamed_lifting_indef_dple_solver"); // name of the function

    Adaptor<LiftingIndefDpleInternal, DleInternal>::addOptions();

    addOption("form",    OT_STRING,    "A",
              "The form of the lifting", "A:0|B:1");

  }

  LiftingIndefDpleInternal::~LiftingIndefDpleInternal() {

  }

  void LiftingIndefDpleInternal::init() {

    form_ = getOptionEnumValue("form");

    // Initialize the base classes
    DpleInternal::init();

    casadi_assert_message(!pos_def_,
      "pos_def option set to True: Solver only handles the indefinite case.");
    casadi_assert_message(const_dim_,
      "const_dim option set to False: Solver only handles the True case.");

    // We will construct an MXFunction to facilitate the calculation of derivatives

    MX As = MX::sym("As", input(DLE_A).sparsity());
    MX Vs = MX::sym("Vs", input(DLE_V).sparsity());

    n_ = A_[0].size1();

    // Chop-up the arguments
    std::vector<MX> As_ = horzsplit(As, n_);
    std::vector<MX> Vs_ = horzsplit(Vs, V_[0].size2());

    MX A;
    if (K_==1) {
      A = As;
    } else {
      if (form_==0) {
        MX AL = diagcat(vector_slice(As_, range(As_.size()-1)));

        MX AL2 = horzcat(AL, MX(AL.size1(), As_[0].size2()));
        MX AT = horzcat(MX(As_[0].size1(), AL.size2()), As_.back());
        A = vertcat(AT, AL2);
      } else {
        MX AL = diagcat(reverse(vector_slice(As_, range(As_.size()-1))));

        MX AL2 = horzcat(MX(AL.size1(), As_[0].size2()), AL);
        MX AT = horzcat(As_.back(), MX(As_[0].size1(), AL.size2()));
        A = vertcat(AL2, AT);
      }
    }

    MX V;

    if (form_==0) {
      V = diagcat(Vs_.back(), diagcat(vector_slice(Vs_, range(Vs_.size()-1))));
    } else {
      V = diagcat(diagcat(reverse(vector_slice(Vs_, range(Vs_.size()-1)))), Vs_.back());
    }

    // Solver options
    Dict options;
    if (hasSetOption(optionsname())) {
      options = getOption(optionsname());
    }

    // Create an dlesolver instance
    solver_ = DleSolver("solver", getOption(solvername()),
                        make_map("a", A.sparsity(), "v", V.sparsity()), options);

    MX Pf = solver_(make_map("a", A, "v" , V)).at("p");

    std::vector<MX> Ps = diagsplit(Pf, n_);

    if (form_==1) {
      Ps = reverse(Ps);
    }

    f_ = MXFunction(name_, dpleIn("a", As, "v", Vs), dpleOut("p", horzcat(Ps)));

    Wrapper<LiftingIndefDpleInternal>::checkDimensions();

  }



  void LiftingIndefDpleInternal::evaluate() {
    Wrapper<LiftingIndefDpleInternal>::evaluate();
  }

  Function LiftingIndefDpleInternal
  ::getDerForward(const std::string& name, int nfwd, Dict& opts) {
    return f_.derForward(nfwd);
  }

  Function LiftingIndefDpleInternal
  ::getDerReverse(const std::string& name, int nadj, Dict& opts) {
    return f_.derReverse(nadj);
  }

  void LiftingIndefDpleInternal::deepCopyMembers(
      std::map<SharedObjectNode*, SharedObject>& already_copied) {
    DpleInternal::deepCopyMembers(already_copied);
  }

  LiftingIndefDpleInternal* LiftingIndefDpleInternal::clone() const {
    // Return a deep copy
    std::map<std::string, std::vector<Sparsity> > tmp;
    tmp["a"] = st_[Dple_STRUCT_A];
    tmp["v"] = st_[Dple_STRUCT_V];
    LiftingIndefDpleInternal* node = new LiftingIndefDpleInternal(tmp);
    node->setOption(dictionary());
    return node;
  }


} // namespace casadi


