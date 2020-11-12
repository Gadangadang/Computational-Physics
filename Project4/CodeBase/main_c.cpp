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
   double final_temp = atof(argv[3]);
   double init_temp = atof(argv[4]);
   double t_step = atof(argv[5]);
    cout << "mcs i main er: " << mcs << endl;
   solver Mcint1;
   Mcint1.Initialize(spins, mcs, init_temp, final_temp, t_step);
   Mcint1.MonteCarloV1();

return 0;
}
