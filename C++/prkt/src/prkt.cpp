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

	Matrix<double> M(10);

	M(3,4) = 5.6;

	std::vector<double> v(10), result(10);

	M(v, result);

	return 0;
}