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
  double FinalTime = .5;

  //double TimeStep = FinalTime/((double) IntegrationPoints);
  double earth_mass = 3.003e-6;
  double sun_mass = 1.0;
  double jup_mass = 0.0009543;
  int fixed =1;
  vec vel(3);vel={-6.957269992142644*1e-03, 1.579734315560513*1e-02, -2.582593092148153*1e-07};
  vec vel2(3);vel2={6.442741439253338*1e-03, 4.130146620372741*1e-03, -1.612738541610256*1e-04};
  vec vel3(3);vel3 = {-7.280593132276730*1e-06,-5.090234498858063*1e-06,2.181619304215098*1e-07};
  //vec vels(3);vels = (-vel2*jup_mass-vel*earth_mass)/sun_mass;
  double beta = 2;
  cout << "Beta " << beta << endl;
  //Earth
  object planet1(earth_mass,9.128884513088843*1e-01,3.928032801600736*1e-01,6.577938183713410*1e-05,-6.957269992142644*1e-03, 1.579734315560513*1e-02, -2.582593092148153*1e-07);
  //Jupiter
  object planet2(jup_mass,2.556653950007264,-4.428596022378350,-3.882840438937561*1e-02,6.442741439253338*1e-03, 4.130146620372741*1e-03, -1.612738541610256*1e-04);
  //Sun
  object planet3(sun_mass, -6.107925513172998*1e-03,6.420679726598624*1e-03,8.893727401374147*1e-05,-7.280593132276730*1e-06,-5.090234498858063*1e-06,2.181619304215098*1e-07);
  //object planet3(sun_mass, -6.107925513172998*1e-03,6.420679726598624*1e-03,8.893727401374147*1e-05,vels[0],vels[1],vels[2]);
  solving binary_verlet(5.0);
  binary_verlet.add(planet1); binary_verlet.add(planet2);binary_verlet.add(planet3);
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
