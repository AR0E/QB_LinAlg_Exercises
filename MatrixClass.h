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

        template class<U> friend matrix<U> operator+ (const matrix<U>& lhs, const matrix<U>& rhs)
        template class<U> friend matrix<U> operator+ (const U& lhs, const matrix<U>& rhs)
        template class<U> friend matrix<U> operator+ (const matrix<U>& lhs, const U& rhs)

        template class<U> friend matrix<U> operator- (const matrix<U>& lhs, const matrix<U>& rhs)
        template class<U> friend matrix<U> operator- (const U& lhs, const matrix<U>& rhs)
        template class<U> friend matrix<U> operator- (const matrix<U>& lhs, const U& rhs)

        template class<U> friend matrix<U> operator* (const matrix<U>& lhs, const matrix<U>& rhs)
        template class<U> friend matrix<U> operator* (const U& lhs, const matrix<U>& rhs)
        template class<U> friend matrix<U> operator* (const matrix<U>& lhs, const U& rhs)

    private:
    // Returns linear inde of row and columns
        int Sub2Ind(int row, int col);
    
    private:
    T *m_matrixdata;
    int m_nRows, m_nCols, m_Elements;
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
}

template <T>
matrix<T>::SetElement(int row, int col, T elementValue);
{
    int linearIndex = Sub2Ind(row, col);
    return (linearIndex >= 0) ? (m_matrixData[linearIndex] = elementValue, true) : false;

}

template <T>
matrix<T>::GetNumRows();

template< <T>
matrix<T>::GetNumCols();


// The + operator



// Private functions 


#endif