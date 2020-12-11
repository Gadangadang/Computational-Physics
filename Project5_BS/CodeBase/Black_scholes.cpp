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


void Black_scholes::Initialize(double T,double L, int N,string filename,
                                double r, double D, double sigma, double E){
  m_filename = filename;
  m_S =vec(N);
  m_utilde=vec(N);
  m_uPrev = vec(N);
  m_x = vec(N);
  m_h = 2*L/((double)N+2);
  m_dt = T/((double)N);
  m_N = N;
  m_T =T;
  m_sigma2 =sigma*sigma/((double)2);
  m_alpha = m_dt/((double)m_h*m_h);
  m_a = (r-D)/((double)sigma*sigma)-1/((double)2);
  m_b = r + m_a*(r-D-0.5*sigma*sigma) - m_a*m_a*sigma*sigma;
  m_E = E;
  m_D = D;
  m_r = r;

  m_x(0)=-L;
  m_x(m_N-1)=L;
  m_utilde(0)=m_uPrev(0)=0.;
  m_S(m_N-1)=E*exp(L);
  m_S(0) = E*exp(-L);
  m_utilde(m_N-1)=m_uPrev(m_N-1)=(m_S(m_N-1)-m_E)*exp(m_a*m_x(m_N-1));

  for(int i= 1;i<m_N-1;i++){
    m_x(i) = -L + (double)i*m_h;
    m_S(i) = E*exp(m_x(i));
    m_uPrev(i)= exp(m_x(i)*m_a)*E*std::max(0.,exp(m_x(i))-1.);
  }
}

void Black_scholes::calc_utilde(double t){
  for(int i=1;i<m_N-1; i++){
    m_utilde(i) = m_sigma2*m_alpha*m_uPrev(i-1) + (2.0-m_sigma2*2.*m_alpha)*m_uPrev(i) +m_sigma2*m_alpha*m_uPrev(i+1);
  }
}
void Black_scholes::Crank_Nic(){
  init_print();
  double t = 0;
  for(int y = 1; y < m_N+1; y++){
    t += m_dt;
    m_utilde(m_N-1)=(m_S(m_N-1)*exp(-t*m_D)-m_E*exp(-m_r*t))*exp(m_a*m_x(m_N-1)+m_b*t);
    calc_utilde(t);
    vec u = Tridiag();
    m_uPrev = u;
    if(y%(m_N/10)==0){
      vec V = transform_u_V(u,t);
      print_vals(V,t);
    }
    cout << "\r";
    cout << "Calculated:"<<100*t/m_T <<"%"<<flush;
  }
  cout << " "<<endl;
}

vec Black_scholes::Tridiag(){
  vec d(m_N-1); d.fill(2.+2.*m_alpha*m_sigma2);
  vec b(m_N-2); b.fill(-m_alpha*m_sigma2);
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
  b(m_N-3) /=d(m_N-3);
  u(m_N-2) /= d(m_N-3);
  d(m_N-3) = 1.;
  //Backward eliminate
  for(int i = m_N-1; i > 1; i--){
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
  vec V_0 = transform_u_V(m_uPrev,0);
  print_vals(V_0,0);
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
