#include "math.hpp"
#include <iostream>
#include <cmath>


using namespace std;

void calc::Initialize(double x){
  m_x = x;
  m_solv = 0.;
}

void calc::calculate(){
  m_solv = cos(m_x);
}

void calc::Print(){
  cout << "Val is  = " << m_solv << endl;
}
