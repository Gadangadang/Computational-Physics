#include "armadillo"
#include "Black_scholes.hpp"
#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>
#include "time.h"
#include <stdio.h>
#include <tuple>
#include <cmath>
#include <stdlib.h>

// polluting the namespaces
using namespace arma;
using namespace std;

void Black_scholes::Initialize(double T,double X, int N){
  m_matrix = zeros<mat>(N, N);
  m_h = X/((double)N);
  m_dt = T/((double)N);
  m_b = vec(N);
  m_matrix(0,0)=2;m_matrix(0,1)=1;m_matrix(N,N)=2;m_matrix(n-1,n-2) = 1; m_matrix(n-2,n-1) = 1;
  for(int i= 1;i<N-1;i++){
    m_matrix(i,i) = 2;
    m_matrix(i,i-1)=-1;
    m_matrix(i,i+1)=-1;
  }
}
