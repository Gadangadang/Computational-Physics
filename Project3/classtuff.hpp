#ifndef CLASSTUFF_HPP
#define CLASSTUFF_HPP
#include "armadillo"

using namespace std;
using namespace arma;

class classtuff {
private:
  double GMstar = 4*pi*pi; // AU^3/yr^2

public:
  void initialization(double mass, vec start_velocity, vec start_position, );
  vec find_acc(double x, double y);
  mat integrator(int N, vec start_pos, vec start_vel);


#endif
