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

vec stable_circle_orbiter(vec pos);

int main(int argc, char const *argv[]) {

  int Dimension = 3;


  int IntegrationPoints = 50000;
  double FinalTime = 100;

  //double TimeStep = FinalTime/((double) IntegrationPoints);
  double sun_mass = 1.0;
  double merc_mass = 1.651e-7;
  int fixed =1;
  int alpha =1;
  double beta = 2;
  cout << "Beta " << beta << endl;
  //When initializing the planets; make sure to initialize the sun last, and the planet furthest away from the sun second last.
  //Mercury
  object planetmercury(merc_mass,0.3075, 0,0 ,0,12.44,0);
  //Sun
  object sun(sun_mass, -6.107925513172998*1e-03,6.420679726598624*1e-03,8.893727401374147*1e-05,-7.280593132276730*1e-06*365,-5.090234498858063*1e-06*365,2.181619304215098*1e-07*365);

  solving binary_verlet(5.0);
  binary_verlet.add(planetmercury); binary_verlet.add(sun);
  binary_verlet.VelocityVerlet(Dimension,IntegrationPoints,FinalTime,1,0., beta, fixed,alpha);

  return 0;
}
