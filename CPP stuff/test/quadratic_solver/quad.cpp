#include "quad.hpp"
#include <iostream>
#include <cmath>


using namespace std;

void quad::Initialize(double a, double b, double c){
  m_a = a;
  m_b = b;
  m_c = c;
}

void quad::find(){
  m_root1 = (-m_b + sqrt(m_b*m_b - 4*m_a*m_c))/(2*m_a);
  m_root2 = (-m_b - sqrt(m_b*m_b - 4*m_a*m_c))/(2*m_a);
}

void quad::Print(){
  cout << "x1 = " << m_root1 << " and x2 = "<< m_root2 << endl;
}
