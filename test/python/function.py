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
import numpy
import unittest
from types import *
from helpers import *

#@run_only(["setjacsparsity"])
class Functiontests(casadiTestCase):

  def test_call_empty(self):
    x = SX.sym("x",2)
    fsx = Function("fsx", [x,[]],[x])
    x = MX.sym("x",2)
    fmx1 = Function("fmx1", [x,MX()],[x])
    fmx2 = Function("fmx2", [x,[]],[x])
    
    for f in [fsx,fmx1,fmx2]:
      f.newcall(0,0)

      X = MX.sym("X",2)
      F = f.newcall(X,MX())
      g = Function("g", [X],[F])

      g.newcall(0)
    
    x = SX.sym("x",2)
    fsx = Function("fsx", [x],[x,[]])
    x = MX.sym("x",2)
    fmx1 = Function("fmx1", [x],[x,MX()])
    fmx2 = Function("fmx2", [x],[x,[]])
    
    for f in [fsx,fmx1,]:
      f.newcall(0)

      X = MX.sym("X",2)
      F = f.newcall(X)
      g = Function("g", [X],F)

      g.newcall(0)
  
  def test_Map(self):
    self.message("Map")
    x = MX.sym("x",2)
    y = MX.sym("y")

    f = Function("f", [x,y],[sin(x) + y])
        
    for mode in ["serial","openmp"]:
      x0 = MX.sym("x0",2)
      y0 = MX.sym("y0")
      x1 = MX.sym("x1",2)
      y1 = MX.sym("y1")

      [[z0],[z1]] = f.map([[x0,y0],[x1,y1]],mode)
      
      p = Function("p", [x0,y0,x1,y1],[z0,z1])
      
      n1 = DM([4,5])
      N1 = 3
      n2 = DM([5,7])
      N2 = 8
      

      out = p.newcall(n1,N1,n2,N2)

      self.checkarray(sin(n1)+N1,out[0],"output")
      self.checkarray(sin(n2)+N2,out[1],"output")
      
  def test_MX_funSeed(self):
    self.message("MX_funSeed")
    x1 = MX.sym("x",2)
    y1 = MX.sym("y")
    x2 = MX.sym("x",2)
    y2 = MX.sym("y")
    p= Function("p", [x1,y1,x2,y2],[sin(x1) + y1,sin(x2) + y2])
    
    n1 = DM([4,5])
    N1 = 3
    n2 = DM([5,7])
    N2 = 8
    
    out = p.newcall(n1,N1,n2,N2)

    self.checkarray(sin(n1)+N1,out[0],"output")
    self.checkarray(sin(n2)+N2,out[1],"output")
                  
  def test_map(self):
    self.message("MX parallel call")
    x = MX.sym("x",2)
    y = MX.sym("y")

    f = Function("f", [x,y],[sin(x) + y])

    #! Evaluate this function ten times in parallel
    x1 = MX.sym("x",2)
    y1 = MX.sym("y")
    x2 = MX.sym("x",2)
    y2 = MX.sym("y")
    [[F1],[F2]] = f.map([[x1,y1],[x2,y2]])
    p = Function("p", [x1,y1,x2,y2],[F1,F2])
    
    n1 = DM([4,5])
    N1 = 3
    n2 = DM([5,7])
    N2 = 8
  
    out = p([n1,N1,n2,N2])

    self.checkarray(sin(n1)+N1,out[0],"output")
    self.checkarray(sin(n2)+N2,out[1],"output")

  def test_issue304(self):
    self.message("regression test for #304") # this code used to segfault
    x = SX.sym("x")

    f = Function("f", [x],[x**2,x**3])

    X = MX.sym("X")

    z=f.newcall(X)

    g = Function("g", [X], z).expand()
  
  def test_jacobian(self):
    x = SX.sym("x",3,1)
    y = SX.sym("y",2,1)

    f = Function("f", [x,y],[x**2,y,x*y[0]])

    g = f.jacobian(0,0)

    self.assertEqual(g.n_in(),f.n_in())
    self.assertEqual(g.n_out(),f.n_out()+1)

  def test_xfunction(self):
    x = SX.sym("x",3,1)
    y = SX.sym("y",2,1)
    
    f = Function("f", [x,y],[x**2,y,x*y[0]])
    
    X = MX.sym("x",3,1)
    Y = MX.sym("y",2,1)
    
    F = Function("F", [X,Y],[X**2,Y,X*Y[0]])
    
    self.checkfunction(f,F,inputs=[[0.1,0.7,1.3],[7.1,2.9]],sens_der=False,evals=False)
    
  
  @memory_heavy()
  def test_jacobians(self):
  
    x = SX.sym("x")
    
    self.assertEqual(jacobian(5,x).nnz(),0)
    
    
    def test(sp):
      x = SX.sym("x",sp.size2())
      sp2 = jacobian(mtimes(DM.ones(sp),x),x).sparsity()
      self.checkarray(sp.row(),sp2.row());
      self.checkarray(sp.colind(),sp2.colind());   

    for i in range(5):
      test(Sparsity.lower(i))
      test(Sparsity.lower(i).T)
      test(Sparsity.dense(i,i))
      test(Sparsity.diag(i))
    
    for i in [63,64,65,127,128,129]:
      d = Sparsity.diag(i)
      test(d)
      
      test(d + Sparsity.rowcol([0],[5],i,i))
      
      b = Sparsity.band(i,-1) + Sparsity.band(i,1)
      test(b + Sparsity.rowcol([0],[5],i,i))
      
    m = IM.ones(Sparsity.diag(129))
    m[:50,0] = 1
    m[60:,0] = 1
    m[6:9,6] = 1
    m[9,9:12] = 1
    
    sp = m[:,:120].sparsity()
    
    test(sp)
    #test(sp.T)
    
    m = IM.ones(Sparsity.diag(64))
    m[:50,0] = 1
    m[60:,0] = 1

    sp = m.T[:40,:].sparsity()
    test(sp)
    test(sp.T)
    
    sp = m[:40,:].sparsity()
    test(sp)
    test(sp.T)
    
    sp = m.T[:20,:].sparsity()
    test(sp)
    test(sp.T)

    sp = m[:20,:].sparsity()
    test(sp)
    test(sp.T)
    
    for i in [63,64,65,127,128,129]:
      test(Sparsity.lower(i))
      test(Sparsity.lower(i).T)
    
    for n in ([63,64,65,127,128,129] if args.run_slow else [63,64,65]):
      for m in ([63,64,65,127,128,129] if args.run_slow else [63,64,65]):
        print (n,m)
        sp = Sparsity.dense(n,m)
        
        test(sp)
        
        random.seed(0)
        
        I = IM.ones(sp)
        for i in range(n):
          for j in range(m):
            if random.random()<0.5:
              I[i,j] = 0
        I = sparsify(I)
        
        sp_holes = I.sparsity()
        
        test(sp_holes)
        
        z = IM(sp_holes.size1(), sp_holes.size2())
        
        R = 5
        v = []
        for r in range(R):
          h = [z]*5
          h[r] = I
          v.append(horzcat(h))
        d = vertcat(v)
        
        test(d.sparsity())
        
  @memory_heavy()
  def test_hessians(self):
    def test(sp):
      x = SX.sym("x",sp.size2())
      self.assertTrue(sp==sp.T)
      f = Function("f", [x],[mtimes([x.T,DM.ones(sp),x])])
      J = f.hessian()
      sp2 = J.sparsity_out(0)
      self.checkarray(sp.row(),sp2.row())
      self.checkarray(sp.colind(),sp2.colind())
      
    A = IM([[1,1,0,0,0,0],[1,1,1,0,1,1],[0,1,1,1,0,0],[0,0,1,1,0,1],[0,1,0,0,1,0],[0,1,0,1,0,1]])
    A = sparsify(A)
    C = A.sparsity()
    
    test(C)
    
    A = IM([[1,0,0,0,0,0],[0,1,1,0,1,1],[0,1,1,1,0,0],[0,0,1,1,0,1],[0,1,0,0,1,0],[0,1,0,1,0,1]])
    A = sparsify(A)
    C = A.sparsity()
    
    test(C)
    
    A = IM([[1,0,0,0,0,0],[0,1,0,0,1,1],[0,0,1,1,0,0],[0,0,1,1,0,1],[0,1,0,0,1,0],[0,1,0,1,0,1]])
    A = sparsify(A)
    C = A.sparsity()
      
    test(C)

    A = IM([[0,0,0,0,0,0],[0,1,0,0,1,1],[0,0,1,1,0,0],[0,0,1,1,0,1],[0,1,0,0,1,0],[0,1,0,1,0,1]])
    A = sparsify(A)
    C = A.sparsity()
      
    test(C)

    A = IM([[0,0,0,0,0,0],[0,1,0,0,1,0],[0,0,1,1,0,0],[0,0,1,1,0,1],[0,1,0,0,1,0],[0,0,0,1,0,1]])
    A = sparsify(A)
    C = A.sparsity()
      
    test(C)
    
    
    for i in [63,64,65,100,127,128,129]:
      d = Sparsity.diag(i)
      test(d)
      
      test(d + Sparsity.rowcol([0],[5],i,i) + Sparsity.rowcol([5],[0],i,i))
      
      b = Sparsity.band(i,-1) + Sparsity.band(i,1)
      test(b)
      test(b + Sparsity.rowcol([0],[5],i,i) + Sparsity.rowcol([5],[0],i,i))
      
      d = Sparsity.dense(i,i)
      test(d)
      
      d = Sparsity.diag(i) + Sparsity.triplet(i,i,[0]*i,range(i))+Sparsity.triplet(i,i,range(i),[0]*i)
      test(d)


      sp = Sparsity.dense(i,i)
        
      random.seed(0)
      
      I = IM.ones(sp)
      for ii in range(i):
        for jj in range(i):
          if random.random()<0.5:
            I[ii,jj] = 0
            I[jj,ii] = 0
      I = sparsify(I)
      
      sp_holes = I.sparsity()
      
      test(sp_holes)
      
      z = IM(sp_holes.size1(), sp_holes.size2())
      
      R = 5
      v = []
      for r in range(R):
        h = [z]*5
        h[r] = I
        v.append(horzcat(h))
      d = vertcat(v)
      
      test(d.sparsity())

  def test_customIO(self):
    
    x = SX.sym("x")
    f = Function('f',[x],[x*x, x],{'output_scheme':["foo","bar"]})
    
    ret = f.newcall(i0=12)

    self.checkarray(DM([144]),ret["foo"])
    self.checkarray(DM([12]),ret["bar"])

    
    with self.assertRaises(Exception):
      f_out["baz"]
      
    ret = f.newcall(i0=SX(12))
    self.checkarray(ret["foo"],DM([144]))
    self.checkarray(ret["bar"],DM([12]))
    with self.assertRaises(Exception):
      self.checkarray(ret["baz"],DM([12]))
              
  def test_setjacsparsity(self):
    x = MX.sym("x",4)
          
    f = Function("f", [x],[x])
    x0 = DM([1,2,3,4])
    J = f.jacobian()
    out,_ = J.newcall(x0)
    
    self.assertEqual(out.nnz(),4)
    
    f = Function("f", [x],[x])
    f.set_jac_sparsity(Sparsity.dense(4,4),0,0,True)
    
    J2 = f.jacobian()
    out2,_ = J2.newcall(x0)
    
    self.assertEqual(out2.nnz(),16)
    self.checkfunction(J,J2,inputs=[x0])
    

  def test_derivative_simplifications(self):
  
    n = 1
    x = SX.sym("x",n)

    M = Function("M", [x],[mtimes((x-DM(range(n))),x.T)])

    P = MX.sym("P",n,n)
    X = MX.sym("X",n)

    M_X= M.newcall(X)

    Pf = Function("P", [X, P], [mtimes(M_X,P)])
    
    P_P = Pf.jacobian(1)
    
    self.assertFalse("derivative" in str(P_P))
      
  def test_map(self):
    a = SX.sym("a",1,2)
    b = SX.sym("b")
    c = sin(a)+b
    d = cos(sumCols(a)-c)
    f = Function("f",[a,b],[c,d])

    random.seed(0)

    random.random(())

    r = [[ DM([1,2]).T , 3],
    [ DM([2,1]).T , 1.7],
    [ DM([3,4.1]).T , 2.7],
    ]

    Fref = blockcat([f.newcall(*e) for e in r])


    F = Function("F",[],[blockcat(f.map(r))])

    self.checkarray(F.call([])[0],Fref)
    
    a = SX.sym("a",1,2)
    c = sin(a)
    d = cos(sumCols(a)-c)
    f = Function("f",[a],[c,d])

    random.seed(0)

    random.random(())

    r = [[ DM([1,2]).T ],
    [ DM([2,1]).T ],
    [ DM([3,4.1]).T],
    ]

    Fref = blockcat([f.call(e) for e in r])


    F = Function("F",[],[blockcat(f.map(r))])

    self.checkarray(F.call([])[0],Fref)

    a = SX.sym("a",1,2)
    b = SX.sym("b")
    c = sin(a)+b
    d = cos(sumCols(a)-c)
    f = Function("f",[a,b],[c])

    random.seed(0)

    random.random(())

    r = [[ DM([1,2]).T , 3],
    [ DM([2,1]).T , 1.7],
    [ DM([3,4.1]).T , 2.7],
    ]

    Fref = blockcat([f.call(e) for e in r])


    F = Function("F",[],[blockcat(f.map(r))])

    self.checkarray(F.call([])[0],Fref)

  def test_issue1464(self):
    n = 6
    x = SX.sym("x",n)
    u = SX.sym("u")


    N = 9

    rk4 = Function("f",[x,u],[x+u])

    for XX,XFunction in [(SX,Function),(MX,Function)]:

      g = []
      g2 = []


      V = XX.sym("V",(N+1)*n+N)
      VX,VU = vertsplit(V,[0,(N+1)*n,(N+1)*n+N])

      VXk = vertsplit(VX,n)
      VUk = vertsplit(VU,1)

      for k in range(N):
          
          xf = rk4.newcall(VXk[k],VUk[k])

          xfp = vertsplit(xf,n/2)
          vp = vertsplit(VXk[k+1],n/2)

          g.append(xfp[0] - vp[0])
          g.append(xfp[1] - vp[1])

          g2.append(xf-VXk[k+1])

      for i in range(2):
        f = XFunction("nlp",[V],[vertcat(g)],{"ad_weight_sp":i})

        assert f.sparsity_jac().nnz()==162

        f2 = XFunction("nlp",[V],[vertcat(g2)],{"ad_weight_sp":i})

        assert f2.sparsity_jac().nnz()==162

  def test_callback(self):
    class mycallback(Callback):
      def __init__(self, name, opts={}):
        Callback.__init__(self)
        self.construct(name, opts)

      def eval(self,argin):
        return [argin[0]**2]

    foo = mycallback("my_f")
    
    x = MX.sym('x')
    y = foo.newcall(x)

    f = Function("f",[x],[y])

    out = f.newcall(5)
    
    self.checkarray(out,25)

  @known_bug()
  def test_callback_errors(self):
    class mycallback(Callback):
      def __init__(self, name, opts={}):
        Callback.__init__(self)
        self.construct(name, opts)
      def eval(self,argin):
        raise Exception("foobar")

    foo = mycallback("my_f")
    
    x = MX.sym('x')
    y = foo([x])

    f = Function("f",[x],y)

    try:
      f([3])
    except Exception as e:
      self.assertTrue("foobar" in str(e))

  @memory_heavy()
  def test_map_node(self):
    x = SX.sym("x")
    y = SX.sym("y",2)
    z = SX.sym("z",2,2)
    v = SX.sym("z",Sparsity.upper(3))

    fun = Function("f",[x,y,z,v],[mtimes(z,y)+x,sin(y*x).T,v/x])

    n = 2

    X = [MX.sym("x") for i in range(n)]
    Y = [MX.sym("y",2) for i in range(n)]
    Z = [MX.sym("z",2,2) for i in range(n)]
    V = [MX.sym("z",Sparsity.upper(3)) for i in range(n)]

    for Z_alt,Z_alt2 in [
          (Z,Z),
          ([Z[0]],[Z[0]]*n),
          ([MX()]*3,[MX()]*3),
        ]:
      print "args", Z_alt

      for parallelization in ["serial","openmp"] if args.run_slow else ["serial"]:
        print parallelization
        res = fun.map(map(horzcat,[X,Y,Z_alt,V]),parallelization)


        F = Function("F",X+Y+Z+V,map(sin,res))

        resref = [[] for i in range(fun.n_out())]
        for r in zip(X,Y,Z_alt2,V):
          for i,e in enumerate(map(sin,fun.call(r))):
            resref[i] = resref[i] + [e]

        Fref = Function("F",X+Y+Z+V,map(horzcat,resref))
        
        np.random.seed(0)
        X_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in X ] 
        Y_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in Y ] 
        Z_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in Z ] 
        V_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in V ] 

        for f in [F, F.expand('expand_'+F.name())]:
          
          self.checkfunction(f,Fref,inputs=X_+Y_+Z_+V_,sparsity_mod=args.run_slow)


  @memory_heavy()
  @slow()
  def test_map_node_old(self):
    x = SX.sym("x")
    y = SX.sym("y",2)
    z = SX.sym("z",2,2)
    v = SX.sym("z",Sparsity.upper(3))

    fun = Function("f",[x,y,z,v],[mtimes(z,y)+x,sin(y*x).T,v/x])

    n = 2

    X = [MX.sym("x") for i in range(n)]
    Y = [MX.sym("y",2) for i in range(n)]
    Z = [MX.sym("z",2,2) for i in range(n)]
    V = [MX.sym("z",Sparsity.upper(3)) for i in range(n)]

    for Z_alt in [Z,[MX()]*3]:

      for parallelization in ["serial","openmp"]:
        res = fun.map(zip(X,Y,Z_alt,V),parallelization)


        flatres = []
        for r in res:
          flatres+= map(sin,r)
        F = Function("F",X+Y+Z+V,flatres)

        flatresref = []
        for r in zip(X,Y,Z_alt,V):
          flatresref+=map(sin,fun(r))

        Fref = Function("F",X+Y+Z+V,flatresref)
        
        np.random.seed(0)
        X_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in X ] 
        Y_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in Y ] 
        Z_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in Z ] 
        V_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in V ] 

        for f in [F, F.expand('expand_'+F.name())]:
          
          self.checkfunction(f,Fref,inputs=X_+Y_+Z_+V_,sparsity_mod=args.run_slow)

  @memory_heavy()
  def test_mapsum(self):
    x = SX.sym("x")
    y = SX.sym("y",2)
    z = SX.sym("z",2,2)
    v = SX.sym("z",Sparsity.upper(3))

    fun = Function("f",[x,y,z,v],[mtimes(z,y)+x,sin(y*x).T,v/x])

    n = 2

    X = [MX.sym("x") for i in range(n)]
    Y = [MX.sym("y",2) for i in range(n)]
    Z = [MX.sym("z",2,2) for i in range(n)]
    V = [MX.sym("z",Sparsity.upper(3)) for i in range(n)]

    zi = 0
    for Z_alt in [Z,[MX()]*3]:
      zi+= 1
      for parallelization in ["serial","openmp"]:
        res = fun.mapsum(map(horzcat,[X,Y,Z_alt,V]),parallelization)


        F = Function("F",X+Y+Z+V,map(sin,res),{"ad_weight": 0})

        resref = [0 for i in range(fun.n_out())]
        for r in zip(X,Y,Z_alt,V):
          for i,e in enumerate(fun.call(r)):
            resref[i] = resref[i] + e

        Fref = Function("F",X+Y+Z+V,map(sin,resref))
        
        np.random.seed(0)
        X_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in X ] 
        Y_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in Y ] 
        Z_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in Z ] 
        V_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in V ] 

        inputs = X_+Y_+Z_+V_
        
        self.check_codegen(F,inputs=inputs)

        for f in [F,toSX_fun(F)]:
          self.checkfunction(f,Fref,inputs=inputs,sparsity_mod=args.run_slow)


  @memory_heavy()
  def test_mapsum2(self):
    x = SX.sym("x")
    y = SX.sym("y",2)
    z = SX.sym("z",2,2)
    v = SX.sym("z",Sparsity.upper(3))

    fun = Function("f",[x,y,z,v],[mtimes(z,y)+x,sin(y*x).T,v/x])

    n = 2

    X = [MX.sym("x") for i in range(n)]
    Y = [MX.sym("y",2) for i in range(n)]
    Z = MX.sym("z",2,2)
    V = MX.sym("z",Sparsity.upper(3))

    for Z_alt in [Z]:

      for parallelization in ["serial","openmp"]:

        F = fun.map("map",n,[True,True,False,False],[False,True,True])

        resref = [0 for i in range(fun.n_out())]
        acc = 0
        bl = []
        cl = []
        for r in zip(X,Y,[Z_alt]*n,[V]*n):
          a,b,c= fun.newcall(*r)
          acc = acc + a
          bl.append(b)
          cl.append(c)

        Fref = Function("F",[horzcat(X),horzcat(Y),Z,V],[acc,horzcat(bl),horzcat(cl)])

        np.random.seed(0)
        X_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in X ] 
        Y_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in Y ] 
        Z_ = DM(Z.sparsity(),np.random.random(Z.nnz()))
        V_ = DM(V.sparsity(),np.random.random(V.nnz()))

        inputs = [horzcat(X_),horzcat(Y_),Z_,V_]
        
        self.check_codegen(F,inputs=inputs)

        for f in [F,toSX_fun(F)]:
          self.checkfunction(f,Fref,inputs=inputs,sparsity_mod=args.run_slow)

  def test_issue1522(self):
    V = MX.sym("X",2)
    P = MX.sym("X",0)

    x =  V[0]
    y =  V[1]

    obj = (x-(x+y))**2

    nlp = Function("nlp", [V, P], [obj, MX()], ['x', 'p'], ['f', 'g'])

    self.assertTrue(nlp.hessian(0,0).sparsity_out(0).is_symmetric())

    V = MX.sym("X",6)

    xs =      [ V[0:2], V[2:4] ]
    travels = [ V[4],   V[5]   ]

    dist = 0

    for j in range(2):
      dist+=sumRows((xs[0]-(xs[j]+travels[j]))**2)

    nlp = Function("nlp", [V, P], [-dist, MX()], ['x', 'p'], ['f', 'g'])

    hs = []
    for n in [nlp, nlp.expand('nlp_expanded')]:
        H = n.derivative(0,1).jacobian(0,2,False,True)

        h = H.newcall(der_x=1,adj0_f=1)[H.name_out(0)]
        hs.append(h)
    self.checkarray(*hs)

  def test_repmatnode(self):
    x = MX.sym("x",2)

    y = sin(repmat(x**2,1,3))

    z = MX.sym("y",2,2)

    F = Function("f",[x,z],[sumCols(sumRows(y))])

    x = SX.sym("x",2)

    y = sin(repmat(x**2,1,3))
    z = SX.sym("y",2,2)

    Fref = Function("f",[x,z],[sumCols(sumRows(y))])
    
    x0 = DM([1,7])
    x1 = DM([[3,0],[2,4]])

    self.check_codegen(F,inputs=[x0,x1])
    self.checkfunction(F,Fref,inputs=[x0,x1])

  def test_repsumnode(self):

    x = MX.sym("x",2)
    z = MX.sym("y",2,2)

    F = Function("f",[x,z],[sin(repsum((x**2).T,1,2)),(cos(x**2)*2*x).T])

    x = SX.sym("x",2)
    z = SX.sym("y",2,2)


    Fref = Function("f",[x,z],[sin(repsum((x**2).T,1,2)),(cos(x**2)*2*x).T])

    x0 = DM([1,7])
    x1 = DM([[3,0],[2,4]])
    
    self.check_codegen(F,inputs=[x0,x1])
    self.checkfunction(F,Fref,inputs=[x0,x1])
    
  def test_unknown_options(self):
    x = SX.sym("x")

    with self.assertRaises(Exception):
      f = SXFunction("f", [x],[x],{"fooo": False})

    with self.assertRaises(Exception):
      f = SXFunction("f", [x],[x],{"ad_weight": "foo"})
      
    if not has_nlpsol("ipopt"):
      return

  @known_bug()
  def test_unknown_options_stringvector(self):
    x = SX.sym("x")
    solver = nlpsol("mysolver", "ipopt", {"x":x,"f":x**2}, {"monitor": ["eval_f"]})
    with self.assertRaises(Exception):
      solver = nlpsol("mysolver", "ipopt", {"x":x,"f":x**2}, {"monitor": ["abc"]})

  @memory_heavy()
  def test_mapaccum(self):
  
    x = SX.sym("x",2)
    y = SX.sym("y")
    z = SX.sym("z",2,2)
    v = SX.sym("v",Sparsity.upper(3))

    fun = Function("f",[x,y,z,v],[mtimes(z,x)+y,sin(y*x).T,v/y])

    n = 2

    X = MX.sym("x",x.sparsity())
    Y = [MX.sym("y",y.sparsity()) for i in range(n)]
    Z = [MX.sym("z",z.sparsity()) for i in range(n)]
    V = [MX.sym("v",v.sparsity()) for i in range(n)]

    np.random.seed(0)
    X_ = DM(x.sparsity(),np.random.random(x.nnz()))
    Y_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in Y ] 
    Z_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in Z ] 
    V_ = [ DM(i.sparsity(),np.random.random(i.nnz())) for i in V ] 

    F = fun.mapaccum("map",n,[True,False,False,False],[0])

    XP = X

    Y0s = []
    Y1s = []
    Xps = []
    for k in range(n):
      XP, Y0,Y1 = fun.newcall(XP,Y[k],Z[k],V[k])
      Y0s.append(Y0)
      Y1s.append(Y1)
      Xps.append(XP)
    Fref = Function("f",[X,horzcat(Y),horzcat(Z),horzcat(V)],[horzcat(Xps),horzcat(Y0s),horzcat(Y1s)])
    inputs = [X_,horzcat(Y_),horzcat(Z_),horzcat(V_)]

    for f in [F,toSX_fun(F)]:

      self.checkfunction(f,Fref,inputs=inputs)
      self.check_codegen(f,inputs=inputs)

    fun = Function("f",[y,x,z,v],[mtimes(z,x)+y+c.trace(v)**2,sin(y*x).T,v/y])

    F = fun.mapaccum("map",n,[False,True,False,True],[0,2])

    XP = X
    VP = V[0]

    Y0s = []
    Y1s = []
    Xps = []
    Vps = []
    for k in range(n):
      XP, Y0, VP = fun.newcall(Y[k],XP,Z[k],VP)
      Y0s.append(Y0)
      Xps.append(XP)
      Vps.append(VP)

    Fref = Function("f",[horzcat(Y),X,horzcat(Z),V[0]],[horzcat(Xps),horzcat(Y0s),horzcat(Vps)])
    inputs = [horzcat(Y_),X_,horzcat(Z_),V_[0]]
    
    for f in [F,toSX_fun(F)]:
      self.checkfunction(f,Fref,inputs=inputs)
      self.check_codegen(f,inputs=inputs)

  # @requiresPlugin(Compiler,"clang")
  # def test_jitfunction_clang(self):
  #   x = MX.sym("x")
  #   F = Function("f",[x],[x**2],{'jit':True})

  #   out = F([5])
  #   self.checkarray(out[0],25)

  # @requiresPlugin(Compiler,"clang")
  # def test_clang_c(self):
  #   compiler = Compiler('../data/helloworld.c', 'clang')
  #   f = external("helloworld_c", compiler)
  #   [v] = f([])
  #   self.checkarray(2.37683, v, digits=4)

  # @requiresPlugin(Compiler,"clang")
  # def test_clang_cxx(self):
  #   compiler = Compiler('../data/helloworld.cxx', 'clang')
  #   f = external("helloworld_cxx", compiler)
  #   [v] = f([])
  #   self.checkarray(2.37683, v, digits=4)

  # @requiresPlugin(Compiler,"shell")
  # def test_shell_c(self):
  #   compiler = Compiler('../data/helloworld.c', 'shell')
  #   f = external("helloworld_c", compiler)
  #   [v] = f([])
  #   self.checkarray(2.37683, v, digits=4)

  # @requiresPlugin(Compiler,"shell")
  # def test_shell_cxx(self):
  #   opts = {'compiler':'g++'}
  #   compiler = Compiler('../data/helloworld.cxx', 'shell', opts)
  #   f = external("helloworld_cxx", compiler)
  #   [v] = f([])
  #   self.checkarray(2.37683, v, digits=4)
    
  @memory_heavy()
  def test_kernel_sum(self):
    n = 20
    m = 40
 
    try:
      xx, yy = np.meshgrid(range(n), range(m),indexing="ij")
    except:
      yy, xx = np.meshgrid(range(m), range(n))

    z = np.cos(xx/4.0+yy/3.0)

    p = SX.sym("p",2)
    x = SX.sym("x",2)

    v = SX.sym("v")

    r = sqrt(sumRows((p-x)**2))

    f = Function("f",[p,v,x],[v**2*exp(-r**2)/pi])

    F = f.kernel_sum("test",(n,m),4,1,{"ad_weight": 1})

    x0 = DM([n/2,m/2])

    Fref = f.map("f",n*m,[True,True,False],[False])
    
    print Fref.newcall(horzcat([vec(xx),vec(yy)]).T,vec(z),x0)
    print F.newcall(z,x0)
    
    zs = MX.sym("z", z.shape)
    xs = MX.sym("x",2)
    Fref = Function("Fref",[zs,xs],[Fref.newcall(horzcat([vec(xx),vec(yy)]).T,vec(zs),xs)])
    
    self.checkfunction(F,Fref,inputs=[z,x0],digits=5,allow_nondiff=True,evals=False)
    self.check_codegen(F,inputs=[z,x0])

if __name__ == '__main__':
    unittest.main()

