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


#include "custom_function_internal.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

namespace casadi {

using namespace std;

  CustomFunction::CustomFunction() {
  }

  CustomFunction::CustomFunction(const std::string& name, const CustomEvaluate &c_fcn,
                                 const std::vector<Sparsity>& inputscheme,
                                 const std::vector<Sparsity>& outputscheme,
                                 const Dict& opts) {
    assignNode(new CustomFunctionInternal(c_fcn, inputscheme, outputscheme));
    setOption("name", name);
    setOption(opts);
    init();
  }

  CustomFunction::CustomFunction(const std::string& name, const CustomEvaluate &c_fcn,
                                 const pair<SparsityDict, vector<string> >& inputscheme,
                                 const vector<Sparsity>& outputscheme,
                                 const Dict& opts) {
    assignNode(new CustomFunctionInternal(c_fcn, make_vector(inputscheme), outputscheme));
    setOption("name", name);
    setOption("input_scheme", inputscheme.second);
    setOption(opts);
    init();
  }

  CustomFunction::CustomFunction(const std::string& name, const CustomEvaluate &c_fcn,
                                 const vector<Sparsity> &inputscheme,
                                 const pair<SparsityDict, vector<string> > &outputscheme,
                                 const Dict& opts) {
    assignNode(new CustomFunctionInternal(c_fcn, inputscheme, make_vector(outputscheme)));
    setOption("name", name);
    setOption("output_scheme", outputscheme.second);
    setOption(opts);
    init();
  }

  CustomFunction::CustomFunction(const std::string& name, const CustomEvaluate &c_fcn,
                                 const pair<SparsityDict, vector<string> > &inputscheme,
                                 const pair<SparsityDict, vector<string> > &outputscheme,
                                 const Dict& opts) {
    assignNode(new CustomFunctionInternal(c_fcn, make_vector(inputscheme),
                                          make_vector(outputscheme)));
    setOption("name", name);
    setOption("input_scheme", inputscheme.second);
    setOption("output_scheme", outputscheme.second);
    setOption(opts);
    init();
  }

#ifdef WITH_DEPRECATED_FEATURES
  CustomFunction::CustomFunction(const CustomEvaluate &c_fcn, const vector<Sparsity>& inputscheme,
                                 const vector<Sparsity>& outputscheme) {
    assignNode(new CustomFunctionInternal(c_fcn, inputscheme, outputscheme));
  }

  CustomFunction::CustomFunction(const CustomEvaluate &c_fcn,
                                 const pair<SparsityDict, vector<string> >& inputscheme,
                                 const vector<Sparsity>& outputscheme) {
    assignNode(new CustomFunctionInternal(c_fcn, make_vector(inputscheme), outputscheme));
    setOption("input_scheme", inputscheme.second);
  }

  CustomFunction::CustomFunction(const CustomEvaluate &c_fcn, const vector<Sparsity> &inputscheme,
                                 const pair<SparsityDict, vector<string> > &outputscheme) {
    assignNode(new CustomFunctionInternal(c_fcn, inputscheme, make_vector(outputscheme)));
    setOption("output_scheme", outputscheme.second);
  }

  CustomFunction::CustomFunction(const CustomEvaluate &c_fcn,
                                 const pair<SparsityDict, vector<string> > &inputscheme,
                                 const pair<SparsityDict, vector<string> > &outputscheme) {
    assignNode(new CustomFunctionInternal(c_fcn, make_vector(inputscheme),
                                          make_vector(outputscheme)));
    setOption("input_scheme", inputscheme.second);
    setOption("output_scheme", outputscheme.second);
  }
#endif // WITH_DEPRECATED_FEATURES

  CustomFunctionInternal* CustomFunction::operator->() {
    return static_cast<CustomFunctionInternal*>(Function::operator->());
  }

  const CustomFunctionInternal* CustomFunction::operator->() const {
    return static_cast<const CustomFunctionInternal*>(Function::operator->());
  }

  bool CustomFunction::testCast(const SharedObjectNode* ptr) {
    return dynamic_cast<const CustomFunctionInternal*>(ptr)!=0;
  }

} // namespace casadi
