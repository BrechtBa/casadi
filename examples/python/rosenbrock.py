#
#     This file is part of CasADi.
# 
#     CasADi -- A symbolic framework for dynamic optimization.
#     Copyright (C) 2010 by Joel Andersson, Moritz Diehl, K.U.Leuven. All rights reserved.
# 
#     CasADi is free software; you can redistribute it and/or
#     modify it under the terms of the GNU Lesser General Public
#     License as published by the Free Software Foundation; either
#     version 3 of the License, or (at your option) any later version.
# 
#     CasADi is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#     Lesser General Public License for more details.
# 
#     You should have received a copy of the GNU Lesser General Public
#     License along with CasADi; if not, write to the Free Software
#     Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
# 
# 
from casadi import *
import numpy as NP
import matplotlib.pyplot as plt

# Declare variables
x = ssym("x")
y = ssym("y")
z = ssym("z")
v = vertcat([x,y,z])

# Form NLP functions
f = SXFunction([v],[x**2 + 100*z**2])
g = SXFunction([v],[z + (1-x)**2 - y])

# Choose NLP solver
nlp_solver = IpoptSolver
#nlp_solver = WorhpSolver
#nlp_solver = SQPMethod
#nlp_solver = LiftedSQP

# Choose a qp solver (for CasADi NLP methods)
#qp_solver = QPOasesSolver
#qp_solver_options = {"printLevel" : "none"}

#qp_solver = NLPQPSolver
#qp_solver_options = {"nlp_solver":IpoptSolver, "nlp_solver_options": {"print_level" : 0}}

#qp_solver = OOQPSolver
#qp_solver_options = {}

# Create solver
solv = nlp_solver(f,g)

# NLP solver options
solv.setOption("generate_hessian",True)
if nlp_solver in (SQPMethod, LiftedSQP):
  solv.setOption("qp_solver",qp_solver)
  solv.setOption("qp_solver_options",qp_solver_options)
  solv.setOption("maxiter",5)
if nlp_solver == SQPMethod:
  #solv.setOption("monitor",['qp'])
  solv.setOption("hessian_approximation","exact")
  
# Init solver  
solv.init()

# Solve the rosenbrock problem
solv.setInput([2.5,3.0,0.75],NLP_X_INIT)
solv.setInput(0,NLP_UBG)
solv.setInput(0,NLP_LBG)
solv.evaluate()

# Print solution
print
print 
print "%50s " % "Optimal cost:", solv.output(NLP_COST)
print "%50s " % "Primal solution:", solv.output(NLP_X_OPT)
print "%50s " % "Dual solution (simple bounds):", solv.output(NLP_LAMBDA_X)
print "%50s " % "Dual solution (nonlinear bounds):", solv.output(NLP_LAMBDA_G)

