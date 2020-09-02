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
#include <stdio.h>

using namespace std;
using namespace arma;



ofstream ofile;

inline double f(double x){return 100*exp(-10*x);}
inline double exactfunc(double x){return 1-(1-exp(-10))*x-exp(-10*x);}

int main(int argc, char const *argv[]) {
  /* code */

  int ex = atof(argv[1]);

  for (int i=1; i<= ex; i++){
    string outfilename ;

    //Formats name of lists from amount of loops needed
    if (ex < 10){

      char poop[9];
      sprintf(poop, "valn%d.txt", i );
      outfilename = poop;
      ofile.open(outfilename);

    }
    else{

      char poop[10];
      sprintf(poop, "valn%d.txt", i );
      outfilename = poop;
      ofile.open(outfilename);

    }

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
    vec Y(n);
    vec X(n);
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

    mat L, U;
    lu(L,U,A);
    //Forward
    for(int i = 1; i<n; i++)
      {
      int sum1 = 0;
      for(int k = 0; k<i;k++){
        sum1 += L(i,k)*Y(k);
      }
      Y(i) = 1./(L(i,i))*(b(i)- sum1);
    }
    //Backwards
    X(n-1) = Y(n-1)/U(n-1,n-1);
    for(int i = n-1; i>=0; i--)
      {
      int sum1 = 0;
      for(int k = i; k<n;k++){
        sum1 += U(i,k)*X(k);
      }
      X(i) = 1./(U(i,i))*(Y(i)- sum1);
    }
    //Solve Av = b
    finish = clock();
    double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
    cout << setprecision(10) << "N="<< n+1<< ":  Time used  for computing=" << timeused  << endl;
    for (int i = 0; i<n; i++){
      exac(i) = exactfunc(i*h);
      ofile << setprecision(15) << X(i) << " " << x(i) << " " << exac(i) << endl;
    }
    ofile.close();
  }

  return 0;
}
