#include "Dreieck.h"

#ifndef GITTER_H
#define GITTER_H

class Dreieck;
class Gitter
{
    public:
        Gitter();
        Gitter(const vector<victor> arg1,const vector<Dreieck> arg2 );
        virtual ~Gitter();
        std::vector<victor> punkte;
        std::vector<Dreieck> dreiecke;
        victor gdp (const int d,const int p); // gitter dreiecks eckpunkt victor ausgeben

        void Minimiere();
};

#endif // GITTER_H
