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
  all_planets.push_back(newplanet);
}

double ** solving::setup_matrix(int height,int width)
{   // Function to set up a 2D array

    // Set up matrix
    double **matrix;
    matrix = new double*[height];

    // Allocate memory
    for(int i=0;i<height;i++)
        matrix[i] = new double[width];

    // Set values to zero
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            matrix[i][j] = 0.0;
        }
    }
    return matrix;
}

void solving::delete_matrix(double **matrix)
{   // Function to deallocate memory of a 2D array

    for (int i=0; i<total_planets; i++)
        delete [] matrix[i];
    delete [] matrix;
}
void solving::delete_matrix3d(double ***matrix,int Integration_points)
{   // Function to deallocate memory of a 2D array

    for (int i=0; i<total_planets; i++)
      for (int k = 0; k<Integration_points;k++)
        delete [] matrix[i][k];
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



  double **acceleration = setup_matrix(total_planets, 3);
  double **acceleration_next = setup_matrix(total_planets, 3);
  double t = 0;
  double Fx, Fy, Fz, Fxnew, Fynew, Fznew, Pot, Kin;
  double dA1=0;
  double dA2=0;
  double h = final_time/((double) integration_points);
  double dt[4];
  dt[0] = 0.19*final_time;
  dt[1]=0.2*final_time;
  dt[2]=0.69*final_time;
  dt[3] = 0.7*final_time;


  std::ofstream ofile;
  std::string outfilename = "Planets_pos.txt";
  ofile.open(outfilename);
  ofile << integration_points << " " << total_planets<< " "<< endl;

  while (t < final_time){

    //Loop over all planets
    for (int nr = 0; nr < total_planets; nr++){

      object &current = all_planets[nr];

      Fx = Fy = Fz = Fxnew = Fynew = Fznew = Pot = Kin = 0;

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
        current.position[k] += current.velocity[k]*h + h*h/2*acceleration[nr][k];
      }
      //Loop again over all other planets
      for (int nr2 = nr + 1; nr2 < total_planets; nr2++){
        object &other = all_planets[nr2];
        GravitationalForce(current, other, Fxnew, Fynew, Fznew, epsilon);
        PotentialEnergySystem(current, other, Pot);
        KineticEnergySystem(current, Kin);
        Delta_A(current,t, dt, dA1, dA2,h);
      }

      acceleration_next[nr][0] = Fxnew/current.mass;
      acceleration_next[nr][1] = Fynew/current.mass;
      acceleration_next[nr][2] = Fznew/current.mass;

      //calculate velocity for planets
      for (int y = 0; y < dimension; y++){
        current.velocity[y] += h/2*(acceleration[nr][y] + acceleration_next[nr][y]);
      }
      //Calculate kinetic energy for current object

      print_to_file(all_planets[nr].position, dimension, ofile);

      if (nr==0) {
        print_energi(Pot, Kin, t,ofile);
      }
    }
    t+= h;
  }
  // Clear memory
  ofile.close();
  delete_matrix(acceleration);
  delete_matrix(acceleration_next);
  std::cout<<"Area of the first time interval is ="<<dA1<<endl;
  std::cout<<"Area of the second time interval is ="<<dA2<<endl;
}
void solving::print_to_file(double planets[3],int dimension, std::ofstream &ofile){
  ofile << std::setprecision(5)<< planets[0] << " "<< planets[1] << " "<< planets[2] <<endl;
}
void solving::print_energi(double &Pot, double &Kin, double &t, std::ofstream &ofile){
  ofile <<std::setprecision(20)<<Pot<< " " << Kin <<" " << t<< endl;
}

void solving::PotentialEnergySystem(object &current, object &other, double &Pot){

  double r = current.distance(other);
  if ( r != 0){
    Pot = -this->G*current.mass*other.mass/r;
  }
  else {
    Pot = 0;
  }
}


void solving::KineticEnergySystem(object &current, double &Kin){
  double velo2 = 0;
  for (int i = 0; i< 3; i++){
    velo2 += (double) current.velocity[i]*current.velocity[i];
  }
  Kin = (double) 1/2*current.mass*velo2;
}
void solving::Delta_A(object &current,double &t, double dt[4],double &dA1, double &dA2,double h){
if(t>dt[0]&&t<dt[1]){
  double velo2=0;
  double pos1=0;
for (int i = 0; i< 3; i++){
  velo2 += (double) current.velocity[i]*current.velocity[i];
  pos1 += (double) current.position[i]*current.position[i];
}
  double pos2 = sqrt(pos1);
  dA1 += (double) 1/2*velo2*pos2*h;
}
if(t>dt[2]&&t<dt[3]){
  double velo2=0;
  double pos1=0;
for (int i = 0; i< 3; i++){
  velo2 += (double) current.velocity[i]*current.velocity[i];
  pos1 += (double) current.position[i]*current.position[i];
}
  double pos2 = sqrt(pos1);
  dA2 += (double) 1/2*velo2*pos2*h;
}
}
