#include "solving.h"
#include "object.h"
#include <iostream>
#include <cmath>
#include "time.h"
#include "armadillo"

solving::solving(){
    total_planets = 0;
    radius = 100;
    total_mass = 0;
    G = 4*M_PI*M_PI;
    totalKinetic = 0;
    totalPotential = 0;
}

solving::solving(double radi){
    total_planets = 0;
    radius = radi;
    total_mass = 0;
    G = 4*M_PI*M_PI;
    totalKinetic = 0;
    totalPotential = 0;
}

vec solving::stable_orbiter(vec pos){
  vec hyp = -pos;
  vec tanvec(2);
  tanvec[0] = -hyp[1]/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1]);
  tanvec[1] = hyp[0]/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1]);
  double v_stable = sqrt(GMstar/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1]));
  vec stable_orbit(2);
  stable_orbit[0] = v_stable*tanvec[0]; stable_orbit[1] = v_stable*tanvec[1];
  return stable_orbit;

}

void add(object newplanet){
  total_planets += 1;
  total_mass += newplanet.mass;
  all_planets.push_back(newplanet);
}

mat setup_Matrix(int height, int width){
  mat matric(height,width,fill::zeros);
  return matric
}

void VelocityVerlet(int dimension, int integration_points, double final_time, int print_number, double epsilon){

}
