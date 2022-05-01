clc;
clear;
%XS������ XF������
%% 
l1=80; 
l2=80;

Ts=1; %����
fai=0.5; %ռ�ձ�
xs=-20;
h=30;
v=0;
vep=50;
Kbx=-0.5

for vep=0:5:50
    
for t=0:0.01:Ts
    
    if t<=Ts*fai
       %% �Ų�̬
        sigma=2*pi*t/(fai*Ts);
    
         % Raibert �����㷽��
        xf=(1/2)*v*fai*Ts-Kbx*(vep-v)
    
        xep=(xf-xs)*((sigma-sin(sigma))/(2*pi));
        zep=h*(1-cos(sigma))/2;

        x1=-xep;
        y1=100-zep;
        %x1=30;
        %y1=100;
    end
    if t>Ts*fai
        t2=t-Ts;
        sigma=2*pi*t2/(fai*Ts);
        x1=(xf-xs)*((sigma-sin(sigma))/(2*pi));
    end

   %% ���
    shank1=180-acosd((x1*x1+y1*y1-l1*l1-l2*l2)/(-2*l1*l2))
    fai1=acosd((l1*l1+x1*x1+y1*y1-l2*l2)/(2*l1*sqrt(x1*x1+y1*y1)))
    if x1>=0
        ham1=abs(atand(y1/x1))-fai1
    else
        ham1=180-abs(atand(y1/x1))-fai1
    end
    %% ����
    x1_d=l1*cosd(ham1);
    y1_d=l1*sind(ham1);

    x2_d=x1_d+cosd(ham1)*cosd(shank1)*l2-sind(ham1)*sind(shank1)*l2;
    y2_d=y1_d+sind(ham1)*cosd(shank1)*l2+cosd(ham1)*sind(shank1)*l2;

    
    %% ��ͼ
    title(strcat('�켣���� V=',num2str(v)))
    line([0,-x1_d],[0,-y1_d]);
    hold on;
    line([-x1_d,-x2_d],[-y1_d,-y2_d])
    hold on;
    plot(-x1_d,-y1_d,'.','MarkerSize',50)
    hold on;
    plot(-x2_d,-y2_d,'.','MarkerSize',50)
    
    pause(0.001)
end
clf;
v=vep*0.5;
end

