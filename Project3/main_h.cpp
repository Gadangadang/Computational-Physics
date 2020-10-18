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
  double FinalTime = 10;

  //double TimeStep = FinalTime/((double) IntegrationPoints);
  double earth_mass = 3.003e-6;
  double sun_mass = 1.0;
  double jup_mass = 0.0009543;
  double mar_mass = 3.213e-7;
  double sat_mass = 0.0002857;
  int fixed =1;

  double beta = 2;
  cout << "Beta " << beta << endl;
  //Earth

  object planet1(earth_mass,9.128884513088843*1e-01,3.928032801600736*1e-01,6.577938183713410*1e-05,-6.957269992142644*1e-03*365, 1.579734315560513*1e-02*365, -2.582593092148153*1e-07*365);
  //Jupiter
  object planet2(jup_mass,2.556653950007264,-4.428596022378350,-3.882840438937561*1e-02,6.442741439253338*1e-03*365, 4.130146620372741*1e-03*365, -1.612738541610256*1e-04*365);
  //Sun
  object planet3(sun_mass, -6.107925513172998*1e-03,6.420679726598624*1e-03,8.893727401374147*1e-05,-7.280593132276730*1e-06*365,-5.090234498858063*1e-06*365,2.181619304215098*1e-07*365);
  //Mars
  object planet4(mar_mass,1.308532937474490E+00,5.379930853282286E-01,-2.102141505220228E-02,-4.717434819666467E-03*365,1.416299295671162E-02*365,4.126758221879923E-04*365);
  //Saturn
  object planet5(sat_mass,5.144031493282123E+00,-8.563703043404734E+00,-5.588847142609978E-02,4.471296615234172E-03*365,2.858910024157302E-03*365,-2.280276562541721E-04*365);
  solving binary_verlet(5.0);
  binary_verlet.add(planet1); binary_verlet.add(planet2);binary_verlet.add(planet3); binary_verlet.add(planet4);binary_verlet.add(planet5);
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
