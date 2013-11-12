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

std::ostream& operator<<(std::ostream &os, const Vector &obj)
{
  for (unsigned int i = 0; i < obj.dimension(); ++i) {
      os << std::setw(5); // field-width
      os << obj[i] << " ";
  }
  os << std::endl;

  return os;
}



#endif /* VEKTOR_HH_ */
