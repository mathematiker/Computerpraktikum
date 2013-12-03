#include "victor.h"

#ifndef DREIECK_H
#define DREIECK_H

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
};

#endif // DREIECK_H
