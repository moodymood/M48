// Matrix.h
// Matrix definition. This file rapresent the Matrix public interface without revealing the implementation of member and functions
// which are defined in Matrix.ccp

#include <iostream>
using namespace std;



#ifndef _MATRIX_H_
#define _MATRIX_H_


template<typename T>
class Matrix
{
	public:

		// Constructors
		Matrix();
		Matrix(const Matrix<T> &);			
		Matrix(const int, const int);

		// public access member function
		bool getElem(const int, const int, T &) const;						
		bool setElem(const int, const int, const T &) const;

		int getNumRows() const;							
		int getNumCols() const;
		
		// Utils not requested
		void setNumRowsCols(const int, const int);
		bool isSameSize(const Matrix<T> &) const;
		bool isSquare() const;
		void initRandom(const int) const;
		void printContent() const;
		void printContent(const string) const;

		// Operators overloading
		Matrix<T>& operator+ (const Matrix<T> &); 
		Matrix<T>& operator+=(const Matrix<T> &);						
		Matrix<T>& operator- (const Matrix<T> &); 				
		Matrix<T>& operator-=(const Matrix<T> &);				
		Matrix<T>& operator* (const T &);
		Matrix<T>& operator* (const Matrix<T> &);				
		Matrix<T>& operator*=(const Matrix<T> &);					
		bool operator== (const Matrix<T> &);	
		bool operator!= (const Matrix<T> &);

		// Transformation
		int Transpose(const Matrix<T> &) const;
		int Inverse(const Matrix<T> &);								
		int setToIdentity(const Matrix<T> &) const;

	private:

		T** elements;	
		int rows;
		int cols;				

};


//#include "Matrix.cpp"
#endif

