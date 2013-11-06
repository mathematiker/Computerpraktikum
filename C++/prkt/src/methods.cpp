/*
 * methods.cpp
 *
 *  Created on: 06.11.2013
 *      Author: hofmanms
 */

// Definiert ein skalarprodukt für Vektor gleicher Dimension
#include <iostream>
#include "MatrixKlassen/matrix.hh"

double skal(std::vector<double>& arg1, std::vector<double>& arg2) {
	int i, n;
	double skal;
	skal= 0;
	n= arg1.size();
	for (i=0; i<n; i++) {
		skal=skal+arg1[i]*arg2[i];
	}
	return skal;
}
