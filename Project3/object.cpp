#include "object.hpp"
#include <cmath>
#include <vector>

object::object(double M,double x,double y,double z,double vx, double vy,double vz){
    mass = M;
    position[0] = x;
    position[1] = y;
    position[2] = z;
    velocity[0] = vx;
    velocity[1] = vy;
    velocity[2] = vz;
    potential = 0.;
    kinetic = 0.;
    Gconst = 4*cmath::pi*cmath::pi;
    epsilon = 0.;
}

double object::distance(object otherObject){

    double x1,y1,z1,x2,y2,z2,xx,yy,zz;

    x1 = this->position[0];
    y1 = this->position[1];
    z1 = this->position[2];

    x2 = otherObject.position[0];
    y2 = otherObject.position[1];
    z2 = otherObject.position[2];

    xx = x1-x2;
    yy = y1-y2;
    zz = z1-z2;

    return sqrt(xx*xx + yy*yy + zz*zz);
}




double object::GravitationalForce(object otherObject,double &Gconst)
{
    double r = this->distance(otherObject);
    if(r!=0) return Gconst*this->mass*otherObject.mass/(r*r);
    else return 0;
}

double object::Acceleration(object otherObject, double &Gconst)
{
    double r = this->distance(otherObject);
    if(r!=0) return this->GravitationalForce(otherObject,Gconst)/(this->mass*r);
    else return 0;
}

double object::KineticEnergy()
{
    double velocity2 = (this->velocity[0]*this->velocity[0]) + (this->velocity[1]*this->velocity[1]) + (this->velocity[2]*this->velocity[2]);
    return 0.5*this->mass*velocity2;
}

double object::PotentialEnergy(object &otherObject, double &Gconst, double &epsilon)
{
    if(epsilon==0.0) return -Gconst*this->mass*otherObject.mass/this->distance(otherObject);
    else return (Gconst*this->mass*otherObject.mass/epsilon)*(atan(this->distance(otherObject)/epsilon) - (0.5*M_PI));
