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
   int mcs = 2.5e5;
   int L = 500;
   double m_0 = 100;
   double tax_or_no = 0;
   double min_tax = 0;
   double alpha, gamma;
   string filename = "V_vis.txt";
   string filename1 = "Mon_vis.txt";

   Finance Fc;
   double savings025 = 0;
   clock_t start, finish;
   double gammaval[5] = {0,1.0,2.0,3.0,4.0};
   double alphaval[2] = {1,2};

   for(int i = 0; i < 2; i++){
     alpha = alphaval[i];

     for(int j = 0; j < 5; j++){
       gamma = gammaval[j];

       start = clock();
       Fc.Initialize(mcs, L,m_0,filename,tax_or_no,min_tax,savings025,alpha,gamma);
       Fc.MonteCarlo();Fc.print_vec(filename1);

       finish = clock();
       double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
       cout << setprecision(10) << "Time used  for computing (single thread) = " << timeused  << " Seconds"<<endl;
     }
   }

return 0;
}
