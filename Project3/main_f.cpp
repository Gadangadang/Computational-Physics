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


  int IntegrationPoints = 10000;
  double FinalTime = 200.0;

  //double TimeStep = FinalTime/((double) IntegrationPoints);
  double x[3],v[3];
  double earth_mass = 3.003e-6;
  double sun_mass = 1.0;

  vec pos(3); pos = {1,0,0};
  double r = sqrt( (pos[0]*pos[0]) + (pos[1]*pos[1]) + (pos[2]*pos[2])  );

  double beta = 2;
  int alpha =0;
  cout << "Beta " << beta << endl;

  //object planet1(earth_mass,1.,0.0,0.0,stab_vel[0], stab_vel[1], stab_vel[2]);

  object planet1(earth_mass,1.,0.0,0.0,0,8.88577,0);
  object planet2(sun_mass, 0,0,0,0,0,0);

  solving binary_verlet(5.0);
  binary_verlet.add(planet1); binary_verlet.add(planet2);

  double vesc = sqrt(2*binary_verlet.G/(r));

  cout << "V_esc = " << vesc << endl;
  binary_verlet.VelocityVerlet(Dimension,IntegrationPoints,FinalTime,1,0., beta,alpha);

  for (int r = 0; r < Dimension; r++){
    x[r] = binary_verlet.all_planets[0].position[r];
    v[r] = binary_verlet.all_planets[0].velocity[r];
  }
  //double ***planets;
  //binary_verlet.print_to_file(x,IntegrationPoints);
  return 0;
}
