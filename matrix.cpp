//
// Created by asaggu on 12/10/2022.
//

#include "matrix.h"

matrix::matrix()
{
    dim = 2;
    m = 2;
    n = 2;
    mode = 1;
    data = new double*[dim];
    for(int i = 0; i < dim; i++)
    {
        data[i] = new double [dim];
    }

    for(int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            data[i][j] = 0.0;
        }
    }
}

matrix::~matrix()
{
    for(int i = 0; i < dim; ++i)
    {
        delete [] data[i];
    }
    delete [] data;
}

matrix::matrix(int d)
{
    dim = d;
    m = d;
    n = d;
    mode = 1;
    data = new double*[dim];
    for(int i = 0; i < dim; i++)
    {
        data[i] = new double [dim];
    }

    for(int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            data[i][j] = 0.0;
        }
    }
}

matrix::matrix(int _m, int _n)
{
    m = _m;
    n = _n;
    mode = 2;
    data = new double*[m];
    for(int i = 0; i < m; i++)
    {
        data[i] = new double [n];
    }

    for(int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            data[i][j] = 0.0;
        }
    }
}

matrix::matrix(int d, double val)
{
    dim = d;
    m = d;
    n = d;
    mode = 1;
    data = new double*[dim];
    for(int i = 0; i < dim; i++)
    {
        data[i] = new double [dim];
    }

    for(int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            data[i][j] = val;
        }
    }
}

matrix::matrix(int _m, int _n, double val)
{
    m = _m;
    n = _n;
    mode = 2;
    data = new double*[m];
    for(int i = 0; i < m; i++)
    {
        data[i] = new double [n];
    }

    for(int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            data[i][j] = val;
        }
    }
}

double matrix::get_component(int x, int y)
{
    return data[x][y];
}

std::ostream &operator<<(std::ostream &output, matrix &w)
{
    output << std::setprecision (6);
    //output.precision(matrix::dbl::max_digits10);
    output << " [ " ;
    for(int i = 0; i < w.dim; i++)
    {
        output << " (" ;
        for (int j = 0; j < w.dim; j++)
        {
            output << w.data[i][j];
            if(j != w.dim - 1)
            {
                output << ", " ;
            }
        }
        output << ")";
        if(i != w.dim - 1)
        {
            output << ", " ;
        }
    }
    output << " ] " << std::endl;

    return output;
}

double& matrix::operator()(int i, int j)
{
    if (i >= dim || j >= dim)
    {
        std::cout << "Matrix subscript out of bounds" << std::endl;
    }
    return data[i][j];
}

double **matrix::getData(){return data;}
int matrix::getDIM(){return dim;}
int matrix::getM(){return m;}
int matrix::getN(){return n;}

matrix &matrix::operator=(const matrix &w)
{
    if( dim != w.dim )
    {
        std::cout << " I cannot assign vectors with different dimensionality! " << std::endl;
        exit(1);
    }
    for(int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            data[i][j] = w.data[i][j];
        }
    }
    return *this;
}
void matrix::operator*(double c)
{
    for(int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            data[i][j] = data[i][j] * c;
        }
    }
}

vectors matrix::operator*(vectors v)
{
    if(dim == 2)
    {
        double d1 = data[0][0] * v.get_component(0) + data[0][1] * v.get_component(1);
        double d2 = data[1][0] * v.get_component(0) + data[1][1] * v.get_component(1);
        vectors vt(d1,d2);
        return vt;
    }
    if(dim == 3)
    {
        double d1 = data[0][0] * v.get_component(0) + data[0][1] * v.get_component(1) + data[0][2] * v.get_component(2);
        double d2 = data[1][0] * v.get_component(0) + data[1][1] * v.get_component(1) + data[1][2] * v.get_component(2);
        double d3 = data[2][0] * v.get_component(0) + data[2][1] * v.get_component(1) + data[2][2] * v.get_component(2);
        vectors vt(d1,d2,d3);
        return vt;
    }
    else
    {
        std::cout << " I cant multiply with wrong dimensionality! " << std::endl;
        exit(1);
    }
}
matrix matrix::operator&(vectors v)
{
    if(dim == 2)
    {
        matrix mt(1,2);
        mt(0,0) = data[0][0] * v.get_component(0) + data[0][1] * v.get_component(1);
        mt(0,1) = data[1][0] * v.get_component(0) + data[1][1] * v.get_component(1);
        return mt;
    }
    if(dim == 3)
    {
        matrix mt(1,3);
        mt(0,0) = data[0][0] * v.get_component(0) + data[0][1] * v.get_component(1) + data[0][2] * v.get_component(2);
        mt(0,1) = data[1][0] * v.get_component(0) + data[1][1] * v.get_component(1) + data[1][2] * v.get_component(2);
        mt(0,2) = data[2][0] * v.get_component(0) + data[2][1] * v.get_component(1) + data[2][2] * v.get_component(2);
        return mt;
    }
    else
    {
        std::cout << " I cant multiply with wrong dimensionality! " << std::endl;
        exit(1);
    }
}

double matrix::det()
{
    if(dim == 2)
    {
        double d1 = data[0][0] * data[1][1];
        double d2 = data[1][0] * data[0][1];
        double d0 = d1 - d2;
        if (d0==0)
        {
            std::cout << " The matrix is singular and the system of equations may not have any solution! " << std::endl;
            exit(1);
        } else{ return d0;}
    }
    if(dim == 3)
    {
        double d1 = data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]);
        double d2 = data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]);
        double d3 = data[0][2] * (data[1][0] * data[2][1] - data[2][0] * data[1][1]);

        double d0 = d1 - d2 + d3;

        if (d0==0)
        {
            std::cout << " The matrix is singular and the system of equations may not have any solution! " << std::endl;
            exit(1);
        }else{ return d0;}
    }
    else
    {
        std::cout << " I cant det with wrong dimensionality! " << std::endl;
        exit(1);
    }
}

matrix matrix::invert()
{
    if(dim == 2)
    {
        matrix mt(2);
        mt(0,0) = data[1][1];
        mt(0,1) = -data[0][1];
        mt(1,0) = -data[1][0];
        mt(1,1) = data[0][0];
        mt * (1.0/(mt.det()));
        return mt;
    }
    if(dim == 3)
    {
        matrix mt(3);
        mt(0,0) = data[0][0] * data[0][0] - data[0][0] * data[0][0];
        mt(0,1) = data[0][0] * data[0][0] - data[0][0] * data[0][0];
        mt(0,2) = data[0][0] * data[0][0] - data[0][0] * data[0][0];
        mt(1,0) = data[0][0] * data[0][0] - data[0][0] * data[0][0];
        mt(1,1) = data[0][0] * data[0][0] - data[0][0] * data[0][0];
        mt(1,2) = data[0][0] * data[0][0] - data[0][0] * data[0][0];
        mt(2,0) = data[0][0] * data[0][0] - data[0][0] * data[0][0];
        mt(2,1) = data[0][0] * data[0][0] - data[0][0] * data[0][0];
        mt(2,2) = data[0][0] * data[0][0] - data[0][0] * data[0][0];

        return m;
    }
    else
    {
        std::cout << " I cant invert with wrong dimensionality! " << std::endl;
        exit(1);
    }
}


