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

  mat S = zeros<mat>(c_size,c_size);

  for (int i = 0; i < c_size; i++){
    A(i,i-1) = 1;
    A(i,i) = -2;
    A(i,i+1) = 1;
  }
}


public:

double tau(double a, double b double c){
  return (double) (a-b)/(2*c);
}

double tau(double theta){
  return (double) math::cos(theta)/math::sin(theta);
}




mat Jacobi_arm(mat T){
  vec eigvals = eig_sym(T);
  return eigvals;
}

void classtuff::Rotate(){

}
void classtuff::Jacobi(){
  //First fill matrix S with
  S.eye();

  }

  int its = 0;




}
