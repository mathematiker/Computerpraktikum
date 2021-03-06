/*
 * methods.cpp
 *
 *  Created on: 06.11.2013
 *      Author: Matthias, Michael, Nadine
 */

#include <math.h>
#include <iostream>
#include "MatrixKlassen/matrix.hh"
#include "vektor.hh"
#include <fstream>

//Erstellt die  M*LxM*L Matrix f�r mode 0, d.h. auf dem Quadrat [0,1]x[0,1]
//M=Anzahl Bl�cke
//L=Gr��e der Bl�cke

Matrix<double> Erstelle(const int& M, const int& L) {
	Matrix<double> A(M * L);
	for (int m = 0; m < M; m++) {
		A(m * L, m * L) = 4;
		A(m * L, m * L + 1) = -1; //Ausnahmef�lle oben

		A(m * L + L - 1, m * L + L - 1) = 4;
		A(m * L + L - 1, m * L + L - 2) = -1; //Ausnahmef�lle unten

		for (int l = 1; l < L - 1; l++) {
			A(m * L + l, m * L + l - 1) = -1;
			A(m * L + l, m * L + l) = 4;
			A(m * L + l, m * L + l + 1) = -1;
		}
	}
	for (int l = L + 1; l < M * L + 1; l++)
		A(l - 1, l - L - 1) = -1;
	for (int l = L + 1; l < M * L + 1; l++)
		A(l - L - 1, l - 1) = -1;
	return A;
}

//Erstelle L erstellt die NxN Matrix f�r den L-Shape
Matrix<double> ErstelleL(const int n) {
	int N;
	N = (3 * n + 2) * n;
	Matrix<double> L(N);

	for (int i = 0; i < N; i++) {
		L(i, i) = 4;
	}

	int l1 = (2 * n + 1) * (n - 1) - 1;
	for (int i = 0; i < l1 + 1; i++) {
		L(i, i + 2 * n + 1) = -1; //oben rechts
		L(i + 2 * n + 1, i) = -1; //oben links
	}
	for (int i = (2 * n + 1) * n; i < N - n; i++) {
		L(i, i + n) = -1; //unten rechts
		L(i + n, i) = -1; //unten links
	}

	for (int m = 0; m < n; m++) {
		for (int i = 0; i < 2 * n; i++) {
			L(m * (2 * n + 1) + i, m * (2 * n + 1) + i + 1) = -1; //T1 rechts
			L(m * (2 * n + 1) + i + 1, m * (2 * n + 1) + i) = -1; //T1 links
		}
	}

	for (int m = 1; m < n + 2; m++) {
		for (int i = 0; i < n - 1; i++) {
			L(2 * n * n + m * n + i, 2 * n * n + m * n + i + 1) = -1; //T2 rechts
			L(2 * n * n + m * n + i + 1, 2 * n * n + m * n + i) = -1; //T2 links
		}
	}

	return L;
}

//TestG ist die gegebene Funktion g, die in G genutzt wird
double TestG(const int i, const int j, const int n) {
	double N2 = (n + 1) * (n + 1);
	return exp(-10 * (i * i + j * j) / N2);

	//Testwerte:
	//	double N=n+1;
	//	return (i+j)/N;
	//	return 1;
}


// G erstellt den Vektor g, der Gitterpunktauswertungen an inneren Punkten, der Funktion g = exp(-10 (||x||^2), bei gegebenen MxL Gitter.
Vector G(int n, const bool mode) {

	// Mode 0 f�r das Quadrat
	if (mode == 0) {
		int N = n * n;
		Vector g(N);
		double i, j;

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				g[i + (j - 1) * n - 1] = TestG(i, j, n);
			}
		}
		return g;
	}
	//Mode 1 f�r den L-Bereich
	else {
		int N = (3 * n + 2) * n;
		Vector g(N);
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= 2 * n + 1; i++) {
				g[i + (j - 1) * (2 * n + 1) - 1] = TestG(-(n + 1) + i, -(n + 1)
						+ j, n);
			}
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i <= n; i++) {
				g[(2 * n + 1) * n + j + i * n] = TestG(j - n, i, n);
			}
		}
		return g;
	}

}

//TestF ist die gegebene Funktion f, die in F genutzt wird
double TestF(const int i, const int j, const int n) {
	double N2 = (n + 1) * (n + 1);
	return -40 * (10 * (i * i + j * j) / N2 - 1) * exp(-10 * ((i * i + j * j)
			/ N2));

	// Test f�r konstante Funktionen
	//	return 0;
}

