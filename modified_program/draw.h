#include <stdio.h>
#include "shared.h"

//put here all the define
//DRAWMODE DEFINE
#define DRAW_MODE_CLEAR 0
#define DRAW_MODE_SET   1
#define DRAW_MODE_XOR   2

int drawPoint(int x, int y, int m);
int drawLine(int x1,int y1,int x2,int y2,int m);
int drawEllipse(int xc, int yc, int dx, int dy, int m);
int abs(int num);
