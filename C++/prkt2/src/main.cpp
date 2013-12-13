#include "klassen.h"
#include <math.h>

int main(){
/*
    victor g1=def(1,1, 1);
	victor g2=def(2,2, 2);
	victor g3=def(3,3, 3);


	victor cont[] = {g1,g2,g3};
	vector<victor> punkte(cont,cont+3);
	//Dreieck d=
    vcout(g1);
	double a=0.5;
	g2*=a;
	g2+=g1*2;

	double b=norm(g2);
	vcout(g2);
	cout << b;*/

	/*victor p0=def(1,0,0);
	victor p1=def(0.5,sqrt(3)/2,0); //int/int schlecht
	victor p2=def(-0.5,sqrt(3)/2,0);
	victor p3=def(-0.3333333,-sqrt(8)/3,0);
	/ictor p4=def(0,-0.666666,sqrt(5)/3);
	victor p5=def(0.01,0.03,-0.6);*/

	victor p0=def(0,0,0.3);
	victor p1=def(1,0,0);
	victor p2=def(0,1,0);
	victor p3=def(-1,0,0);
	victor p4=def(0,-1,0);
	victor cont[] = {p0,p1,p2,p3, p4};
	vector<victor> punkte(cont,cont+5);

	Dreieck d0(0,0,1,2);
	Dreieck d1(0,0,2,3);
	Dreieck d2(0,0,3,4);
	Dreieck d3(0,0,4,1);

	vector<Dreieck> Trip(4);
	Trip[0]=d0;
	Trip[1]=d1;
	Trip[2]=d2;
	Trip[3]=d3;

	Gitter Gittel(punkte,Trip);

	Gcout(Gittel);

	Gittel.finde();

	Gittel.punkte[1].ausgeben();


return 0;
}
