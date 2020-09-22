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

mat classtuff::Initialize(double a, mat ex, mat R){
  c_size = a;
  A = ex;
  maxiter = (double) c_size * (double) c_size * (double) c_size;
  S = zeros<mat>(c_size,c_size);

  A(0,0) = -2; A(0,1) = 1;
  for (int i = 1; i < c_size-1; i++){
    A(i,i-1) = 1;
    A(i,i) = -2;
    A(i,i+1) = 1;
  }
  A(c_size-1,c_size-1) = -2;
  A(c_size-1,c_size-2) = 1;
  A(c_size-2,c_size-1) = 1;

  return A;
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
      t = (double) 1/(tau + sqrt(1 + tau*tau));
    }
    else{
      t = (double) -1/(-tau + sqrt(1 + tau*tau));
    }
    c = (double) 1/(sqrt(1 + t*t));
    s = (double) c*t;
  }else{
    c = 1.0;
    s = 0.0;
  }
  // Det under er kopiert fra foiler
  double a_kk, a_ll, a_ik, a_il, r_ik, r_il;
  a_kk = A(p,p);
  a_ll = A(q,q);
  A(p,p) = c*c*a_kk - 2.0*c*s*A(p,q) + s*s*a_ll;
  A(q,q) = s*s*a_kk + 2.0*c*s*A(p,q) + c*c*a_ll;
  A(p,q) = 0.0;  // hard-coding non-diagonal elements by hand
  A(q,p) = 0.0;  // same here
  S(p,p) = c;
  S(q,q) = c;
  S(p,q) = s;
  S(q,p) = -s;
  for ( int i = 0; i < n; i++ ) {
    if ( i != p && i != q ) {
      a_ik = A(i,p);
      a_il = A(i,q);
      A(i,p) = c*a_ik - s*a_il;
      A(p,i) = A(i,p);
      A(i,q) = c*a_il + s*a_ik;
      A(q,i) = A(i,q);
    }
//  And finally the new eigenvectors
    r_ik = S(i,p);
    r_il = S(i,q);
    S(i,p) = c*r_ik - s*r_il;
    S(i,q) = c*r_il + s*r_ik;
    cout << S << endl;
  }
  return;
}


void classtuff::Jacobi(mat A, double eps){
  double nde_m;
  int iter, n;
  iter = 0;
  nde_m = 1;
  n = c_size;
  while( fabs(nde_m) > eps && iter <= maxiter){
    offdiag(A,&p, &q, n);
    Rotate(A, S, p, q, n);
    nde_m = A(p,q);
    iter ++;
  }
  }
