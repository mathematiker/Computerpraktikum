#ifndef VICTOR_H_
#define VICTOR_H_

#include<iostream>
#include<vector>
#include<cstdlib>
#include<math.h>

using namespace std;

const unsigned int dim=2;

class victor {
    public:
        vector<double> v;
        victor();
        victor(const vector<double> arg);

        victor& operator+=(const victor& arg);
        victor operator+(const victor& arg)const;

        victor operator-(const victor& arg)const;
        victor& operator-=(const victor& arg);

        victor& operator*=(const double& arg);
        victor operator*(const double& arg)const;

        victor& operator/=(const double& arg);
        victor operator/(const double& arg)const;


        double operator*(const victor& arg)const;


};

static double norm(const victor& arg) {
    return sqrt(arg*arg);
};

static void vcout(victor arg) {
        cout << "("<< arg.v.at(0) ;
    for (std::vector<double>::iterator it = arg.v.begin()+1 ; it != arg.v.end(); ++it){
        cout <<","  << *it ;
    };
    cout << ")"<< endl;
};

static victor def(double a, double b){
double cont[]={a,b};
return victor(vector<double> (cont,cont+2));
}

static victor def(double a, double b,double c){
double cont[]={a,b,c};
return victor(vector<double> (cont,cont+3));
}

static victor cross(victor a, victor b)
{
    if(dim != 3)
    {
        cout << "Kreuzprodukt fuer "<< dim << "D Vektoren nicht definiert" << endl;
        return victor();
    }
    victor res;
    res.v[0] = a.v[1]*b.v[2]-a.v[2]*b.v[1];
    res.v[1] = a.v[2]*b.v[0]-a.v[0]*b.v[2];
    res.v[2] = a.v[0]*b.v[1]-a.v[1]*b.v[0];
    return res;
}

#endif
