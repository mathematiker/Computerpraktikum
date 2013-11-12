/*
 * vektor.hh
 *
 *  Created on: 12.11.2013
 *      Author: hofmanms
 */

#ifndef VEKTOR_HH_
#define VEKTOR_HH_
class Vector
{
private:
    std::vector<int> vector;
public:
    // Ctor
    explicit Vector( size_t n ) : vector(std::vector<int>(n)) {}

    // Ueberladung fuer non-const Vector Objekte
    int& operator[]( const size_t index )
    {
        return vector[index];
    }

    // Ueberladung fuer const-Vector Objekte
    const int& operator[]( const size_t index ) const
    {
        return vector[index];
    }

    const Vector operator+( const Vector& rhs )
    {
        Vector v(dimension());
        for ( size_t i = 0; i < dimension(); i++ )
            v[i] = vector[i] + rhs[i];

        return v; // Es wird eine Kopie zurueckgegeben. Nicht sehr effizient, aber etwas einfacher zum implementieren und korrek
    }

    // Liefert die Groesse des Vektors
    size_t dimension() const { return vector.size(); }
};


#endif /* VEKTOR_HH_ */
