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
#include <stdlib.h>

// polluting the namespaces
using namespace arma;
using namespace std;


void solver::Initialize(int n_spins, int mcs, double init_temp, double final_temp, double t_step){
// Initialize values by reference, and set them to point at internal Class variables
    m_smatrix = zeros<mat>(n_spins, n_spins);
    m_spins = n_spins;
    m_mcs = mcs;
    m_M = 0;
    m_E = 0;
    long m_part = -1; // what does this do ? Example sets this to -1, calls it random??
    vec m_w(17);
    vec m_average(5);

// function to initialise energy, magnetization, and populate spin-matrix
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

// setup array for possible energy changes
    for( int de =-8; de <= 8; de++) m_w[de+8] = 0;
    for( int de =-8; de <= 8; de+=4) m_w[de+8] = exp(-de/init_temp);
    
// initialise array for expectation values
    for( int i = 0; i < 5; i++) m_average[i] = 0.;

}// end function initialise

double solver::ran1(long seed){ // can I even call double(long) to specify long storage of type double?
    // Random number generator. Needs to be implemented
}

int periodic(int i, int limit, int add){
    //  Idunno how this works, but Im keeping it until we can figure out something better. 
    return (i+limit+add) % (limit);
}
void solver::Metropolis(mat& m_smatrix, long& m_part, double& m_E, double& m_M, double& w){
// loop over all spins
    for(int y =0; y < m_spins; y++) {
    for (int x= 0; x < m_spins; x++){
// Find random position
    int ix = (int) (ran1(m_part)*(double)m_spins);
    int iy = (int) (ran1(m_part)*(double)m_spins);
    int deltaE = 2*m_smatrix(iy, ix)*
    (m_smatrix(iy, periodic(ix,m_spins,-1))+
    m_smatrix(periodic(iy,m_spins,-1), ix) +
    m_smatrix(iy, periodic(ix,m_spins,1)) +
    m_smatrix(periodic(iy,m_spins,1), ix));
// Here we perform the Metropolis test
    if ( ran1(m_part) <= m_w(deltaE+8) ) {
    m_smatrix(iy, ix) *= -1; // flip one spin and accept new spin config
// update energy and magnetization
    m_M += (double) 2*m_smatrix(iy, ix);
    m_E += (double) deltaE;
}
}
}

}




void solver::MonteCarloV1(){
    // Main solver loop and Datagenerator. 
    // This section needs work. 

    // Monte Carlo cycles
    for (int cycles = 1; cycles <= mcs; cycles++){
    Metropolis(n_spins, idum, m_smatrix, E, M, w);
    // update expectation values
    average[0] += E; average[1] += E*E;
    average[2] += M; average[3] += M*M; average[4] += fabs(M);
    }
    }

}// end function MonteCarloV1

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