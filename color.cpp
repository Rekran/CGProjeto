#include "color.h"
#include <math.h>

void interpolacao(int dx, int dy,color *c)
{
	float dist;
	dx = fabs(dx);
	dy = fabs(dy);

	if(dx > dy)
		dist = dx;
	else
		dist = dy;



	c->varR = (c->rf - c->r)/dist; 
	c->varG = (c->gf - c->g)/dist;
	c->varB = (c->bf - c->b)/dist;
	c->varA = (c->af - c->a)/dist;


}