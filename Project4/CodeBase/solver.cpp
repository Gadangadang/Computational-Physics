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
    // Initialize values by reference, and set them to point at internal Class variables
    m_spins = n_spins;
    m_mcs = mcs;
    m_M = 0;
    m_E = 0;
    long m_part; // what does this do ? 
    // can possibly rewrite this to:
    /*
    m_smatrix = zeros<mat>(n_spins, n_spins);
    long m_part;
    int& spins = m_spins; spins = n_spins;
    int& mcs = m_mcs; mcs = MonteCarloSims;
    double& M = m_M; M = 0;
    double& E = m_E; E = 0;
    */

// function to initialise energ, magnetization, and populate spin-matrix
for(int y =0; y < m_spins; y++) {
for (int x= 0; x < m_spins; x++){
if (init_temp < 1.5) m_smatrix(y, x) = 1; // spin orientation for the ground state
m_M += (double) m_smatrix(y, x);
}
}
// setup initial energy

for(int y =0; y < m_spins; y++) {
for (int x= 0; x < m_spins; x++){
m_E -= (double) m_smatrix(y, x)*(m_smatrix(periodic(y,m_spins,-1), x) + m_smatrix(y, periodic(x,m_spins,-1)));
}
}
}// end function initialise


int periodic(int i, int limit, int add){
    //  Idunno how this works, but lets keep it until we can figure out something better
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