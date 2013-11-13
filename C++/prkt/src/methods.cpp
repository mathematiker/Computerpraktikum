/*
 * methods.cpp
 *
 *  Created on: 06.11.2013
 *      Author: hofmanms
 */

// Definiert ein skalarprodukt für Vektor gleicher Dimension
#include <math.h>
#include <iostream>
#include "MatrixKlassen/matrix.hh"
#include "vektor.hh"


//Erstellt die gwünschte M*LxM*L Matrix
//M=Anzahl Blöcke
//L=Größe der Blöcke
	Matrix<double> Erstelle(const int& M, const int& L) {
		double N=M*L;
Matrix<double> A(M*L);
for (int m=0; m<M;m++)
{
	A(m*L,m*L)=-4*N;
	A(m*L,m*L+1)=N; //Ausnahmefälle oben


	A(m*L+L-1,m*L+L-1)=-4*N;
	A(m*L+L-1,m*L+L-2)=N; //Ausnahmefälle unten


	for (int l=1;l<L-1;l++)
	{
		A(m*L+l,m*L+l-1)=N;
		A(m*L+l,m*L+l)=-4*N;
		A(m*L+l,m*L+l+1)=N;


	}

}
for (int l=L+1;l<M*L+1;l++)
{
	A(l-1,l-L-1)=N;
}
for (int l=L+1;l<M*L+1;l++)
{
	A(l-L-1,l-1)=N;
}
return A;
}
// G erstellt den Vektor g, der Gitterpunktauswertungen, bei gegebenen MxL Gitter.
	Vector   G(int n) {
		n=(double) n;
		double N=n*n;
		Vector g(N);
	double i,j; //N ist die Anzahl der inneren Punkte

	// innere Punkte
	for(i=1; i<=n; i++ ) {
		for(j=1; j<=n; j++) {
			g[i+(j-1)*n-1]=exp(-10*(i*i/(n*n)+j*j/(n*n)));
		}
	}
	/* Randpunkte
 	int N=(n-2)+(n-3)*(n-1);
	for(i=0; i<n; i++) {
		g[N+1+4*i]=exp(-10*(i*i/((n-1)*(n-1))));
		g[N+2+4*i]=exp(-10*(i*i/((n-1)*(n-1))));
		g[N+3+4*i]=exp(-10*(1+i*i/((n-1)*(n-1))));
		g[N+4+4*i]=exp(-10*(1+i*i/((n-1)*(n-1))));
	}*/
	return g;
}

// F erstellt den Vektor f, der Gitterpunktauswertungen, bei gegebenen MxL Gitter.
Vector F(int n) {
	n = (double) n;
	double N=n*n;
	Vector f(N);
	double i,j; //N ist die Anzahl der inneren Punkte
	// innere Punkte
	for(i=1; i<=n; i++ ) {
		for(j=1; j<=n; j++) {
			f[i+(j-1)*n-1]=-(400*(i*i+j*j)/(n*n)-40)*exp(-10*((i*i+j*j)/(n*n)));
		}
	}
	/* Randpunkte
	 * int N=(n-2)+(n-3)*(n-1);
	for(i=0; i<n; i++) {
		f[N+1+4*i]=(400*i*i/((n-1)*(n-1))-40)*exp(-10*(i*i/((n-1)*(n-1))));
		f[N+2+4*i]=(400*i*i/((n-1)*(n-1))-40)*exp(-10*(i*i/((n-1)*(n-1))));
		f[N+3+4*i]=(360+400*i*i/((n-1)*(n-1)))*exp(-10*(1+i*i/((n-1)*(n-1))));
		f[N+4+4*i]=(360+400*i*i/((n-1)*(n-1)))*exp(-10*(1+i*i/((n-1)*(n-1))));
	}*/
	return f;
}

Vector B(int n){
	n= (double) n;
	double N= n*n;
	double N2= (n+1)*(n+1);
	Vector  b1(N), b2(N), b3(N), b4(N);
	for(int i=0; i<n; i++) {
			b1[i*n]=exp(-10*(i*i/(n*n))); //x1=i=0
			b3[i]=exp(-10*(i*i/(n*n)));//x2=j=0
			b2[n-1+i*n]=exp(-10*(1+i*i/(n*n)));//x1=1 i=n-1
			b4[N-i-1]=exp(-10*(1+i*i/(n*n)));//x2=1 j=n-1
	}
	return b1.operator+(b2).operator+(b3).operator+(b4).operator*(-N2);
}

Vector mult(Matrix<double>& A, Vector& arg)
   {
	  int i,j, n;
	  n=arg.dimension();
	  Vector result(n);
	  for (i=0; i<n; i++) {
		  for (j=0; j<n; j++) {
			  result[i]=result[i]+A(i,j)*arg[j];
		  }
	  }
	  return result;
   }
Vector CG(Matrix<double> A, Vector& b) {
	double tol2=0.0001; //wähle geeignete Toleranz
	int n=A.size();
	double a=0,beta=0;
	Vector x(n), z(n), az(n), r(n), r1(n), d(n), ad(n), betad(n);

	r=b;
	d=b;
	double oktopus=r.operator*(r);
	while (oktopus>=tol2)
	{
		z=mult(A,d);
		a=r.operator*(r)/d.operator*(z);
		ad=d.operator*(a);
		x=x.operator+(ad);
		az=z.operator*(-a);
		r1=r.operator+(az);
		beta=r1.operator*(r1)/r.operator*(r);
		betad=d.operator*(beta);
		d=r1.operator+(betad);
		r=r1;
		oktopus= r.operator*(r);
	}
	return x;
}

std::ostream& operator<<(std::ostream& os, const Vector& obj)
{
  for (unsigned int i = 0; i < obj.dimension(); ++i) {
      os << std::setw(5); // field-width
      os << obj[i] << " ";
  }
  os << std::endl;

  return os;
}




