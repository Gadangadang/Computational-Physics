#include <iostream>
#include "armadillo"
#include "solver.hpp"
#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include "armadillo"
#include "time.h"
#include <stdio.h>
#include <tuple>
#include <cmath>
// polluting the namespaces
using namespace arma;
using namespace std;


void solver::Initialize(int n_spins, int mcs, double init_temp, double final_temp, double t_step){
    m_smatrix = zeros<mat>(n_spins, n_spins);
    long m_part;
    double M = 0;
    double E = 0;
// function to initialise energ, magnetization, and populate spin-matrix
for(int y =0; y < n_spins; y++) {
for (int x= 0; x < n_spins; x++){
if (init_temp < 1.5) m_smatrix(y, x) = 1; // spin orientation for the ground state
M += (double) m_smatrix(y, x);
}
}
// setup initial energy

for(int y =0; y < n_spins; y++) {
for (int x= 0; x < n_spins; x++){
E -= (double) m_smatrix(y, x)*
(m_smatrix(periodic(y,n_spins,-1), x) +
m_smatrix(y, periodic(x,n_spins,-1));
}
}
}// end function initialise
}

int periodic(int i, int limit, int add){
    return (i+limit+add) % (limit);
}
solver::Metropolis(){}

solver::output(){}


/* Example function
void Metropolis(int n_spins, long& idum, int **m_smatrix, double& E, double&M, double *w)
{
// loop over all spins
for(int y =0; y < n_spins; y++) {
for (int x= 0; x < n_spins; x++){
// Find random position
int ix = (int) (ran1(&idum)*(double)n_spins);
int iy = (int) (ran1(&idum)*(double)n_spins);
int deltaE = 2*m_smatrix[iy][ix]*
(m_smatrix[iy][periodic(ix,n_spins,-1)]+
m_smatrix[periodic(iy,n_spins,-1)][ix] +
m_smatrix[iy][periodic(ix,n_spins,1)] +
spin_matrix[periodic(iy,n_spins,1)][ix]);
// Here we perform the Metropolis test
if ( ran1(&idum) <= w[deltaE+8] ) {
spin_matrix[iy][ix] *= -1; // flip one spin and accept new spin config
// update energy and magnetization
M += (double) 2*spin_matrix[iy][ix];
E += (double) deltaE;
}
}
}
} // end of Metropolis sampling over spins¨
*/