#ifndef TROT_H
#define TROT_H
#include "main.h"
#include "math.h"

#define pi 3.1415926
extern double t;
extern int height;
extern double x1,x2,x3,x4,y1,y2,y3,y4;
extern int r1,r2,r3,r4;
extern float faai;
extern int Ts;
extern int xf,xs,h;
extern int l1,l2;
extern double sita1_1,sita2_1,sita1_2,sita2_2,sita1_3,sita2_3,sita1_4,sita2_4;
void ik(void);
void trot(void);

#endif