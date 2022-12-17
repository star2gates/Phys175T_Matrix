# Phys175T_Matrix
Doing matrix math using C++.

### Introduction
There are lots of functions in this code. There are also some that are not working correctly. This code can handle matrix from size 2 by 2 and  3 by 3[^1]. It can take a system of 2 or 3 equations of the same number of variables and solve it to get the solution.


## Important Functions
From the **vectors** class

~~~~c++
    vectors(int);
    vectors(int, double); 
    vectors(double, double);
    vectors(double, double, double);
    double& operator[](int i);
~~~~
From the **matrix** class
~~~~c++
    matrix(int);
    matrix& operator=(const matrix&);
    void multiplyByVector(vectors &, vectors &ab);
    double& operator()(int, int);
    double det();
    void invert();
    friend std::ostream& operator<<(std::ostream& output, matrix& w);
~~~~

## How to use the vector class
To create a vector with 2 components use
~~~~c++
vectors v(2);
~~~~

Then to assign it values use the operator []
~~~~c++
v[0] = 1.1;
v[1] = 2.2;
~~~~

> you can also use the overloaded constructor if you want the code to be more concise
~~~~c++
vectors v(input1,  input2);
~~~~

A vector of 3 components can be made but it won't be usefull since the 3 by  3 matrix is not functioning yet.


## How to use the matrix class

To create a 2 by 2 matrix use the constructor like
~~~~c++
matrix m(2);
~~~~

Then to assign it values use the overloaded operator **()**
~~~~c++
m(0, 0) = input_a;
m(0, 1) = input_b;
m(1, 0) = input_c;
m(1, 1) = input_d;
~~~~

To get the determinant of the matrix you use **det()**, it returns a double so it can be put in to an variable if needed.
~~~~c++
m.det();
double detVal = m.det();
~~~~
To invert the matrix you use **invert()**
~~~~c++
m.invert();
~~~~
To multiply the matrix by a vector you need two vectors and the function **multiplyByVector()**, like this
~~~~c++
vectors xy(2);  // vector for the solution
m.multiplyByVector(v,xy);
~~~~
Now you solution is in the xy vector.

### Printing the vectors
So at any time the vectors and matrix can be printed using the overloaded **<<**
~~~~c++
// print matrix out  
std::cout << " m = " << m << std::endl;  
// print out the vector  
std::cout << " v = " << v << std::endl;
// print out the solution vector  
std::cout << " xy = " << xy << std::endl;
~~~~

That's is for the basic functioning of the classes. There is a lot more in the classes but they are not used directly in this context. For any questions you can create a new issue under the issue tab on GitHub.

# Here is an example
~~~~c++
void test()
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
    //v.id=1;

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
    //xy.id=2;
    m.multiplyByVector(v,xy);
    std::cout << " xy = " << xy << std::endl;
}
~~~~

[^1]: 3 by 3 is not working yet.

> Written with [StackEdit](https://stackedit.io/).