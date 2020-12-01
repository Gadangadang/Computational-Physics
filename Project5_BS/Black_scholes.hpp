#ifndef SOLVER_HPP
#define SOLVER_HPP
#define _USE_MATH_DEFINES
#include <cmath>
#include "armadillo"
#include <string>

using namespace arma;
using namespace std;

class Black_scholes
{
    private:
      mat m_matrix;
      double m_h;
      double m_dt;
      vec m_b;
    public:
      void Initialize(double T,double X, int N)
};

#endif // ISING_MCINT
