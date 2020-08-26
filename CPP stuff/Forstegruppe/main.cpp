#include "trapesmetoden.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double f(double x);

int main(int argc, char const *argv[]) {
  /* code */
  //Solver
  Trapezoidal my_solver;

  //Parameters
  double a = 0;
  double b = 1.57;
  int N = 1000;

  my_solver.Initialize(a,b,N);
  my_solver.Integrate(f);
  my_solver.Print();

  return 0;
}

double f(double x){
  return sin(x);
}
