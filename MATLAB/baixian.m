clc;
clear;
Ts=1;
fai=0.5;
xs=0;
xf=40;
zs=0;
h=30;

x=[];
z=[];

for t=0:0.01:Ts
    if t<Ts*fai
        sigma=2*pi*t/(fai*Ts);
        xep=(xf-xs)*((sigma-sin(sigma))/(2*pi))+xs;
        zep=h*(1-cos(sigma))/2+xs;
        x=[x,xep];
        z=[z,zep];
    else
        t2 = t - Ts*fai;
        sigma=2*pi*t2/(fai*Ts);
        xep=(xf-xs)*((sigma-sin(sigma))/(2*pi))+xs;
        zep=0;
        x=[x,xep];
        z=[z,zep];
    end
end
plot(x,z)
