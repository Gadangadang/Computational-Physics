#ifndef CLASSTUFF_HPP
#define CLASSTUFF_HPP
#include "armadillo"

using namespace std;
using namespace arma;


class classtuff {
private:
  int c_size;
  double s, c, theta, maxiter;
  int p; int q;
  double maxoff;
public:
  mat S,A;
  double eps;
  mat Initialize(double a, mat ex);
  void Rotate(mat &A, mat S, int &p, int &q, int n);
  mat Jacobi(mat A, double eps);
  vec Jacobi_arm(mat T);
  void offdiag(mat A, int &p, int &q, int n, double &maxoff);
  double tau(double theta);
  double tau(double a, double b, double c);
  double zero_test(mat it_A);
};

#endif
