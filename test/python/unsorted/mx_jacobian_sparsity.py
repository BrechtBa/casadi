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

x = MX.sym("x",5)
y = MX.sym("y")
x2 = SX.sym("x",5)
y2 = SX.sym("y")

fcn = Function('fcn', [x,y],[4*vertcat((x[2:5],x[0:2])) + y*x])
js = IM.ones(fcn.sparsity_jac())
js.print_dense()

fcn2 = Function('fcn2', [x2,y2],[4*vertcat((x2[2:5],x2[0:2])) + y2*x2])
js2 = IM.ones(fcn2.sparsity_jac())
js2.print_dense()

fcn3 = Function('fcn3', [x,y],[fcn2.newcall(x,y)])
js3 = IM.ones(fcn3.sparsity_jac())
js3.print_dense()
