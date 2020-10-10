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
}
