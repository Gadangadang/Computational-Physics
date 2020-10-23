#include "object.hpp"
#include "solving.hpp"
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
#include <typeinfo>
using namespace std;
using namespace arma;

int main(int argc, char const *argv[]) {

  int Dimension = 3;


  int IntegrationPoints = 15000;
  double FinalTime = 150.0;

  double earth_mass = 3.003e-6;
  double sun_mass = 1.0;

  vec pos(3); pos = {1,0,0};

  double beta = 2;
  int alpha =0;
  cout << "Beta " << beta << endl;

  //object planet1(earth_mass,1.,0.0,0.0,stab_vel[0], stab_vel[1], stab_vel[2]);
  object planet1(earth_mass,1.,0.0,0.0,0,6.3,0);
  object planet2(sun_mass, 0,0,0,0,0,0);

  solving binary_forward;
  binary_forward.add(planet1); binary_forward.add(planet2);
  binary_forward.Forward_Euler(Dimension,IntegrationPoints,FinalTime,0., beta,alpha);
  binary_forward.VelocityVerlet(Dimension,IntegrationPoints,FinalTime,1,0., beta,0,alpha);
  return 0;
}
