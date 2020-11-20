#include <iostream>
#include "armadillo"
#include "solver.hpp"
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
   solver Mcint1;

   Mcint1.init_output();

   clock_t start, finish;


   double L1 = 20.; double L2 = 40.; double L3 = 60.; double L4 = 80.;

   int spins = L1;

   int mcs = 1e5;
   double init_temp = 1;
   double final_temp = 4.4;
   double t_step = 0.05;
   int param = 0;
   double Tc_L;
   int size = (int) (final_temp - init_temp)/t_step;


   for (double i_temp = init_temp; i_temp <= final_temp; i_temp += t_step){
     start = clock();
     Mcint1.Initialize(spins, mcs, i_temp, param,size);
     string filename = "MonteCarloRun.txt";
     Mcint1.MonteCarloV2(filename);

     finish = clock();
     double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
     cout << setprecision(10) << "Time used  for computing (single thread) = " << timeused  << " Seconds"<<endl;

   }














return 0;
}
