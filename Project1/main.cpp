//  Project 1
#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "armadillo"

using namespace std;
using namespace arma;

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

  for (int i = 0; i<n;i++) e(i) =1;


  cout << e << endl;





  return 0;
}
