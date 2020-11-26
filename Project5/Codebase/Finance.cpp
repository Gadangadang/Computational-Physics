#include "armadillo"
#include "Finance.hpp"
#include <iostream>
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
#include <stdlib.h>

// polluting the namespaces
using namespace arma;
using namespace std;


void Finance::Initialize(int mcs, int agents, double m_0, string filename){
// Initialize internal Class variables
    m_agents = agents;
    m_avec = vec(agents);
    m_norm = 1/((double)m_agents);
    m_m_0 = m_0;
    m_mcs = mcs;
    m_beta = 1/((double) m_m_0);
    m_avec = m_avec.fill(m_m_0);
    m_filename =filename;
    m_counter =0;
    ofstream ofile;
    ofile.open(m_filename);
    ofile.close();

}// end function initialise

double Finance::ran1(){ // can I even call double(long) to specify long storage of type double?;
    double Rnum = dis(generator);
    return Rnum;
}
double Finance::p_dist(double delta_m){
  return m_beta*exp(m_beta*delta_m);
}
void Finance::Metropolis(){
// loop over all spins

  int i = (int) (ran1()*(double)m_agents);
  int j = (int) (ran1()*(double)m_agents);
  double eps = ran1();
  double delta_m = -m_avec(i)+eps*(double)(m_avec(i)+m_avec(j));
  double tax = delta_m/10;
  if ( ran1() < p_dist(delta_m)){
    m_avec(i) += delta_m ; //- tax;
    m_avec(j) -= delta_m ;
    m_counter ++;}
  //if (m_avec(i) < max(m_avec)/10){
    //m_avec(i) += tax;
  //}

//}// End of the Metropolis function.
}

void Finance::MonteCarlo(){
    // Monte Carlo cycles
    for (int cycles = 1; cycles <= m_mcs; cycles++){
        Metropolis();
        calc_variance();
        print_variance();
    }
}// end function MonteCarloV1
void Finance::print_variance(){
  ofstream ofile;
  ofile.open(m_filename, fstream::app);
  ofile << setw(20) << setprecision(8) << m_variance<<endl;
  ofile.close();
}
void Finance::print_vec(string filename){
  ofstream ofile;
  ofile.open(filename);
  for(int i=0;i<m_agents; i++){
    ofile << setw(20) << setprecision(8) << m_avec(i)<<endl;}
  ofile.close();
}
void Finance::calc_variance(){
  m_variance = 0;
  for(int i=0;i<m_agents; i++){
    m_variance += (m_m_0-m_avec(i));}
  //m_variance *= m_norm;
  m_variance = max(m_avec)-min(m_avec);
}
