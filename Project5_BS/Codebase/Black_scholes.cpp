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

void Black_scholes::Initialize(double T,double X, int N,string filename,
                                double r, double D, double sigma, double E){
  m_Amtrx = zeros<mat>(N, N);
  m_filename = filename;
  m_S =vec(N);m_utilde=vec(N);m_uPrev = vec(N);
  m_h = X/((double)N);m_dt = T/((double)N);
  m_N = N;m_T =T;m_alpha = m_dt/((double)m_h*m_h);
  m_a = (r-D)*2/((double)sigma*sigma);
  m_b = 2*m_a+r;
  m_x = vec(m_N);
  double x_0 = -X/((double)2);
  m_Amtrx(0,0)=2+2*m_alpha;m_Amtrx(0,1)=-m_alpha;m_Amtrx(m_N-1,m_N-1)=2+2*m_alpha;
  m_Amtrx(m_N-1,m_N-2) = -m_alpha; m_Amtrx(m_N-2,m_N-1) = -m_alpha;
  m_utilde(0)=m_uPrev(0)=0;
  m_utilde(m_N-1)=m_uPrev(m_N-1) =m_S(m_N-1)=E*exp(-x_0); 
  for(int i= 1;i<m_N-1;i++){
    m_Amtrx(i,i) = 2+2*m_alpha;
    m_Amtrx(i,i-1)=-m_alpha;
    m_Amtrx(i,i+1)=-m_alpha;
    m_x(i) = x_0 + i*m_h;
    m_S(i) = E*exp(m_x(i));
    double st = fmod(exp(m_x(i)),1.);
    m_uPrev(i)= exp(m_x(i)*m_a)*(exp(m_x(i))-1)*st;
  }
}
//void Black_scholes::D1d_explicit(){
//  for(int i=1;i<m_N-1;i++){
//    for(int i=1;i<m_N-1;i++)
//    m_u(i) = m_alpha*m_u(i-1)+(1-2*m_alpha) * m_u(i) +m_alpha*m_u(i+1);
//  }
//}
void Black_scholes::calc_utilde(){
  for(int i=1;i<m_N-1; i++){
    m_utilde(i) = m_alpha*m_uPrev(i-1) + (1.0-2*m_alpha)*m_uPrev(i) + m_alpha*m_uPrev(i+1);
  }
}
void Black_scholes::Crank_Nic(){
  init_print();
  double t = 0;
  for(int y = 0; y < m_N; y++){
    t += m_dt;
    calc_utilde();
    cout << "\r";
    cout << "Calculated:"<<100*t/m_T <<"%"<<flush;
    vec u_j = solve(m_Amtrx,m_utilde);
    m_uPrev = u_j;
    if(y%(m_N/10)==0){
      vec V = transform_u_V(u_j,t);
      print_vals(V,t);
    }
  }
  vec V = transform_u_V(m_uPrev,t);
  print_vals(V,t);
  cout << " "<<endl;

}
vec Black_scholes::transform_u_V(vec u,double t){
  vec V = vec(m_N);
  for(int i =1;i<m_N-1;i++){
    V(i) = u(i)*exp(-(m_a*m_x(i)+m_b*t));
  }
  return V;
}
void Black_scholes::init_print(){
  ofstream ofile;
  ofile.open(m_filename);
  for(int i=0;i<m_N-1;i++){
  ofile << setw(20) << setprecision(8) << m_S(i) << " ";
  }
  ofile << setw(20) << setprecision(8) << m_S(m_N-1)<<endl;
  ofile.close();
}
void Black_scholes::print_vals(vec u,double t){
  ofstream ofile;
  ofile.open(m_filename, fstream::app);
  ofile << setw(20) << setprecision(8) << t << " ";
  for(int i=0;i<m_N-1; i++){
    ofile << setw(20) << setprecision(8) << u(i) << " ";
  }
  ofile << setw(20) << setprecision(8) << u(m_N-1)<<endl;
  ofile.close();
}
