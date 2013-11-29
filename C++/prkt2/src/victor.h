//============================================================================
// Name        : Triangulation.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#ifndef VICTOR_H_
#define VICTOR_H_

#include<iostream>
#include<vector>
#include<cstdlib>
#include<math.h>

using namespace std;

unsigned int dim=2;

class victor {
    public:
        vector<double> v;
        victor();
        victor(const vector<double> arg);
        victor& operator+=(const victor& arg);
        victor operator+(const victor& arg)const;
        victor& operator*=(const double& arg);
        victor operator*(const double& arg)const;
        double operator*(const victor& arg)const;

};



#endif
