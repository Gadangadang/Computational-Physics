#include "armadillo"
#include "Black_scholes.hpp"
#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "time.h"
#include <stdio.h>
#include <tuple>
#include <cmath>
#include <stdlib.h>
#include <algorithm>

// polluting the namespaces
using namespace arma;
using namespace std;


void Black_scholes::Initialize(double T,double X, int N,string filename,
                                double r, double D, double sigma, double E){
  m_Amtrx = zeros<mat>(N, N);
  m_filename = filename;
  m_S =vec(N);
  m_utilde=vec(N);
  m_uPrev = vec(N);
  m_h = X/((double)N+2);
  m_dt = T/((double)N);
  m_N = N;
  m_T =T;
  m_alpha = m_dt/((double)m_h*m_h);
  m_a = (r-D)/((double)sigma*sigma) -1/((double)2);
  //m_b = 2*m_a+r;
  m_b = (r+D)/((double)2) +sigma*sigma/((double)8) + (r-D)*(r-D)/((double)2*sigma*sigma);
  m_x = vec(m_N);
  m_sigma2 =sigma*sigma/((double)2);
  m_E = E;
  m_D = D;
  m_r = r;
  double x_0 = -1;

  m_Amtrx(0,0)=m_Amtrx(m_N-1,m_N-1)=2+2*m_alpha;
  m_Amtrx(m_N-1,m_N-2) = m_Amtrx(0,1)=m_Amtrx(m_N-2,m_N-1) = -m_alpha;

  m_x(0)=-1; m_x(m_N-1)=3.;
  m_utilde(0)=m_uPrev(0)=0.;

  m_S(m_N-1)=E*exp(3.); m_S(0) = E*exp(-1.);
  m_utilde(m_N-1)=m_uPrev(m_N-1)=(m_S(m_N-1)-m_E)*exp(m_a*m_x(m_N-1));
  cout<<m_S(m_N-1)<<endl;
  for(int i= 1;i<m_N-1;i++){
    m_Amtrx(i,i) = 2+2*m_alpha;
    m_Amtrx(i,i-1)=-m_alpha;
    m_Amtrx(i,i+1)=-m_alpha;
    m_x(i) = x_0 + i*m_h;
    m_S(i) = E*exp(m_x(i));
    m_uPrev(i)= exp(m_x(i)*m_a)*E*std::max(0.,exp(m_x(i))-1.);
  }
}

//void Black_scholes::D1d_explicit(){
//  for(int i=1;i<m_N-1;i++){
//    for(int i=1;i<m_N-1;i++)
//    m_u(i) = m_alpha*m_u(i-1)+(1-2*m_alpha) * m_u(i) +m_alpha*m_u(i+1);
//  }
//}
void Black_scholes::calc_utilde(double t){
  for(int i=1;i<m_N-1; i++){
    m_utilde(i) = m_sigma2*m_alpha*m_uPrev(i-1) + (2.0-m_sigma2*2.*m_alpha)*m_uPrev(i) +m_sigma2*m_alpha*m_uPrev(i+1);
  }
}
void Black_scholes::Crank_Nic(){
  init_print();
  double t = 0;
  vec V_0 = transform_u_V(m_uPrev,t);
  print_vals(V_0,t);
  for(int y = 0; y < m_N; y++){
    t += m_dt;

    calc_utilde(t);
    vec u = Tridiag();
    u(m_N-1)=(m_S(m_N-1)*exp(-t*m_D)-m_E*exp(-m_r*t))*exp(m_a*m_x(m_N-1)+m_b*t);
    u(0)=0;
    m_uPrev = u;
    if(y%(m_N/10)==0 && y>0){
      vec V = transform_u_V(u,t);
      print_vals(V,t);
    }

    cout << "\r";
    cout << "Calculated:"<<100*t/m_T <<"%"<<flush;
  }

  cout << "\r";
  cout << "Calculated:"<<100*t/m_T <<"%"<<flush;
  cout << " "<<endl;
}

vec Black_scholes::Tridiag(){

  vec d(m_N-2); d.fill(2.+2.*m_alpha*m_sigma2);
  vec b(m_N-3); b.fill(-m_alpha*m_sigma2);
  vec u = m_utilde;
  //Forward eliminate:
  for(int i = 1; i < m_N-2; i++){
    //Normalize row

    b(i-1) /= d(i-1);
    u(i) /= d(i-1);
    d(i-1) = 1.;
    //Eliminate
    u(i+1) += u(i)*m_alpha*m_sigma2;
    d(i) += b(i-1)*m_alpha*m_sigma2;
  }

  u(m_N-2) /= d(m_N-3);
  d(m_N-3) = 1.;

  //Backward eliminate
  for(int i = m_N-2; i > 1; i--){

    u(i-1) -= u(i)*b(i-2);
  }
  return u;
}


vec Black_scholes::transform_u_V(vec u,double t){
  vec V = vec(m_N);
  for(int i =0;i<m_N;i++){
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
