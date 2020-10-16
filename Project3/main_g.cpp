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


  int IntegrationPoints = 10000;
  double FinalTime = 5.0;

  //double TimeStep = FinalTime/((double) IntegrationPoints);
  double x[3],v[3];
  double earth_mass = 3.003e-6;
  double sun_mass = 1.0;
  double jup_mass = 0.0009543;

  vec pos(3); pos = {1,0,0};
  vec pos_jup(3); pos = {5.2,0,0};
  vec stab_vel = stable_circle_orbiter(pos);
  vec stab_vel_jup = stable_circle_orbiter(pos_jup);

  double beta = 2;
  cout << "Beta " << beta << endl;

  object planet1(earth_mass,1.,0.0,0.0,stab_vel[0], stab_vel[1], stab_vel[2]);
  //object planet1(earth_mass,1.,0.0,0.0,0,5,0);
  object planet2(jup_mass,5.2,0.0,0.0,stab_vel_jup[0], stab_vel_jup[1], stab_vel_jup[2]);
  object planet3(sun_mass, 0,0,0,0,0,0);

  solving binary_verlet(5.0);
  binary_verlet.add(planet1); binary_verlet.add(planet2);binary_verlet.add(planet3);
  binary_verlet.VelocityVerlet(Dimension,IntegrationPoints,FinalTime,1,0., beta);

  for (int r = 0; r < Dimension; r++){
    x[r] = binary_verlet.all_planets[0].position[r];
    v[r] = binary_verlet.all_planets[0].velocity[r];
  }
  //double ***planets;
  //binary_verlet.print_to_file(x,IntegrationPoints);
  return 0;
}

vec stable_circle_orbiter(vec pos){
  double GMstar = 4*M_PI*M_PI; // AU^3/yr^2
  vec hyp = -pos;
  vec tanvec(3);
  tanvec[0] = -hyp[1]/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1] + hyp[2]*hyp[2]);
  tanvec[1] = hyp[0]/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1] + hyp[2]*hyp[2]);
  tanvec[2] = hyp[2]/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1] + hyp[2]*hyp[2]);
  double v_stable = sqrt(GMstar/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1] + hyp[2]*hyp[2]));
  vec stable_orbit(3);
  stable_orbit[0] = v_stable*tanvec[0]; stable_orbit[1] = v_stable*tanvec[1];
  stable_orbit[2] = v_stable*tanvec[2];
  for (int i = 0; i<3; i++){
    if (isnan(stable_orbit[i]) == true){
      stable_orbit[i] = 0;
    }
  }

  return stable_orbit;
}
