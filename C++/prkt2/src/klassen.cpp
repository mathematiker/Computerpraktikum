/*
 * klassen.cpp
 *
 *  Created on: 10.12.2013
 *      Author: matthias
 */
#include <iostream>
#include <fstream>
#include <iterator>
#include <list>
#include <cstddef>
#include<vector>
#include<cstdlib>
#include<math.h>
#include"klassen.h"
#include<map>
#define PI (3.141592653589793)

// Gibt die Länge eines Vektors aus
double norm(const victor& arg) {
	return sqrt(arg * arg);
}
;

// Vektorausgabe
void vcout(victor arg) {
	cout << "(" << arg.v.at(0);
	for (std::vector<double>::iterator it = arg.v.begin() + 1;
			it != arg.v.end(); ++it) {
		cout << "," << *it;
	};
	cout << ")" << endl;
}
;

// Ausgabe für Geomview
void Gcout(const Gitter& arg) {
	ofstream file;
	file.open("Test");
	file << "OFF" << endl;
	file << arg.punkte.size() << " " << arg.dreiecke.size() << " " << 4 << endl;
	std::vector<Punkt> arg2 = arg.punkte;
	for (unsigned int i = 0; i < arg2.size(); i++) {
		file << arg2[i].Ort.v[0] << " " << arg2[i].Ort.v[1] << " "
				<< arg2[i].Ort.v[2] << endl;
	}
	std::vector<Dreieck> arg3 = arg.dreiecke;
	for (unsigned int i = 0; i < arg3.size(); i++) {
		file << 3 << " " << arg3[i].punkte[0] << " " << arg3[i].punkte[1] << " "
				<< arg3[i].punkte[2] << endl;
	}
	file.close();
}

// zweidimensionaler Vektor
victor def(double a, double b) {
	double cont[] = { a, b };
	return victor(vector<double>(cont, cont + 2));
}

// dreidimensionaler Vektor
victor def(double a, double b, double c) {
	double cont[] = { a, b, c };
	return victor(vector<double>(cont, cont + 3));
}

// Kreuzprodukt
victor cross(victor a, victor b) {
	if (dim != 3) {
		cout << "Kreuzprodukt fuer " << dim << "D Vektoren nicht definiert"
				<< endl;
		return victor();
	}
	victor res;
	res.v[0] = a.v[1] * b.v[2] - a.v[2] * b.v[1];
	res.v[1] = a.v[2] * b.v[0] - a.v[0] * b.v[2];
	res.v[2] = a.v[0] * b.v[1] - a.v[1] * b.v[0];
	return res;
}

// Randfunktion für gegebenen mode (s. main)
victor randkurve(double t, int mode) {
	double a, b, c;
	switch (mode) {
	case 1:
		//Tennisballkurve
		a = 6.0;
		b = 0.5;
		c = 2 * sqrt(a * b);
		return def(a * cos(2 * PI * t) + b * cos(3.0 * 2 * PI * t),
				a * sin(2 * PI * t) - b * sin(3 * 2 * PI * t),
				c * 2 * sin(2 * 2 * PI * t));
	case 2:
		//sich selbst schneidende Kurve
		return def(cos(PI * 4 * t), sin(PI * 4 * t), sin(PI * 6 * t) * 0.5);

	case 3:
		//Testkurve (Kreis)
		return def(cos(2 * PI * t), sin(2 * PI * t), 0);

	default:
		return def(0, 0, 0);
	}
}

// Erzeugt für gegebenen Parameter einen Randpunkt
Punkt randpunkt(double t, int mode) {
	Punkt arg(randkurve(t, mode), t);
	arg.Ort.isRand = 1;
	return arg;
}

//Vektorenklasse

//Konstruktor
victor::victor() {
	v = vector<double>(dim, 0);
	isRand = 0;
}
;

//Auf Nullvektor setzen.
void victor::clear() {
	v = vector<double>(dim, 0);
}

