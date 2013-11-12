/*
 * methods.hh
 *
 *  Created on: 06.11.2013
 *      Author: hofmanms
 */

#ifndef METHODS_HH_
#define METHODS_HH_


Matrix<double> Erstelle(const int& M, const int& L);
//void CG(const int M, const int L, const std::vector<double>& b, std::vector<double>& result);
//void F(const int n, std::vector<double> f);
//void G(const int n, std::vector<double> g);
Vector mult(Matrix<double>& A, Vector& arg);

#endif /* METHODS_HH_ */
