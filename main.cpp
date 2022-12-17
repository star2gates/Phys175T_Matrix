#include <iostream>
#include "matrix.h"

void test1();

int main()
{
    std::cout << "Hello, World! Time for some matrix math!" << std::endl;
    std::cout << std::setprecision (6);

    test1();

    return 0;
}

void test1()
{
    // create matrix of 2*2 matrix
    matrix m(2);

    /*
     * using the coefficients form these 2 system
     * of equations
     * */
    m(0, 0) = 5.0;
    m(0, 1) = -3.0;
    m(1, 0) = 2.0;
    m(1, 1) = -1.0;

    // print matrix out
    std::cout << " m = " << m << std::endl;

    /*
     * now to create the "column" vector to
     * hold the alpha and beta of the system of equations
     * */
    vectors v(-1.0,2.0);

    // print out the vector
    std::cout << " v = " << v << std::endl;

    std::cout << "\n now det m = " << m.det() << std::endl;

    // invert the matrix
    std::cout << " dim of m = " << m.getDIM() << std::endl;
    m.invert();
    std::cout << " inverted m = " << m << std::endl;

    // multiply by vector of alpha and beta to get solutions
    vectors xy(2);
    m.multiplyByVector(v,xy);
    std::cout << " xy = " << xy << std::endl;
}