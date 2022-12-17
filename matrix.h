//
// Created by asaggu on 12/10/2022.
//

#ifndef PHYS175T_MATRIX_MATRIX_H
#define PHYS175T_MATRIX_MATRIX_H

#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include <limits>
#include "vectors.h"

class matrix
{
protected:
    int dim, m, n;
    int mode = 0;
    double **data;
    //double (*f)(double);
public:
    typedef std::numeric_limits<double> dbl;

    //default constructor
    matrix();
    //constructor with one integer parameter: the dimensionality
    matrix(int);
    //constructor with two integer parameter: the dimensionality
    matrix(int, int);
    //constructor with dimensionality and one value
    matrix(int, double);
    //constructor with m*n dimensionality and one value
    matrix(int, int, double);
    //destructor
    ~matrix();
    //typical methods
    double get_component(int, int);

    //assignment operator
    matrix& operator=(const matrix&);
    //multiplication by a number
    void operator*(double c);
    //multiplication by a vector return
    vectors operator*(vectors);
    matrix operator&(vectors);
    //to access and change components
    double& operator()(int, int);

    //calculate and return determinant or exit if singular
    double det();
    //invert the matrix
    matrix invert();

    // get object members
    double** getData();
    int getDIM();
    int getM();
    int getN();


    friend std::ostream& operator<<(std::ostream& output, matrix & w);

};


#endif //PHYS175T_MATRIX_MATRIX_H
