#include "math.hpp"
#include <iostream>
#include <cmath>

using namespace std;



int main(int argc, char const *argv[]) {
  /* code */
  //Solver
  calc my_solver;

  //Parameters
  double x = 3.14;


  my_solver.Initialize(x);
  my_solver.calculate();
  my_solver.Print();

  return 0;
}
