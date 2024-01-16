#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

#include "VectorClass.h"

using namespace std

template <class T>
void PrintVector(vector<T> inputVector)
{
    int nRows = inputVector.GetNumDims();
    for (int row = 0 ; i < nRows ; ++i)
    {
        // IO manip functions
        std::cout << std::fixed << std::setprecision(3) << inputVector.GetElement(row) << endl;
    }
}

int main()
{
    cout << "Code to test Vector class" << endl;

    //Create a vector class object
    std::vector(double) Data = {1.0, 2.0, 3.0};
    vector<double> vector1(Data);
    cout << "Initial test vector with data: " << endl;
    PrintVector(vector1);
    cout << endl;

    cout << "Test basic vector arithmetic" << endl;
    cout << "Vector A + Vector B" << endl;
    vector<double> vector2(std::vector(double) {4.0, 5.0, 6.0});
    vector<double> vector3 = vector1 + vector2;
    PrintVector(vector3);


    cout << "Vector A - Vector B" << endl;
    vector<double> vector4 = vector1 - vector2;
    PrintVector(vector4);


    cout << "Vector A * constant" << endl;
    vector<double> vector5 = vector1 * 2;
    PrintVector(vector5);


    cout << "constant * Vector A" << endl;
    vector<double> vector6 = 2 * vector1;
    PrintVector(vector6);


    cout << "Test dot product" << endl;
    // Tell the code the function "dot" is from the vector<double> class
    double dotProduct = vector<double>::dot(vector1, vector2);
    cout << std:fixed << std:setprecision(3) << dotProduct << endl;


    cout << "Test cross product" << endl;
    vector<double> crossVector = vector<double>::cross(vector1, vector2);
    PrintVector(crossVector);


    cout << "Test Hadamard product" << endl;
    vector<double> vector7 = vector<double>::hadamard(vector1, vector2);
    PrintVector(vector7);


    cout << "Test projection operator" << endl;
    // Tell the code the function "dot" is from the vector<double> class
    double HadProd = vector<double>::proj(vector1, vector2);
    cout << std:fixed << std:setprecision(3) << HadProd << endl;







}

