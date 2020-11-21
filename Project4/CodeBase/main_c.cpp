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
// Borrowing the initial code from the lecturenote2015.pdf, page 437.
// Available at: https://github.com/CompPhysics/ComputationalPhysics/tree/master/doc/Lectures
// input needs the following: spins, mcs, initial_temp, final_temp, t_step

// Will need to create an input handling structure to feed Class initialization.

// This section wont be filled until the whole class is finished.
// Will probably be very small. Solver will be general, and also the scope of questions is limited.
   int mcs = 1e5;
   int L = 2;
   double param_1 = 0.;
   solver Mcint1;
   clock_t start, finish;
   start = clock();
   double T = 1;
   Mcint1.Initialize(L, mcs,T,param_1);
   string filename = "MonteCarloRun.txt";
   Mcint1.init_output(filename);
   Mcint1.MonteCarloV2();
   finish = clock();
   double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
   cout << setprecision(10) << "Time used  for computing (single thread) = " << timeused  << " Seconds"<<endl;
   double Z = 12 + 2*exp(8/((double)T)) + 2*exp(-8/((double)T));
   double E_mean = (-16*exp(8/((double)T)) + 16*exp(-8/((double)T)))/((double) Z);
   double M_mean =  (8*exp(8/((double)T))+16)/((double)Z);
   double EE_mean = (2*(8*8)*exp(8/((double)T)) + 2*(8*8)*exp(-8/((double)T)))/((double) Z);
   double c_v = (EE_mean-E_mean*E_mean)/((double)T*T);
   double
   cout <<E_mean<<endl;
   cout <<M_mean<<endl;
   cout <<c_v<<endl;

return 0;
}
