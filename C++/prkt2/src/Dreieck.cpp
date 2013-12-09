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
