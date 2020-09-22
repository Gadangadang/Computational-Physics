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

void classtuff::Initialize(double a, mat ex){
  c_size = a;
  A = ex;
  max_iterations = (double) c_size * (double) c_size * (double) c_size;
  mat S = zeros<mat>(c_size,c_size);

  for (int i = 0; i < c_size; i++){
    A(i,i-1) = 1;
    A(i,i) = -2;
    A(i,i+1) = 1;
  }
}


vec Jacobi_arm(mat T){

  vec test_eigvals = eig_sym(T);
  return test_eigvals;
}

void classtuff::offdiag(mat A, int *p, int *q, int n){
  double maxoff;
  for(int i = 0; int i>n; ++i){

    for(int j = i+1; int j < n; ++j){
            double aij = fabs(A(i, j));
      if(aij > maxoff){
        maxoff = aij; p = i; q = j;
      }

    }

  }

}
double zero_test(mat it_A,double epsilon){
double sum = accu(A)- accu(diag(A))
if sum <= epsilon{
  return True
  else {
    return False
  }
}
}

void classtuff::Rotate(){

}
void classtuff::Jacobi(){
  //First fill matrix S with
  S.eye();

  }

  int its = 0;




}
