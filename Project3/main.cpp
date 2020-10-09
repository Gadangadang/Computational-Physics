#include "classtuff.hpp"
#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include "armadillo"
#include "time.h"
#include <stdio.h>
#include <tuple>
#include <math.h>

using namespace std;
using namespace arma;



int main(int argc, char const *argv[]) {
  ofstream ofile;
  string outfilename;
  outfilename = "values.txt";
  ofile.open(outfilename);
  //Define class object
  classtuff mysolver;

  double earth_mass = 3.003e-6;
  vec pos(2); pos(0) = 1; pos(1) = 0;
  vec vel(2); vel(0) = 0; vel(1) = 1;

  int N = 100000;

  mysolver.initialization(N, earth_mass, vel, pos);

  //vec posx(N); vec posy(N);
  auto[posx, posy] = mysolver.integrator();

  cout << posx << " " << posy << endl;

  return 0;
}
