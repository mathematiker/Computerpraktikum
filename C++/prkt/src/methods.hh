/*
 * methods.hh
 *
 *  Created on: 06.11.2013
 *      Author: hofmanms
 */

#ifndef METHODS_HH_
#define METHODS_HH_


Matrix<double> Erstelle(const int& M, const int& L);
Vector CG(int& M, int& L, Vector& b);
//void F(const int n, std::vector<double> f);
//void G(const int n, std::vector<double> g);
Vector mult(Matrix<double>& A, Vector& arg);
std::ostream& operator<<(std::ostream& os, const Vector& obj);

#endif /* METHODS_HH_ */
