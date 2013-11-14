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

//	int N;

//for (int n=2; n<2500; n=2*n) {
int n=100, N=n*n;
//Matrix<double> A(N)	;
//A=Erstelle(n, n);

	Vector g(N), f(N),b(N),o(N),erg(N);
//f=F(n);
// cout << f << endl;
//g=G(n);
	g=G();
//b=B(n);
	b=B();
o=f.operator+(b);
erg=CG(n,o);
//ofstream file;
//file.open("test");
//file << erg;
//file.close();
ofstream file;
file.open("test");
file << erg;
file.close();
//}

return 0;
}
