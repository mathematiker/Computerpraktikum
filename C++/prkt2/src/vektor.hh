/*
 * vektor.hh
 *
 *  Created on: 12.11.2013
 *      Author: Matthias,Michael,Nadine
 *
 *      Vektoren-Klasse
 */

#ifndef VEKTOR_HH_
#define VEKTOR_HH_

#include <iostream>
#include <iomanip>

class Vector
{
private:
    double x,y,z;
public:

    //definiere Vector
    explicit Vector( double x, double y, double z ) : x(x), y(y), z(z) {}

};

#endif /* VEKTOR_HH_ */
