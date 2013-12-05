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
	std::vector<Dreieck> Kreistest(3);
	std::vector<victor> punkte(4);

	int n=4;
	int m=2;
	double points[n][m];
	points[4][1]=0.076;
	points[4][2]=0.8;
	points[4][3]=0;
	points[1][1]=sqrt(3)/2;			//x-Koordinate immer auf [1]
	points[1][2]=1/2;			//y-Koordinate immer auf [2]
	points[1][3]=0;			//z-Koordinate immer auf [3], hier 0
	points[2][1]=sqrt(3)/2;
	points[2][2]=-1/2;
	points[2][3]=0;
	points[3][1]=0;
	points[3][2]=-1;
	points[3][3]=0;
	points[4][1]=0.03;
	points[4][2]=0.007;
	points[4][3]=0;

	for (int i=0;i<=m;i++){			//points Ausgabe(haesslich)
		for(int j=0;j<n;j++) {
			cout << points[j][i]<<"  ";
		}
		cout << points [n][i]<<endl;
	}

	int dreiecke[1][2];
	dreiecke[0][0]=1;
	dreiecke[0][1]=2;
	dreiecke[0][2]=3;

	dreiecke[1][0]=0;
	dreiecke[1][1]=1;
	dreiecke[1][2]=3;


	int i= dreiecke[0][0];
	int j= dreiecke[0][1];
	int k= dreiecke[0][2];
	//Keine Ahnung, wie man  arrays an Funktionen übergibt
	//Flaeche(i,j,k,points);

return 0;
}
