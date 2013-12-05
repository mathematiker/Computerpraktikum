#include "Gitter.h"
#include "methods.h"
#include "math.h"
#include <vector>
using namespace std;

int main(){
/*
	victor g (vector<double> (2,1), 0);
	double a=0.5;
	g*=a;
	g+=g*2;
	double b=norm(g);
	vcout(g);
	cout << b << endl;
	*/
	//Implementiere noch isRand-Option und die Dreiecke...
	Gitter* test;
	int n=3;
	int m=4;
	std::vector<Dreieck> Kreistest(n);
	std::vector<victor> punkte(m);

	//Vorsicht mit int/int
	punkte[0][0]=0.076;
	punkte[0][1]=0.8;
	punkte[0][2]=0;
	punkte[1][0]=sqrt(3)/2;			//x-Koordinate immer auf [0]
	punkte[1][1]=0.5;			//y-Koordinate immer auf [1]
	punkte[1][2]=0;			//z-Koordinate immer auf [2], hier 0
	punkte[2][0]=sqrt(3)/2;
	punkte[2][1]=-0.5;
	punkte[2][2]=0;
	punkte[3][0]=0;
	punkte[3][1]=-1;
	punkte[3][2]=0;
//	punkte[4][1]=0.03;
//	punkte[4][2]=0.007;
//	punkte[4][3]=0;

	for (int i=0;i<m;i++){			//punkte Ausgabe(haesslich)
		for(int j=0;j<n;j++) {
			cout << punkte[i][j]<<"  "; //zuerst der punkt dann die koordinaten
		}
		cout << endl;
	}
	//glaube so:
	Kreistest[0].Schreibe(1,2,3);
	Kreistest[1].Schreibe(0,1,3);
	Kreistest[2].Schreibe(0,1,2);


return 0;
}
