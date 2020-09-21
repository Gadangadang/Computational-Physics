#ifndef CLASSTUFF_HPP
#define CLASSTUFF_HPP
#include "armadillo"

using namespace std;
using namespace arma;


class classtuff {
private:
  int c_size;
  mat A;
  mat S;
  double eps = 1.0e-8;
  double max_iterations = (double) c_size * (double) c_size * (double) c_size;
  double s, c, theta;

public:
  void Initialize(double a, mat ex);
  void Rotate();
  void Jacobi();
  mat Jacobi_arm(mat T);
  double tau(double theta);
  double tau(double a, double b, double c);
};

#endif
