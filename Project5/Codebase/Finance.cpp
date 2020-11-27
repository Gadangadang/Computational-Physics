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


void Finance::Initialize(int mcs, int agents, double m_0, string filename, double tax_or_no, double tax,double savings){
// Initialize internal Class variables
    m_agents = agents;
    m_avec = vec(agents);
    m_norm = 1/((double)m_agents);
    m_m_0 = m_0;
    m_savings = savings;
    m_mcs = mcs;
    m_tax = tax/((double)100);
    m_tax_or_no = tax_or_no;
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
  return 1000*exp(m_beta*delta_m);
}
void Finance::Metropolis(){
// loop over all spins
  int i = (int) (ran1()*(double)m_agents);
  int j = (int) (ran1()*(double)m_agents);
  double eps = ran1();
  double delta_m = (1-m_savings)*(eps*(double)m_avec(j)-(1-eps)*(double)m_avec(i));
  if ( ran1() < p_dist(delta_m)){
    double tax = ss(i,delta_m);
    m_avec(i) += delta_m -tax; //- tax;
    m_avec(j) -= delta_m ;
    m_counter ++;}
//}// End of the Metropolis function.
}

double Finance::ss(int i, double delta_m){
  uvec indx = sort_index(m_avec);
  double tax = m_tax_or_no*delta_m*(m_tax+0.1*m_avec(i)/((int)m_avec(indx(m_agents-10))));
  for(int k=0;k<10;k++){
    m_avec[indx[k]] +=0.1*tax;
  }
  return tax;
}
void Finance::MonteCarlo(){
    // Monte Carlo cycles
    for (int cycles = 1; cycles <= m_mcs; cycles++){
        Metropolis();
        calc_avg_dist();
        print_avg_dist();
    }
}// end function MonteCarloV1
void Finance::print_avg_dist(){
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
void Finance::print_omega(string filename){
  ofstream ofile;
  ofile.open(filename);
  for(int i=0;i<m_agents; i++){
    ofile << setw(20) << setprecision(8) << log(p_dist(-m_avec(i)))<<endl;}
  ofile.close();
}
void Finance::calc_avg_dist(){
  m_variance = 0;
  for(int i=0;i<m_agents; i++){
    m_variance += fabs(m_m_0-m_avec(i));}
  //m_variance *= m_norm;
  m_variance *= m_norm;
}
