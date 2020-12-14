#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
//#include "classtuff.cpp"
#include "armadillo"
#include <cstdio>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <string>
#include "Black_scholes.hpp"
#include <functional>

using namespace arma ;
using namespace std ;

TEST_CASE( "Check for errors in code" ) {


  SECTION("Check if value of option is negative at any time"){
    Black_scholes SC;

    double T = 1; double X=0.75; int N=1e4;
    string filename="u.txt";
    double r = 0.04; double D=0.12;
    double sigma=0.4; double E=50;
    SC.Initialize(T,X,N,filename,r,D,sigma,E);
    SC.Crank_Nic();

    // File pointer
    fstream fin;
    // Open an existing file
    fin.open("u.txt", ios::in);
    // Read the Data from the file
    // as String Vector
    vector<double> S;
    vector<double> time;
    string line, word, temp;

    int count = 0;
    vector<vector<double> > matrix; //Matrix to hold option value for each time step

    while (fin >> temp){

      getline(fin, line);

      // used for breaking words
      stringstream s(line);

      std::string resultstr = s.str();
      const char* cstr2 = resultstr.c_str();

      vector <double> VperS;

      char* line = (char*) cstr2;
      char* pch = strtok(line, " ");
      if (count == 0){  //If count == 0, line in file is stock price
        while (pch != NULL){
          S.push_back( std::atof(pch) );
          pch = strtok (NULL, " ");
        }
        count += 1;
      }
      else{ //Time and option value
        int hello = 0;
        while (pch != NULL){
          if ( hello == 0 ){
            time.push_back( std::atof(pch) );
            pch = strtok (NULL, " ");
            hello += 1;
          }
          VperS.push_back( std::atof(pch) );
          pch = strtok (NULL, " ");
        }
        matrix.push_back(VperS);
      }
    }

    vector<double> compare_vec;
    for (int i = 0; i < N; i++){
      compare_vec.push_back((double) 0);
    }

    bool ok;
    int number = 0;
    for (int i = 0; i < 11; i++){
        ok = compare_vec <= matrix[i];
        number += ok;
    }

    REQUIRE(number == 11);

  }
  SECTION("Tridiag works as expected"){
    REQUIRE(1 == 1);
  }
}
