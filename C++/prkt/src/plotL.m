U_h=load('solvedL');	%bzw. realL/FehlerL
n=load('n'); 

U1=U_h(1:(2*n+1)*n);
U2=U_h(2*n*n+n+1: (3*n+2)*n);

h=1/(n+1);
U1=reshape(U1,2*n+1, n);
U2=reshape(U2,n, n+1);
[X1,Y1]=meshgrid((-1+h):h:-h,(-1+h):h:(1-h));
[X2, Y2]=meshgrid( 0:h:1-h,(-1+h):h:-h);
figure(1)
clf
hold on
surf(X1,Y1,U1,'FaceColor','interp','EdgeAlpha',0);
surf(X2,Y2,U2,'FaceColor','interp','EdgeAlpha',0);
xlabel('x-Achse');
ylabel('y-Achse');
zlabel('u(x,y)');
view(120,50);
%axis([0 1 0 1 0 1])
print("L.png", "-dpng");


