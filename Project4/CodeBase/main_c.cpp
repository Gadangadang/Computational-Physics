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
   int mcs = atoi(argv[1]);
   int spins = atoi(argv[2]);
   double init_temp = atof(argv[3]);
   double final_temp = atof(argv[4]);
   double t_step = atof(argv[5]);
    ofstream ofile;
        ofile.open("MonteCarloRun.txt");
        ofile << setiosflags(ios::showpoint | ios::uppercase);
        ofile << setw(15) << "Inital Temp";
        ofile << setw(15) << "E average";
        ofile << setw(15) << "E variance";
        ofile << setw(15) << "M average";
        ofile << setw(15) << "M variance";
        ofile << setw(15) << "M abs total" << endl;
    ofile.close();

   solver Mcint1;
   clock_t start, finish;
   start = clock();
   //for (double i_temp = init_temp; i_temp <= final_temp; i_temp += t_step){
   //Mcint1.Initialize(spins, mcs, i_temp);
   //Mcint1.MonteCarloV1();
   //}
   double T = 2.4;
   int param_1=1;
   Mcint1.Initialize(2, mcs,T, param_1,0);
   Mcint1.MonteCarloV1();
   finish = clock();
   double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
   cout << setprecision(10) << "Time used  for computing (single thread) = " << timeused  << " Seconds"<<endl;

return 0;
}
