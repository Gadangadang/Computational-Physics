//  Project 1
#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include "armadillo"
#include "time.h"

using namespace std;
using namespace arma;


ofstream ofile;

inline double f(double x){return 100*exp(-10*x);}
inline double exactfunc(double x){return 1-(1-exp(-10))*x-exp(-10*x);}

int main(int argc, char const *argv[]) {
  /* code */

  // Define matrix size

  int ex = atof(argv[1]);

  for (int i=1; i<= ex; i++){
    string outfilename ;
    if (i == 1){

    outfilename = "valn0.txt";
    }
    else if (i == 2){
    outfilename = "valn1.txt";
    }
    else if (i == 3){
    outfilename = "valn2.txt";
    }

    ofile.open(outfilename);

    int n = (int) pow(10,i);
    double h = 1./(n);
    cout << "Time step :" << h << endl;
    cout << "Dimension of vectors:" << n << endl;

    // Define vectors to solve equation Av = b
    n = n-1; //Reset n to only use end points
    mat A = zeros<mat>(n,n);
    vec b(n);
    vec v(n);
    vec x(n);
    vec exac(n);
    clock_t start, finish;
    start = clock();
    A(0,0) = -2; A(0,1) = 1; x(0) = h; b(0) = -h*h*f(x(0));
    x(n-1) = x(0) + (n-1)*h; b(n-1) = -h*h*f(x(n-1));

    for (int i =1; i<n-1; i++){
      x(i) = x(0) + i*h;
      b(i) = -h*h*f(x(i));
      A(i,i-1) = 1;
      A(i,i) = -2;
      A(i,i+1) = 1;

    }
    A(n-1,n-1) = -2; A(n-1,n-2) = 1; A(n-2,n-1) = 1;

    //Solve Av = b
    v = solve(A,b);
    finish = clock();
    double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
    cout << setprecision(10) << "N="<< n+1<< ":  Time used  for computing=" << timeused  << endl;
    for (int i = 0; i<n; i++){
      exac(i) = exactfunc(i*h);
      ofile << setprecision(15) << v(i) << " " << x(i) << " " << exac(i) << endl;
    }
    ofile.close();
  }




  return 0;
}