// F erstellt den Vektor f, der Gitterpunktauswertungenan inneren Punkten,der Funktion f=-/\exp(-10(||x||^2) bei gegebenen MxL Gitter.
Vector F(int n, const bool mode) {
	//Mode 0 f�r das Quadrat
	if (mode == 0) {
		//	n = (double) n;
		int N = n * n;

		Vector f(N);
		double i, j;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				f[i + (j - 1) * n - 1] = TestF(i, j, n);
			}
		}
		return f;
	}
	//Mode 1 f�r den L-Bereich
	else {
		int N = (3 * n + 2) * n;
		Vector f(N);
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= 2 * n + 1; i++) {
				f[i + (j - 1) * (2 * n + 1) - 1] = TestF(-(n + 1) + i, -(n + 1)
						+ j, n);
			}
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i <= n; i++) {
				f[(2 * n + 1) * n + j + i * n] = TestF(j - n, i, n);
			}
		}
		return f;
	}
}

// B erstellt den Vektor b, der die Randpunktauswertungen von f enth�lt
Vector B(int n, const bool mode) {
	//Mode 0 f�r das Quadrat
	if (mode == 0) {
		int N = n * n;
		double N2 = (n + 1) * (n + 1);
		Vector b1(N), b2(N), b3(N), b4(N), b(N);
		for (int i = 0; i < n; i++) {
			b1[i * n] = TestG(0, i + 1, n); //x1=i=0
			b2[i] = TestG(i + 1, 0, n);//x2=j=0
			b3[n - 1 + i * n] = TestG(n + 1, i + 1, n);//x1=1 i=n+1
			b4[N - i - 1] = TestG(n - i, n + 1, n);//x2=1 j=n+1
		}
		return (b1 + b2 + b3 + b4) * N2;
	}
	//Mode 1 f�r den L-Bereich
	else {
		int N = (3 * n + 2) * n;
		double N2 = (n + 1) * (n + 1);
		Vector b1(N), b2(N), b3(N), b4(N), b5(N), b6(N), b(N);
		for (int i = 0; i < n + 1; i++) {
			b1[(2 * n + 1) * n + i * n] = TestG(-(n + 1), i, n);
			b6[(2 * n + 1) * (n - 1) + n + i] = TestG(i, 0, n);
			b5[(2 * n + 1) * n + n - 1 + i * n] = TestG(0, i, n);
		}
		for (int i = 0; i < n; i++) {
			b1[i * (2 * n + 1)] = TestG(-(n + 1), i - n, n);
			b2[2 * n + i * (2 * n + 1)] = TestG(n + 1, i - n, n);
			b4[(2 * n + 1) * n + n * n + i] = TestG(i - n, n + 1, n);
		}
		for (int i = 0; i < 2 * n + 1; i++)
			b3[i] = TestG(i - n, -(n + 1), n);
		return (b1 + b2 + b3 + b4 + b5 + b6) * N2;
	}
}
/*Test:
 //mult multipliziert eine Matrix und einen Vektor und gibt das Ergebnis zur�ck
 Vector mult(Matrix<double>& A, Vector& arg)
 {
 int i,j, n;
 n=arg.dimension();
 Vector result(n);
 for (i=0; i<n; i++) {
 for (j=0; j<n; j++) {
 result[i]+=A(i,j)*arg[j];
 }
 }
 return result;
 }
 */

//multipliziert die Matrix aus Erstelle/ErstelleL mit einem Vektor und gibt das Ergebinis zur�ck ,
//wobei nur die Nichtnull-Eintr�ge ber�cksichtigt werden

