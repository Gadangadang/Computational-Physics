#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
//#include "classtuff.cpp"
#include "armadillo"
#include <cstdio>
#include <math.h>
#include "solver.hpp"

using namespace arma ;

TEST_CASE( "Check for errors in code" ) {
  solver Mcint1;
SECTION("Check if the spins ar randomly ordered:"){
  //Checks if the spins are randomly ordered by checking if the avarage spin
  //converges towards 0.
  int mcs =1e2; double T =2.4; double param_1 = 0.;  int L_1 =10;int L_2 = 20;
  Mcint1.Initialize(L_1, mcs,T, param_1);
  int sum_1 = 0;
  for(int i = 0; i <L_1*L_1; i++){sum_1 += Mcint1.m_smatrix[i];}
  double sum_L_10 = sum_1/((double) L_1*L_1);
  Mcint1.Initialize(L_2, mcs,T, param_1);
  int sum_2=0;
  for(int i = 0; i <L_2*L_2; i++){sum_2 += Mcint1.m_smatrix[i];}
  double sum_L_20 = sum_2/((double)L_2*L_2);
  REQUIRE(fabs(sum_L_20) < fabs(sum_L_10));
}
SECTION("Check if the Variance increases with the temperature:"){
  int mcs =1e5; double T_1 =1; double T_2 = 2.4; double param_1 = 0.;  int L =20;
  int stabile_indx = 7e4;
  Mcint1.Initialize(L, mcs,T_1, param_1);
  Mcint1.MonteCarloV1();
  Mcint1.calc_variance(stabile_indx);
  double variance_1 = Mcint1.m_variance;
  Mcint1.Initialize(L, mcs,T_2, param_1);
  Mcint1.MonteCarloV1();
  Mcint1.calc_variance(stabile_indx);
  double variance_2 = Mcint1.m_variance;
  REQUIRE(fabs(variance_1) < fabs(variance_2));
}

}
