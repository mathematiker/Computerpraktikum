#include "victor.h"


victor::victor(){
            v=vector<double>(dim,0);
        };

victor::victor(const vector<double> arg)
{
       if (arg.size() == dim){
            v=arg;
       }
       else {
       cout << "Der Vektor ist von falscher Dimension!" << endl;
       exit(0);
       }
};

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

victor& victor::operator-=(const victor& arg){
            return (*this)+=(arg*(-1));
        };

victor victor::operator-(const victor& arg) const{
            victor temp(*this);
            return temp-=arg;
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
victor& victor::operator/=(const double& arg) {
            if(arg==0){
            cout<<"Fehler: Man darf nicht durch 0 teilen!"<<endl;
            exit(0);
            }else{
            return (*this)*=(1/arg);
            }
        };

victor victor::operator/(const double& arg) const{
            victor temp(*this);
            return temp/=arg;
        };

double victor::operator*(const victor&arg) const{
    double temp =0;
    for (unsigned int i=0;i<dim;i++){
       temp+=(v.at(i))*(arg.v.at(i)) ;
}
    return temp;
};
