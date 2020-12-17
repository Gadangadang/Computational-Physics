#include <iostream>
#include "armadillo"
#include "Black_scholes.hpp"
#include <new>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>
#include "time.h"
#include <stdio.h>
#include <tuple>
#include <cmath>
// polluting the namespaces
using namespace arma;
using namespace std;

int main(int argc, char* argv[])
{
   Black_scholes SC;
   clock_t start, finish;
   start = clock();
   double T = 6.; double X=0.25; int N=1e4;
   int print_per =6;
   double D =(1.83989+1.85169+2.02683+5.4525)/((double)217.20);
   string filename="Aker_numeric.txt";double r = 0.0011; double sigma=0.3; double E=215.;
   SC.Initialize(T,X,N,filename,r,D,sigma,E);
   //SC.D1d_explicit();
   SC.Crank_Nic(print_per);
   finish = clock();
   double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
   cout << setprecision(10) << "Time used  for computing (single thread) = " << timeused  << " Seconds"<<endl;
return 0;
}
