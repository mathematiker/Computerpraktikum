/*
 * methods.cpp
 *
 *  Created on: 03.12.2013
 *      Author: schlotne
 */

#include "methods.h"
#include "math.h"
#include "Dreieck.h"
#include "victor.h"
#include <vector>

using namespace std;
/*
double Flaeche(const int i, const int j, const int k, double *points){
	//return 1/2*sqrt((points[1][2]*points[2][3]-points[2][2]*points[1][3]+points[2][2]*points[3][3]-points[2][3]*points[3][2]+points[3][2]*points[1][3]+points[3][3]*points[1][2])^2+(points[1][3]*points[2][1]-points[2][3]*points[1][1]+points[2][3]*points[3][1]-points[2][1]*points[3][3]+points[3][3]*points[1][1]+points[3][1]*points[1][3])^2+(points[1][1]*points[2][2]-points[2][1]*points[1][2]+points[2][1]*points[3][2]-points[2][2]*points[3][1]+points[3][1]*points[1][2]+points[3][2]*points[1][1])^2);
}
*/

// Für Dreieck müsste man sich noch überlegen wie man an die konkreten
// Int-Einträge kommt
double Flaeche(Dreieck dreieck, std::vector<victor> punkte) {

	return 0;
}
