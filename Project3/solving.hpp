#ifndef SOLVING_HPP
#define SOLVING_HPP
#include "object.hpp"
#include <fstream>
#include "armadillo"
#include <vector>
using namespace arma;
using namespace std;

class solving{
  public:
    friend class object;

    // properties
    double radius,total_mass,G;
    int total_planets;
    vector<object> all_planets;
    double totalKinetic;
    double totalPotential;
    // initializers
    solving();
    solving(double radi);

    // functions
    void add(object newplanet);
    void addM(object newplanet);
    void GravitationalConstant();
    void print_position(std::ofstream &output, int dimension, double time, int number);
    void print_energy(std::ofstream &output, double time, double epsilon);
    void VelocityVerlet(int dimension, int integration_points, double final_time, int print_number, double epsilon);
    void delete_matrix3d(double ***matrix,int Integration_points);
    double **setup_matrix(int height,int width);
    void delete_matrix(double **matrix);
    void print_to_file(double planets[3],int dimension, std::ofstream &output);
    void GravitationalForce(object &current, object &other, double &Fx, double &Fy, double &Fz, double epsilon);
    void GravitationalForce_RK(double x_rel, double y_rel, double z_rel, double &Fx, double &Fy, double &Fz, double mass1, double mass2);
    void KineticEnergySystem();
    void PotentialEnergySystem(double epsilon);
    double EnergyLoss();
    bool Bound(object OnePlanet);
};


#endif
