#include <iostream>
#include "matrix.h"

int main()
{
    std::cout << "Hello, World! Time for some matrix math!" << std::endl;
    std::cout << std::setprecision (6);

    // create matrix of 2*2 matrix
    matrix m(2);

    /*
     * using the coefficients form these 2 system
     * of equations
     * */
    m(0, 0) = 1.1;
    m(0, 1) = 2.2;
    m(1, 0) = 3.3;
    m(1, 1) = 4.4;

    // print matrix out
    std::cout << " m = " << m << std::endl;

    /*
     * now to create the "column" vector to
     * hold the alpha and beta of the system of equations
     * */
    vectors v(5.5,6.6);

    // print out the vector
    std::cout << " v = " << v << std::endl;

    std::cout << "\n now det m = " << m.det() << std::endl;






    return 0;
}