//Erzeuge einen victor-element aus einem std::vector
victor::victor(const vector<double> arg) {
	if (arg.size() == dim) {
		v = arg;
	} else {
		cout << "Der Vektor ist von falscher Dimension!" << endl;
		exit(0);
	}
	isRand = 0;
}
;

// Addition
victor& victor::operator+=(const victor& arg) {
	for (unsigned i = 0; i < dim; i++) {
		v.at(i) += arg.v.at(i);
	};
	return *this;
}
;

// Addition
victor victor::operator+(const victor& arg) const {
	victor temp(*this);
	return temp += arg;
}
;

// Subtraktion
victor& victor::operator-=(const victor& arg) {
	return (*this) += (arg * (-1));
}
;

// Subtraktion
victor victor::operator-(const victor& arg) const {
	victor temp(*this);
	return temp -= arg;
}
;

// Multiplikation mit Skalar
victor& victor::operator*=(const double& arg) {
	for (unsigned i = 0; i < dim; i++) {
		v.at(i) *= arg;
	};
	return *this;
}
;

// Multiplikation mit Skalar
victor victor::operator*(const double& arg) const {
	victor temp(*this);
	return temp *= arg;
}
;
// Division mit Skalar
victor& victor::operator/=(const double& arg) {
	if (arg == 0) {
		cout << "Fehler: Man darf nicht durch 0 teilen!" << endl;
		exit(0);
	} else {
		return (*this) *= (1 / arg);
	}
}
;

// Division mit Skalar
victor victor::operator/(const double& arg) const {
	victor temp(*this);
	return temp /= arg;
}
;

//Skalarprodukt
double victor::operator*(const victor&arg) const {
	double temp = 0;
	for (unsigned int i = 0; i < dim; i++) {
		temp += (v.at(i)) * (arg.v.at(i));
	}
	return temp;
}
;
/*
//Ausgabe der Dreieckselemente
void victor::ausgeben() {
	//  cout << "(" ;
	for (list<pair<int, int> >::iterator it = dreiecke.begin();
			it != dreiecke.end(); ++it) {
		cout << it->first << " ";
	};
	// cout << ")"<< endl;
}
*/

//Dreiecke


Dreieck::Dreieck() {
	//ctor
}

//Initialisiere Dreieck durch ein zugehöriges Gitter
Dreieck::Dreieck(Gitter* vater) {
	papa = vater; //setze Gitter
	punkte[0] = punkte[1] = punkte[2] = -1;
	//nachbarn[0] = nachbarn[1] = nachbarn[2] = -1;
}

Dreieck::~Dreieck() {
	//dtor
}

//Initialisiere ein Dreieck durch ein zugehöriges Gitter und belege die zugehörigen Punkte
Dreieck::Dreieck(Gitter* vater, int a, int b, int c) {
	papa = vater;
	punkte[0] = a;
	punkte[1] = b;
	punkte[2] = c;
//	nachbarn[0] = nachbarn[1] = nachbarn[2] = -1;
}
/*
//Definiere das Dreieck mit zugehörigen Punkten und Nachbardreiecken für Triangulation
Dreieck::Dreieck(Gitter* vater, int a, int b, int c, int n1, int n2, int n3) {
	papa = vater;
	punkte[0] = a;
	punkte[1] = b;
	punkte[2] = c;
	nachbarn[0] = n1;
	nachbarn[1] = n2;
	nachbarn[2] = n3;
}
*/

//Flaecheninhalt von Dreieck berechnen
double Dreieck::flaeche() {
	// Hole die viktoren
	victor a = papa->punkte[punkte[0]].Ort;
	victor b = papa->punkte[punkte[1]].Ort;
	victor c = papa->punkte[punkte[2]].Ort;

	victor x = b - a;
	victor y = c - a;

	//return sqrt(pow((x.v[1]*y.v[2]-x.v[2]*y.v[1]),2)+pow((x.v[2]*y.v[0]-x.v[0]*y.v[2]),2)+pow((x.v[0]*y.v[1]-x.v[1]*y.v[0]),2));
	return norm(cross(x, y)) / 2;
}

