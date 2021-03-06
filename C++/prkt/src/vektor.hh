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

#include "MatrixKlassen/matrix.hh"
#include <vector>
#include <iostream>
#include <iomanip>

class Vector
{
private:
    std::vector<double> vector;
public:

    //definiere Vector
    explicit Vector( size_t n ) : vector(std::vector<double>(n)) {}

    // Eintragen/Ausgeben von nicht const Vector Objekten
    double& operator[]( const size_t index )
    {
        return vector[index];
    }

    // Ausgeben von const Vector Objekten
    const double& operator[]( const size_t index ) const
    {
        return vector[index];
    }

    //definiert eine Addition auf den Vector Objekten
    Vector operator+( const Vector& rhs )
    {
        Vector v(dimension());
        for ( size_t i = 0; i < dimension(); i++ )
            v[i] = vector[i] + rhs[i];

        return v;
    }

    //definiert eine Multiplikation auf den Vector Objekten
    double operator*(const Vector& rhs)
    {
    	double v=0;
    	for ( size_t i=0; i <dimension(); i++)
    		v=v+vector[i]*rhs[i];
    	return v;
    }

    //definiert eine Skalar-Vektor-Multiplikation auf den Vector Objekten
    Vector operator*( const double& a)
    {
    	Vector v(dimension());
    	for ( size_t i=0; i <dimension(); i++ )
    	{
    		v[i]=vector[i]*a;
    	}
    	return v;
    }

    //definiert eine Subtraktion auf den Vector Objekten
    Vector operator-(const Vector&rhs)
    {
    	Vector v(dimension());
    	        for ( size_t i = 0; i < dimension(); i++ )
    	            v[i] = vector[i] - rhs[i];

    	        return v;
    	return v;
    }

    // gibt die Groesse des Vektors aus
    size_t dimension() const { return vector.size(); }
};

#endif /* VEKTOR_HH_ */
