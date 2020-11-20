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
   double init_temp = 2;
   double final_temp = 2.3;
   double t_step = 0.001;
   int param = 0;

   string name[4] = {"MCL40.txt", "MCL60.txt", "MCL80.txt", "MCL100.txt"};
   int p = 0;

   omp_set_num_threads(100); // this number needs to be optimized for individual pc's !
   int iter = int( (final_temp - init_temp) / t_step );
   double start = omp_get_wtime();
   #pragma omp parallel for

   for(int L = 40; L < 101; L += 20){
     for(int i = 0; i <= iter; i++){
       double i_temp = (double) init_temp + i*t_step;
       solver Mcint1;
       Mcint1.init_output();
       Mcint1.Initialize(L, mcs, i_temp, param);
       string filename = name[p];
       Mcint1.MonteCarloV2(filename);

     }
     cout << "L = " << L << endl;
     p+=1;

     double finish = omp_get_wtime();
     double timeused = (double) (finish - start);
     cout << setprecision(10) << "Time used  for computing (Multithread) = " << timeused  << " Seconds"<<endl;
   }


return 0;
}
