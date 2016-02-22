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

socpsolvers = []
if SdpSolver.hasPlugin("dsdp"):
  socpsolvers.append(("sdp",{"sdp_solver": "dsdp" ,"verbose": True, "sdp_solver_options": {"verbose":True}},{},False))

if SdpSolver.hasPlugin("dsdp"):
  socpsolvers.append(("sdp.dsdp",{ "sdp_solver_options": {"verbose":True}},{},False))

if SocpSolver.hasPlugin("mosek"):
  socpsolvers.append(("mosek",{ "MSK_DPAR_INTPNT_CO_TOL_REL_GAP":1e-10 },{"less_digits": 1},False))

if SocpSolver.hasPlugin("ecos"):
  socpsolvers.append(("ecos",{"abstol":1e-10,"reltol":1e-10},{"less_digits": 1},False))

print(socpsolvers)
  
class SocpSolverTests(casadiTestCase):

  def test_simple(self):
    #  min  2 x + y
    #
    #    ||  x-5 , y-7 ||_2 <= 4
    #
    #
    c = DMatrix([2,1])
    G = sparsify(DMatrix([[1,0],[0,1]])).T
    H = DMatrix([-5,-7])
    E = sparsify(DMatrix([0,0]))
    F = DMatrix([4])

    A = DMatrix(0,2)
    LBA = DMatrix()
    UBA = DMatrix()
    LBX = DMatrix([ 0 ]*2)
    UBX = DMatrix([ 100 ]*2)
    
    for socpsolver, socp_options, aux_options, re_init in socpsolvers:
      self.message("socpsolver: " + str(socpsolver))

      allopts = dict(socp_options)
      allopts["ni"] = [2]
      solver = SocpSolver("mysolver",socpsolver,{'g':G.sparsity(),'e':E.sparsity(),'a':A.sparsity()},allopts)

      try:
        less_digits=aux_options["less_digits"]
      except:
        less_digits=0

      solver.setInput(c,"c")
      solver.setInput(A,"a")
      solver.setInput(G,"g")
      solver.setInput(H,"h")
      solver.setInput(E,"e")
      solver.setInput(F,"f")
      solver.setInput(LBX,"lbx")
      solver.setInput(UBX,"ubx")
      solver.setInput(LBA,"lba")
      solver.setInput(UBA,"uba")

      solver.evaluate()

      self.checkarray(solver.getOutput(),DMatrix([5-8/sqrt(5),7-4/sqrt(5)]),str(socpsolver),digits=max(1,5-less_digits))
      self.checkarray(solver.getOutput("lam_x"),DMatrix([0,0]),str(socpsolver),digits=max(1,5-less_digits))
      self.assertAlmostEqual(solver.getOutput("cost")[0],10-16/sqrt(5)+7-4/sqrt(5),max(1,5-less_digits),str(socpsolver))
      
  def testboundsviol(self):

    a = 1.3
    
    c = DMatrix([2,1])
    G = sparsify(DMatrix([[1,0],[0,1]])).T
    H = DMatrix([0,0])
    E = sparsify(DMatrix([a,0]))
    F = DMatrix([4])

    A = DMatrix(0,2)
    LBA = DMatrix()
    UBA = DMatrix()
    
    for socpsolver, socp_options, aux_options, re_init in socpsolvers:
      self.message("socpsolver: " + str(socpsolver))

      allopts = dict(socp_options)
      allopts["ni"] = [2]
      solver = SocpSolver("mysolver",socpsolver,{"g": G.sparsity(),"e":E.sparsity(),"a":A.sparsity()},allopts)

      solver.setInput(c,"c")
      solver.setInput(A,"a")
      solver.setInput(G,"g")
      solver.setInput(H,"h")
      solver.setInput(E,"e")
      solver.setInput(F,"f")
      
      solver.setInput([0,0],"lbx")
      solver.setInput([0,-3],"ubx")

      with self.assertRaises(Exception):
        solver.evaluate()
      
  def test_simple2(self):
    #  min  2 x + y
    #
    #    ||  x , y ||_2 <= ax+4
    #
    #
    
    a = 1.3
    
    c = DMatrix([2,1])
    G = sparsify(DMatrix([[1,0],[0,1]])).T
    H = DMatrix([0,0])
    E = sparsify(DMatrix([a,0]))
    F = DMatrix([4])

    A = DMatrix(0,2)
    LBA = DMatrix()
    UBA = DMatrix()
    
    for socpsolver, socp_options, aux_options, re_init in socpsolvers:
      self.message("socpsolver: " + str(socpsolver))

      allopts = dict(socp_options)
      allopts["ni"] = [2]
      solver = SocpSolver("mysolver",socpsolver,{'g':G.sparsity(),'e':E.sparsity(),'a':A.sparsity()},allopts)

      try:
        less_digits=aux_options["less_digits"]
      except:
        less_digits=0

      solver.setInput(c,"c")
      solver.setInput(A,"a")
      solver.setInput(G,"g")
      solver.setInput(H,"h")
      solver.setInput(E,"e")
      solver.setInput(F,"f")

      solver.evaluate()
      
      # solution: intersection of 2*x-4*y-(2*a*(a*x+4))=0,x^2+y^2=(4+a*x)^2

      xs = -(8*sqrt(5-a**2)+4*a**3-20*a)/(a**4-6*a**2+5)
      ys = 4*sqrt(5-a**2)/(a**2-5)
      self.checkarray(solver.getOutput(),DMatrix([xs,ys]),str(socpsolver),digits=max(1,5-less_digits))
      self.checkarray(solver.getOutput("lam_x"),DMatrix([0,0]),str(socpsolver),digits=max(1,5-less_digits))
      self.assertAlmostEqual(solver.getOutput("cost")[0],2*xs+ys,max(1,5-less_digits),str(socpsolver))
            
  def test_multi(self):
    #  min  2 x + y
    #
    #    ||  x-5 , y-7 ||_2 <= 4
    #    ||  x/6 , y/5 ||_2 <= 1
    #
    #  solution is in cornerpoint of intersection
    c = DMatrix([2,1])
    G = sparsify(DMatrix([[1,0],[0,1],[1.0/6,0],[0,1.0/5]])).T
    H = DMatrix([-5,-7,0,0])
    E = sparsify(DMatrix([[0,0],[0,0]]))
    F = DMatrix([4,1])

    A = DMatrix(0,2)
    LBA = DMatrix()
    UBA = DMatrix()
    LBX = DMatrix([ 0 ]*2)
    UBX = DMatrix([ 100 ]*2)
    
    for socpsolver, socp_options, aux_options, re_init in socpsolvers:
      self.message("socpsolver: " + str(socpsolver))

      allopts = dict(socp_options)
      allopts["ni"] = [2,2]
      solver = SocpSolver("mysolver",socpsolver,{'g':G.sparsity(),'e':E.sparsity(),'a':A.sparsity()},allopts)

      try:
        less_digits=aux_options["less_digits"]
      except:
        less_digits=0

      solver.setInput(c,"c")
      solver.setInput(A,"a")
      solver.setInput(G,"g")
      solver.setInput(H,"h")
      solver.setInput(E,"e")
      solver.setInput(F,"f")
      solver.setInput(LBX,"lbx")
      solver.setInput(UBX,"ubx")
      solver.setInput(LBA,"lba")
      solver.setInput(UBA,"uba")

      solver.evaluate()

      self.checkarray(solver.getOutput(),DMatrix([1.655450403084473,4.805919456574478]),str(socpsolver),digits=max(1,5-less_digits))
      self.checkarray(solver.getOutput("lam_x"),DMatrix([0,0]),str(socpsolver),digits=max(1,5-less_digits))

  def test_all(self):
    #  min  2 x + y
    #   x,y
    #      
    #
    c = DMatrix([-2., 1., 5.])
    G = DMatrix([[-13,3,5],[-12,12,-6],[-3,6,2],[1,9,2],[-1,-19,3]]).T
    H = DMatrix([-3,-2,0,3,-42])
    E = DMatrix([[-12,-6,5],[-3,6,-10]]).T
    F = DMatrix([-12,27])
    A = DMatrix(0,3)
    LBA = DMatrix()
    UBA = DMatrix()
    LBX = DMatrix([ -inf ]*3)
    UBX = DMatrix([ inf ]*3)
    
    for socpsolver, socp_options, aux_options, re_init in socpsolvers:
      self.message("socpsolver: " + str(socpsolver))

      allopts = dict(socp_options)
      allopts["ni"] = [2,3]
      solver = SocpSolver("mysolver",socpsolver,{'g':G.sparsity(),'e':E.sparsity(),'a':A.sparsity()},allopts)

      try:
        less_digits=aux_options["less_digits"]
      except:
        less_digits=0

      solver.setInput(c,"c")
      solver.setInput(A,"a")
      solver.setInput(G,"g")
      solver.setInput(H,"h")
      solver.setInput(E,"e")
      solver.setInput(F,"f")
      solver.setInput(LBX,"lbx")
      solver.setInput(UBX,"ubx")
      solver.setInput(LBA,"lba")
      solver.setInput(UBA,"uba")

      solver.evaluate()

      # checked with http://abel.ee.ucla.edu/cvxopt/userguide/coneprog.html
      self.checkarray(solver.getOutput(),DMatrix([-5.0147928622,-5.766930599,-8.52180472]),str(socpsolver),digits=max(1,5-less_digits))

if __name__ == '__main__':
    unittest.main()
