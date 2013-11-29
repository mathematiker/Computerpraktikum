#include "victor.h"


victor::victor(){
            v=vector<double>(dim,0);
        };

victor::victor(const vector<double> arg){
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

double norm(victor arg) {
    return sqrt(arg*arg);
};

void vcout(victor arg) {
		cout << "("<< arg.v.at(0) ;
    for (std::vector<double>::iterator it = arg.v.begin()+1 ; it != arg.v.end(); ++it){
        cout <<","  << *it ;
    };
    cout << ")"<< endl;
};
