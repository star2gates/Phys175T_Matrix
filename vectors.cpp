//
// Created by asaggu on 12/6/2022.
//

#include <algorithm>
#include "vectors.h"

vectors::vectors()
{
    dim = 1;
    data = new double[dim];
    data[0] = 0.0;
}

vectors::vectors(int d)
{
    dim = d;
    data = new double[dim];
    for(int i=0; i<dim; i++)
    {
        data[i] = 0.0;
    }
}

vectors::vectors(int d, double val)
{
    dim = d;
    data = new double[dim];
    for(int i=0; i<dim; i++)
    {
        data[i] = val;
    }
}

vectors::vectors(double x, double y)
{
    dim = 2;
    data = new double[dim];
    data[0] = x;
    data[1] = y;
}

vectors::vectors(double x, double y, double z)
{
    dim = 3;
    data = new double[dim];
    data[0] = x;
    data[1] = y;
    data[2] = z;
}

vectors::vectors(double (*fun)(double), int d)
{
    dim = d;
    data = new double[dim];
    f = fun;
    for(int i=0; i<dim; i++)
    {
        data[i] = 0.0;
    }
}

vectors::vectors(double (*fun)(double), int d, double val)
{
    dim = d;
    data = new double[dim];
    for(int i=0; i<dim; i++)
    {
        data[i] = val;
    }
}

vectors::vectors(double (*fun)(double), double x, double y, double z)
{
    dim = 3;
    data = new double[dim];
    f = fun;
    data[0] = x;
    data[1] = y;
    data[2] = z;
}

 void vectors::setFunction(double (*fun)(double))
{
    f = fun;
}

vectors::~vectors()
{
    if(deleted)
    {
        //cout << "Hi, garbage already collected ... vector id = " << id << endl;
        exit(2);

    } else{
        //cout << "Hi, collecting garbage ... vector id = " << id << endl;
        delete[] data;
    }

}

double vectors::get_component(int i)
{
    if(i < 0 || i >= dim)
    {
        cout << " Sorry, out of range " << endl;
        return -1;
        //exit(1);
    }
    else
    {
        return data[i];
    }

}

double *vectors::getData()
{
    return data;
}
int vectors::getDIM()
{
    return dim;
}

vectors vectors::operator*(double c)
{
    vectors output(dim);

    for(int i=0; i<dim; i++)
    {
        output[i] = data[i] * c;
    }

    return output;
}

vectors vectors::operator+(const vectors& w)
{
    if( dim != w.dim )
    {
        cout << " I cannot sum vectors with different dimensionality! " << endl;
        exit(1);
    }

    vectors output(dim);

    for(int i=0; i<dim; i++)
    {
        output[i] = data[i] + w.data[i];
    }

    return output;
}

double& vectors::operator[](int i)
{
    return data[i];
}

vectors& vectors::operator=(const vectors& w)
{
    if( dim != w.dim )
    {
        cout << " I cannot assign vectors with different dimensionality! " << endl;
        exit(1);
    }
    for(int i=0; i<dim; i++)
    {
        data[i] = w.data[i];
    }

    // I cant believe I forgot this for the last assignment
    dim = w.dim;
    f = w.f;

    return *this;
}


std::ostream& operator<<(std::ostream& output, vectors& w)
{
    output << " [ " ;
    for(int i=0; i<w.dim-1; i++)
    {
        output << w.data[i] << " , " ;
    }
    output << w.data[w.dim-1] << " ] " ;

    return output;
}

vectors vectors::operator-(const vectors &w)
{
    if( dim != w.dim )
    {
        cout << " I cannot sub vectors with different dimensionality! " << endl;
        exit(1);
    }

    vectors output(dim);

    for(int i=0; i<dim; i++)
    {
        output[i] = data[i] - w.data[i];
    }

    return output;
}

double vectors::dotProduct(const vectors& w)
{
    if( dim != w.dim )
    {
        cout << " I cannot dot product vectors with different dimensionality! " << endl;
        exit(1);
    }

    double s = 0.0;

    for(int i=0; i<3; ++i)
    {
        s = s + data[i]*w.data[i];
    }

    return s;
}

double vectors::operator&(const vectors &w)
{
    if( dim != w.dim )
    {
        cout << " I cannot dot product vectors with different dimensionality! " << endl;
        exit(1);
    }

    double s = 0.0;

    for(int i=0; i<3; ++i)
    {
        s = s + data[i]*w.data[i];
    }

    return s;
}

vectors vectors::crossProduct(const vectors &w)
{
    if( dim != w.dim )
    {
        cout << " I cannot cross product vectors with different dimensionality! " << endl;
        exit(1);
    }

    vectors C(3);
    double cx, cy, cz;

    cx = data[1]*w.data[2] - data[2]*w.data[1];
    cy = data[2]*w.data[0] - data[0]*w.data[2];
    cz = data[0]*w.data[1] - data[1]*w.data[0];


    C[0] = cx;
    C[1] = cy;
    C[2] = cz;

    return C;
}

vectors vectors::operator*(const vectors &w)
{
    if( dim != w.dim )
    {
        cout << " I cannot cross product vectors with different dimensionality! " << endl;
        exit(1);
    }

    vectors C(3);
    double cx, cy, cz;

    cx = data[1]*w.data[2] - data[2]*w.data[1];
    cy = data[2]*w.data[0] - data[0]*w.data[2];
    cz = data[0]*w.data[1] - data[1]*w.data[0];

    C[0] = cx;
    C[1] = cy;
    C[2] = cz;

    return C;
}

void vectors::operator+=(double in)
{
    for(int i=0; i<dim; i++)
    {
        data[i] = data[i] + in;
    }
}

void vectors::operator+=(const vectors &w)
{
    if( dim != w.dim )
    {
        cout << " I cannot sum vectors with different dimensionality! " << endl;
        exit(1);
    }

    //vectors output(dim);

    for(int i=0; i<dim; i++)
    {
        data[i] = data[i] + w.data[i];
    }
}

void vectors::operator-=(double in)
{
    for(int i=0; i<dim; i++)
    {
        data[i] = data[i] + in;
    }
}

void vectors::operator-=(const vectors &w)
{
    if( dim != w.dim )
    {
        cout << " I cannot sub vectors with different dimensionality! " << endl;
        exit(1);
    }

    for(int i=0; i<dim; i++)
    {
        data[i] = data[i] + w.data[i];
    }
}

void vectors::bubble_sort(int mode)
{
    double temp;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j + 1 < dim - i; j++)
        {
            switch (mode)
            {
                case 1:
                    if (data[j] > data[j + 1])
                    {
                        temp = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = temp;
                    }
                    break;
                case 2:
                    if (data[j] < data[j + 1])
                    {
                        temp = data[j+1];
                        data[j+1] = data[j];
                        data[j] = temp;
                    }
                    break;
                default:
                    cout<<"INVALID INPUT";
                    break;
            }
        }
    }
}

void vectors::bubble_sort()
{
    size_t len = sizeof(data)/sizeof(data[0]);
    double temp;
    cout << " dim = " <<  len << endl;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j + 1 < dim - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void vectors::applyFunction()
{
    for(int i=0; i<dim; i++)
    {
        data[i] = f(data[i]);
    }
}

vectors::vectors(double (*fun)(double), double, double)
{

}







