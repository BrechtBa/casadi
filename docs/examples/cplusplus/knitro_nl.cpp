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

#include <casadi/casadi.hpp>
 
/**
 * This example demonstrates how NL-files, which can be generated
 * by AMPl or Pyomo, can be imported in CasADi and solved using
 * e.g. the interface to AMPL
 
 \author Joel Andersson, Vyacheslav Kungurtsev
 \date 2013
*/
  
using namespace casadi;
 
int main(int argc, char **argv){

  // Get the problem
  std::string problem = (argc==2) ? argv[1] : "../docs/examples/nl_files/hs107.nl";

  // Parse an NL-file
  NlpBuilder nl;
  nl.parseNL(problem);

  // NLP
  SXFunction nlp("nlp", nlpIn("x", nl.x), nlpOut("f", nl.f, "g", nl.g));

  // Set options
  Dict opts;
  // opts["verbose"] = true;

  // Allocate NLP solver and buffers
  NlpSolver nlp_solver("nlp_solver", "knitro", nlp, opts);
  std::map<std::string, DMatrix> arg, res;

  // Structure with bounds and initial guess
  arg["lbx"] = nl.x_lb;
  arg["ubx"] = nl.x_ub;
  arg["lbg"] = nl.g_lb;
  arg["ubg"] = nl.g_ub;
  arg["x0"] = nl.x_init;

  // Solve the NLP
  res = nlp_solver(arg);

  return 0;
}
