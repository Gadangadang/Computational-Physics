#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
//#include "classtuff.cpp"
#include "classtuff.hpp"
#include "armadillo"
using namespace arma ;

TEST_CASE( "Check for errors in code" ) {
  int p,q;
  double maxoff;

  mat A = zeros<mat>(3,3);
  classtuff test_obj ;

  mat Atest = test_obj.Initialize(3,A);
  test_obj.offdiag(Atest, p,q,3,maxoff);

  SECTION("Finding max value of matrix"){
    REQUIRE( maxoff == 1 );
  }

  vec test_eigvals = test_obj.Jacobi_arm(Atest);
  mat qen = test_obj.Jacobi(Atest,1e-16);

  SECTION("Finding eigenvalues for matrix"){
    REQUIRE( fabs(accu(sort(test_eigvals) - sort(qen.diag()))) < 1e-3 );
  }
  SECTION("CHECK ORTHOGONALITY OF EIGENVECTORS"){
    REQUIRE(fabs(accu(test_obj.S*test_obj.S.t()-A.eye()))<1e-6);
  }

}
