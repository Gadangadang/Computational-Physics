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

using namespace std;
using namespace arma;

ofstream ofile;

inline double f(double x){return 100*exp(-10*x);}
inline double exactfunc(double x){return 1-(1-exp(-10))*x-exp(-10*x);}
inline double relativeerror(double sol, double exac){return fabs((sol-exac)/exac);}

int main(int argc, char const *argv[]) {
  /* code */
  string outfilename;
  outfilename = "values.txt";
  ofile.open(outfilename);
  // Define matrix size

  int ex = atof(argv[1]);


  //Loop over all n to find max error for each n

  vec errlist(ex);
  vec nvals(ex);

  for (int p = 1; p <= ex; p++){

    int n = (int) pow(10,p);

    double h = 1./(n);
    cout << "Time step :" << h << endl;
    cout << "Dimension of vectors:" << n << endl;



    // Define vectors to solve equation Av = b
    vec v(n+1);
    vec x(n+1);
    vec g(n+1);
    vec gtilde(n+1);
    vec d(n+1);
    vec dtilde(n+1);
    vec e(n+1);
    vec sol(n+1);
    vec relerr(n+1);


    for (int i = 0; i<n; i++) e(i) =1;
    for (int i =0; i<n; i++) d(i) = -2;

    for (int i =0; i<n; i++){
      g(i) = -h*h*f(i*h);
      x(i) = i*h;
    }


    dtilde(0) = d(0);
    gtilde(0) = g(0);
    v(0)= 0 ;
    v(n) = 1;

    //Forward Part
    for (int i = 1; i<n; i++)
    {
      dtilde(i) = d(i)-1./dtilde(i-1);
      gtilde(i) = g(i) - gtilde(i-1)/(dtilde(i-1));
    }
    //Backward Part

    v(n-1) = gtilde(n-1)/dtilde(n-1);

    //exact solution

    for (int i= 0; i <n; i++){
      sol(i) = exactfunc(i*h);
    }

    for (int i = n-2; i>0; i--)
    {
      v(i) = (gtilde(i) - v(i+1))/dtilde(i);

    }

    for (int i = 0; i<n; i++){
      relerr(i) = relativeerror(v(i),sol(i));
      }


    //Print and write out log10 of relative error for a given n
    cout << log10(max(relerr)) << endl;
    ofile << setprecision(15) << n << " " << log10(max(relerr)) << endl;

  }





  ofile.close();




  return 0;
}
