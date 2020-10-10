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

void add(object newplanet){
  total_planets += 1;
  total_mass += newplanet.mass;
  all_planets.push_back(newplanet);
}
