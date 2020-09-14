#include "quad.hpp"
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

int main(int argc, char const *argv[]) {

  //Define class object
  classtuff mysolver;
  int size = atof(argv[1]);

  //Define matrix to solve Ax = lambda x
  mat A = zeros<mat>(size,size);
  mat eigvec = zeros<mat>(size,size);

  //Initialize matrices
  mysolver.Initialize(size, A);




  return 0;
}
