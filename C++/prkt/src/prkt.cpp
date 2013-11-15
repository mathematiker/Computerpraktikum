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

	int n=50;
	int N=(3*n+2)*n;
	bool mode=1;
	Vector g(N), erg(N);
	g=G(n, mode);
	erg=PoissonDiff(n, mode);
	ofstream file;
file.open("test");
	file << PoissonDiff(n, mode);
  file.close();
	cout << maximal(g-erg)<<endl;


/*
	int n=40;
	bool mode=1;
	int N=3*(n+1)*n;
// cout << ErstelleL(2) << endl;
Vector g(N); //, f(N),b(N),o(N),erg(N);
//	f=F(n, mode);
	 g=G(n, mode);
//	 b=B(n, mode);
//	o=f+b;
//	cout <<o<<endl;
	 ofstream file;
	 file.open("test");
	 file << g;
	 file.close();
//	cout << maximal(CG(5,o,mode)-g)<<endl;

// cout << ErstelleL(2) <<endl;

 Vector e(16);
 e[0]=1;
 cout << mult(2, e, 1) << endl;
 for (int k=0; k<15; k++) {
	 e[k]=0;
	 e[k+1]=1;
	 cout << mult(2,e,1) <<endl;
 }

 cout << B(2, 1) << endl;
*/





	return 0;
}
