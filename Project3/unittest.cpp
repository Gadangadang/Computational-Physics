#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
//#include "classtuff.cpp"
#include "solving.hpp"
#include "object.hpp"
#include "armadillo"
#include <cstdio>
using namespace arma ;

TEST_CASE( "Check for errors in code" ) {

// Make our test system
//Add objects you wish to look at
int IntegrationPoints = 50000;
double FinalTime = 10;
int Dimension = 3;
double beta = 2;
int fixed =1;

double earth_mass = 3.003e-6;
double sun_mass = 1.0;

object planetearth(earth_mass,9.128884513088843*1e-01,3.928032801600736*1e-01,6.577938183713410*1e-05,-6.957269992142644*1e-03*365, 1.579734315560513*1e-02*365, -2.582593092148153*1e-07*365);
object sun(sun_mass, -6.107925513172998*1e-03,6.420679726598624*1e-03,8.893727401374147*1e-05,-7.280593132276730*1e-06*365,-5.090234498858063*1e-06*365,2.181619304215098*1e-07*365);

solving unittest_solv(5.0);
unittest_solv.add(planetearth); unittest_solv.add(sun);


//Run simulation to aquire data
unittest_solv.VelocityVerlet(Dimension,IntegrationPoints,FinalTime,1,0., beta, fixed);

  //SECTION("Check conservation of angular momentum"){
  //  REQUIRE( );
  //}

  //  SECTION(""){
  //    REQUIRE();
  //  }
  //}

  int *integrationpoints = nullptr;
  float *number_o_planet = nullptr;
  float *t = nullptr;

  double *kin, *pot, *x, *y, *z ;


  char* planet_info = "Planets_pos.txt";
  FILE *fp_init = fopen(planet_info, "r"); //Open file to read, specified by "r".

  fscanf(fp_init, "%d %e ", integrationpoints, number_o_planet);

  kin = new double[*integrationpoints];
  pot = new double[*integrationpoints];
  x = new double[*integrationpoints];
  y = new double[*integrationpoints];
  z = new double[*integrationpoints];

  //Read info from file
  int j = 0;
  for (int i = 0; i < (*number_o_planet+1)**integrationpoints; i++){
    if ( j ==1  ){
    fscanf(fp_init, "%lf %lf %e ", &pot[i], &kin[i], t);
    }
    else {
      fscanf(fp_init,"%lf %lf %lf ", &x[i], &y[i], &z[i]);
    }
    if (j == 2){
      j *= 0;
    }
    else {
      j += 1;
    }
  }


  SECTION("Check conservation of energy"){


    //Now sum up energy
    double toten[*integrationpoints];
    for (int i = 0; i < *integrationpoints; i++){
      toten[i] = kin[i] + pot[i];
    }

    //Find max total energy value for each half of the array.
    double maxval = toten[0];
    for (int i = 1; i < *integrationpoints/2; i++){
      if (toten[i] > maxval){
        maxval = toten[i];
      }
    }

    double maxval2 = toten[*integrationpoints/2];
    for (int k = *integrationpoints/2; k < *integrationpoints; k++){
      if (toten[k] > maxval2){
        maxval2 = toten[k];
      }
    }



    REQUIRE( fabs((maxval - maxval2) < (double)maxval2) );
  }
}
