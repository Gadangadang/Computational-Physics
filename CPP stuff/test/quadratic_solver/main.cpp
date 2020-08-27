#include "quad.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;


int main(int argc, char const *argv[]) {

  quad mysolver;

  double a = atof(argv[1]);
  double b = atof(argv[2]);
  double c = atof(argv[3]);

  mysolver.Initialize(a,b,c);
  mysolver.find();
  mysolver.Print();

  return 0;
}
