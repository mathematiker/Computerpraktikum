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
 n			max(erg-g)

10			0.348287
20			0.297169
30			0.281444
50			0.269251
100			0.259745
200			0.255094
500			0.252319
*/

//Hier wird die diskrete Lösung des Problems berechnet und in die Datei "test" geschrieben, damit sie später geplottet werden kann

int N;
int n=500;
N=n*n;

	Vector g(N), f(N),b(N),o(N),erg(N);
f=F(n);
 g=G(n);
 b=B(n);
o=f.operator+(b);
erg=CG(n,o);
//file << erg.operator+(g.operator*(-1))<<endl;



ofstream file;
file.open("test");
file << erg;
file.close();
cout << maximal(erg.operator+(g.operator*(-1)))<<endl;



	return 0;
}
