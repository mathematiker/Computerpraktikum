/*
 * methods.hh
 *
 *  Created on: 06.11.2013
 *      Author: hofmanms
 */

#ifndef METHODS_HH_
#define METHODS_HH_

double skal(std::vector<double>& arg1, std::vector<double>& arg2);
Matrix<double> Erstelle(const int& M, const int& L);
void add(std::vector<double>& v, std::vector<double>& u, std::vector<double>& w );
double skal(const std::vector<double>& arg1, const std::vector<double>& arg2);
void CG(const int M, const int L, const std::vector<double>& b, std::vector<double>& result);
void F(const int n, std::vector<double> f);
void G(const int n, std::vector<double> g);

#endif /* METHODS_HH_ */
