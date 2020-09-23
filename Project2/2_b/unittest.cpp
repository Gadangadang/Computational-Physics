#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
//#include "classtuff.cpp"
#include "classtuff.hpp"
#include "armadillo"
using namespace arma ;


mat A = zeros<mat>(3,3);
classtuff test_obj ;

mat Atest = test_obj.Initialize(3,A);
test_obj.offdiag(Atest, p,q,n,maxoff);

TEST_CASE( "Check for errors in code" ) {

  SECTION("Finding max value of matrix"){
    REQUIRE( test_obj.maxoff == 1 );
  }

  SECTION("Finding eigenvalues for matrix"){

    vec test_eigvals = test_obj.Jacobi_arm(Atest);
    mat qen = test_obj.Jacobi(Atest,1e-16);

    REQUIRE( fabs(accu(sort(test_eigvals) - sort(qen.diag()))) < 1e-3 );
  }

}
