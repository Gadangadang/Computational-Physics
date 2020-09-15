#ifndef CLASSTUFF_HPP
#define CLASSTUFF_HPP
#include "armadillo"

using namespace std;
using namespace arma;


class quad {
private:
  int c_size;
  mat A;
  mat S;
  double s, c, theta;


public:
  void Initialize(double a, mat ex);
  void Diag(double a);
  double tau(double theta);
  double tau(double a, double b, double c);
};

#endif
