/*
 * vektor.hh
 *
 *  Created on: 12.11.2013
 *      Author: hofmanms
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
    // Ctor
    explicit Vector( size_t n ) : vector(std::vector<double>(n)) {}

    // Ueberladung fuer non-const Vector Objekte
    double& operator[]( const size_t index )
    {
        return vector[index];
    }

    // Ueberladung fuer const-Vector Objekte
    const double& operator[]( const size_t index ) const
    {
        return vector[index];
    }

    Vector operator+( const Vector& rhs )
    {
        Vector v(dimension());
        for ( size_t i = 0; i < dimension(); i++ )
            v[i] = vector[i] + rhs[i];

        return v;
    }

    double operator*(const Vector& rhs)
    {
    	double v=0;
    	for ( size_t i=0; i <dimension(); i++)
    		v=v+vector[i]*rhs[i];
    	return v;
    }

    Vector operator*( const double& a)
    {
    	Vector v(dimension());
    	for ( size_t i=0; i <dimension(); i++ )
    	{
    		v[i]=vector[i]*a;
    	}
    	return v;
    }

    // Liefert die Groesse des Vektors
    size_t dimension() const { return vector.size(); }
};







#endif /* VEKTOR_HH_ */
