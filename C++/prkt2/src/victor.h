#ifndef VICTOR_H_
#define VICTOR_H_

#include<iostream>
#include<vector>
#include<cstdlib>
#include<math.h>

using namespace std;

class victor {
    public:
        vector<double> v;
        bool isRand;
        victor();
        victor(const vector<double> arg, bool is);
        victor& operator+=(const victor& arg);
        victor operator+(const victor& arg)const;
        victor& operator*=(const double& arg);
        victor operator*(const double& arg)const;
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


#endif
