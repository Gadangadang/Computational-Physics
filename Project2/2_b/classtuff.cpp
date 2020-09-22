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


vec classtuff::Jacobi_arm(mat T){

  vec test_eigvals = eig_sym(T);
  return test_eigvals;
}

void classtuff::offdiag(mat A, int *p, int *q, int n){
  double maxoff;
  for(int i = 0; i<n; ++i){

    for(int j = i+1;  j < n; ++j){
            double aij = fabs(A(i, j));
      if(aij > maxoff){
        maxoff = aij; p = &i; q = &j;
      }

    }

  }

}


void classtuff::Rotate(mat A, mat S, int p, int q, int n){
  /*
  Where A is input, S is the solution matrix, p,q is row column from 
  offdiag() function. Rotates the A matrix around the biggest off-diagonal element and 
  deposits eigenvalues into the S matrix.  
  */

  double s, c;
  if( A(p,q) != 0.0 ){
    double t, tau;
    tau = (double) (A( p, p ) - A( q, q )) / A( p, q );

    if( tau >= 0){
      t = (double) 1/(tau + arma::sqrt(1 + tau*tau));
    }
    else{
      t = (double) -1/(-tau + arma::sqrt(1 + tau*tau));
    }
    c = (double) 1/(arma::sqrt(1 + t*t));
    s = (double) c*t;
  }else{
    c = 1.0;
    s = 0.0;
  }

  

}
void classtuff::Jacobi(){
  //First fill matrix S with
  S.eye();

  }
