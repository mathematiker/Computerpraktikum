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


//Erstellt die gwünschte M*LxM*L Matrix
//M=Anzahl Blöcke
//L=Größe der Blöcke
	Matrix<double> Erstelle(const int& M, const int& L) {
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
return A;
	}
