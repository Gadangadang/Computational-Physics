#ifndef OBJECT.H
#define OBJECT.H
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
using std::vector;

class object
{
    public:
    // Attributes
    double mass;
    double position[3];
    double velocity[3];
    double potential;
    double kinetic;
    double Gconst;


    //Initializer
    object(double M,double x,double y,double z,double vx, double vy,double vz);


    //Functions
    double distance(object otherObject);
    double GravitationalForce(object otherObject, double Gconst);
    double Acceleration(object otherObject, double Gconst);
    double KineticEnergy();
    double PotentialEnergy(object &otherObject, double Gconst, double epsilon);



}
