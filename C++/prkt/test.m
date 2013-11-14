U_h=load("test");
n=500;

h=1/(n+1);
U_h_matrix=reshape(U_h,n,n);
[X,Y]=meshgrid(h:h:(1-h),h:h:(1-h));
figure(1)
clf
surf(X,Y,U_h_matrix,'FaceColor','interp','EdgeAlpha',0);
xlabel('x-Achse');
ylabel('y-Achse');
zlabel('u(x,y)');
view(60,30);
% axis([0 1 0 1 0 1])
print("test.png", "-dpng");
