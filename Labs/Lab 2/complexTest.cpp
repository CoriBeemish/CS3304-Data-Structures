//FILE: complexTest.cpp

#include "complexNumbers.h"

#include <iostream>
#include <cassert>
#include <cmath>

int main(int argc, char **argv)
{
    complex c1 (3, 2);
    assert (c1.get_real() == 3);
    assert (c1.get_imag() == 2);

    complex c2 (-4, 3);

    //SUM
    complex c3 = c1 + c2;
    assert (c3.get_real() == -1);
    assert (c3.get_imag() == 5);

    //DIFFERENCE
    complex c4 = c1 - c2;
    assert (c4.get_real() == 7);
    assert (c4.get_imag() == -1);

    //PRODUCT
    complex c5 = c1 * c2;
    assert (c5.get_real() == -18);
    assert (c5.get_imag() == -6);

    //QUOTIENT
    complex c6 = c1/ c2;
    assert (c6.get_real() == -6/25.0);
    assert (c6.get_imag() == -17/25.0);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
