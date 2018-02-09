// FILE: ComplexNumbers.h
// AUTHOR: Main & Savitch

#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

class complex
{
    public:
      complex (double real, double imag);

      double get_real() const;
      //POSTCONDITION: The real number part of the complex number has been returned.
      double get_imag() const;
      //POSTCONDITION: The imaginary number part of the complex number has been returned.

    private:
      double realNum;
      double imagNum;
};

complex operator + (const complex& c1, const complex& c2);
    //POSTCONDITION: The sum of c1 & c2 has been returned.

complex operator - (const complex& c1, const complex& c2);
    //POSTCONDITION: The difference of c1 & c2 has been returned.

complex operator * (const complex& c1, const complex& c2);
    //POSTCONDITION: The product of c1 & c2 has been returned.

complex operator / (const complex& c1, const complex& c2);
    //POSTCONDITION: The quotient of c1 & c2 has been returned.

#endif // COMPLEX_H_INCLUDED

