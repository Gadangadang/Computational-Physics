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

void Black_scholes::Initialize(double T,double X, int N,string filename,double r, double D, double sigma){
  m_Amtrx = zeros<mat>(N, N);
  m_filename = filename;
  m_u =vec(N);m_h = X/((double)N);m_dt = T/((double)N);m_S =vec(N);
  m_N = N;m_T =T;m_alpha = m_dt/((double)m_h*m_h);
  m_a = (r-D)*2/((double)sigma*sigma);
  m_b = 2*m_a+r;
  m_Amtrx(0,0)=2+2*m_alpha;m_Amtrx(0,1)=-m_alpha;m_Amtrx(N-1,N-1)=2+2*m_alpha;
  m_Amtrx(N-1,N-2) = -m_alpha; m_Amtrx(N-2,N-1) = -m_alpha;
  for(int i= 1;i<N-1;i++){
    m_Amtrx(i,i) = 2+2*m_alpha;
    m_Amtrx(i,i-1)=-m_alpha;
    m_Amtrx(i,i+1)=-m_alpha;
    m_x =
    m_S[i] = E*exp(x_0 +m_h*i);
  }
}
//void Black_scholes::D1d_explicit(){
//  for(int i=1;i<m_N-1;i++){
//    for(int i=1;i<m_N-1;i++)
//    m_u(i) = m_alpha*m_u(i-1)+(1-2*m_alpha) * m_u(i) +m_alpha*m_u(i+1);
//  }
//}
void Black_scholes::calc_utilde(){
  for(int i=1;i<m_N; i++){
    m_utilde(i) = m_alpha*m_uPrev(i-1) + (1.0-2*m_alpha)*m_uPrev(i) + m_alpha*m_uPrev(i+1)
  }
}
void Black_scholes::Crank_Nic(){
  init_print();
  for(int t=0;t<m_T;t+=m_dt){
    calc_utilde();
    vec u_j = solve(m_Amtrx,m_utilde);
    m_uPrev = u_j;
    if(t%100==0){
      vec V = transform_u_V(u_j,t);
      print_vals(V,t);
    }
  }
}
vec Black_scholes::transform_u_V(vec u,double t){
  vec V = vec(m_N);
  for(int i =0;i<m_N;i++){
    V = u_j(i)*exp(-(m_a*m_x(i)+m_b*t));
  }
  return V
}
void Black_scholes::init_print(){
  ofstream ofile;
  ofile.open(m_filename);
  for(int i=0;i<m_N-1;i++){
  ofile << setw(20) << setprecision(8) << m_S(i);
  }
  ofile << setw(20) << setprecision(8) << m_S(m_N-1)<<endl;
  ofile.close();
}
void Black_scholes::print_vals(vec u,double t){
  ofstream ofile;
  ofile.open(m_filename, fstream::app);
  ofile << setw(20) << setprecision(8) << t;
  for(int i=0;i<m_N-1; i++){
    ofile << setw(20) << setprecision(8) << u(i);}
  ofile << setw(20) << setprecision(8) << u(m_N-1)<<endl;
  ofile.close();
}