//Bestimmt die Richtung des Gradienten
victor Dreieck::gradient(int ecke) {
	victor a = papa->punkte[punkte[(ecke) % 3]].Ort;
	victor b = papa->punkte[punkte[(ecke + 1) % 3]].Ort;
	victor c = papa->punkte[punkte[(ecke + 2) % 3]].Ort;

	return cross(cross(a - b, a - c), b - c);
}

/*
//Setzt im Nachhinein ein zugehöriges Gitter
void Dreieck::setParent(Gitter* arg) {
	papa = arg;
}
*/

//Initialisiere einen Punkt.
Punkt::Punkt() {
	Ort=victor ();
	Ort.isRand = 0;
	parameter=0;
}

//Erzeuge einen Punkt für Parameter t und gegeben vektor v;
Punkt::Punkt(victor v, double t) {
	Ort = v;
	parameter = t;
}

Punkt::~Punkt() {
	//dtor
}

//Umdefinition des Punktoperators
Punkt& Punkt::operator=(const Punkt& rhs) {
	if (this == &rhs)
		return *this; // handle self assignment
	//assignment operator
	return *this;
}

//Gitter
Gitter::Gitter() {
	//ctor
}

Gitter::~Gitter() {
	//ltor
}

// Initialisiere Gitter durch ein Dreieck
Gitter::Gitter(int mode) {
	punkte = vector<Punkt>();
	dreiecke = vector<Dreieck>();
	punkte.push_back(randpunkt(0, mode));
	punkte.push_back(randpunkt(1.0 / 3.0, mode)); //int/int ist schlecht :)
	punkte.push_back(randpunkt(2.0 / 3.0, mode));
	dreiecke.push_back(Dreieck(this, 0, 1, 2));
}

//Sucht zu allen Punkten die zugehörigen Dreiecke
void Gitter::finde() {
	// leere Listen
	for (unsigned int j = 0; j < punkte.size(); j++) {
		punkte[j].Ort.dreiecke.clear();
	}
	for (unsigned int i = 0; i < dreiecke.size(); i++) {
		punkte[dreiecke[i].punkte[0]].Ort.dreiecke.push_back(make_pair(i, 0));
		punkte[dreiecke[i].punkte[1]].Ort.dreiecke.push_back(make_pair(i, 1));
		punkte[dreiecke[i].punkte[2]].Ort.dreiecke.push_back(make_pair(i, 2));
	}
}

//Berechnet die Oberflaeche der Gitterstruktur
double Gitter::Oberflaeche() {
	double neuegesamtflaeche=0;
	for(int i = 0; i < dreiecke.size(); ++i)
	        {
	            neuegesamtflaeche += dreiecke[i].flaeche();
	        }
	return neuegesamtflaeche;
}

void Gitter::verbessere() {
	victor grad, grad_tmp, tmp;
	double flaeche_ref;
	double flaeche;
	double faktor; //Schrittweite
	double armijo=0.01;
	for (unsigned int i = 0; i < punkte.size(); i++) {
		//Gradientenverfahren
		flaeche_ref = 0;
		grad.clear();

		faktor = 2; //Schrittweite
		//Berechne Gradienten
		if (punkte[i].Ort.isRand == 0) {
			for (list<pair<int, int> >::iterator it =
					punkte[i].Ort.dreiecke.begin();
					it != punkte[i].Ort.dreiecke.end(); ++it) {
				grad += dreiecke[it->first].gradient(it->second);
				flaeche_ref += dreiecke[it->first].flaeche();
			}
		//repeat-Schleife
		do {
			flaeche=0;
			grad_tmp.clear();
			tmp=punkte[i].Ort;
			faktor*=0.5;
			punkte[i].Ort-=grad*faktor; //update Punkt
			for (list<pair<int,int> >::iterator it = punkte[i].Ort.dreiecke.begin();
					it != punkte[i].Ort.dreiecke.end(); ++it) {
				grad_tmp+=dreiecke[it->first].gradient(it->second);
				flaeche+=dreiecke[it->first].flaeche();
			}
			punkte[i].Ort=tmp;
		} while (flaeche>flaeche_ref-armijo*faktor*(grad*grad));
		//Wir akzeptieren unsere Verbesserung nur wenn sie sich nicht verschlechtert
		punkte[i].Ort-=grad*faktor;
		grad=grad_tmp;
		flaeche_ref=flaeche;
	}
}
}

