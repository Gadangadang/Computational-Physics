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
  int p; int q;
  double eps = 1.0e-8;
  double s, c, theta, max_iterations;

public:
  void Initialize(double a, mat ex);

  void Rotate();
  void Jacobi();
  vec Jacobi_arm(mat T);
  void offdiag(mat A, int *p, int *q, int n);
  double tau(double theta);
  double tau(double a, double b, double c);
  double zero_test(mat it_A);
};

#endif
