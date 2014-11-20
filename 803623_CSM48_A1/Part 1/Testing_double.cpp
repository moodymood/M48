// Testing.ccp is the class demonstratio for the Matrix class

#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
	
	cout << "***************************************************" << endl;
	cout << "* MATRIX CLASS TEST                               *" << endl;
	cout << "***************************************************" << endl;


/*
	TEST 1: Testing constructors, get and set methods
*/
	cout << "***************************************************" << endl;
	cout << "* TEST 1                                          *" << endl;
	cout << "*                                                 *" << endl;
	cout << "* Testing constructors, getElem, setElem,         *" << endl; 
	cout << "* getNumRows, getNumCols:                         *" << endl; 
	cout << "***************************************************" << endl;
	cout << endl;

	// 1.1 Empty matrix
	Matrix<double> m1;
	double m1rows = m1.getNumRows();
	double	m1cols = m1.getNumCols();

	cout << "1.1 Empty matrix created: " << endl;
	cout << "m1 is a " << m1rows << "x" << m1cols << " matrix" << endl;
	m1.printContent("m1");
	

	// 1.2 Matrix with MxN elements set to 0
	Matrix<double> m2 = Matrix<double>(3,3);
	double m2rows = m2.getNumRows();
	double	m2cols = m2.getNumCols();

	cout << "1.2 MxN matrix created and initialized to 0: " << endl;
	cout << "m2 is a " << m2rows << "x" << m2cols << " matrix" << endl;
	m2.printContent("m2");


	// 1.3 Matrix with copy constructor
	Matrix<double> &m3 = m2;
	double m3rows = m3.getNumRows();
	double	m3cols = m3.getNumCols();

	cout << "1.3 A copy of the m2 matrix created: " << endl;
	cout << "m3 is a " << m3rows << "x" << m3cols << " matrix" << endl;
	m3.printContent("m1");


	// 1.4 Set metod
	cout << "1.4 Changing the values with random values:" << endl; 
	m3.initRandom(10);
	m3.printContent("m3");


	// 1.5 Get metod
	cout << "1.5 Getting a value from a random position:" << endl; 
	cout << endl;

	double randRow = rand() % (m3.getNumRows() + 3);
	double randCol = rand() % (m3.getNumCols() + 3);
	double randValue;
	if(m3.getElem(randRow, randCol, randValue))
	{
		cout << "Value m3[" << randRow << "][" << randCol << "] is " << randValue << endl;
		cout << endl;
	}
	else
	{
		cout << "get method return false, you are trying to access a wrong position" << endl;
		cout << endl;
	}
		

/*
	TEST 2: Testing overloading of operator
*/	
cout << "***************************************************" << endl;
cout << "* TEST 2                                          *" << endl;
cout << "*                                                 *" << endl;
cout << "* Testing overloading of operator                 *" << endl; 
cout << "***************************************************" << endl;
cout << endl;


	// 2.1 +=, + (+ uses +=)
	cout << "2.1. Testing += and + (+ is based on +=): " << endl;

	Matrix<double> op1 = Matrix<double>(3,3);
	op1.initRandom(10);
	op1.printContent("op1");

	Matrix<double> op2 = Matrix<double>(3,2);
	op2.initRandom(10);
	op2.printContent("op2");

	Matrix<double> op3 = Matrix<double>(3,3);
	op3.initRandom(10);
	op3.printContent("op3");

	cout << "Executing op1 = op1 + op2; (impossible they don't have the same size)" << endl;
	op1 = op1 + op2;
	op1.printContent("op1");

	cout << "Executing op1 = op1 + op3;" << endl;
	op1 = op1 + op3;
	op1.printContent("op1");

	// 2.2 -=, - (- uses -=)
	cout << "2.2. Testing -= and - (- is based on -=): " << endl;

	op1.printContent("op1");
	op2.printContent("op2");
	op3.printContent("op3");

	cout << "Executing op1 = op1 - op2 (impossible they don't have the same size)" << endl;
	op1 = op1 - op2;
	op1.printContent("op1");

	cout << "Executing op1 = op1 - op3" << endl;
	op1 = op1 - op3;
	op1.printContent("op1");


	// 2.3 M*k
	cout << "2.3. Testing M*k: " << endl;

	Matrix<double> op4 = Matrix<double>(2,2);
	op4.initRandom(5);
	op4.printContent("op4");

	double randMult = rand() % 5;

	cout << "Executing op4 = op4*" << randMult << endl;
	op4 = op4*randMult;
	op4.printContent("op4");

	
	// 2.4 M*=M
	cout << "2.4. Testing M*=M: " << endl;

	op3.printContent("op3");
	op4.printContent("op4");
	
	cout << "Executing op4*=op4" << endl;
	op4*=op4;
	op3.printContent("op3");
	op4.printContent("op4");

	cout << "Executing op2*=op2 (not possible)" << endl;
	op2*=op2;
	op2.printContent("op2");


	// 2.5 M*M
	cout << "2.5. Testing M*M: " << endl;

	Matrix<double> op5 = Matrix<double>(2,3);
	op5.initRandom(5);
	op5.printContent("op5");

	Matrix<double> op6 = Matrix<double>(3,4);
	op6.initRandom(5);
	op6.printContent("op6");

	cout << "Executing op5 = op5*op5 (not possible)" << endl;
	op5 = op5*op5;
	op5.printContent("op5");

	cout << "Executing op5 = op5*op6" << endl;
	op5 = op5*op6;
	op5.printContent("op5");


	// 2.6 != and == 
	cout << "2.6. Testing == and != " << endl;

	cout << "Is op5 equal to op6?" << endl;
	if(op5==op6)
		cout << "yes" << endl;
	if(op5!=op6)
		cout << "no" << endl;


/*
	TEST 3: Testing transformation methods 
*/		
cout << "***************************************************" << endl;
cout << "* TEST 3                                          *" << endl;
cout << "*                                                 *" << endl;
cout << "* Testing transformation methods                  *" << endl; 
cout << "***************************************************" << endl;
cout << endl;

	// Transpose
	cout << "3.1 Testing Transpose" << endl;

	Matrix<double> m7 = Matrix<double>(2,3);
	m7.initRandom(5);
	m7.printContent("m7");
	Matrix<double> m8 = Matrix<double>(3,2);
	m8.printContent("m8");

	cout << "Transposing m7 on m8" << endl;
	m7.Transpose(m8);
	m8.printContent("m8");

	cout << "Transposing m7 on m7 (not possible)" << endl;
	m7.Transpose(m7);
	m7.printContent("m7");

	// Identity
	cout << "3.2 Testing Identity" << endl;

	Matrix<double> m9 = Matrix<double>(3,3);
	m9.printContent("m9");
	Matrix<double> m10 = Matrix<double>(3,3);
	m10.printContent("m10");

	cout << "Identity of m9 on m10" << endl;
	m9.setToIdentity(m10);
	m10.printContent("m10");

	cout << "Identity of m9 on m7 (not possible)" << endl;
	m9.setToIdentity(m7);
	m9.printContent("m9");

/*
	// Inverse
	Matrix<double> m11 = Matrix<double>(3,3);
	m11.initRandom(5);
	m11.printContent("m11");
	Matrix<double> m12 = Matrix<double>(3,3);
	m12.printContent("m12");

	cout << "Inverse of m11 on m12" << endl;
	m11.Inverse(m12);
	//m12.printContent("m12");
	
*/





		


}