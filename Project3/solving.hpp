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
    double c = 63239.7263; // Speed of light in AU/year
    // initializers
    solving();
    solving(double radi);

    // functions
    void add(object newplanet);
    void addM(object newplanet);
    void GravitationalConstant();
    double angularmomentum(object &current);
    void center_of_mass(double cm[3], int dimension);
    void print_position(std::ofstream &output, int dimension, double time, int number,object &current, object &other);
    void peri(object &curent, object &other,double &alpha,double mon,double tue,double wen,double x_p,double y_p);
    void VelocityVerlet(int dimension, int integration_points, double final_time, int print_number, double epsilon, double beta, int fixed,int alpha);
    void Forward_Euler(int dimension, int integrationpoints, double final_time,double epsilon,double beta, int alpha);
    void delete_matrix3d(double ***matrix,int Integration_points);
    double **setup_matrix(int height,int width);
    void Delta_A(object &current,double &t, double dt[4],double &dA1, double &dA2,double h);
    void delete_matrix(double **matrix);
    void print_to_file(double planets[3],int dimension, std::ofstream &ofile);
    void print_energi(double &pot, double &Kin, double &t, double &l, std::ofstream &ofile);
    void GravitationalForce(object &current, object &other, double &Fx, double &Fy, double &Fz, double epsilon, double beta,int alpha);
    void GravitationalForce_RK(double x_rel, double y_rel, double z_rel, double &Fx, double &Fy, double &Fz, double mass1, double mass2);
    void KineticEnergySystem(object &current, double &Kin);
    void PotentialEnergySystem(object &current, object &other, double &Pot);
    double EnergyLoss();
    bool Bound(object OnePlanet);
};


#endif
