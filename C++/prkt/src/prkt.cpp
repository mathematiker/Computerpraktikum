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
#include <fstream>



using namespace std;

int main() {
/*Diese for Schleife ermittelt die Maximumsnorm der Differenz der exakten Lösung mit unserer diskreten Lösung

 for (int n=10;n<=100;n=n+10){
	int N=n*n;
	Matrix<double> A(N)	;
	A=Erstelle(n, n);

	Vector g(N), f(N),b(N),o(N),erg(N), diff(N);
	f=F(n);
	// cout << f << endl;
	g=G(n);
	b=B(n);
	o=f.operator+(b);
	erg=CG(n,o);
	diff=g.operator+(erg.operator*(-1));
	cout << maximal(diff)<<endl;
}

 FEHLER
 n			max(g-erg)

10			1.09146
20			1.03016
30			1.01244
40			1.00499
50			1.00116
60			0.99904
70			0.997754
80			0.9969
90			0.996363
100			0.995995
*/

//Hier wird die diskrete Lösung des Problems berechnet und in die Datei "test" geschrieben, damit sie später geplottet werden kann

int N;
ofstream file;
file.open("test");
for (int n=10; n<100; n=n+10) {

N=n*n;
//Matrix<double> A(N)	;
//A=Erstelle(n, n);

	Vector g(N), f(N),b(N),o(N),erg(N);
f=F(n);
// cout << f << endl;
 g=G(n);
//	g=G();
 b=B(n);
//	b=B();
o=f.operator+(b);
//cout << f << endl;
//cout << b << endl;
//cout << o << endl;
erg=CG(n,o);
// ofstream file;
// file.open("test");
file << maximal(erg.operator+(g.operator*(-1)))<<endl;
}

file.close();

/*
ofstream file;
file.open("test");
file << erg;
file.close();
//}


	Vector e(9);
	for (int i=0; i<8; i++) {
	e[i+1]=1;
	e[i]=0;
	cout << mult(3, e) << endl;
	}

/*
	double n= 3;
	double N= n*n;
	double N2= (n+1)*(n+1);
	Vector  b1(N), b2(N), b3(N), b4(N);
	for(int i=0; i<n; i++) {
			b1[i*n]=1; //x1=i=0
			b3[i]=1;//x2=j=0
			b2[n-1+i*n]=1;//x1=1 i=n-1
			b4[N-i-1]=1;//x2=1 j=n-1
	}
	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	cout << b4 << endl;*/
	/*
	int n=10;
	double h=1/(10*10);
	cout << h << endl;
	*/
	return 0;
}
