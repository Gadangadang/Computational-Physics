#include "classtuff.hpp"
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

void classtuff::initialization(double &mass, vec &start_velocity, vec &start_position){
    start_pos = start_position;
    start_vel = start_velocity;
    double planet_mass = mass;
}

vec classtuff::find_acc(double x, double y){
  vec acc(2);
  acc(0) = GMstar/x;
  acc(1) = GMstar/y;
  return acc;
}
tuple<vec, vec> classtuff::integrator(int N){
  vec Pos_X(N);
  vec Pos_Y(N);

  Pos_X(0) = start_pos(0);
  Pos_Y(0) = start_pos(1);

  double time = 100.0; //Years
  double h = time/N;
  int t = 0;
  int i = 0;

  while ( t < time ){
    Pos_X(i+1) = 2*Pos_X(i) - Pos_X(i-1) + h*h*find_acc(Pos_X(i), Pos_Y(i))(0);
    Pos_Y(i+1) = 2*Pos_Y(i) - Pos_Y(i-1) + h*h*find_acc(Pos_X(i), Pos_Y(i))(0);
    i = i + 1;
  }
  return {Pos_X, Pos_Y};
}
