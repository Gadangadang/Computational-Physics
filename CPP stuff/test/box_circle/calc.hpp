#ifndef CALC_HPP
#define CALC_HPP


class calc {
private:
  double m_a, m_b, m_c;
  double m_area1, m_area2;


public:
  void Initialize(double a, double b, double c);
  void find();
  void Print();

};

#endif
