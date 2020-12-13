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
#include <string>
#include "Black_scholes.hpp"

using namespace arma ;
using namespace std ;

TEST_CASE( "Check for errors in code" ) {

  SECTION("Check if value of option is negative at any time"){

    Black_scholes SC;

    double T = 1; double X=0.75; int N=1e4;
    string filename="u.txt";double r = 0.04; double D=0.12; double sigma=0.4; double E=50;
    SC.Initialize(T,X,N,filename,r,D,sigma,E);
    //SC.D1d_explicit();
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

    vector<vector<double> > matrix;
    while (fin >> temp){

      // read an entire row and
      // store it in a string variable 'line'
      getline(fin, line);

      // used for breaking words
      stringstream s(line);

      // read every column data of a row and
      // store it in a string variable, 'word'
      vector <double> VperS;
      int index = 0;
      while (getline(s, word, ' ')) {
          // add all the column data
          // of a row to a vector
          double value = std::atof(word.c_str());
          if (count == 0){
            S.push_back(value);
          }

          if (index == 0){
            time.push_back(value);
          }

          VperS.push_back(value);

      }

      matrix.push_back(VperS);
      count += 1;
    }


    for (int i = 0; i < 12; i++){
      for (int j = 0; j < N; j++){
        cout << matrix[i][j] << " ";
      }
      cout << "\n";
    }
    //double *S, *V, *t;
    //const char* optionvals = "u.txt";
    //FILE *fp_init = fopen(optionvals, "r"); //Open file to read, specified by "r".


    //S = new double[N];
    //V = new double[N];
    //t = new double[10];


    //Read info from file
    //int j = 0; int k = 0;
    //int o = 0; int u = 0;
    //for (int i = 0; i < 11; i++){
      //if (i == 0){
      //  for (int j = 0; j < N; j++){
      //    fscanf(fp_init, "%lf", &[k]);
      //  }
    //  }
  //  }
    //fclose(fp_init);

    int a = 0;


    REQUIRE(a == 0);
  }
}
