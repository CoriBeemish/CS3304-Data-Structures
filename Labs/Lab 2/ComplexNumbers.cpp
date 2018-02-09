// FILE: complexNumbers.cpp
// AUTHOR: Cori Beemish
// DATE: 06/02/2017

#include "complexNumbers.h"

#include <iostream>
#include <cassert>
#include <cmath>

complex::complex (double real, double imag)
{
    realNum = real;
    imagNum = imag;
}

double complex::get_real() const
{
    return realNum;
}

double complex::get_imag() const
{
    return imagNum;
}

complex operator + (const complex& c1, const complex& c2)
{
  double real = c1.get_real() + c2.get_real();
  double imag = c1.get_imag() + c2.get_imag();
  //std::cout << "The sum is:          " << real << " + " << imag << "i" << std::endl; //CHECKING
  return complex (real, imag);
}

complex operator - (const complex& c1, const complex& c2)
{
  double real = c1.get_real() - c2.get_real();
  double imag = c1.get_imag() - c2.get_imag();
  //std::cout << "The difference is:  " << real << " + " << imag << "i." << std::endl; //CHECKING
  return complex (real, imag);
}

complex operator * (const complex& c1, const complex& c2)
{
  double real = (c1.get_real() * c2.get_real()) - (c1.get_imag() * c2.get_imag()) ;
  double imag = (c1.get_real() * c2.get_real()) + (c1.get_imag() * c2.get_imag());
  //std::cout << "The product is:     " << real << " + " << imag << "i." << std::endl; //CHECKING
  return complex (real, imag);
}

complex operator / (const complex& c1, const complex& c2)
{
  assert (c1.get_real() != 0 || c1.get_imag() != 0);

  double real = (c1.get_real() * c2.get_real()) + (c1.get_imag() * c2.get_imag()) ;
  double imag = c2.get_real() * c1.get_imag() - c1.get_real() * c2.get_imag() ;
  double denom = c2.get_real() * c2.get_real() + c2.get_imag() * c2.get_imag() ;

  //std::cout << "The quotient is:    " << real/denom << " + " << imag/denom << "i." << std::endl; //CHECKING
  return complex (real/denom, imag/denom);
}
