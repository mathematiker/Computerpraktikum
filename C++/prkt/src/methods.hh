/*
 * methods.hh
 *
 *  Created on: 06.11.2013
 *      Author: Matthias, Michael, Nadine
 */

#ifndef METHODS_HH_
#define METHODS_HH_

Matrix<double> Erstelle(const int& M, const int& L);
Vector CG(int n, Vector& b, bool mode);
Vector F(int n, const bool mode);
Vector G(int n, const bool mode);
Vector mult(Matrix<double>& A, Vector& arg);
Vector mult(const int& n, Vector v,const bool mode);
Vector mult(const int& n, Vector v);
std::ostream& operator<<(std::ostream& os, const Vector& obj);
double maximal(Vector v);
Vector B(int n, const bool);
Vector PoissonDiff(int n, bool mode);
Matrix<double> ErstelleL(const int n);
double Fehler(const int n, const bool mode);

#endif /* METHODS_HH_ */
