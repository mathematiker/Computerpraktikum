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

	Gitter* test;
	std::vector<Dreieck> Kreistest(3);
	std::vector<victor> punkte(4);

	punkte[0][0]=1;
	punkte[0][1]=0;
	punkte[1][0]=-1;
	punkte[1][1]=0;
	punkte[2][0]=0;
	punkte[2][1]=-1;
	punkte[3][0]=0.03;
	punkte[3][1]=-0.05;

	cout << punkte[0][0]<< endl;
	cout << "test" << endl;




return 0;
}
