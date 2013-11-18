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

	/*Maximums-Norm der Differenz auf dem Quadrat
	n=50		0.000305519
	n=100		7.78393e-05
	n=200		1.96514e-05
	n=300		8.76348e-06
	n=400		4.93752e-06

	Maximums-Norm der Differenz auf dem L-Bereich für
	n=50		0.00040141
	n=100		0.000102042
	n=200		2.57335e-05
	n=300		1.14721e-05
	n=400		6.4632e-06
	*/




	// Schreibt die diskretisierte Lösung unseres Problems auf dem Quadrat in die Datei "solvedQ"
	// und für den L-Bereich in die Datei "solvedL", für eine Schrittweite von 1/(n-1) für
	// vom Nutzer eingegebenes n
	int n;
	cout<<"Bitte geben Sie das n für die Schrittweite ein"<<endl;
	cin>>n;
	ofstream file;
	file.open("n");
		file << n;
	file.close();
	bool mode =0;
	Vector ergQ =PoissonDiff(n,mode);
	mode =1;
	Vector ergL=PoissonDiff(n,mode);


	file.open("solvedQ");
			file << ergQ;
	file.close();
	file.open("solvedL");
			file << ergL;
	file.close();

	//Schreibt die Auswertung der wahren Lösung auf dem Quadrat in die Datei "realQ"
	//und für den L-Bereich in die Datei "realL", für die selbe Stützstellenanzahl wie oben
	mode =0;
	Vector realQ=G(n,mode);
	mode =1;
	Vector realL=G(n,mode);

	file.open("realQ");
			file << realQ;
	file.close();
	file.open("realL");
			file << realL;
	file.close();

	//Berechnet die Differenz der wahren Lösung und unserer diskretisierten Lösung,
	//schreibt diese in eine Datei, damit der Fehler geplottet werden kann und gibt die Maximums-Norm der Differenz aus
	Vector FehlerQ=realQ-ergQ;
	Vector FehlerL=realL-ergL;
	file.open("FehlerQ");
			file << FehlerQ;
	file.close();
	file.open("FehlerL");
			file << FehlerL;
	file.close();
	cout <<"Maximums-Norm der Differenz auf dem Quadrat für n= " << n <<" :"<<endl;
	cout << maximal(FehlerQ)<<endl;
	cout <<"Maximums-Norm der Differenz auf dem L-Bereich für n= "<< n  <<" "<<endl;
	cout << maximal(FehlerL)<<endl;
/*
	//Schreibt die beiden Matrizen in die Dateien Matrix A und Matrix A2, so dass daraus die Kondition berechnet werden können
	file.open("Matrix A");
		file << Erstelle(10,10);
	file.close();

	file.open("Matrix A2");
		file << ErstelleL(10);
	file.close();
*/

/*
	//Schreibe den Fehler zwischen unserer diskretisierten Lösung und der wahren Lösung des Problems auf dem L-Bereich
	//für kleiner werdende Schrittweiten in die Datei Fehler
	bool mode=0;
	int i,j;
	Vector Fehl(25);
	for (i=20,  j=0; i< 501; i=i+20, j++){
		Fehl[j]=Fehler(i,mode);
		cout << j<<endl;
	}
	cout << Fehl << endl;
	ofstream file;
	file.open("FQ");

	file << Fehl;
	file.close();


*/





return 0;
}
