/*
 * methods.cpp
 *
 *  Created on: 06.11.2013
 *      Author: hofmanms
 */

// Definiert ein skalarprodukt für Vektor gleicher Dimension
#include <iostream>
#include "MatrixKlassen/matrix.hh"

double skal(const std::vector<double>& arg1, const std::vector<double>& arg2) {
	int i, n;
	double skal;
	skal= 0;
	n= arg1.size();
	for (i=0; i<n; i++) {
		skal=skal+arg1[i]*arg2[i];
	}
	return skal;
}


void add(std::vector<double>& v, std::vector<double>& u, std::vector<double>& w ) {
	int i,n;
	n = v.size();
	for (i=0; i<n; i++) {
	w[i]=v[i]+u[i];
	}
}
/*
//Addiert Vektoren
void plus(std::vector<double> arg1, std::vector<double> arg2, std::vector<double>& sum) {
	int i, n;
	n=arg1.size();
	for (i=0; i<n; i++) {
		sum[i]=arg1[i]+arg2[i];
	}
}
*/
void skalmul(const double a, const std::vector<double> arg, std::vector<double> mult) {
	int i;
	int n=arg.size();
	for (i=0; i<n; i++) {
		mult[i]=a*arg[i];
	}
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

void CG(const int M, const int L, const std::vector<double>& b, std::vector<double>& result) {
	int tol=0.00000001; //wähle geeignete Toleranz
	Matrix<double> A;
	A=Erstelle(M, L);
	int n;
	double a,beta;
	n=M*L;
	std::vector<double> x(n, 0), z(n), az(n), r(n), r1(n), d(n), ad(n), betad(n);
	r=b;
	d=b;
	A(d, z);

	while (skal(r,r)<tol)
	{
		a=skal(r,r)/skal(d,z);
		skalmul(a,d, ad);
		add(x, ad, x);
		skalmul(-a, z, az);
		add(r, az, r1);
		beta=skal(r1,r1)/skal(r,r);
		skalmul(beta, d, betad);
		add(r, betad, d);
	}
}


