#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
//#include "classtuff.cpp"
#include "classtuff.hpp"
#include "armadillo"
using namespace arma ;

inline void offfdiag(mat A, int &p, int &q, int n, double &maxoff){
  maxoff=0;
  for(int i = 0; i<n; ++i){
    for(int j = 0;  j < n; ++j){
            double aij = fabs(A(i, j));
            if(aij > maxoff && i !=j){
              maxoff = aij; p = i; q = j;
      }
    }
  }
}



TEST_CASE( "Check for errors in code" ) {
  int p,q;
  double maxoff;

  mat A = zeros<mat>(3,3);
  classtuff test_obj ;

  mat Atest = test_obj.Initialize(3,A);
  offfdiag(Atest, p,q,3,maxoff);

  SECTION("Finding max value of matrix"){
    REQUIRE( maxoff == 1 );
  }

  vec test_eigvals = test_obj.Jacobi_arm(Atest);
  mat qen = test_obj.Jacobi(Atest,1e-16);

  SECTION("Finding eigenvalues for matrix"){
    REQUIRE( fabs(accu(sort(test_eigvals) - sort(qen.diag()))) < 1e-3 );
  }

}
