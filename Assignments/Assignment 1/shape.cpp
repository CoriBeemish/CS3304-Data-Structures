// FILE: shape.cpp
// AUTHOR: Cori Beemish
// DATE: 06/02/2017

#include <iostream>
#include <cmath>
#include <cassert>   // Provides assert function

double triangleArea(int length)
{
    assert (length > 0 && length <= 6);
    double triangle_area = (pow(length, 2) * sqrt(3)) / 4 ;
    return triangle_area;
}

double squareArea(int length)
{
    assert (length > 0 && length <= 6);
    double square_area = pow(length, 2);
    return square_area;
}

double pentagonArea(int length)
{
    assert (length > 0 && length <= 6);
    double pentagon_area = pow(length, 2) * 1.7204 ;
    return pentagon_area;
}

double hexagonArea(int length)
{
    assert (length > 0 && length <= 6);
    double hexagon_area = pow(length, 2) * 2.5981;
    return hexagon_area;
}

double heptagonArea(int length)
{
    assert (length > 0 && length <= 6);
    double heptagon_perimeter = length * 7;
    double heptagon_apothem = length * 1.03;
    double heptagon_area = heptagon_perimeter * heptagon_apothem * 0.500;
    return heptagon_area;
}

double octagonArea(int length)
{
    assert (length > 0 && length <= 6);
    double octagon_area = pow(length,2) * 4.828;
    return octagon_area;
}
