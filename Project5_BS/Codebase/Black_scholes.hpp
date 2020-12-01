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
      mat m_Amtrx;
      mat m_u;
      double m_h;
      double m_dt;
      vec m_V;
      int m_N;
      double m_alpha;
    public:
      void Initialize(double T,double X, int N);
      void D1d_explicit();
};

#endif // ISING_MCINT
