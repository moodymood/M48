// Matrix.ccp
// Matrix member-function definition. This file contains implementation of the member functions
// prototyed in Matrix.h


#include "Matrix.h"
#include <iostream>
#include <stddef.h>
using namespace std;	


/*
 * Constructors
 */

/*
 * Create a matrix with 0 rows and 0 columns
 */
template<typename T>
Matrix<T>::Matrix()
{
	setNumRowsCols(0,0);
	elements = NULL;	
}	

/*
 * Create a matrix coping values for another matrix
 * passed as input parameters
 */
template<typename T>
Matrix<T>::Matrix(const Matrix<T> &m)
{
	int m_rows = m.getNumRows(),
	    m_cols = m.getNumCols();
	setNumRowsCols(m_rows,m_cols);
	T elem;
	elements = new T*[rows];
	for(int row = 0; row < m_rows; row++)
	{
   		elements[row] = new T[cols];
	   	for(int col = 0; col < m_cols; col++)
	   	{
	   		m.getElem(row,col,elem);
	   		setElem(row,col,elem);
	   	}
	}  
}

/*
 * Create a MxN matrix and initialize it to 0
 */
template< typename T>
Matrix<T>::Matrix(const int rows, const int cols)
{
	setNumRowsCols(rows,cols);
	T elem = 0;
	elements = new T*[rows];
	for(int row = 0; row < rows; row++)
	{
   		elements[row] = new T[cols];
	   	for(int col = 0; col < cols; col++)
	        setElem(row,col,elem);
	}          
}



/*
 * Public access member functions
 */

/*
 * Get the element in the [row][col] position of the matrix and store
 * the value in elem.
 * If succeeded return true, false otherwise
 */
template< typename T>
bool Matrix<T>::getElem(const int row, const  int col, T &elem) const
{
	if(row<getNumRows() && col<getNumCols()){
		elem = elements[row][col];
		return true;
	}else{
		return false;
	}
}						

/*
 * Set the element in the [row][col] position of the matrix with the
 * value of elem.
 * If succeeded return true, false otherwise
 */
template< typename T>
bool Matrix<T>::setElem(const int row, const int col, const T &elem) const
{
	if(row<getNumRows() && col<getNumCols())
	{
		elements[row][col] = elem;
		return true;
	}else
	{
		return false;
	}
	return 0;
}

/*
 * Get the number of rows of the current matrix
 */
template< typename T>
int Matrix<T>::getNumRows() const
{
	return rows;
}

/*
 * Get the number of columns of the current matrix
 */
template< typename T>
int Matrix<T>::getNumCols() const
{	
	return cols;
}



/*
 * Utils method, not requested
 */


/*
 * Set rows and cols fields for of a matrix
 */
template< typename T>
void Matrix<T>::setNumRowsCols(const int rows, const int cols)
{

	this->rows = rows;
	this->cols = cols;
}

/*
 * Check if two matrix have the same size, if so return true
 * otherwise return false
 */
template< typename T>
bool Matrix<T>::isSameSize(const Matrix<T> &m) const
{
	if(getNumRows()==m.getNumRows()&&getNumCols()==m.getNumCols())
		return true;
	else
		return false;
}

/*
 * Check if a matrix is square, if so return true
 * otherwise return false
 */
template< typename T>
bool Matrix<T>::isSquare() const
{
	if(getNumRows()==getNumCols())
		return true;
	else
		return false;
}

/*
 * Initalize a function with random values between 0 and the
 * input parameter maxValue
 */
template< typename T>
void Matrix<T>::initRandom(const int maxValue) const
{
	for(int i=0; i<getNumRows(); i++)
		for(int j=0; j<getNumCols(); j++)
			setElem(i,j, (T)(rand() % maxValue));
}

/*
 * Print the content of a matrix with the info of
 * number of rows and cols
 */
template< typename T>
void Matrix<T>::printContent(string matrix_name) const
{	
	cout << matrix_name << "[" << getNumRows() << "][" << getNumCols() << "]=" << endl;
	printContent();
}

/*
 * Print the content of a matrix with the info
 */
