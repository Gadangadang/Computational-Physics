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
// Initialize internal Class variables
    m_smatrix = zeros<mat>(n_spins, n_spins);
    m_spins = n_spins;
    m_mcs = mcs;
    m_M = 0;
    m_E = 0;
    m_final_temp = final_temp;
    m_init_temp = init_temp;
    m_tstep = t_step;
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
void solver::Metropolis(mat& m_smatrix, long& m_part, double& m_E, double& m_M, vec& m_w){

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
}// End of the Metropolis function.




void solver::MonteCarloV1(){
    // Main solver loop
    // This section needs work. 

    // Monte Carlo cycles
    for (int cycles = 1; cycles <= m_mcs; cycles++){
        Metropolis(m_smatrix, m_part, m_E, m_M, m_w);
    // update expectation values
        m_average(0) += m_E; m_average(1) += m_E*m_E;
        m_average(2) += m_M; m_average(3) += m_M*m_M; m_average(4) += fabs(m_M);
    }
}// end function MonteCarloV1


void solver::output(){

}
