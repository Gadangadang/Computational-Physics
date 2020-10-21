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

void classtuff::initialization(int &N, double &mass ,vec &start_velocity, vec &start_position){
    N_size = N;
    start_pos = start_position;
    start_vel = start_velocity;
}

vec classtuff::stable_orbiter(vec pos){
  vec hyp = -pos;
  vec tanvec(2);
  tanvec[0] = -hyp[1]/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1]);
  tanvec[1] = hyp[0]/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1]);
  double v_stable = sqrt(GMstar/sqrt(hyp[0]*hyp[0] + hyp[1]*hyp[1]));
  vec stable_orbit(2);
  stable_orbit[0] = v_stable*tanvec[0]; stable_orbit[1] = v_stable*tanvec[1];
  return stable_orbit;

}

vec classtuff::find_acc(double x, double y){
  vec acc(2);
  double r = sqrt(x*x + y*y);
  acc[0] = -GMstar*x/(r*r*r);
  acc[1] = -GMstar*y/(r*r*r);
  return acc;
}
tuple<vec, vec> classtuff::integrator(){

  vec Pos_X(N_size+1);
  vec Pos_Y(N_size+1);

  Pos_X[0] = start_pos[0];
  Pos_Y[0] = start_pos[1];


  double time = 10.0; //Years
  double h = time/(N_size+1);

  int i = 0;

  vec vel_x(N_size+1); vel_x[0] = start_vel[0];
  vec vel_y(N_size+1); vel_y[0] = start_vel[1];

  while ( i < N_size ){
    Pos_X[i+1] = Pos_X[i] + h*vel_x[i] + h*h/2*find_acc(Pos_X[i], Pos_Y[i])(0);
    Pos_Y[i+1] = Pos_Y[i] + h*vel_y[i] + h*h/2*find_acc(Pos_X[i], Pos_Y[i])(1);
    vel_x[i+1] = vel_x[i] + h/2*(find_acc(Pos_X[i+1], Pos_Y[i+1])(0) + find_acc(Pos_X[i], Pos_Y[i])(0));
    vel_y[i+1] = vel_y[i] + h/2*(find_acc(Pos_X[i+1], Pos_Y[i+1])(1) + find_acc(Pos_X[i], Pos_Y[i])(1));
    i = i + 1;
  }
  return {Pos_X, Pos_Y};
}
