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
		Gitter* papa;
		bool isRand;
        vector<double> v;
        list<int> dreiecke;
        list<int> position;
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
        void setParent(Gitter* arg);
       // void verbessere();
//        void finde();
};



//Dreieck
class Dreieck
{
    public:
		Dreieck();
        Dreieck(Gitter* vater);
        Dreieck(Gitter* vater,int a, int b, int c);
        Dreieck(Gitter* vater,int a, int b, int c, int n1, int n2, int n3);
        virtual ~Dreieck();
        int punkte[3];
        int nachbarn[3];
        Gitter* papa;

        // gibt die fläche des rechtecks zurück
        double flaeche();
        // gibt den gradienten an einer ecke (also 0 = 1. ecke, 1 = 2. ecke, 2 = 3. ecke) zurück
        victor gradient(int ecke);
        victor gradient();
        void setParent(Gitter* arg);
};

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
        std::vector<Punkt> gib();
        virtual ~Gitter();
        std::vector<Punkt> punkte;
        std::vector<Dreieck> dreiecke;
        victor gdp (const int d,const int p); // gitter dreiecks eckpunkt victor ausgeben

        void finde();
        void verbessere();
        void Minimiere();
        void Verfeinere();
};



//Methods
double norm(const victor& arg);
void vcout(victor arg);
void Gcout(const Gitter& arg);
victor def(double a, double b);
victor def(double a, double b,double c);
victor cross(victor a, victor b);

#endif /* KLASSEN_H_ */
