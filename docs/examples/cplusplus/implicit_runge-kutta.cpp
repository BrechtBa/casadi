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


/**
   Demonstration on how to construct a fixed-step implicit Runge-Kutta integrator
   @author: Joel Andersson, K.U. Leuven 2013
*/

#include <casadi/casadi.hpp>
#include <casadi/core/misc/integration_tools.hpp>
#include <iomanip>

using namespace casadi;
using namespace std;

int main(){

  // End time
  double tf = 10.0;

  // Dimensions
  int nx = 3;
  int np = 1;

  // Declare variables
  SX x  = SX::sym("x",nx);  // state
  SX p  = SX::sym("u",np);  // control

  // ODE right hand side function
  SX ode = vertcat((1 - x[1]*x[1])*x[0] - x[1] + p,
                   x[0],
                   x[0]*x[0] + x[1]*x[1] + p*p);
  SXFunction f("f", daeIn("x",x,"p",p),daeOut("ode",ode));

  // Number of finite elements
  int n = 100;

  // Size of the finite elements
  double h = tf/n;

  // Choose collocation points
  vector<double> tau_root = collocationPoints(4,"legendre");

  // Degree of interpolating polynomial
  int d = tau_root.size()-1;

  // Coefficients of the collocation equation
  vector<vector<double> > C(d+1,vector<double>(d+1,0));

  // Coefficients of the continuity equation
  vector<double> D(d+1,0);

  // For all collocation points
  for(int j=0; j<d+1; ++j){

    // Construct Lagrange polynomials to get the polynomial basis at the collocation point
    Polynomial p = 1;
    for(int r=0; r<d+1; ++r){
      if(r!=j){
        p *= Polynomial(-tau_root[r],1)/(tau_root[j]-tau_root[r]);
      }
    }
    
    // Evaluate the polynomial at the final time to get the coefficients of the continuity equation
    D[j] = p(1.0);
    
    // Evaluate the time derivative of the polynomial at all collocation points to get the coefficients of the continuity equation
    Polynomial dp = p.derivative();
    for(int r=0; r<d+1; ++r){
      C[j][r] = dp(tau_root[r]);
    }
  }

  // Total number of variables for one finite element
  MX X0 = MX::sym("X0",nx);
  MX P  = MX::sym("P",np);
  MX V = MX::sym("V",d*nx);
  
  // Get the state at each collocation point
  vector<MX> X(1,X0);
  for(int r=0; r<d; ++r){
    X.push_back(V[Slice(r*nx,(r+1)*nx)]);
  }
  
  // Get the collocation quations (that define V)
  MX V_eq;
  for(int j=1; j<d+1; ++j){
    // Expression for the state derivative at the collocation point
    MX xp_j = 0;
    for(int r=0; r<d+1; ++r){
      xp_j += C[r][j]*X[r];
    }
    
    // Append collocation equations
    MX f_j = f(make_map("x",X[j],"p",P)).at("ode");
    V_eq.append(h*f_j - xp_j);
  }

  // Root-finding function, implicitly defines V as a function of X0 and P
  MXFunction vfcn("vfcn", {V, X0, P}, {V_eq});
  
  // Convert to SXFunction to decrease overhead
  SXFunction vfcn_sx(vfcn);

  // Create a implicit function instance to solve the system of equations
  ImplicitFunction ifcn("ifcn", "newton", vfcn_sx, make_dict("linear_solver", "csparse"));
  vector<MX> ifcn_arg = {MX(), X0, P};
  V = ifcn(ifcn_arg).front();
  X.resize(1);
  for(int r=0; r<d; ++r){
    X.push_back(V[Slice(r*nx, (r+1)*nx)]);
  }

  // Get an expression for the state at the end of the finite element
  MX XF = 0;
  for(int r=0; r<d+1; ++r){
    XF += D[r]*X[r];
  }
  
  // Get the discrete time dynamics
  MXFunction F("F", {X0, P}, {XF});

  // Do this iteratively for all finite elements
  MX Xk = X0;
  for(int i=0; i<n; ++i){
    Xk = F(vector<MX>{Xk, P}).at(0);
  }

  // Fixed-step integrator
  MXFunction irk_integrator("irk_integrator",
                            integratorIn("x0", X0, "p", P),
                            integratorOut("xf", Xk));

  // Create a convensional integrator for reference
  Integrator ref_integrator("ref_integrator", "cvodes", f, make_dict("tf", tf));

  // Test values
  vector<double> x0_val = {0, 1, 0};
  double p_val = 0.2;

  // Make sure that both integrators give consistent results
  for(int integ=0; integ<2; ++integ){
    Function integrator = integ==0 ? Function(irk_integrator) : Function(ref_integrator);
    cout << "-------" << endl;
    cout << "Testing " << integrator.getOption("name") << endl;
    cout << "-------" << endl;

    // Generate a new function that calculates two forward directions and one adjoint direction
    Function dintegrator = integrator.derivative(2,1);

    // Arguments for evaluation
    map<string, DMatrix> arg, res;
    arg["der_x0"] = x0_val;
    arg["der_p"] = p_val;

    // Forward sensitivity analysis, first direction: seed p
    arg["fwd0_x0"] = 0;
    arg["fwd0_p"] = 1;
  
    // Forward sensitivity analysis, second direction: seed x0[0]
    arg["fwd1_x0"] = vector<double>{1, 0, 0};
    arg["fwd1_p"] = 0;

    // Adjoint sensitivity analysis, seed xf[2]
    arg["adj0_xf"] = vector<double>{0, 0, 1};

    // Integrate
    res = dintegrator(arg);

    // Get the nondifferentiated results
    cout << setw(15) << "xf = " << res.at("der_xf") << endl;

    // Get the forward sensitivities
    cout << setw(15) << "d(xf)/d(p) = " <<  res.at("fwd0_xf") << endl;
    cout << setw(15) << "d(xf)/d(x0[0]) = " << res.at("fwd1_xf") << endl;

    // Get the adjoint sensitivities
    cout << setw(15) << "d(xf[2])/d(x0) = " << res.at("adj0_x0") << endl;
    cout << setw(15) << "d(xf[2])/d(p) = " << res.at("adj0_p") << endl;
  }
  return 0;
}

