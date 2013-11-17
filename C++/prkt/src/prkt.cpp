//============================================================================
// Author      : Matthias Hofmann, Michael Rehme, Nadine Schlotz
// Description : Differenzenverfahren zur Diskretisierung des Poisson-Problems
//============================================================================

#include <math.h>
#include <iostream>
#include "vektor.hh"
#include "MatrixKlassen/matrix.hh"
#include "methods.hh"
#include <fstream>



using namespace std;

int main() {
/*Diese for Schleife ermittelt die Maximumsnorm der Differenz der exakten Loesung mit unserer diskreten Losung

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

//Hier k�nnte ihre Werbung stehen

//Hier wird die diskrete Loesung des Problems berechnet und in die Datei "test" geschrieben, damit sie spaeter geplottet werden kann

int N;
int n=100;
N=n*n;

	Vector g(N), f(N),b(N),o(N),erg(N);
f=F(n);
 g=G(n);
 b=B(n, 0);
o=f+b;
erg=CG(n,o);
//file << erg.operator+(g.operator*(-1))<<endl;



ofstream file;
file.open("test");
file << erg;
file.close();

cout << maximal(g-erg)<<endl; */
/*
	int n=2;
	Matrix<double>L(n*n*2+(n+1)*(n+1));
	L=ErstelleL(n);
	cout<<L<<endl;
	*/

/*
Matrix<double> L;
L=ErstelleL(3);
cout <<L<<endl;
*/
/*
	int n=50;
	bool mode=1;
	Vector g((2*n+3)*n);
	g=G(n, mode);
	ofstream file;
	file.open("test");
	file << (PoissonDiff(n, mode));
	file.close();
	*/



	int n=4;
	bool mode=1;
	int N=(3*n+2)*n;
//	int N=n*n;
	Vector g(N), f(N),b(N),o(N),erg(N);
	f=F(n, mode);
	 g=G(n, mode);
	 b=B(n, mode);
//	 cout << b << endl;
//	 cout << g << endl;
//	 cout << f << endl;
	o=f+b;
	erg=CG(n, o, mode);
//	cout << erg << endl;
//	cout << g-erg << endl;
	cout <<  maximal(g-erg) << endl;
//	cout << erg << endl;
//	cout << (g-erg).dimension() << endl;
//	cout << g.dimension() << endl;
//	cout << erg << endl;

	/*
	int n=2;
	int N=(3*n+2)*n;
	bool mode =1;
	Vector e(N);
	e[0]=1;
	cout << mult(n, e, mode) << endl;
	for (int i=0; i<N-1; i++) {
		e[i]=0;
		e[i+1]=1;
		cout << mult(n,e, mode) << endl;

	}
*/

return 0;
}
