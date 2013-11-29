#include <vector>
#include "Dreieck.h"
#include "victor.cpp"

#ifndef GITTER_H
#define GITTER_H

class Dreieck;
class Gitter
{
    public:
        Gitter();
        virtual ~Gitter();
        std::vector<victor> punkte;
        std::vector<Dreieck> dreiecke;
};

#endif // GITTER_H
