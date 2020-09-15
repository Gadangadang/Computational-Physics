#ifndef CLASSTUFF_HPP
#define CLASSTUFF_HPP


class quad {
private:
  int c_size;
  mat A;
  mat S;
  int eps = 1.0e-8;
  double max_iterations = (double) c_size * (double) c_size * (double) c_size;
  

public:
  void Initialize(double a, mat ex);
  void Rotate();
  void Jacobi();

};

#endif
