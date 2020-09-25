#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
//#include "classtuff.cpp"
#include "classtuff.hpp"
#include "armadillo"
using namespace arma ;
double V(double x){return 0;}
TEST_CASE( "Check for errors in code" ) {
  int p,q;
  double maxoff;

  mat A = zeros<mat>(3,3);
  classtuff test_obj ;
  double a = 0;
  double b = 1;
  int c_size = 3; 
  mat Atest = test_obj.Initialize(a, b, V, c_size);
  test_obj.offdiag(Atest, p,q,3,maxoff);

  SECTION("Finding max value of matrix"){
    REQUIRE( maxoff == 16 );
  }
  vec test_eigvals = test_obj.Jacobi_arm(Atest);
  mat qen = test_obj.Jacobi(Atest, 1e-16, c_size);

  SECTION("Finding eigenvalues for matrix"){
    REQUIRE( fabs(accu(sort(test_eigvals) - sort(qen.diag()))) < 1e-3 );
  }
  
  SECTION("CHECK ORTHOGONALITY OF EIGENVECTORS"){
    REQUIRE(fabs(accu(test_obj.S*test_obj.S.t()-A.eye()))<1e-6);
  }
}
