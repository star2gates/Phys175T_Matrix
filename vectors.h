//
// Created by asaggu on 12/6/2022.
//

#ifndef PHYS175T_NEWVECTORS_VECTORS_H
#define PHYS175T_NEWVECTORS_VECTORS_H


#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include <limits>

using namespace std;

class vectors
{
protected:
    int dim;
    double* data;
    double (*f)(double);
    bool deleted = false;
public:
    int id=0;
    //default constructor
    vectors();
    //constructor with one integer parameter: the dimensionality
    vectors(int);
    //constructor with dimensionality and one value
    vectors(int, double);
    vectors(double, double);
    vectors(double, double, double);
    vectors(double (*fun)(double), int);
    vectors(double (*fun)(double), int d, double val);
    vectors(double (*fun)(double), double, double);
    vectors(double (*fun)(double), double, double, double);
    //destructor
    ~vectors();
    //typical methods
    double get_component(int);


    //assignment operator
    vectors& operator=(const vectors&);
    //multiplication by a number
    vectors operator*(double c);
    //sum by a vector
    vectors operator+(const vectors&);
    //to access and change components
    double& operator[](int i);

    vectors operator-(const vectors&);

    double dotProduct(const vectors&);
    double operator&(const vectors&);

    vectors crossProduct(const vectors&);
    vectors operator*(const vectors &);

    void operator+=(double in);
    void operator+=(const vectors &);

    void operator-=(double in);
    void operator-=(const vectors &);

    double* getData();

    int getDIM();

    void setFunction(double (*fun)(double));
    void applyFunction();

    void bubble_sort();
    void bubble_sort(int mode);

    friend std::ostream& operator<<(std::ostream& output, vectors& w);
};



#endif //PHYS175T_NEWVECTORS_VECTORS_H
