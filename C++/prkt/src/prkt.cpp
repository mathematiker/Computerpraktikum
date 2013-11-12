//============================================================================
// Name        : prkt.cpp
// Author      : ich und ich ganz alleine
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <math.h>
#include <iostream>
#include "vektor.hh"
#include "MatrixKlassen/matrix.hh"
#include "methods.hh"



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
double x=1;

Matrix<double> A(3);
int M=3,L=2;
A=Erstelle(M,L);
cout << A <<endl;
A(0,0)=1;
A(0,1)=3;
A(0,2)=2;

Vector a(3), b(3), c(3), result(3);
result[0]=0;
result[1]=0;
result[2]=0;
a[0]=1;
a[1]=2;
a[2]=2;
b[0]=2;
result=mult(A, a);
c=a.operator+(b);
cout<<c[2]<<endl;
for (unsigned int i = 0; i < 3; ++i) {
cout << result[i];
cout << " ";
 }
 cout << " "<<endl;

//mult(A, b, result);
//x=a.operator*(b);
//x=2;
//cout<<x<<endl;

c=a.operator*(x);
c[0]=2;
cout<<result[2]<<endl;
return 0;

}
