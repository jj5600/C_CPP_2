//
//  C2A4E3_pointerArray4D.cpp

#include <stdio.h>
extern const int DIM0 = 2;
extern const int DIM1 = 3;
extern const int DIM2 = 4;
extern const int DIM3 = 5;

static int xa[DIM3],xb[DIM3],xc[DIM3],xd[DIM3],xe[DIM3],xf[DIM3],xg[DIM3],xh[DIM3],
xi[DIM3],xj[DIM3],xk[DIM3],xl[DIM3],xm[DIM3],xn[DIM3],xo[DIM3],xp[DIM3],xq[DIM3],xr[DIM3],
xs[DIM3],xt[DIM3],xu[DIM3],xv[DIM3],xw[DIM3],xx[DIM3];

static int *y1[DIM2] = {xa,xb,xc,xd};
static int *y2[DIM2] = {xe,xf,xg,xh};
static int *y3[DIM2] = {xi,xj,xk,xl};
static int *y4[DIM2] = {xm,xn,xo,xp};
static int *y5[DIM2] = {xq,xr,xs,xt};
static int *y6[DIM2] = {xu,xv,xw,xx};

static int **z1[DIM1] = {y1,y2,y3};
static int **z2[DIM1] = {y4,y5,y6};

int ***pointerArray4D[DIM0] = {z1,z2};
