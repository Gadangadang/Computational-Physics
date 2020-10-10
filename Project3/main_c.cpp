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

using namespace std;
using namespace arma;

vec stable_orbiter(vec pos);

int main(int argc, char const *argv[]) {

  int Dimension = 3;


  int IntegrationPoints = 10000;
  double FinalTime = 50.;

  //double TimeStep = FinalTime/((double) IntegrationPoints);
  vec x(3),v(3);  // positions and velocities

  double earth_mass = 3.003e-6;
  double sun_mass = 1.0;

  vec pos(3); pos = {1,0,0};
  vec stab_vel =stable_orbiter(pos);

  object planet1(earth_mass, 1,0,0, stab_vel[0],stab_vel[1], stab_vel[2]);
  object planet2(sun_mass, 0,0,0,0,0,0);

  solving binary_verlet(5.0);
  binary_verlet.add(planet1); binary_verlet.add(planet2);

  for (int r = 0; r < Dimension; r++){
    x[r] = binary_verlet.all_planets[0].position[r];
    v[r] = binary_verlet.all_planets[0].velocity[r];
  }


  return 0;
}

vec stable_orbiter(vec pos){
  double GMstar = 4*M_PI*M_PI; // AU^3/yr^2
  vec hyp = -pos;
  vec tanvec(3);
  tanvec[0] = -hyp[1]/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1]);
  tanvec[1] = hyp[0]/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1]);
  tanvec[3] = 0/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1]);
  double v_stable = sqrt(GMstar/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1] + hyp[2]*hyp[2]));
  vec stable_orbit(3);
  stable_orbit[0] = v_stable*tanvec[0]; stable_orbit[1] = v_stable*tanvec[1];
  stable_orbit[2] = v_stable*tanvec[2];
  return stable_orbit;

}
