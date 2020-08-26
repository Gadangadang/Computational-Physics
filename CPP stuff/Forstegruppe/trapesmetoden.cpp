#include "trapesmetoden.hpp"
#include <iostream>
#include <cmath>


using namespace std;

void Trapezoidal::Initialize(double a, double b, int N){
  m_a = a;
  m_b = b;
  m_I = 0.;
  m_N = N;
  m_Stepsize = (b-a)*(1./N);

}

void Trapezoidal::Integrate(double f(double x)){
  double x = 0;
  //Set start value for integral
  m_I += 0.5*(f(m_a)+f(m_b));

  //Integrate over function
  for (int i = 0; i< m_N; i++){
    x = m_a + i*m_Stepsize;
    m_I += f(x);

  }
  //*h
  m_I *= m_Stepsize;

}

void Trapezoidal::Print(){
  cout << "Integral = " << m_I << endl;
}
