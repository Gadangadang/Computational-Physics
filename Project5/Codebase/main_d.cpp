#include <iostream>
#include "armadillo"
#include "Finance.hpp"
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
   int mcs = 1e6;
   int L = 1000;
   double m_0 = 1;
   double tax_or_no = 0;
   double min_tax = 0;
   double alpha = 0.5;
   string filename1 = "Mon_vis.txt";
   string filename2 = "V_vis.txt";
   string filename3 = "Omega.txt";

   Finance Fc;
   double savings025 = 0;
   clock_t start, finish;
   start = clock();
   Fc.Initialize(mcs, L,m_0,filename2,tax_or_no,min_tax,savings025,alpha,0);
   Fc.MonteCarlo();
   Fc.print_vec(filename1);
   Fc.print_omega(filename3);

   finish = clock();
   double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
   cout << setprecision(10) << "Time used  for computing (single thread) = " << timeused  << " Seconds"<<endl;
return 0;
}