// arg mal Verbessern
void Gitter::verbessere(int arg) {
	for (int i=0;i<arg; i++)
	this->verbessere();
}

//Verfeinerungsalgorithmus in Kooperation mit den anderen Grupppen, leicht modifiziert
void Gitter::Verfeinere(int mode) {
 // enthält zu (a,b) den Punkt c.Ort = (a.Ort+b.Ort)/2, wobei a,b,c mithilfe von punktindizes definiert werden
std::map<std::pair<int, int>, int> erstelltepunkte;
std::vector<Dreieck> neuedreiecke = std::vector<Dreieck>();
int pcnt = 0;
int dcnt = 0;
for (unsigned int i = 0; i < dreiecke.size(); ++i) {
int np[3];
for (int j = 0; j < 3; ++j) {
	int a = dreiecke[i].punkte[j];
	int b = dreiecke[i].punkte[(j + 1) % 3];

	if (erstelltepunkte.find(std::pair<int, int>(a, b)) == erstelltepunkte.end()
			&& erstelltepunkte.find(std::pair<int, int>(b, a))
					== erstelltepunkte.end()) {
		Punkt c = Punkt();
		c.Ort = (punkte[a].Ort + punkte[b].Ort) * 0.5;
		if (punkte[a].parameter < punkte[b].parameter)
			c.parameter = (punkte[a].parameter + punkte[b].parameter) * 0.5;
		else
			c.parameter = (1.0 + punkte[a].parameter + punkte[b].parameter)
					* 0.5;
		np[j] = punkte.size();
		c.Ort.isRand = 0;
		punkte.push_back(c);
		pcnt++;
		erstelltepunkte.insert(
				std::pair<std::pair<int, int>, int>(std::pair<int, int>(a, b),
						np[j]));
	} else {
		if (erstelltepunkte.find(std::pair<int, int>(a, b))
				== erstelltepunkte.end()) {
			np[j] = erstelltepunkte[std::pair<int, int>(b, a)];
		} else {
			np[j] = erstelltepunkte[std::pair<int, int>(a, b)];
		}
	}
}
// neue dreiecke erstellen
for (int k = 0; k < 3; ++k) {
	Dreieck d = Dreieck(this, dreiecke[i].punkte[k], np[k], np[(k + 2) % 3]);
	neuedreiecke.push_back(d);
	dcnt++;
}
Dreieck e = Dreieck(this, np[0], np[1], np[2]);
neuedreiecke.push_back(e);
dcnt++;
}
dreiecke = neuedreiecke;
std::cout << "Erstellte " << pcnt << " neue Punkte und " << dcnt
	<< " neue Dreiecke" << std::endl;

this->finde();
 //Wenn ein Punkt in weniger als 6 Dreiecken vertreten ist, ist es ein Randpunkt
for (unsigned int i = 0; i < punkte.size(); i++) {
if (punkte[i].Ort.dreiecke.size() < 6) {
	punkte[i].Ort = randpunkt(punkte[i].parameter, mode).Ort;
	punkte[i].Ort.isRand=1;
}
}
}

//Verfeinere arg mal
void Gitter::Verfeinere(int mode, int arg) {
	for(int i=0; i<arg; i++)
		this->Verfeinere(mode);
}
