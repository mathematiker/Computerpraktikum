#include "Gitter.h"
#include "methods.h"
#include "math.h"
int main(){

	victor g (vector<double> (2,1), 0);
	double a=0.5;
	g*=a;
	g+=g*2;
	double b=norm(g);
	vcout(g);

	vector<int> Kreistest;


	vector<double> xKord(4);
	vector<double> yKord(4);

	xKord[1]=1;
	yKord[1]=0;
	xKord[2]=-1;
	yKord[2]=0;
	xKord[3]=0;
	yKord[3]=-1;
	xKord[4]=0.03;
	yKord[4]=-0.05;




return 0;
}
