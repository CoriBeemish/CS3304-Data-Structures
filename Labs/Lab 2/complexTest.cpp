//FILE: complexTest.cpp

#include "complexNumbers.h"

#include <iostream>
#include <cassert>

int main(int argc, char **argv)
{
  complex c1 (-5, -8);
  complex c2 (2, 8);
  complex c3 = c1 + c2;
  assert (c3.get_real() == 7);
  assert (c3.get_imag() == 8);

  complex c4 = c1 - c2;
  assert (c4.get_real() == 3);
  assert (c4.get_imag() == 8);

  complex c5 = c1 * c2;
  assert (c5.get_real() == 5);
  assert (c5.get_imag() == 32);

  complex c6 = c1 / c2;
  assert (c6.get_real() == 5);
  assert (c6.get_imag() == 2);

  std::cout << "passed all tests" << std::endl;
  return 0;
}
