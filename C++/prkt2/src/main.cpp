#include "klassen.h"
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	// Variablen
	int mode, n;
	double alteflaeche=0, neueflaeche=0;

	// Nachkommastellen
	cout.setf(ios::fixed, ios::floatfield); //fixed macht 10.00000000, floatfield für floatformat
	cout.precision(8);

	// Programmstruktur
	cout << "Wählen Sie eine Kurve aus:" <<endl;
	cout << "(1) Tennisballkurve" << endl;
	cout << "(2) sich selbst schneidende Kurve" << endl;
	cout << "(3) Kreiskurve" << endl;
	cin >> mode;
	cout << "Anzahl der Verfeinerungschritte:" <<endl;
	cin >> n;
	cout << "Initialisiere" << endl;
	Gitter g=Gitter(mode);
	g.finde();
	cout << "Oberfläche: (Anfangszustand) " << g.Oberflaeche()<<endl;
	for(int i=0; i<n; i++){
	g.Verfeinere(mode);
	alteflaeche=g.Oberflaeche();
	cout <<"Oberfläche nach Verfeinerung: " << alteflaeche <<endl;
	g.verbessere();
	neueflaeche=g.Oberflaeche();
	cout <<"Oberfläche nach Minimierungsschritt: " << neueflaeche <<endl;
	cout <<"relative Verbesserung nach Minimierungsschritt: " <<  fabs((alteflaeche-neueflaeche)/alteflaeche*100) << "%"<< endl;
	}
	cout <<"Ausgabe... Sie koennen nun mit Geomview die Datei 'Test' aufrufen" << endl;
	Gcout(g);
return 0;
}
