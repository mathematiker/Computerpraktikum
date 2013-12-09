#include "Gitter.h"

int main(){

    victor g1=def(1,1);
	victor g2=def(2,2);
	victor g3=def(3,3);


	victor cont[] = {g1,g2,g3};
	vector<victor> punkte(cont,cont+3);
	//Dreieck d=
    vcout(g1);
	double a=0.5;
	g2*=a;
	g2+=g1*2;

	double b=norm(g2);
	vcout(g2);
	cout << b;


return 0;
}
