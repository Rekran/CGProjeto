#ifndef _COLOR_H_
#define _COLOR_H_

struct color 
{	
	float r;
	float g;
	float b; 
	float a;
	

	float rf;
	float gf;
	float bf;
	float af;


	float varR ;
	float varG ;
	float varB ;
	float varA ;
};

void interpolacao(int dx, int dy,color *c);

#endif // _COLOR_H_
