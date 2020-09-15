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

  public:

  double tau(double a, double b double c){
    return (double) (a-b)/(2*c);
  }

  double tau(double theta){
    return (double) math::cos(theta)/math::sin(theta);
  }

  
}

void classtuff::Rotate(){

}
void classtuff::Jacobi(){
  //First fill matrix S with
  for (int i = 0; i < c_size; i++){
    for (int j = 0; j < c_size; i++){
      if (i == j){
        S[i][j] == 1;
      }
      else{
        S[i][j] = ;
      }
    }
  }

  int its = 0;




}
