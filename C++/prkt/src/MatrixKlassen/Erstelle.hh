#ifndef MATRIX_HH
#define MATRIX_HH

#include <vector>
#include <iostream>
#include <iomanip>

double&operator()(int n){
	Matrix<double> T(n);
	T(0,0)=4;
	T(0,1)=-1;
	T(n-1,n-2)=-1;
	T(n-1,n-1)=4;

	for (i=1:i<n-2:i++)
	{
		T(i,i-1)=-1;
		T(i,i)=4;
		T(i,i+1)=-1;
	}
	return T;
}
