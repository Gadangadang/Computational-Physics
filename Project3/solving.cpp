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


void solving::add(object newplanet){
  total_planets += 1;
  total_mass += newplanet.mass;
  all_planets.insert_rows(newplanet);
}

mat solving::setup_Matrix(int height, int width){
  mat matric(height,width,fill::zeros);
  return matric;
}

void solving::GravitationalForce(object &current,object &other,double &Fx,double &Fy,double &Fz,double epsilon)
{   // Function that calculates the gravitational force between two objects, component by component.

    // Calculate relative distance between current planet and all other planets
    double relative_distance[3];

    for(int j = 0; j < 3; j++) relative_distance[j] = current.position[j]-other.position[j];
    double r = current.distance(other);
    double smoothing = epsilon*epsilon*epsilon;

    // Calculate the forces in each direction
    Fx -= this->G*current.mass*other.mass*relative_distance[0]/((r*r*r) + smoothing);
    Fy -= this->G*current.mass*other.mass*relative_distance[1]/((r*r*r) + smoothing);
    Fz -= this->G*current.mass*other.mass*relative_distance[2]/((r*r*r) + smoothing);
}

void solving::VelocityVerlet(int dimension, int integration_points, double final_time, int print_number, double epsilon){



  mat acceleration = setup_Matrix(total_planets, 3);
  mat acceleration_next = setup_Matrix(total_planets, 3);
  double t = 0;
  double Fx, Fy, Fz, Fxnew, Fynew, Fznew;
  double h = final_time/((double) integration_points);
  t+= h;

  while (t < final_time){



    //Loop over all planets
    for (int nr = 0; nr < total_planets; nr++){

      object &current = all_planets[nr];

      Fx = Fy = Fz = Fxnew = Fynew = Fznew = 0;

      //Find forces on other planets
      for (int nr2 = nr + 1; nr2 < total_planets; nr2++){
        object &other = all_planets[nr2];
        GravitationalForce(current, other, Fx, Fy, Fz, epsilon);
      }

      acceleration[nr][0] = Fx/current.mass;
      acceleration[nr][1] = Fy/current.mass;
      acceleration[nr][2] = Fz/current.mass;

      //Calculate position for each planet
      for (int k = 0; k<dimension; k++){
        current.position[k] += current.velocity[k] + h*h/2*acceleration[nr][k];
      }

      //Loop again over all other planets
      for (int nr2 = nr + 1; nr2 < total_planets; nr2++){
        object &other = all_planets[nr2];
        GravitationalForce(current, other, Fxnew, Fynew, Fznew, epsilon);
      }

      acceleration_next[nr][0] = Fxnew/current.mass;
      acceleration_next[nr][1] = Fynew/current.mass;
      acceleration_next[nr][2] = Fznew/current.mass;

      //calculate velocity for planets
      for (int y = 0; y < dimension; y++){
        current.velocity[y] += h/2*(acceleration[nr][y] + acceleration_next[nr][y]);
      }
    }
  }






}
void solving::print_to_file(arma::mat planets,int Integration_points){
  std::ofstream ofile;
  std::string outfilename = "Planets_pos.txt";
  ofile.open(outfilename);
  ofile << std::setprecision(5) << total_planets <<" "<<Integration_points<<endl;
  for(int i=0; i<total_planets; i++){
    for(int j=0; j<Integration_points;j++){
      if(i==total_planets-1){
      ofile << std::setprecision(5) << planets[i][j][0] << " " << planets[i][j][1] << planet[i][j][2] <<;
    }
    else{
      ofile << std::setprecision(5) << planets[i][j][0] << " " << planets[i][j][1] << planets[i][j][2] <<endl;
    }
  }
}
}
