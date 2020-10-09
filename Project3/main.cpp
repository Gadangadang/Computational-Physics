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
  pos = pos/2;

  vec stable_orbit = mysolver.stable_orbiter(pos);

  vec vel(2); vel(0) = stable_orbit[0]; vel(1) = stable_orbit[1];

  int N = 1.0e6;

  mysolver.initialization(N, earth_mass, vel, pos);
  auto[posx, posy] = mysolver.integrator();
  for(int k = 0; k<N; k++){
    ofile << setprecision(15) << posx(k) << " " <<posy(k)<< endl;
  }
  //vec posx(N); vec posy(N);
  ofile.close();


  return 0;
}
