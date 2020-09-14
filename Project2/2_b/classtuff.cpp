#include "quad.hpp"
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

using namespace std;
using namespace arma;

void classtuff::Initialize(double a, mat ex){
  c_size = a;
  A = ex;
  
  mat S = zeros<mat>(c_size,c_size);


}
