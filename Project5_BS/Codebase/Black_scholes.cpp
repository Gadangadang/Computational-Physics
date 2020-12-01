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
  m_Amtrx = zeros<mat>(N, N);
  m_u = zeros<mat>(N, N);
  m_h = X/((double)N);
  m_dt = T/((double)N);
  m_V = vec(N);
  m_N = N;
  m_alpha = m_dt/((double)m_h*m_h);
  //m_Amtrx(0,0)=2;m_Amtrx(0,1)=1;m_Amtrx(N-1,N-1)=2;m_Amtrx(N-1,N-2) = 1; m_Amtrx(N-2,N-1) = 1;
  //for(int i= 1;i<N-1;i++){
    //m_Amtrx(i,i) = 1-m_alpha;
    //m_Amtrx(i,i-1)=m_alpha;
    //m_Amtrx(i,i+1)=m_alpha;
  //}
}
void Black_scholes::D1d_explicit(){
  for(int i=1;i<m_N-1;i++){
    for(int i=1;i<m_N-1;i++)
    m_u(i) = m_alpha*m_u(i-1)+(1-2*m_alpha) * m_u(i) +m_alpha*m_u(i+1);
  }
}
