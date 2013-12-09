#include "victor.h"
#ifndef DREIECK_H
#define DREIECK_H
#include "Gitter.h"

class Gitter;
class Dreieck
{
    public:
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
};

#endif // DREIECK_H
