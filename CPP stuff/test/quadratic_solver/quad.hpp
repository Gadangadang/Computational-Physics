#ifndef QUAD_HPP
#define QUAD_HPP


class quad {
private:
  double m_a, m_b, m_c;
  double m_root1, m_root2;


public:
  void Initialize(double a, double b, double c);
  void find();
  void Print();

};

#endif
