//  Simple matrix inversion example
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
  cout << n << endl;

  // Solve equation Av = b,
  vec v(n);
  vec g(n);
  vec gtilde(n);
  vec d(n);
  vec dtilde(n);
  vec e(n);

  cout << v << endl;





  return 0;
}
