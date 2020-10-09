#ifndef CLASSTUFF_HPP
#define CLASSTUFF_HPP
#include "armadillo"
#include <tuple>
#include <math.h>

using namespace std;
using namespace arma;

class classtuff {
private:
  vec start_pos;
  vec start_vel;
  double planet_mass;

  int N_size;

public:
  double GMstar = 4*M_PI*M_PI; // AU^3/yr^2
  void initialization(int &N, double &mass, vec &start_velocity, vec &start_position);
  vec find_acc(double x, double y);
  tuple<vec, vec> integrator();

};

#endif