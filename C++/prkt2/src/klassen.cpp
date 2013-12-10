/*
 * klassen.cpp
 *
 *  Created on: 10.12.2013
 *      Author: matthias
 */
#include <iostream>
#include <list>
#include <cstddef>
#include<vector>
#include<cstdlib>
#include<math.h>
#include"klassen.h"

double norm(const victor& arg) {
    return sqrt(arg*arg);
};

void vcout(victor arg) {
        cout << "("<< arg.v.at(0) ;
    for (std::vector<double>::iterator it = arg.v.begin()+1 ; it != arg.v.end(); ++it){
        cout <<","  << *it ;
    };
    cout << ")"<< endl;
};

victor def(double a, double b){
double cont[]={a,b};
return victor(vector<double> (cont,cont+2));
}

victor def(double a, double b,double c){
double cont[]={a,b,c};
return victor(vector<double> (cont,cont+3));
}

victor cross(victor a, victor b)
{
    if(dim != 3)
    {
        cout << "Kreuzprodukt fuer "<< dim << "D Vektoren nicht definiert" << endl;
        return victor();
    }
    victor res;
    res.v[0] = a.v[1]*b.v[2]-a.v[2]*b.v[1];
    res.v[1] = a.v[2]*b.v[0]-a.v[0]*b.v[2];
    res.v[2] = a.v[0]*b.v[1]-a.v[1]*b.v[0];
    return res;
}

//Dreiecke
victor::victor(){
            v=vector<double>(dim,0);
            papa=0;
            isRand=0;
        };

victor::victor(const vector<double> arg)
{
       if (arg.size() == dim){
            v=arg;
       }
       else {
       cout << "Der Vektor ist von falscher Dimension!" << endl;
       exit(0);
       }
       papa=0;
       isRand=0;
};

victor& victor::operator+=(const victor& arg){
            for(unsigned i=0; i<dim; i++){
                v.at(i)+=arg.v.at(i);
            };
            return *this;
        };

victor victor::operator+(const victor& arg) const{
            victor temp(*this);
            return temp+=arg;
        };

victor& victor::operator-=(const victor& arg){
            return (*this)+=(arg*(-1));
        };

victor victor::operator-(const victor& arg) const{
            victor temp(*this);
            return temp-=arg;
        };

victor& victor::operator*=(const double& arg) {
            for(unsigned i=0; i<dim; i++){
                v.at(i)*=arg;
            };
            return *this;
        };

victor victor::operator*(const double& arg) const{
            victor temp(*this);
            return temp*=arg;
        };
victor& victor::operator/=(const double& arg) {
            if(arg==0){
            cout<<"Fehler: Man darf nicht durch 0 teilen!"<<endl;
            exit(0);
            }else{
            return (*this)*=(1/arg);
            }
        };

victor victor::operator/(const double& arg) const{
            victor temp(*this);
            return temp/=arg;
        };

double victor::operator*(const victor&arg) const{
    double temp =0;
    for (unsigned int i=0;i<dim;i++){
       temp+=(v.at(i))*(arg.v.at(i)) ;
}
    return temp;
};



//Dreiecke
Dreieck::Dreieck(Gitter* vater)
{
    papa = vater;
    punkte[0]=punkte[1]=punkte[2]=-1;
    nachbarn[0]=nachbarn[1]=nachbarn[2]=-1;
}

Dreieck::~Dreieck()
{
    //dtor
}

Dreieck::Dreieck(Gitter* vater,int a, int b, int c)
{
    papa = vater;
    punkte[0]=a;
    punkte[1]=b;
    punkte[2]=c;
    nachbarn[0]=nachbarn[1]=nachbarn[2]=-1;
}

Dreieck::Dreieck(Gitter* vater,int a, int b, int c, int n1, int n2, int n3)
{
    papa = vater;
    punkte[0]=a;
    punkte[1]=b;
    punkte[2]=c;
    nachbarn[0]=n1;
    nachbarn[1]=n2;
    nachbarn[2]=n3;
}


double Dreieck::flaeche()
{
    // Hole die viktoren
    victor a = papa->punkte[punkte[0]];
    victor b = papa->punkte[punkte[1]];
    victor c = papa->punkte[punkte[2]];

    victor x = b-a;
    victor y = c-a;

    //return sqrt(pow((x.v[1]*y.v[2]-x.v[2]*y.v[1]),2)+pow((x.v[2]*y.v[0]-x.v[0]*y.v[2]),2)+pow((x.v[0]*y.v[1]-x.v[1]*y.v[0]),2));
    return norm(cross(x,y))/2;
}

victor Dreieck::gradient(int ecke)
{
    victor a = papa->punkte[punkte[(ecke+1)%3]]-papa->punkte[punkte[ecke]];
    victor b = papa->punkte[punkte[(ecke+2)%3]]-papa->punkte[punkte[ecke]];

    victor c = cross(cross(a,b),b);

    return c*(norm(b)/norm(c));
}

//Gitter
Gitter::Gitter()
{
    //ctor
}

Gitter::~Gitter()
{
    //ltor
}

Gitter::Gitter(const vector<victor> arg1,const vector<Dreieck> arg2){
    punkte=arg1;
    dreiecke=arg2;

}

victor Gitter::gdp(const int d, const int p){
return punkte.at(dreiecke.at(d).punkte[p]);
}

void Gitter::finde() {
	for (unsigned int i=0; i<dreiecke.size(); i++)
	{
		punkte[dreiecke[i].punkte[0]].dreiecke.push_back(i);
		punkte[dreiecke[i].punkte[1]].dreiecke.push_back(i);
		punkte[dreiecke[i].punkte[2]].dreiecke.push_back(i);
	}
}
