/*
 * klassen.h
 *
 *  Created on: 10.12.2013
 *      Author: matthias
 */

#ifndef KLASSEN_H_
#define KLASSEN_H_

#include <iostream>
#include <fstream>
#include <list>
//#include <cstddef>
#include<vector>
#include<cstdlib>
#include<math.h>

using namespace std;

const unsigned int dim=3;

class Gitter; //forward declaration

//Vektor
class victor {
    public:
		bool isRand;
        vector<double> v;
        list<pair<int, int> > dreiecke;
        victor();
        victor(const vector<double> arg);

        victor& operator+=(const victor& arg);
        victor operator+(const victor& arg)const;

        victor operator-(const victor& arg)const;
        victor& operator-=(const victor& arg);

        victor& operator*=(const double& arg);
        victor operator*(const double& arg)const;

        victor& operator/=(const double& arg);
        victor operator/(const double& arg)const;


        double operator*(const victor& arg)const;

        void clear();

        void ausgeben();
};



//Dreieck
class Dreieck
{
    public:
		Dreieck();
        Dreieck(Gitter* vater);
        Dreieck(Gitter* vater,int a, int b, int c);
        virtual ~Dreieck();
        int punkte[3];
        Gitter* papa;

        // gibt die fläche des dreiecks zurück
        double flaeche();
        // gibt den gradienten an einer ecke (also 0 = 1. ecke, 1 = 2. ecke, 2 = 3. ecke) zurück
        victor gradient(int ecke);
};

//Punkteklasse
class Punkt
{
    public:
        Punkt();
        Punkt(victor v, double t);
        virtual ~Punkt();
        Punkt& operator=(const Punkt& other);

        victor Ort;
        double parameter;
};



//Gitter
class Gitter
{
    public:
        Gitter();
        Gitter(const vector<Punkt> arg1,const vector<Dreieck> arg2 );
        Gitter(int mode);
        std::vector<Punkt> gib();
        virtual ~Gitter();
        std::vector<Punkt> punkte;
        std::vector<Dreieck> dreiecke;

        void finde();
        victor gradient(Dreieck* arg, int ecke);
        double Oberflaeche();
        void verbessere();
        void verbessere(int arg);
        void Verfeinere(int mode);
        void Verfeinere(int mode, int arg);
};



//Methods
double norm(const victor& arg);
void vcout(victor arg);
void Gcout(const Gitter& arg);
victor def(double a, double b);
victor def(double a, double b,double c);
victor cross(victor a, victor b);
victor randkurve(double t, int mode);
Punkt randpunkt();

#endif /* KLASSEN_H_ */
