/*
 * methods.cpp
 *
 *  Created on: 06.11.2013
 *      Author: hofmanms,rehmeml
 */


#include <math.h>
#include <iostream>
#include "MatrixKlassen/matrix.hh"
#include "vektor.hh"
//#include <stdio.h>


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
		A(l-1,l-L-1)=N;
	for (int l=L+1;l<M*L+1;l++)
		A(l-L-1,l-1)=N;
	return A;
}

// G erstellt den Vektor g, der Gitterpunktauswertungen an inneren Punkten, der Funktion g = exp(-10 (||x||^2), bei gegebenen MxL Gitter.

Vector   G(int n) {
	n=(double) n;
	double N=n*n;
	double N2=(n+1)*(n+1);
	Vector g(N);
	double i,j;

	for(i=1; i<=n; i++ ) {
		for(j=1; j<=n; j++) {
			g[i+(j-1)*n-1]=exp(-10*(i*i/N2+j*j/N2));
		}
	}
	return g;
}

// G erstellt den Vektor g, der Gitterpunktauswertungen an inneren Punkten, der Funktion g = exp(-10 (||x||^2), bei gegebenen MxL Gitter.
Vector   G() {
	double n=100;
	double N=n*n;
	double N2=(n+1)*(n+1);
	Vector g(N);
	double i,j;

	for(i=1; i<=n; i++ ) {
		for(j=1; j<=n; j++) {
			g[i+(j-1)*n-1]=1;
			}
		}
	return g;
	}

// F erstellt den Vektor f, der Gitterpunktauswertungenan inneren Punkten,der Funktion f=-/\exp(-10(||x||^2) bei gegebenen MxL Gitter.
Vector F(int n) {
	n = (double) n;
	double N=n*n;
	double N2=(n+1)*(n+1);
	Vector f(N);
	double i,j;
	for(i=1; i<=n; i++ ) {
		for(j=1; j<=n; j++) {
			f[i+(j-1)*n-1]=-40*(10*(i*i+j*j)/N2-1)*exp(-10*((i*i+j*j)/N2));
		}
	}
	return f;
}

// B erstellt den Vektor b, der die Randpunktauswertungen von f enthält
Vector B(int n){
	n= (double) n;
	double N= n*n;
	double N2= (n+1)*(n+1);
	Vector  b1(N), b2(N), b3(N), b4(N);
	for(int i=0; i<n; i++) {
			b1[i*n]=exp(-10*(i*i/N2)); //x1=i=0
			b2[i]=exp(-10*(i*i/N2));//x2=j=0
			b3[n-1+i*n]=exp(-10*(1+i*i/N2));//x1=1 i=n-1
			b4[N-i-1]=exp(-10*(1+i*i/N2));//x2=1 j=n-1
	}
	return b1.operator+(b2).operator+(b3).operator+(b4).operator*(-N2);
}

// B erstellt den Vektor b, der die Randpunktauswertungen von f enthält
Vector B(){
	double n= 100;
	double N= n*n;
	double N2= (n+1)*(n+1);
	Vector  b1(N), b2(N), b3(N), b4(N);
	for(int i=0; i<n; i++) {
			b1[i*n]=1; //x1=i=0
			b2[i]=1;//x2=j=0
			b3[n-1+i*n]=1;//x1=1 i=n-1
			b4[N-i-1]=1;//x2=1 j=n-1
	}
	return b1.operator+(b2).operator+(b3).operator+(b4).operator*(-N2);
}

// mult multipliziert eine Matrix und einen Vektor und gibt das Ergebnis zurück
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


//multipliziert die Matrix aus Erstelle mit einem Vektor und gibt das Ergebinis zurück
Vector mult(const int& n, Vector v) {
	int M=n, L=n;
	int N=(M+1)*(L+1);
	Vector w(M*L);
	for (int m=0; m<M;m++)
	{
		w[m*L]+=-4*N*v[m*L];
		w[m*L]+=N*v[m*L+1]; //Ausnahmefälle oben

		w[m*L+L-1]+=-4*N*v[m*L+L-1];
		w[m*L+L-1]+=N*v[m*L+L-2]; //Ausnahmefälle unten

		for (int l=1;l<L-1;l++)
		{
			w[m*L+l]+=N*v[m*L+l-1];
			w[m*L+l]+=-4*N*v[m*L+l];
			w[m*L+l]+=N*v[m*L+l+1];
		}
	}
	for (int l=L+1;l<M*L+1;l++)
		w[l-1]+=N*v[l-L-1];
	for (int l=L+1;l<M*L+1;l++)
		w[l-L-1]+=N*v[l-1];
	return w;
	}

//maximal gibt den betragsgrößten Eintrag eines Vektors zurück
double maximal(Vector v){
	int n=v.dimension();
	double temp;
	temp=fabs(v[0]);
	for (int i=1;i<n;i++){
		if (fabs(v[i])>temp){
			temp=fabs(v[i]);
		}
	}
	return temp;
}

//CG löst das Gleichungssystem Ax=b für gegebenen Vektor b und der Matrix A aus Erstelle nach x auf
Vector CG(int n, Vector& b) {
	int N=n*n;
	double tol2=1e-14; //wähle geeignete Toleranz
//	int n=A.size();
	double a=0,beta=0;
	Vector x(N), z(N), az(N), r(N), r1(N), d(N), ad(N), betad(N);

	r=b;
	d=b;
	double oktopus=r.operator*(r);
	while (oktopus>=tol2)
	{
		z=mult(n,d);
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




