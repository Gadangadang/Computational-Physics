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

  double beta = 2;
  cout << "Beta " << beta << endl;
  //When initializing the planets; make sure to initialize the sun last, and the planet furthest away from the sun second last.
  //Mercury
  object planetmercury(merc_mass,2.643154303593134e-01, -3.157121726001744e-01,-5.104028200574216e-02 ,1.594913945525348e-02*365,1.943209256008390e-02*365,1.248175570907458e-04*365);
  //Sun
  object sun(sun_mass, -6.107925513172998*1e-03,6.420679726598624*1e-03,8.893727401374147*1e-05,-7.280593132276730*1e-06*365,-5.090234498858063*1e-06*365,2.181619304215098*1e-07*365);

  solving binary_verlet(5.0);
  binary_verlet.add(planetmercury); binary_verlet.add(sun);
  binary_verlet.VelocityVerlet(Dimension,IntegrationPoints,FinalTime,1,0., beta, fixed);

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
