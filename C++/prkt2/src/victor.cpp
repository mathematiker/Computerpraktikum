#include "victor.h"

unsigned int dim=3;

victor::victor(){
            v=vector<double>(dim,0);
            isRand=0;
        };

victor::victor(const vector<double> arg, const bool is)
{
       if (arg.size() == dim){
            v=arg;
       }
       else {
       cout << "Der Vektor ist von falscher Dimension!" << endl;
       exit(0);
       }
       isRand=is;
};

// Eintragen/Ausgeben von nicht const Vector Objekten
   double& victor::operator[](int i )
   {
       return v[i];
   }

victor& victor::operator+=(const victor& arg){
            for(unsigned i=0; i<dim; i++){
                v.at(i)+=arg.v.at(i);
            };
            return *this;
        };

victor victor::operator+(const victor& arg) const{
            victor temp(*this);
            return temp+=arg;
        };

victor& victor::operator*=(const double& arg) {
            for(unsigned i=0; i<dim; i++){
                v.at(i)*=arg;
            };
            return *this;
        };

victor victor::operator*(const double& arg) const{
            victor temp(*this);
            return temp*=arg;
        };

double victor::operator*(const victor&arg) const{
    double temp =0;
	for (unsigned int i=0;i<dim;i++){
       temp+=(v.at(i))*(arg.v.at(i)) ;
}
	return temp;
};


