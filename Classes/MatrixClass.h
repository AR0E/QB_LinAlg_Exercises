#ifndef MATRIX_H
#define MATRIX_H
// Header include guards for safety

template <class T>
class matrix
{
    public: // Acess specifier
    // Constructors
        matrix();
        matrix(int Rows, int Col);
        matrix(int nRows, int nCols, const T *inputData);
        matrix(const matrix<T>& inputMatrix);

    // Destructor (Memory allocation)
        ~matrix();

    // Element acess methods
        T GetElement(int row, int col);
        bool SetElement(int row, int col, T elementValue);
        int GetNumRows();
        int GetNumCols();

    // Overload == operator
        bool operator== (const matrix<T>& rhs);
    

    /* Overload +, - and * operators. Friends are allowed to acess the private and
    protected class members of the matrix() class
    */ 

        template class<U> friend matrix<U> operator+ (const matrix<U>& lhs, const matrix<U>& rhs);
        template class<U> friend matrix<U> operator+ (const U& lhs, const matrix<U>& rhs);
        template class<U> friend matrix<U> operator+ (const matrix<U>& lhs, const U& rhs);

        template class<U> friend matrix<U> operator- (const matrix<U>& lhs, const matrix<U>& rhs);
        template class<U> friend matrix<U> operator- (const U& lhs, const matrix<U>& rhs);
        template class<U> friend matrix<U> operator- (const matrix<U>& lhs, const U& rhs);

        template class<U> friend matrix<U> operator* (const matrix<U>& lhs, const matrix<U>& rhs);
        template class<U> friend matrix<U> operator* (const U& lhs, const matrix<U>& rhs);
        template class<U> friend matrix<U> operator* (const matrix<U>& lhs, const U& rhs);

    private:
    // Returns linear index of row and columns
        int Sub2Ind(int row, int col);
    
    private:
    T *m_matrixData;
    int m_nRows, m_nCols, m_nElements;
};




// Constructors and destructor functions

// Default constructor produces a scalar (Array with 0)
template class<T>
matrix<T>::matrix()
{
    m_nRows = 1;
    m_nCols = 1;
    m_nElements = 1;
    m_matrixData = new T[m_nElements];
    m_matrixData[0] = 0.0;
}

// Construct empty matrix
template class<T>
matrix<T>::matrix(int nRows, int nCols);
{
    m_nRows = nRows;
    m_nCols = nCols;
    m_nElements = m_nRows * m_nCols;
    m_matrixData = new T[m_nElements];
    for(int i = 0; i < m_nElements; i++)
        m_matrixData[i] = 0.0;
}

// Construct from constant linear array
template class<T>
matrix<T>:: matrix(int nRows, int nCols, const T *inputData);
{
    m_nRows = nRows;
    m_nCols = nCols;
    m_nElements = m_nRows * m_nCols;
    m_matrixData = new T[m_nElements];
    for(int i = 0; i < m_nElements; i++)
        m_matrixData[i] = inputData[i];
}

// Copy constructor
template class<T>
matrix<T>::matrix(const matrix<T>& inputMatrix);
{
    m_nRows = inputMatrix.m_nRows;
    m_nCols = inputMatrix.m_nCols;
    m_nElements = inputMatrix.m_nElements;
    m_matrixData = new T[m_nElements];
    for(int i = 0; i < m_nElements; i++)
        m_matrixData[i] = inputMatrix.m_matrixData[i];
}


// Destructor functions
template class<T>
matrix<T>::~matrix()
{
    if (m_matrixData != nullptr)
        delete[] m_matrixData;
}


// Element functions
template <T>
T matrix<T>::GetElement(int row, int col);
{
    int linearIndex = Sub2Ind(row, col);
    if (linearIndex >= 0)
        return m_matrixData[linearIndex];
    else
        return 0.0;
}

template <T>
matrix<T>::SetElement(int row, int col, T elementValue);
{
    int linearIndex = Sub2Ind(int row, int col);
    if (linearIndex >= 0)
    {
        m_matrixData[linearIndex] = elementValue;
        return true;
    }
    else
    {
        return false;
    }

}

template <T>
matrix<T>::GetNumRows()
{
    return m_nRows;
}

template< <T>
matrix<T>::GetNumCols()
{
    return m_nCols;
}


// The + operator

template <class T>
matrix<T> operator+ (const matrix<T>& lhs, const matrix<T>& rhs)
{

    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;

    // Test if two matrices have the same dimensions
    if ((lhs.m_nCols != rhs.m_nCols) || (lhs.m_nRows != rhs.m_nRows) )
        return std::invalid_argument("Matrices have different dimensions");


    T *tempResult = new T[numElements];

    for(int i = 0; i < numRows; ++i)
        tempResult[i] = lhs.m_matrixData[i] + rhs.m_matrixData[i];
    
    matrix<T> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;

}

// Scalar + Matrix

template <class T>
matrix<T> operator+ (const T& lhs, const matrix<T>& rhs)
{
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;

    // Test if two matrices have the same dimensions
    if ((lhs.m_nCols != rhs.m_nCols) || (lhs.m_nRows != rhs.m_nRows) )
        return std::invalid_argument("Matrices have different dimensions");


    T *tempResult = new T[numElements];

    for(int i = 0; i < numRows; ++i)
        tempResult[i] = lhs + rhs.m_matrixData[i];
    
    matrix<T> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}

// Matrix + Scalar

