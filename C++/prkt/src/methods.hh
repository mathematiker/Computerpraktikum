/*
 * methods.hh
 *
 *  Created on: 06.11.2013
 *      Author: hofmanms
 */

#ifndef METHODS_HH_
#define METHODS_HH_


Matrix<double> Erstelle(const int& M, const int& L);
Vector CG(Matrix<double> A, Vector& b);
Vector F(int n);
Vector   G(int n);
Vector mult(Matrix<double>& A, Vector& arg);
std::ostream& operator<<(std::ostream& os, const Vector& obj);
Vector B(int n);

#endif /* METHODS_HH_ */
