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
void plus(const std::vector<double>& arg1, const std::vector<double>& arg2, std::vector sum);
void skalmul(const double a, const std::vector<double>& arg, std::vector mult);
void CG(const M, const L, const std::vector<double>& b, std::vector<double>& result);

#endif /* METHODS_HH_ */
