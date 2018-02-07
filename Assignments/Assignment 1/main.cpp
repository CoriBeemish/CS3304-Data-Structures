// FILE: main.cpp
// AUTHOR: Cori Beemish
// DATE: 07/02/2017

#include "shape.cpp"

int main()
{
    std::cout << "The area of an equilateral triangle with length of side: " << std::endl;
    for(int a = 1; a < 7; a++)
    {
        std::cout << a << ": " << triangleArea(a) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "The area of an square with length of side: " << std::endl;
    for(int a = 1; a < 7; a++)
    {
        std::cout << a << ": " << squareArea(a) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "The area of an regular pentagon with length of side: \n" << std::endl;
    for(int a = 1; a < 7; a++)
    {
        std::cout << a << ": " << pentagonArea(a) << std::endl;
    }
    std::cout << std::endl;


    std::cout << "The area of an regular hexagon with length of side: " << std::endl;
    for(int a = 1; a < 7; a++)
    {
        std::cout << a << ": " << hexagonArea(a) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "The area of an regular heptagon with length of side: " << std::endl;
    for(int a = 1; a < 7; a++)
    {
        std::cout << a << ": " << heptagonArea(a) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "The area of an regular octagon with length of side: " << std::endl;
    for(int a = 1; a < 7; a++)
    {
        std::cout << a << ": " << octagonArea(a) << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
