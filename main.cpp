#include "main.h"
#include "color.h"


//-----------------------------------------------------------------------------
void MyGlDraw(void)
{

color c;
c.r = 255;
c.g = 0;
c.b = 0;
c.a = 255;

c.rf = 0;
c.gf = 255;
c.bf = 0;
c.af = 255;

color r;

r.r = 0;
r.g = 0;
r.b = 255;
r.a = 255;

r.rf = 255;
r.gf = 0;
r.bf = 0;
r.af = 255;




//PutPixel(256,256,r);
DrawTriangle(100,100,256,256,400,100,c);

//Reta(0,512,512,0,r);
//Reta(0,0,512,512,r);
//Reta(0,256,512,256,r);
//Reta(256,0,256,512,r);


//Reta(128,0,384,512,c);
//Reta(0,128,512,384,c);
//Reta(0,384,512,128,c);
//Reta(128,512,384,0,c);


}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

