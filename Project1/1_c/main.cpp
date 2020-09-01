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
#include <algorithm>

using namespace std;
using namespace arma;

ofstream ofile;

inline double f(double x){return 100*exp(-10*x);}
inline double exactfunc(double x){return 1-(1-exp(-10))*x-exp(-10*x);}
inline double relativeerror(double sol, double exac){return fabs((sol-exac)/exac);}

int main(int argc, char const *argv[]) {
  /* code */
  string error_file;
  error_file = "error_values.txt";
  // Define matrix size
  int ex = atof(argv[1]);
  for (int i = 1; i <=ex; i++)
  {
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
    vec v(n+1);
    vec x(n+1);
    vec g(n+1);
    vec gtilde(n+1);
    vec d(n+1);
    vec dtilde(n+1);
    vec e(n+1);
    vec sol(n+1);
    clock_t start, finish;
    start = clock();

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
      //i+2 to make sure we get x in [0,1]


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
    finish = clock();
    double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
    cout << setprecision(10) << "N="<< n<< ":  Time used  for computing=" << timeused  << endl;

    for (int i = 0; i<n; i++){
      ofile << setprecision(15) << v(i)<< " ";
      ofile << setprecision(15) << x(i) << " ";
      ofile << setprecision(15) << sol(i) << " ";

      if (i == 0){ //correct for nan value in first error calc
        ofile << setprecision(15) << 0 << endl;
      }
      else{
        ofile << setprecision(15) << relativeerror(v(i),sol(i)) << endl;
      }


    }
    //vec R_error(n+1);
    //int b;

    //ofile.close();
    //ofile.open(error_file)
    //for(b=0; b<n; b++){R_error(b)= relativeerror(v(b),sol(b))}
    //ofile << setprecision(15) << std::mak_element(v)<<endl;
    }

  return 0;
}
