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
#include <omp.h>
#include <tuple>
#include <cmath>
// polluting the namespaces
using namespace arma;
using namespace std;


int main(int argc, char* argv[])
{




   int mcs = 1e5;
   double init_temp = 1;
   double final_temp = 4.4;
   double t_step = 0.05;
   int param = 0;

   string name = ["MCL40.txt","MCL60.txt","MCL80.txt","MCL100.txt"];
   int i = 0;

   omp_set_num_threads(100); // this number needs to be optimized for individual pc's !

   double start = omp_get_wtime();
   #pragma omp parallel for

   for(int L = 40; L < 101; L += 20){
     for(double i_temp = init_temp; i_temp <= final_temp; i_temp += t_step){
       solver Mcint1;
       Mcint1.init_output();
       Mcint1.Initialize(L, mcs, i_temp, param);
       string filename = name[i];
       Mcint1.MonteCarloV2(filename);
     }
     i+=1;

     double finish = omp_get_wtime();
     double timeused = (double) (finish - start);
     cout << setprecision(10) << "Time used  for computing (single thread) = " << timeused  << " Seconds"<<endl;
   }


return 0;
}