Vector mult(const int& n, Vector v, const bool mode) {
	//Mode 0 f�r das Quadrat
	if (mode == 0) {
		int M = n, L = n;
		int N = (M + 1) * (L + 1);
		Vector w(M * L);
		for (int m = 0; m < M; m++) {
			w[m * L] += 4 * N * v[m * L];
			w[m * L] += -N * v[m * L + 1]; //Ausnahmef�lle oben

			w[m * L + L - 1] += 4 * N * v[m * L + L - 1];
			w[m * L + L - 1] += -N * v[m * L + L - 2]; //Ausnahmef�lle unten

			for (int l = 1; l < L - 1; l++) {
				w[m * L + l] += -N * v[m * L + l - 1];
				w[m * L + l] += 4 * N * v[m * L + l];
				w[m * L + l] += -N * v[m * L + l + 1];
			}
		}
		for (int l = L + 1; l < M * L + 1; l++)
			w[l - 1] += -N * v[l - L - 1];
		for (int l = L + 1; l < M * L + 1; l++)
			w[l - L - 1] += -N * v[l - 1];
		return w;
	}
	//===================================
	//Mode 1 f�r den L-Bereich
	else {
		int N;
		N = (3 * n + 2) * n; //L ist eine NxN Matrix
		int N2 = (n + 1) * (n + 1);
		Vector w(N);

		for (int i = 0; i < N; i++) {
			w[i] += 4 * N2 * v[i];
		}

		int l1 = (2 * n + 1) * (n - 1) - 1 + n;
		for (int i = 0; i < l1 + 1; i++) {
			w[i] += -N2 * v[i + 2 * n + 1]; //oben rechts
			w[i + 2 * n + 1] += -N2 * v[i]; //oben links
		}
		for (int i = (2 * n + 1) * n; i < N - n; i++) {
			w[i] += -N2 * v[i + n]; //unten rechts
			w[i + n] += -N2 * v[i]; //unten links
		}

		for (int m = 0; m < n; m++) {
			for (int i = 0; i < 2 * n; i++) {
				w[m * (2 * n + 1) + i] += -N2 * v[m * (2 * n + 1) + i + 1]; //T1 rechts
				w[m * (2 * n + 1) + i + 1] += -N2 * v[m * (2 * n + 1) + i]; //T1 links
			}
		}

		for (int m = 1; m < n + 2; m++) { //war vorher m<n+2
			for (int i = 0; i < n - 1; i++) {
				w[2 * n * n + m * n + i] += -N2 * v[2 * n * n + m * n + i + 1]; //T2 rechts
				w[2 * n * n + m * n + i + 1] += -N2 * v[2 * n * n + m * n + i]; //T2 links
			}
		}
		return w;
	}
}



//CG l�st das Gleichungssystem Ax=b f�r gegebenen Vektor b und der Matrix A aus Erstelle/ErstelleL nach x auf
//geschrieben nach Wikipedia-Pseudocode , http://de.wikipedia.org/wiki/CG-Verfahren
Vector CG(int n, Vector& b, bool mode) {
	int N;
	//Mode 0 f�r das Quadrat
	if (mode == 0)
		N = n * n;
	//Mode 1 f�r den L-Bereich
	else
		N = (3 * n + 2) * n;

	double tol2 = 1e-14; //w�hle geeignete Toleranz
	double a = 0, beta = 0;
	Vector x(N), z(N), r(N), r1(N), d(N), betad(N);

	r = b;
	d = b;
	double qfehler = r * r; //quadratischer Fehler
	double qfehler2; // neuer quadratischer Fehler
	while (qfehler >= tol2) {
		z = mult(n, d, mode);
		a = qfehler / (d * z);
		x = x + d * a;
		r1 = r + z * (-a);
		qfehler2 = r1 * r1;
		beta = qfehler2 / qfehler;
		d = r1 + d * beta;
		r = r1;
		qfehler = qfehler2;
	}
	return x;
}

//PoissonDiff gibt die diskretisierte L�sung unseres Problems f�r Schrittweite 1/(n-1) zur�ck
//-f�r Mode 0 auf dem Quadrat
//-f�r Mode 1 auf dem L-Bereich
Vector PoissonDiff(int n, bool mode) {
	int N;
	if (mode == 0)
		N = n * n;
	else
		N = (3 * n + 2) * n;
	Vector g(N), f(N), b(N), o(N), erg(N);
	f = F(n, mode);
	g = G(n, mode);
	b = B(n, mode);
	o = f + b;
	erg = CG(n, o, mode);
	return erg;
}
//maximal gibt den betragsgr��ten Eintrag eines Vektors zur�ck
double maximal(Vector v) {
	int n = v.dimension();
	double temp;
	temp = fabs(v[0]);
	for (int i = 1; i < n; i++) {
		if (fabs(v[i]) > temp) {
			temp = fabs(v[i]);
		}
	}
	return temp;
}

//Vektorausgabe
std::ostream& operator<<(std::ostream& os, const Vector& obj) {
	for (unsigned int i = 0; i < obj.dimension(); ++i) {
		os << std::setw(5); // field-width
		os << obj[i] << " ";
	}
	os << std::endl;

	return os;
}

//Fehler gibt den Fehler zwischen der diskretisierten L�sung mit Schrittweite 1/(n-1) und der wahren L�sung zur�ck
double Fehler(const int n, const bool mode) {
	Vector temp = PoissonDiff(n, mode);
	Vector g = G(n, mode);
	return maximal(temp - g);

}

