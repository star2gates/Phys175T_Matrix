#include <iostream>
#include "matrix.h"

void test1();
void test2();

int main()
{
    std::cout << "Hello, World! Time for some matrix math!" << std::endl;
    std::cout << std::setprecision (6);

    test1();
    std::cout << std::endl;
    test2();

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
    //v.id=1;

    // print out the vector
    std::cout << " v = " << v << std::endl;

    // do the determinant
    std::cout << "\n determinant m = " << m.det() << std::endl;

    // invert the matrix
    m.invert();
    std::cout << " inverted m = " << m << std::endl;

    // multiply by vector of alpha and beta to get solutions
    vectors xy(2);
    //xy.id=2;
    //xy = m*v; //broken
    m.multiplyByVector(v,xy);
    std::cout << " xy = " << xy << std::endl;
}

void test2()
{
    // create matrix of 2*2 matrix
    matrix m(2);

    double a ,b ,c ,d , alpha , beta ;
    std::cout << " Please enter your a value : " << std::endl;
    std::cin >> a;
    std::cout << " Please enter your b value : " << std::endl;
    std::cin >> b;
    std::cout << " Please enter your c value : " << std::endl;
    std::cin >> c;
    std::cout << " Please enter your d value : " << std::endl;
    std::cin >> d;
    std::cout << " Please enter your alpha value : " << std::endl;
    std::cin >> alpha;
    std::cout << " Please enter your beta value : " << std::endl;
    std::cin >> beta;

    // put values in the matrix and vector
    m(0, 0) = a;
    m(0, 1) = b;
    m(1, 0) = c;
    m(1, 1) = d;
    vectors v(alpha,beta);
    v.id=1;

    // print matrix out
    std::cout << " m = " << m << std::endl;
    // print out the vector
    std::cout << " v = " << v << std::endl;

    // do the determinant
    std::cout << "\n determinant m = " << m.det() << std::endl;

    // invert the matrix
    m.invert();
    std::cout << " inverted m = " << m << std::endl;

    // multiply by vector to get solutions
    vectors xy(2);
    xy.id=2;
    m.multiplyByVector(v,xy);
    std::cout << " xy = " << xy << std::endl;
}
