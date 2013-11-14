/*
 * methods.hh
 *
 *  Created on: 06.11.2013
 *      Author: hofmanms
 */

#ifndef METHODS_HH_
#define METHODS_HH_


Matrix<double> Erstelle(const int& M, const int& L);
Vector CG(int n, Vector& b);
Vector F(int n);
Vector   G(int n);
Vector mult(Matrix<double>& A, Vector& arg);
Vector mult(const int& n, Vector v);
std::ostream& operator<<(std::ostream& os, const Vector& obj);
Vector B(int n);

#endif /* METHODS_HH_ */
