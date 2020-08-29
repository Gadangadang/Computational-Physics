//  Project 1
#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "armadillo"

using namespace std;
using namespace arma;

double f(double x){return 100*exp(-10*x);}

int main(int argc, char const *argv[]) {
  /* code */

  // Define matrix size
  int n = atof(argv[1]);
  double h = 1./(n+1);
  cout << "Time step :" << h << endl;
  cout << "Dimension of vectors:" << n << endl;

  // Define vectors to solve equation Av = b
  vec v(n);
  vec g(n);
  vec gtilde(n);
  vec d(n);
  vec dtilde(n);
  vec e(n);

  for (int i = 0; i<n; i++) e(i) =1;
  for (int i =0; i<n; i++) d(i) = -2;

  dtilde(0) = d(0);
  gtilde(0) = g(0);

  //Forward Part

  for (int i = 1; i<n; i++)
  {
    g(i) = h*h*f(i*h);
    dtilde(i) = d(i) - 1./dtilde(i-1);
    gtilde(i) = g(i) - gtilde(i-1)/(dtilde(i-1));
  }

  //Backward Part
  







  return 0;
}
