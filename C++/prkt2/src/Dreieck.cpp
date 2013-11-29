#include "Dreieck.h"

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

