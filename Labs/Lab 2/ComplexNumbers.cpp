//FILE: complexNumbers.cpp

#include "ComplexNumbers.h"
#include <cassert>
#include <cstdlib>

//https://www.mathsisfun.com/numbers/complex-numbers.html

int rational::get_real() const
{
  return real;
}

int rational::get_imag() const
{
  return imag;
}

complex operator + (const complex& c1, const complex& c2)
{
  int r = c1.get_real() + c2.get_real();
  int i = c1.get_imag() + c2.get_imag();
  return complex (r, i);
}

complex operator - (const complex& c1, const complex& c2)
{
  int r = c1.get_real() - c2.get_real();
  int i = c1.get_imag() - c2.get_imag();
  return complex (r, i);
}

complex operator * (const complex& c1, const complex& c2)
{
  double part1 = (c1.get_real() * c2.get_real()) + (c1.get_imag() * c2.get_imag());
  double part2 =
  int r =  ;
  int i = c1.get_imag() * c2.get_imag();
  return complex (r, i);
}
complex operator / (const complex& c1, const complex& c2)
{
  assert (c2.get_num() != 0);
  int r = c1.get_num() * c2.get_denom();
  int i = c1.get_denom() * c2.get_num();
  return complex (r, i);
}
