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
 *  Example program demonstrating the usage of C-code generated from CasADi
 *  Generated code is encapsulated in self-contained code with the entry points
 *  defined below. 
 *  Note that other usage, e.g. accessing the internal data structures in the 
 *  generated files is not recommended and subject to change.
 *
 *  We show how the generated code can be used from C (or C++), without requiring
 *  any CasADi classes as well as how to use it from C++ using CasADi's ExternalFunction.
 *
 *  Joel Andersson, 2013-2015
 */

#include <stdio.h>
#include <dlfcn.h>

// Usage from C
int usage_c(){
  printf("---\n");
  printf("Usage from C.\n");
  printf("\n");

  /* Signature of the entry points */
  typedef int (*initPtr)(int *f_type, int *n_in, int *n_out, int *sz_arg, int* sz_res);
  typedef int (*sparsityPtr)(int n_in, int *n_col, int *n_row, int **colind, int **row);
  typedef int (*workPtr)(int *sz_iw, int *sz_w);
  typedef int (*evalPtr)(const double** arg, double** res, int* iw, double* w);

  /* Handle to the dll */
  void* handle;

  /* Load the dll */
  handle = dlopen("./f.so", RTLD_LAZY);  
  if(handle==0){
    printf("Cannot open f.so, error %s\n", dlerror()); 
    return 1;
  }

  /* Reset error */
  dlerror(); 

  /* Function for initialization and getting the number of inputs and outputs */
  initPtr init = (initPtr)dlsym(handle, "f_init");
  if(dlerror()){
    printf("Failed to retrieve \"init\" function.\n");
    return 1;
  }

  /* Function for getting the sparsities of the inputs and outptus */
  sparsityPtr sparsity = (sparsityPtr)dlsym(handle, "f_sparsity");
  if(dlerror()){
    printf("Failed to retrieve \"sparsity\" function.\n");
    return 1;
  }

  /* Function for getting the size of the required work vectors */
  workPtr work = (workPtr)dlsym(handle, "f_work");
  if(dlerror()){
    printf("Failed to retrieve \"work\" function.\n");
    return 1;
  }

  /* Function for numerical evaluation */
  evalPtr eval = (evalPtr)dlsym(handle, "f");
  if(dlerror()){
    printf("Failed to retrieve \"f\" function.\n");
    return 1;
  }

  /* Initialize and get the number of inputs and outputs */
  int f_type, n_in, n_out, sz_arg, sz_res;
  int flag = init(&f_type, &n_in, &n_out, &sz_arg, &sz_res);
  if (flag) {
    printf("Initialization failed.\n");
    return 1;
  }
  if (f_type!=1) {
    printf("Function type not supported.\n");
    return 1;
  }
  printf("n_in = %d, n_out = %d, sz_arg = %d, sz_out = %d\n", n_in, n_out, sz_arg, sz_res);

  /* Get sparsities */
  int ind;
  for(ind=0; ind<n_in + n_out; ++ind){
    if(ind<n_in){
      printf("Input %d\n",ind);
    } else {
      printf("Output %d\n",ind-n_in);
    }

    int nrow,ncol;
    int *colind, *row;
    sparsity(ind,&nrow,&ncol,&colind,&row);

    printf("  Dimension: %d-by-%d\n",nrow,ncol);
    printf("  Nonzeros: {");
    int rr,cc,el;
    for(cc=0; cc<ncol; ++cc){ /* loop over rows */
      for(el=colind[cc]; el<colind[cc+1]; ++el){ /* loop over nonzeros */
        /* Separate the entries */
        if(el!=0) printf(", ");

        /* Get the column */
        rr = row[el]; 
        
        /* Print the nonzero */
        printf("{%d,%d}",rr,cc);
      }
    }

    printf("}\n\n");
  }

  /* Work vector size */
  int sz_iw, sz_w;
  work(&sz_iw, &sz_w);

  /* Allocate input/output buffers and work vectors*/
  const double *arg[sz_arg];
  double *res[sz_res];
  int iw[sz_iw];
  double w[sz_w];

  /* Function input and output */
  const double x_val[] = {1,2,3,4};
  const double y_val = 5;
  double res0;
  double res1[4];

  /* Evaluate the function */
  arg[0] = x_val;
  arg[1] = &y_val;
  res[0] = &res0;
  res[1] = res1;
  eval(arg, res, iw, w);

  /* Print result of evaluation */
  printf("result (0): %g\n",res0);
  printf("result (1): [%g,%g;%g,%g]\n",res1[0],res1[1],res1[2],res1[3]);
  
  /* Free the handle */
  dlclose(handle);

  return 0;
}


// C++ (and CasADi) from here on
#include <casadi/casadi.hpp>
using namespace casadi;
using namespace std;

void usage_cplusplus(){
  cout << "---" << endl;
  cout << "Usage from C++" << endl;
  cout << endl;

  // Use CasADi's "ExternalFunction" to load the compiled function
  ExternalFunction f("f");

  // Use like any other CasADi function
  vector<double> x = {1, 2, 3, 4};
  vector<DMatrix> arg = {reshape(DMatrix(x), 2, 2), 5};
  vector<DMatrix> res = f(arg);

  cout << "result (0): " << res.at(0) << endl;
  cout << "result (1): " << res.at(1) << endl;
}

int main(){
    
  // Variables
  SX x = SX::sym("x", 2, 2);
  SX y = SX::sym("y");

  // Simple function
  SXFunction f("f", {x, y}, {sqrt(y)-1, sin(x)-y});

  // Generate C-code
  f.generate("f");

  // Compile the C-code to a shared library
  string compile_command = "gcc -fPIC -shared -O3 f.c -o f.so";
  int flag = system(compile_command.c_str());
  casadi_assert_message(flag==0, "Compilation failed");

  // Usage from C
  flag = usage_c();
  casadi_assert_message(flag==0, "Example failed");

  // Usage from C++
  usage_cplusplus();

  return 0;
}
