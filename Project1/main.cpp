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
  vec new v(n);
  vec new g(n);
  vec new gtilde(n);
  vec new d(n);
  vec new dtilde(n);
  vec new e(n);

  for (int i = 0; i<n; i++) e(i) =1;
  for (int i =0; i<n; i++) d(i) = -2;

  dtilde(0) = d(0);
  gtilde(0) = g(0);

  //Forward Part

  for (int i = 1; i<n; i++)
  {
    //i+2 to make sure we get x in [0,1]

    g(i) = h*h*f( (i+2) * h);
    dtilde(i) = -(i+1)/i;
    gtilde(i) = g(i) - gtilde(i-1)/(dtilde(i-1));
  }
  delete [] g;
  //Backward Part

  v(n-1) = gtilde(n-1)/dtilde(n-1);

  for (int i = n-2; i>0; i--)
  {
    v(i) = (gtilde(i) - v(i+1))/dtilde(i);
  }







  return 0;
}
