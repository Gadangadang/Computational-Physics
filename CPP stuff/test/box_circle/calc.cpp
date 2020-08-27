#include "calc.hpp"
#include <iostream>
#include <cmath>
#include <math.h>


using namespace std;

void calc::Initialize(double a, double b, double c){
  m_a = a;
  m_b = b;
  m_c = c;
}

void calc::find(){
  m_area1 = m_a*m_b;
  m_area2 = M_PI*m_c*m_c;
}

void calc::Print(){
  if(m_area1 < m_area2){
    cout << "False" << endl;
    }
  else{
    cout << "True" << endl;
  }

}
