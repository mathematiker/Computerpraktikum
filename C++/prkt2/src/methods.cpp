/*
 * methods.cpp
 *
 *  Created on: 03.12.2013
 *      Author: schlotne
 */

#include "methods.h"
#include "math.h"

double Flaeche(const int i, const int j, const int k, double *points){
	//return 1/2*sqrt((points[1][2]*points[2][3]-points[2][2]*points[1][3]+points[2][2]*points[3][3]-points[2][3]*points[3][2]+points[3][2]*points[1][3]+points[3][3]*points[1][2])^2+(points[1][3]*points[2][1]-points[2][3]*points[1][1]+points[2][3]*points[3][1]-points[2][1]*points[3][3]+points[3][3]*points[1][1]+points[3][1]*points[1][3])^2+(points[1][1]*points[2][2]-points[2][1]*points[1][2]+points[2][1]*points[3][2]-points[2][2]*points[3][1]+points[3][1]*points[1][2]+points[3][2]*points[1][1])^2);
	double erg=points[1*2];  // das hier ist ein Test, wie man auf den übergebenen Array zugreift, die Formel oben wäre für den Flächeninhalt
	return erg;
}


methods::methods() {
	// TODO Auto-generated constructor stub

}

methods::~methods() {
	// TODO Auto-generated destructor stub
}