template< typename T>
void Matrix<T>::printContent() const
{	
	//cout << "I am printContent()" << endl;
	if(getNumRows()==0 && getNumCols()==0)
	{
		cout << "*empty*" << endl;
	}
	else
	{
		for(int row=0; row<getNumRows(); row++)
		{
			cout << "           [";
			for(int col=0; col<getNumCols(); col++)
				cout << " " << elements[row][col] << " "; 		
			cout << "]" << endl;	
		}
	}
	cout << endl;
}



/*
 * Operators overloading
 *
 * All methods return a reference instead a pointer: in this way it is possible to concatenate
 * operators.
 * Operation like:
 * - a = a + b;
 * - a = b + c + d;
 * would not be possible because the return type of the operation would be a pointer, and
 * the new operator would expect a reference.e
 * Because it's not possible to return 0 to a reference, in case of failure the current
 * matrix value (*this) has returned instead.
 *
 */

/*
 * The + operator calls the += operator
 */
template< typename T>
Matrix<T>& Matrix<T>::operator+(const Matrix<T> &m)
{
	*this+=m;
	return *this;	
}

/*
 * The += operator can be implemented only between matrix
 * with the same size otherwise the operator returns the 
 * value of the current matrix (*this) not modified.
 */
template< typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T> &m)
{
	if(isSameSize(m))
	{
		int m_rows = m.getNumRows();
		int m_cols = m.getNumCols();
		T elem1, elem2;
		
		for(int row = 0; row < m_rows; row++)
		   	for(int col = 0; col < m_cols; col++)
		   	{
		   		getElem(row,col,elem1);
		   		m.getElem(row,col,elem2);
		   		setElem(row,col,elem1+elem2);
		   	}
	}
	*this;
}	

/*
 * The - operator calls the -= operator
 */
template< typename T>
Matrix<T>& Matrix<T>::operator-(const Matrix<T> &m)
{
	*this-=m;
	return *this;	
}

/*
 * The -= operator can be implemented only between matrix
 * with the same size otherwise the operator returns the 
 * value of the current matrix (*this) not modified.
 */
template< typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T> &m)
{
	if(isSameSize(m))
	{
		int m_rows = m.getNumRows();
		int m_cols = m.getNumCols();
		T elem1, elem2;
		
		for(int row = 0; row < m_rows; row++)
		   	for(int col = 0; col < m_cols; col++)
		   	{
		   		getElem(row,col,elem1);
		   		m.getElem(row,col,elem2);
		   		setElem(row,col,elem1-elem2);
		   	}
	}
	return *this;
}	

template< typename T>
Matrix<T>& Matrix<T>::operator*(const T &mult)
{
	int rows = getNumRows(),
	    cols = getNumCols();
	Matrix<T> m_res = *this;
	T elem;
		
	for(int row = 0; row < rows; row++)
	   	for(int col = 0; col < cols; col++)
	   	{
	   		m_res.getElem(row,col,elem);
	   		m_res.setElem(row,col,elem*mult);
	   	}	
	return m_res;	
}

/*
 * The * operator can be implemented only if the first one number of columns is
 * the same of the second one number of rows. If not the operator returns the 
 * value of the current matrix (*this) not modified
 */
template< typename T>
Matrix<T>& Matrix<T>::operator*(const Matrix<T> &m)
{
	int rows = getNumRows(),
	    cols = getNumCols(),
		m_rows = m.getNumRows(),
	    m_cols = m.getNumCols();	 
	
		Matrix<T> m_res = Matrix<T>(rows,m_cols);
		T elem1, elem2, product;
		if(cols == m_rows)
		{
			for (int row = 0; row < rows; row++) 
			{
		        for (int col = 0; col < rows; col++) {
		            for (int inner = 0; inner < cols; inner++) {
		            	getElem(row,inner,elem1);
		            	m.getElem(inner,col,elem2);
		            	m_res.getElem(row,col,product);
		            	m_res.setElem(row,col, product+(elem1*elem2));
		            }
		        }
	    	}
	    	return m_res;
		}
		else
		{
			return *this;
		}		
}

/*
 * The *= operator can be implemented only on squared matrix. If called on a not quared 
 * matrix it returns the value of the current matrix (*this) not modified.
 */
template< typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T> &m)
{
	if(isSquare() && m.isSquare())
	{
		int m_rows = m.getNumRows(),
	    	m_cols = m.getNumCols();
	    
		Matrix<T> m_temp = *this;
		T elem1, elem2, product;
		for (int row = 0; row < rows; row++) 
		{
	        for (int col = 0; col < rows; col++) 
	        {
	            for (int inner = 0; inner < cols; inner++) 
	            {
	            	m_temp.getElem(row,inner,elem1);
	            	m.getElem(inner,col,elem2);
	            	getElem(row,col,product);
	            	setElem(row,col, product+(elem1*elem2));
	            }
	        }
		    }
	}
	return *this;	
}

/*
 * Return true if matrix are equal, false otherwise
 */
template< typename T>
bool Matrix<T>::operator==(const Matrix<T> &m)
{
	if(isSameSize(m))
	{ 
		int m_rows = m.getNumRows(),
	    	m_cols = m.getNumCols();
		T elem1, elem2;
		for(int row = 0; row < m_rows; row++)
			for(int col = 0; col < m_cols; col++)
			{
				getElem(row, col, elem1);
				m.getElem(row, col, elem2);
				if (elem1 != elem2)
					return false;	
			}
	}
	else
	{
		return false;
	}
	return true;
}	

/*
 * The != operator calls the == operator
 */
template< typename T>
bool Matrix<T>::operator!=(const Matrix<T> &m)
{
	return !(*this==m);
}


/*
 * Tansformation methods
 */

/*
 * The Transpose method can be implemented only when if the first matrix
 * is MxN the second one is NxM. If it is not the case the operator returns the 
 * value of the current matrix (*this) not modified
 */
template< typename T>
int Matrix<T>::Transpose(const Matrix<T> &m) const
{
	int m_rows = m.getNumRows(),
	    m_cols = m.getNumCols();
	if(m_rows == getNumCols() && m_cols == getNumRows())
	{
		T elem;
		for(int row = 0; row < m_rows; row++)
			for(int col = 0; col < m_cols; col++)
			{
				getElem(col, row, elem);
				m.setElem(row, col, elem);
			}
		return true;
	}
	else
	{
		return false;
	}	
}	
		
/*
 * The setToIdentity method can be implemented only for square matrix;
 * if it is not the case the value of the current matrix (*this)
 * not modified is return
 */								
template< typename T>
int Matrix<T>::setToIdentity(const Matrix<T> &m) const
{
	int rows = getNumRows();
	int cols = getNumCols();
	if(isSquare() && isSameSize(m))
	{
		T id = 1;
		T zero = 0;
		for(int row = 0; row < rows; row++)
			for(int col = 0; col < cols; col++)
				if(row == col)
					m.setElem(row, col, id);
				else
					m.setElem(row, col, zero);
		return true;
	}
	else
	{
		return false;
	}
}	

template< typename T>
int Matrix<T>::Inverse(const Matrix<T> &a)
{
/*	int static const n = a.getNumRows();
	Matrix<T> x = Matrix<T>(n,n);
	Matrix<T> b = Matrix<T>(n,n);
	int index[n] = {};
	for (int i=0; i<n; ++i) 
            b.elements[i][i] = 1;


    a.printContent("a");
    b.printContent("b");

    for (int i=0; i<n-1; ++i)
        for (int j=i+1; j<n; ++j)
            for (int k=0; k<n; ++k)
            {
            	cout << i << "-" << k << "-" << j << endl;
                b.elements[index[j]][k] -= a.elements[index[j]][i]*b.elements[index[i]][k];
            }

 a.printContent("a");
    b.printContent("b");
   
	/*
	rows = m.getNumRows();
	cols = m.getNumCols();
	Matrix<T> m_res = Matrix<T>(rows, 2*cols);
	Matrix<T> m_identity = Matrix<T>(rows, cols);
	m.setToIdentity(m_identity);
	m_identity.printContent("identity");
	int n = cols;

	for (int row = 0; row < rows; row++)
       for (int col = 0; col < cols; col++)
       {
       		
            m_res.elements[row][col] = this->elements[row][col];
            m_res.printContent("mres");
       }
        
    


    for (int row = 0; row < rows ; row++)
    
        for (int col = n; col < (2 * n); col++)
        {
        	cout << "row" << row << "col" << cols - n << endl;
        	m_res.printContent("mres");
            m_res.elements[row][col] = m_identity.elements[row][(cols - n)];
        }
        */
}

template class Matrix<int>;

