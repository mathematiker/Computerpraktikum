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


	int n=3;
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
	Matrix<double>Id(n);
	for (int i=0;i<n;i++)
	{
		Id(i,i)=1;
	}
cout << T << endl;
*/

int M=3;
int L=3;
Matrix<double> A(M*L);
for (int m=0; m<M;m++)
{
	A(m*L,m*L)=4;
	A(m*L,m*L+1)=-1; //Ausnahmefälle oben


	A(m*L+L-1,m*L+L-1)=4;
	A(m*L+L-1,m*L+L-2)=-1; //Ausnahmefälle unten


	for (int l=1;l<L-1;l++)
	{
		A(m*L+l,m*L+l-1)=-1;
		A(m*L+l,m*L+l)=4;
		A(m*L+l,m*L+l+1)=-1;


	}

}
for (int l=L+1;l<M*L+1;l++)
{
	A(l-1,l-L-1)=-1;
}
for (int l=L+1;l<M*L+1;l++)
{
	A(l-L-1,l-1)=-1;
}

cout << A << endl;

}
