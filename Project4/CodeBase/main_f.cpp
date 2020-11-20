#include <iostream>
#include "armadillo"
#include "solver.hpp"
#include <new>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>
#include <omp.h>
#include "time.h"
#include <stdio.h>
#include <tuple>
#include <cmath>
// polluting the namespaces
using namespace arma;
using namespace std;


int main(int argc, char* argv[])
{
// Borrowing the initial code from the lecturenote2015.pdf, page 437.
// Available at: https://github.com/CompPhysics/ComputationalPhysics/tree/master/doc/Lectures
// input needs the following: spins, mcs, initial_temp, final_temp, t_step

// Will need to create an input handling structure to feed Class initialization.

// This section wont be filled until the whole class is finished.
// Will probably be very small. Solver will be general, and also the scope of questions is limited.
   int mcs = atoi(argv[1]);
   int spins = atoi(argv[2]);
   double init_temp = atof(argv[3]);
   double final_temp = atof(argv[4]);
   double t_step = atof(argv[5]);
   int param = 0;

   int iter = int( (final_temp - init_temp) / t_step );


   // Parallel thread region

   omp_set_num_threads(100); // this number needs to be optimized for individual pc's !
   // thread count analysis
   double wtime = omp_get_wtime();
   #pragma omp parallel for
   for (int i = 0; i <= iter; i++){
   solver Mcint1;
   Mcint1.init_output();
   double i_temp = (double) init_temp + i*t_step;
   Mcint1.Initialize(spins, mcs, i_temp, param);
   string filename = "MonteCarloRun.txt";
   Mcint1.MonteCarloV2(filename);
   }

   double wtime2 = omp_get_wtime() - wtime; ;
   cout << setprecision(10) << "Time used  for computing (Multithread) = " << wtime2  << " Seconds"<<endl;

   // single thread region
   solver Mcint1;
   Mcint1.init_output();
   double wtime3 = omp_get_wtime();
   for (int i = 0; i <= iter; i++){
   double i_temp = (double) init_temp + i*t_step;
   Mcint1.Initialize(spins, mcs, i_temp, param);
   string filename = "MonteCarloRun.txt";
   Mcint1.MonteCarloV2(filename);
   }

   double wtime4 = omp_get_wtime() - wtime3;
   cout << setprecision(10) << "Time used  for computing (single thread) = " << wtime4  << " Seconds"<<endl;

return 0;
}
