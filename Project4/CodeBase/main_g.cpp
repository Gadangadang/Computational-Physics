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


   double L1 = 40.; double L2 = 60.; double L3 = 80.; double L4 = 100.;


   int mcs = 1e5;
   double init_temp = 1;
   double final_temp = 4.4;
   double t_step = 0.05;
   int param = 0;


   start = clock();
   for (double i_temp = init_temp; i_temp <= final_temp; i_temp += t_step){

     Mcint1.Initialize(L1, mcs, i_temp, param);
     string filename = "MCL40.txt";
     Mcint1.MonteCarloV2(filename);
   }
   finish = clock();
   double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
   cout << setprecision(10) << "Time used  for computing (single thread) = " << timeused  << " Seconds"<<endl;



<<<<<<< HEAD
=======

>>>>>>> 2df9d6ea2a81e45549d824a4782dc8517ebf8491













return 0;
}
