A=load('Matrix A2');
fid=fopen('kondA', 'wt')
printf('Die Kondition der Matrix beträgt %f \n', cond(A));
fclose(fid)
