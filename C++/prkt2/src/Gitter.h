#include "Dreieck.h"

#ifndef GITTER_H
#define GITTER_H


class Gitter
{
    public:
        Gitter();
        virtual ~Gitter();
        std::vector<victor> punkte;
        std::vector<Dreieck> dreiecke;
};

#endif // GITTER_H
