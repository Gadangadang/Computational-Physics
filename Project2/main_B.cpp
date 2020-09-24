#include "classtuff.hpp"
#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include "armadillo"
#include "time.h"
#include <stdio.h>

using namespace std;
using namespace arma;
double V(double x){return 0;}
int main(int argc, char const *argv[]) {

  //Define class object
  classtuff mysolver;

  //int size = pow(10,atof(argv[1]));
  int c_size = 3;
  //Define matrix to solve Ax = lambda x
  double a = 0;
  double b = 1;
  //Initialize matrices
  mat A = mysolver.Initialize(a,  b,  V,  c_size);
  vec test_eigvals = mysolver.Jacobi_arm(A);
  mat qen = mysolver.Jacobi(A,1e-16, c_size);
  cout << sort(qen.diag()) << endl;
  cout << sort(test_eigvals) << endl;


  return 0;
}
