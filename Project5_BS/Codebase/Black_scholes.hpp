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
      double m_h;
      double m_dt;
      int m_N;
      double m_alpha;
      string m_filename;
      double m_T;
      vec m_S;
      double m_a;
      double m_b;
      vec m_x ;
      vec m_utilde;
      vec m_uPrev;
    public:
      void Initialize(double T,double X, int N,string filename,
                      double r, double D, double sigma, double E);
      void D1d_explicit();
      void calc_utilde();
      void print_vals(vec u, double t);
      void init_print();
      void Crank_Nic();
      vec transform_u_V(vec u,double t);
      vec Tridiag();
};

#endif // ISING_MCINT
