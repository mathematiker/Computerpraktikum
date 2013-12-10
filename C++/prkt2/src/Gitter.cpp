#include "Gitter.h"

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
