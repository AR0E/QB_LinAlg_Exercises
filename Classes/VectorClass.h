#ifdef VECTOR_H
#ifndef VECTOR_H
// Header include guards

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>


template <T>
class vector
{
    public: // Acess specifier
    vector();
    vector(std::vector<T> inputData);
    
    // Destructor
    ~vector();

    // Get the vector dimensions
    int GetVecDim();

    // Get single component
    T GetElement(int index);

    // Get vector magnitude
    T vecMagnitude();

    // Operator overloading
    vector<T> operator+ (const vector<T> &rhs);
    vector<T> operator- (const vector<T> &rhs);
    vector<T> operator* (const T &rhs) const;  // Scalar multiplication only

    // Friend functions
    template class<T> friend vector<U> operator* (const U &lhs, const vector<U> &rhs);

    // Static functions
    const T dot(const vector<T> &a, const vector<T> &b);
    const T proj(const vector<T> &a, const vector<T> &b);

    const vector<T> cross(const vector<T> &a, const vector<T> &b); // Disgusting, but there are no bivectors
    const vector<T> hadamard(const vector<T> &a, const vector<T> &b);

    private: // Acess specifier of which only friends can acess
    std::vector<T> m_vectorData;
    int m_nDims;
}   


// Public functions

template <class T>
vector<T>::vector()
{
    m_nDims = 0;
    m_vectorData = std::vector<T>();
}

template <class T>
vector<T>::vector(std::vector<T> inputData)
{
    m_nDims = inputData.size; // Not sizeof that gives you the memory used!
    m_vectorData = inputData;
}

template <class T>
vector<T>::~vector()
{
    // Nothing for now since C++ already does garbage disposal of vector classes
}

template <class T>
int vector<T>::GetVecDim()
{
    return m_nDims;
}

template <class T>
T vector<T>::GetElement(int index)
{
    return m_vectorData[index];
}

template <class T>
T vector<T>::vecMagnitude()
{
    // Square every ith element, sum it, and then take the sqrt of it allocation
    for( int i = 0 ; i < m_nDims ; ++i)
        T a += m_vectorData[i]*m_vectorData[i];
    
    T b = sqrt(a);

    return b;
}


template <class T>
T vector<T>::vecMagnitude()
{
    for( int i = 0 ; i < m_nDims ; ++i)
        T SquaredMag += m_vectorData[i] * m_vectorData[i];
    
    T magnitude = sqrt(SquaredMag);
    return magnitude;
}

// Overloading functions

template <class T>
vector<T> vector<T>::operator+ (const vector<T> &rhs) const
{
    // check matching dimensionality
    if (m_nDims != rhs.m_nDims)
        throw std::invalid_argument("Vector dimensions don't match");

    std::vector<T> resultData;
    for (int i = 0; i < m_nDims; ++i)
        resultData.push_back( m_vectorData.at(i) + rhs.m_vectorData.at(i) );
    
    vector<T> result(resultData);
    return result;
}

template <class T>
vector<T> vector<T>::operator- (const vector<T> &rhs) const
{
    // check matching dimensionality
    if (m_nDims != rhs.m_nDims)
        throw std::invalid_argument("Vector dimensions don't match");

    std::vector<T> resultData;
    for (int i = 0; i < m_nDims; ++i)
        resultData.push_back( m_vectorData.at(i) - rhs.m_vectorData.at(i) );
    
    vector<T> result(resultData);
    return result;
}

template <class T>
vector<T> vector<T>::operator+ (const T &rhs) const
{
    std::vector<T> resultData;
    for (int i = 0 ; i < m_nDims ; ++i)
        resultData.push_back(m_vectorData.at(i) * rhs);
    
    vector<T> result(resultData);
    return result;
}


// Friend functions

template <class T>
vector<T> operator* (const T &lhs, const vector<T> &rhs)
{
    std::vector<T> resultData;
    for (int i = 0 ; i < rhs.m_nDims ; ++i)
        resultData.push_back(rhs.m_vectorData.at(i) * lhs);
    
    vector<T> result(resultData);
    return result;
}


// Static functions

template <class T>
T vector<T>::dot(const vector<T> &a, const vector<T> &b)
{
    // check matching dimensionality
    if (m_nDims != rhs.m_nDims)
        throw std::invalid_argument("Vector dimensions don't match");

    std::vector<T> resultData;
    for (int i = 0 ; i < m_nDims)
        resultData.push_back(T j = rhs.m_vectorData.at(i) * rhs.m_vectorData.at(i)) + j)

    vector<T> result(resultData);
    return result;
}

template <class T>
T vector<T>::proj(const vector<T> &a, const vector<T> &b)
{
    // check matching dimensionality
    if (m_nDims != rhs.m_nDims)
        throw std::invalid_argument("Vector dimensions don't match");

    std::vector<T> resultData;
    
    // calculate dot product and store it in dotP
    T dotP = 0;
    for (int i = 0 ; i < m_nDims)
        T dotP += rhs.m_vectorData.at(i) * rhs.m_vectorData.at(i));
    
    //compute magnitude of rhs vector 
    
    T squaredMagnitudeRHS = 0;
    for( int i = 0 ; i < m_nDims ; ++i)
        T squaredMagnitudeRHS += rhs.m_vectorData[i]*rhs.m_vectorData[i];
    
    T vecMagnitudeRHS = sqrt(a);
    T resultData.push_back (dotP/vecMagnitudeRHS);

    //

    vector<T> result(resultData);
    return result;
}


template <class T>
vector<T> vector()::cross(const vector<T> &a, const vector<T> &b)
{
    // check matching dimensionality
    if (m_nDims != rhs.m_nDims)
        throw std::invalid_argument("Vector dimensions don't match");

    // check if three dimensional
    if (m_nDims != 3)
        throw std::invalid_argument("Shabadoo shabadee, this lie algebra only goes to three!");

    // calculating the cross product
    std::vector<T> resultData;
    resultData.push_back( a.m_vectorData(1)*a.m_vectorData(2) - a.m_vectorData(2)*a.m_vectorData(1) );
    resultData.push_back( a.m_vectorData(1)*a.m_vectorData(0) - a.m_vectorData(0)*a.m_vectorData(1) );
    resultData.push_back( a.m_vectorData(0)*a.m_vectorData(2) - a.m_vectorData(2)*a.m_vectorData(0) );

    vector<T> result(resultData);
    return result;

}

template <class T>
vector<T> vector()::hadamard(const vector<T> &a, const vector<T> &b)
{
    // check matching dimensionality
    if (m_nDims != rhs.m_nDims)
        throw std::invalid_argument("Vector dimensions don't match");

    std::vector<T> resultData;

    for(int i = 0; i < rhs.m_nDims ; ++i)
        resultData.push_back(rhs.m_vectorData.at(i) * rhs.m_vectorData.at(i))

    vector<T> result(resultData);
    return result;
}

#endif