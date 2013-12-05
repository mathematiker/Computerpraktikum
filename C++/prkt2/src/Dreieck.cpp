#include "Dreieck.h"
#include<iostream>
#include<vector>
#include<cstdlib>
#include<math.h>

Dreieck::Dreieck() {
	papa =0;
	punkte[0]=0;
	punkte[1]=0;
	punkte[2]=0;
	nachbarn[0]=nachbarn[1]=nachbarn[2]=-1;
};
Dreieck::Dreieck(int a, int b, int c) {
		papa=0;
		punkte[0]=a;
	    punkte[1]=b;
	    punkte[2]=c;
	    nachbarn[0]=nachbarn[1]=nachbarn[2]=-1;
}
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

void Dreieck::Schreibe(int a, int b, int c)
   {
       punkte[0]=a;
       punkte[1]=b;
       punkte[2]=c;
   }


