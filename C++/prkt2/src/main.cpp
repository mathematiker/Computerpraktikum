#include "Gitter.h"

int main(){

	victor g (vector<double> (2,1), 0);
	double a=0.5;
	g*=a;
	g+=g*2;
	double b=norm(g);
	vcout(g);

return 0;
}
