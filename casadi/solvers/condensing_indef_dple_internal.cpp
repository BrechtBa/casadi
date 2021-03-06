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


#include "condensing_indef_dple_internal.hpp"
#include <cassert>
#include "../core/std_vector_tools.hpp"
#include "../core/function/mx_function.hpp"
#include "../core/function/sx_function.hpp"

#include <numeric>

INPUTSCHEME(DPLEInput)
OUTPUTSCHEME(DPLEOutput)

using namespace std;
namespace casadi {

  extern "C"
  int CASADI_DPLESOLVER_CONDENSING_EXPORT
  casadi_register_dplesolver_condensing(DpleInternal::Plugin* plugin) {
    plugin->creator = CondensingIndefDpleInternal::creator;
    plugin->name = "condensing";
    plugin->doc = CondensingIndefDpleInternal::meta_doc.c_str();
    plugin->version = 23;
    plugin->adaptorHasPlugin = DleSolver::hasPlugin;
    return 0;
  }

  extern "C"
  void CASADI_DPLESOLVER_CONDENSING_EXPORT casadi_load_dplesolver_condensing() {
    DpleInternal::registerPlugin(casadi_register_dplesolver_condensing);
  }

  CondensingIndefDpleInternal::
  CondensingIndefDpleInternal(const std::map<std::string, std::vector<Sparsity> >& st)
    : DpleInternal(st) {

    // set default options
    setOption("name", "unnamed_condensing_indef_dple_solver"); // name of the function

    Adaptor<CondensingIndefDpleInternal, DleInternal>::addOptions();

  }

  CondensingIndefDpleInternal::~CondensingIndefDpleInternal() {

  }

  void CondensingIndefDpleInternal::init() {
    // Initialize the base classes
    DpleInternal::init();

    casadi_assert_message(!pos_def_,
      "pos_def option set to True: Solver only handles the indefinite case.");
    casadi_assert_message(const_dim_,
      "const_dim option set to False: Solver only handles the True case.");

    n_ = A_[0].size1();


    MX As = MX::sym("A", horzcat(A_));
    MX Vs = MX::sym("V", horzcat(V_));

    std::vector< MX > Vss = horzsplit(Vs, n_);
    std::vector< MX > Ass = horzsplit(As, n_);

    for (int k=0;k<K_;++k) {
      Vss[k] = (Vss[k]+Vss[k].T())/2;
    }

    MX R = MX::zeros(n_, n_);

    for (int k=0;k<K_;++k) {
      R = mul(mul(Ass[k], R), Ass[k].T()) + Vss[k];
    }

    std::vector< MX > Assr(K_);
    std::reverse_copy(Ass.begin(), Ass.end(), Assr.begin());

    MX Ap = mul(Assr);

    // Solver options
    Dict options;
    if (hasSetOption(optionsname())) {
      options = getOption(optionsname());
    }

    // Create an dlesolver instance
    solver_ = DleSolver("solver", getOption(solvername()),
                        make_map("a", Ap.sparsity(), "v", R.sparsity()), options);

    std::vector<MX> Ps(K_);
    Ps[0] = solver_(make_map("a", Ap, "v", R)).at("p");

    for (int k=0;k<K_-1;++k) {
      Ps[k+1] = mul(mul(Ass[k], Ps[k]), Ass[k].T()) + Vss[k];
    }

    f_ = MXFunction(name_, dpleIn("a", As, "v", Vs), dpleOut("p", horzcat(Ps)),
                    make_dict("input_scheme", ischeme_, "output_scheme", oscheme_));
    Wrapper<CondensingIndefDpleInternal>::checkDimensions();

  }

  void CondensingIndefDpleInternal::evaluate() {
    Wrapper<CondensingIndefDpleInternal>::evaluate();
  }

  Function CondensingIndefDpleInternal
  ::getDerForward(const std::string& name, int nfwd, Dict& opts) {
    return f_.derForward(nfwd);
  }

  Function CondensingIndefDpleInternal
  ::getDerReverse(const std::string& name, int nadj, Dict& opts) {
    return f_.derReverse(nadj);
  }

  void CondensingIndefDpleInternal::deepCopyMembers(
      std::map<SharedObjectNode*, SharedObject>& already_copied) {
    DpleInternal::deepCopyMembers(already_copied);
  }

  CondensingIndefDpleInternal* CondensingIndefDpleInternal::clone() const {
    // Return a deep copy
    std::map<std::string, std::vector<Sparsity> > tmp;
    tmp["a"] = st_[Dple_STRUCT_A];
    tmp["v"] = st_[Dple_STRUCT_V];
    CondensingIndefDpleInternal* node = new CondensingIndefDpleInternal(tmp);
    node->setOption(dictionary());
    return node;
  }


} // namespace casadi