template <class T>
matrix<T> operator+ (const T& lhs, const matrix<T>& rhs)
{
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;

    // Test if two matrices have the same dimensions
    if ((lhs.m_nCols != rhs.m_nCols) || (lhs.m_nRows != rhs.m_nRows) )
        return std::invalid_argument("Matrices have different dimensions");


    T *tempResult = new T[numElements];

    for(int i = 0; i < numRows; ++i)
        tempResult[i] = lhs.m_matrixData[i] + rhs;
    
    matrix<T> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}

// The - operator

template <class T>
matrix<T> operator- (const matrix<T>& lhs, const matrix<T>& rhs)
{

    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;

    // Test if two matrices have the same dimensions
    if ((lhs.m_nCols != rhs.m_nCols) || (lhs.m_nRows != rhs.m_nRows) )
        return std::invalid_argument("Matrices have different dimensions");


    T *tempResult = new T[numElements];

    for(int i = 0; i < numRows; ++i)
        tempResult[i] = lhs.m_matrixData[i] - rhs.m_matrixData[i];
    
    matrix<T> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;

}

// Scalar - Matrix

template <class T>
matrix<T> operator- (const T& lhs, const matrix<T>& rhs)
{
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;

    // Test if two matrices have the same dimensions
    if ((lhs.m_nCols != rhs.m_nCols) || (lhs.m_nRows != rhs.m_nRows) )
        return std::invalid_argument("Matrices have different dimensions");


    T *tempResult = new T[numElements];

    for(int i = 0; i < numRows; ++i)
        tempResult[i] = lhs - rhs.m_matrixData[i];
    
    matrix<T> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}

// Matrix + Scalar

template <class T>
matrix<T> operator- (const T& lhs, const matrix<T>& rhs)
{
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;

    // Test if two matrices have the same dimensions
    if ((lhs.m_nCols != rhs.m_nCols) || (lhs.m_nRows != rhs.m_nRows) )
        return std::invalid_argument("Matrices have different dimensions");


    T *tempResult = new T[numElements];

    for(int i = 0; i < numRows; ++i)
        tempResult[i] = lhs.m_matrixData[i] - rhs;
    
    matrix<T> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}


// The * operator

template <class T>
matrix<T> operator* (const matrix<T>& lhs, const matrix<T>& rhs)
{

    int r_numRows = rhs.m_nRows;
    int r_numCols = rhs.m_nCols;
    int l_numRows = lhs.m_nRows;
    int l_numCols = lhs.m_nCols;

    if (l_numCols == r_numRows) // Matrix multiplication condition
    {

        T *tempResult = new T[lhs.m_nRows * rhs.m_nCols]; // New matrix size

        for (int lhsRows = 0; lhsRows < l_numRows; lhsRows++)
        {
            for (int rhsCol = 0; rhsCol < r_numCols; rhsCol++)
            {
                T elementResult = 0.0;

                for (int lhsCol = 0; lhsCol < l_numCols lhsCol++)
                {
                    int lhsLinearIndex = (lhsRow * l_numCols) + lhsCol;
                    int rhsLinearIndex = (lhsCol * r_numCols) + rhsCol;

                    elementResult += lhs.m_matrixData[lhsLinearIndex] * rhs.m_matrixData[rhsLinearIndex];
                }

                int resultLinearIndex = (lhsRow * r_numCols) + rhsCol;
                tempResult[resultLinearIndex] = elementResult;
            }
        }
        matrix result(l_numRows, r_numCols, tempResult);
        delete[] tempResult;
        return result;
    }
    else 
    {
        matrix<T> result(1, 1);
        return result;
    }

}

// Scalar * Matrix

template <class T>
matrix<T> operator* (const T& lhs, const matrix<T>& rhs)
{
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;

    // Test if two matrices have the same dimensions
    if ((lhs.m_nCols != rhs.m_nCols) || (lhs.m_nRows != rhs.m_nRows) )
        return std::invalid_argument("Matrices have different dimensions");


    T *tempResult = new T[numElements];

    for(int i = 0; i < numRows; ++i)
        tempResult[i] = lhs * rhs.m_matrixData[i];
    
    matrix<T> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}

// Matrix * Scalar

template <class T>
matrix<T> operator* (const T& lhs, const matrix<T>& rhs)
{
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;

    // Test if two matrices have the same dimensions
    if ((lhs.m_nCols != rhs.m_nCols) || (lhs.m_nRows != rhs.m_nRows) )
        return std::invalid_argument("Matrices have different dimensions");


    T *tempResult = new T[numElements];

    for(int i = 0; i < numRows; ++i)
        tempResult[i] = lhs.m_matrixData[i] * rhs;
    
    matrix<T> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}


// The == (Comparison) operator

template <class T>
bool matrix<T>::operator== (const matrix<T>& rhs)
{
    // Check if the matrices are of the same size; if not, return false
    if ((this -> m_nRows != rhs.m_nRows) && (this -> m_nCols != rhs.m_nCols))
        return false;
    
    // Check if all the elements are equal
    bool flag = true;
    for (int i = 0; i < this -> m_Elements; i++)
    {
        if (this -> m_matrixData[i] != rhs.m_matrixData[i])
            flag false;
    }

    return
} 

// Private functions 

template <class T>
int matrix()::Sub2Ind(int row, int col)
{
    if ((row < m_nRows) && (row >= 0) && (row < m_nRows) && (row >= 0))
    {
        return (row * m_nCols) + col;
    }
    else
    {
        return -1;
    }
}

#endif