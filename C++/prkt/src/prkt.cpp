//============================================================================
// Name        : prkt.cpp
// Author      : ich und ich ganz alleine
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "MatrixKlassen/matrix.hh"
using namespace std;

int main() {
/*
	Matrix<double> M(3);


	M(2,2) = 5.6;
	M(1,2) = 18;

	Matrix<double> M(1);


	BlockMatrix<Matrix<double> > B(2,3);


	//std::vector<double> v(10), result(10);

	//M(v, result);
	B.block(0,0)=M;
	B.block(0,1)=M;
	cout << M << endl;
	cout << B << endl;

	std::vector<double> v(10, 1), result(10);

	M(v, result);

	cout << result[4] << endl;

	return 0;
	*/

	int n=6;
	Matrix<double> T(n);
	T(0,0)=4;
	T(0,1)=-1;
	T(n-1,n-2)=-1;
	T(n-1,n-1)=4;

	for (int i=1;i<(n-1);i++)
	{
		T(i,i-1)=-1;
		T(i,i)=4;
		T(i,i+1)=-1;
	}
cout << T << endl;
}
