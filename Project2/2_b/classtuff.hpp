#ifndef CLASSTUFF_HPP
#define CLASSTUFF_HPP
#include "armadillo"

using namespace std;
using namespace arma;


class classtuff {
private:
  int c_size;
  double s, c, theta, maxiter;

public:
  int p; int q;
  mat S,A,R;
  double eps = 1.0e-8;
  mat Initialize(double a, mat ex);
  mat Rotate(mat A, mat S, int p, int q, int n);
  mat Jacobi(mat A, double eps);
  vec Jacobi_arm(mat T);
  void offdiag(mat A, int p, int q, int n);
  double tau(double theta);
  double tau(double a, double b, double c);
  double zero_test(mat it_A);
};

#endif
