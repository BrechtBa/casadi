#
#     This file is part of CasADi.
#
#     CasADi -- A symbolic framework for dynamic optimization.
#     Copyright (C) 2010-2014 Joel Andersson, Joris Gillis, Moritz Diehl,
#                             K.U. Leuven. All rights reserved.
#     Copyright (C) 2011-2014 Greg Horn
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
import casadi as c
from numpy import *
import unittest
from types import *
from helpers import *

qcqpsolvers = []
if SdpSolver.hasPlugin("dsdp"):
  qcqpsolvers.append(("socp",{"socp_solver": "sdp", "socp_solver_options": {"sdp_solver": "dsdp"} },{},False))

if SdpSolver.hasPlugin("dsdp"):
  qcqpsolvers.append(("socp.sdp.dsdp",{},{},False))

if SocpSolver.hasPlugin("mosek"):
  qcqpsolvers.append(("socp",{"socp_solver": "mosek", "socp_solver_options": {"MSK_DPAR_INTPNT_CO_TOL_REL_GAP": 1e-10} },{"less_digits": 3},False))

if SocpSolver.hasPlugin("ecos"):
  qcqpsolvers.append(("socp",{"socp_solver": "ecos", "socp_solver_options": {"abstol": 1e-10,"reltol":1e-10} },{"less_digits": 1},False))

class QcqpSolverTests(casadiTestCase):

  def testboundsviol(self):
    H = 1e-6*DMatrix([[1,0],[0,1]])
    G = DMatrix([2,1])
    A = DMatrix(0,2)
    P = 2*DMatrix([[1,0],[0,2]])
    Q = DMatrix([2,3])
    R = DMatrix([-7])
    LBX = DMatrix([ -inf,-3 ])
    UBX = DMatrix([ inf, -inf ])
    
    for qcqpsolver, qcqp_options, aux_options, re_init in qcqpsolvers:
      solver = QcqpSolver("mysolver",qcqpsolver,{'a':A.sparsity(),'p':P.sparsity(),'h':H.sparsity()},qcqp_options)

      solver.setInput(H,"h")
      solver.setInput(G,"g")
      solver.setInput(A,"a")
      solver.setInput(P,"p")
      solver.setInput(Q,"q")
      solver.setInput(R,"r")
      solver.setInput(LBX,"lbx")
      solver.setInput(UBX,"ubx")

      with self.assertRaises(Exception):
        solver.evaluate()
      
  def test_bounds(self):
    #  min  1/2 x' H x + 2 x + y
    #   x,y
    #
    #  s.t.  x^2 + 2y^2 + 2*x + 3*y - 7 <= 0
    H = 1e-6*DMatrix([[1,0],[0,1]])
    G = DMatrix([2,1])
    A = DMatrix(0,2)
    P = 2*DMatrix([[1,0],[0,2]])
    Q = DMatrix([2,3])
    R = DMatrix([-7])
    LBX = DMatrix([ -inf, -inf ])
    UBX = DMatrix([ inf, inf ])
    
    for qcqpsolver, qcqp_options, aux_options, re_init in qcqpsolvers:
      self.message("qcqpsolver: " + str(qcqpsolver))

      solver = QcqpSolver("mysolver",qcqpsolver,{'a':A.sparsity(),'p':P.sparsity(),'h':H.sparsity()},qcqp_options)

      try:
        less_digits=aux_options["less_digits"]
      except:
        less_digits=0

      solver.setInput(H,"h")
      solver.setInput(G,"g")
      solver.setInput(A,"a")
      solver.setInput(P,"p")
      solver.setInput(Q,"q")
      solver.setInput(R,"r")
      solver.setInput(LBX,"lbx")
      solver.setInput(UBX,"ubx")

      solver.evaluate()
      
      #socp = solver.getSolver()
        
      self.checkarray(solver.getOutput(),DMatrix([-(sqrt(73)+3)/3,-(sqrt(73)+9)/12]),str(qcqpsolver),digits=max(1,5-less_digits))
      self.checkarray(solver.getOutput("lam_x"),DMatrix([0,0]),str(qcqpsolver),digits=max(1,5-less_digits))

      self.checkarray(solver.getOutput("lam_a"),DMatrix([]),str(qcqpsolver),digits=max(1,5-less_digits))
      
      self.checkarray(solver.getOutput("cost"),mul(G.T,solver.getOutput()),str(qcqpsolver),digits=max(1,4-less_digits))

  def test_qp(self):
    #  min  1/2 x' H x + 2 x + y
    #   x,y
    #
    H = DMatrix([[1,0],[0,1]])
    G = DMatrix([2,1])
    A = DMatrix(0,2)
    P = DMatrix(2,0)
    Q = DMatrix(0,1)
    R = DMatrix(0,1)
    LBX = DMatrix([ -inf, -inf ])
    UBX = DMatrix([ inf, inf ])
    
    for qcqpsolver, qcqp_options, aux_options, re_init in qcqpsolvers:
      self.message("qcqpsolver: " + str(qcqpsolver))

      solver = QcqpSolver("mysolver",qcqpsolver,{'a':A.sparsity(),'p':P.sparsity(),'h':H.sparsity()},qcqp_options)

      try:
        less_digits=aux_options["less_digits"]
      except:
        less_digits=0

      solver.setInput(H,"h")
      solver.setInput(G,"g")
      solver.setInput(A,"a")
      solver.setInput(P,"p")
      solver.setInput(Q,"q")
      solver.setInput(R,"r")
      solver.setInput(LBX,"lbx")
      solver.setInput(UBX,"ubx")

      solver.evaluate()
      
      #socp = solver.getSolver()
        
      self.checkarray(solver.getOutput(),DMatrix([-2,-1]),str(qcqpsolver),digits=max(1,5-less_digits))
      self.checkarray(solver.getOutput("lam_x"),DMatrix([0,0]),str(qcqpsolver),digits=max(1,5-less_digits))

      self.checkarray(solver.getOutput("lam_a"),DMatrix([]),str(qcqpsolver),digits=max(1,5-less_digits))
      
      self.checkarray(solver.getOutput("cost"),-2.5,str(qcqpsolver),digits=max(1,4-less_digits))
  
      
if __name__ == '__main__':
    unittest.main()
