#include "trot.h"

double t=0;
int height=-80;
double x1=0,x2=0,x3=0,x4=0,y1=-80,y2=-80,y3=-80,y4=-80;
int r1=1,r2=1,r3=1,r4=1;
float faai=0.5;
int Ts=1;
int xf=40,xs=-30,h=30;
double sita1_1=0,sita2_1=0;
int l1=80,l2=80;
double sita1_1,sita2_1,sita1_2,sita2_2,sita1_3,sita2_3,sita1_4,sita2_4;


void trot()
{
	double sigma,zep,xep_b,xep_z;
    if(t<=Ts*faai)
		{
			sigma=2*pi*t/(faai*Ts);
			zep=h*(1-cos(sigma))/2;
			xep_b=(xf-xs)*((sigma-sin(sigma))/(2*pi))+xs; //前进腿
			xep_z=(xs-xf)*((sigma-sin(sigma))/(2*pi))+xf; 
			//输出y
			y1=zep+height;
			y2=0+height;
			y3=zep+height;
			y4=0+height;
			//输出x
			x1=-xep_b*r1;
			x2=-xep_z*r2;
			x3=-xep_b*r3;
			x4=-xep_z*r4;
		}
    else if(t>Ts*faai && t<=Ts)
		{
			sigma=2*pi*(t-Ts*faai)/(faai*Ts);
			zep=h*(1-cos(sigma))/2;
			xep_b=(xf-xs)*((sigma-sin(sigma))/(2*pi))+xs;
			xep_z=(xs-xf)*((sigma-sin(sigma))/(2*pi))+xf;
			//输出y
			y1=0+height;
			y2=zep+height;
			y3=0+height;
			y4=zep+height;
			//输出x
			x1=-xep_z*r1;
			x2=-xep_b*r2;
			x3=-xep_z*r3;
			x4=-xep_b*r4;
		}
}

void ik()
{
	double ik_x[4],ik_y[4];
	double L1,L2,L3,L4;
	double fai1,fai2,fai3,fai4;
	//腿1 LF
	ik_y[0]=-y1;
	ik_x[0]=-x1;
	L1=sqrt(ik_x[0]*ik_x[0]+ik_y[0]*ik_y[0]);
	fai1=acos((L1*L1+l1*l1-l2*l2)/(2*l1*L1));
	if(ik_x[0]>0)
		sita1_1=(fabs(atan(ik_y[0]/ik_x[0]))-fai1)*4;
	else if(ik_x[0]<0)
		sita1_1=(pi-fabs(atan(ik_y[0]/ik_x[0]))-fai1)*4;
	else  
		sita1_1=(pi/2-fai1)*4;
	sita2_1=(pi/2-acos((L1*L1-l1*l1-l2*l2)/(-2*l1*l2)))*4+sita1_1;
	
	//腿2 RF
	ik_y[1]=-y2;
	ik_x[1]=-x2;
	L2=sqrt(ik_x[1]*ik_x[1]+ik_y[1]*ik_y[1]);
	fai2=acos((L2*L2+l1*l1-l2*l2)/(2*l1*L2));
	if(ik_x[1]<0)
		sita1_2=(pi-fabs(atan(ik_y[1]/ik_x[1]))-fai2)*4;
	else if(ik_x[1]>0)
		sita1_2=(fabs(atan(ik_y[1]/ik_x[1]))-fai2)*4;
	else  
		sita1_2=(pi/2-fai2)*4;
	sita2_2=(pi/2-acos((L2*L2-l1*l1-l2*l2)/(-2*l1*l2)))*4+sita1_2;
	
	//腿3 RB
	ik_y[2]=-y3;
	ik_x[2]=-x3;
	L3=sqrt(ik_x[2]*ik_x[2]+ik_y[2]*ik_y[2]);
	fai3=acos((L3*L3+l1*l1-l2*l2)/(2*l1*L3));
	if(ik_x[2]<0)
		sita1_3=(pi-fabs(atan(ik_y[2]/ik_x[2]))-fai3)*4;
	else if(ik_x[2]>0)
		sita1_3=(fabs(atan(ik_y[2]/ik_x[2]))-fai3)*4;
	else  
		sita1_3=(pi/2-fai3)*4;
	sita2_3=(pi/2-acos((L3*L3-l1*l1-l2*l2)/(-2*l1*l2)))*4+sita1_3;
	
	//腿4 LB
	ik_y[3]=-y4;
	ik_x[3]=-x4;
	L4=sqrt(ik_x[3]*ik_x[3]+ik_y[3]*ik_y[3]);
	fai4=acos((L4*L4+l1*l1-l2*l2)/(2*l1*L4));
	if(ik_x[3]<0)
		sita1_4=(pi-fabs(atan(ik_y[3]/ik_x[3]))-fai4)*4;
	else if(ik_x[3]>0)
		sita1_4=(fabs(atan(ik_y[3]/ik_x[3]))-fai4)*4;
	else  
		sita1_4=(pi/2-fai4)*4;
	sita2_4=(pi/2-acos((L4*L4-l1*l1-l2*l2)/(-2*l1*l2)))*4+sita1_4;
}
    
