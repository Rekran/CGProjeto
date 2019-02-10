#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include "color.h"
#include <math.h>
//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************


void PutPixel(int x, int y,color c)
{

   FBptr[x*4 + y*IMAGE_WIDTH*4] = c.r; //Red
   FBptr[(x*4 + y*IMAGE_WIDTH*4)+1] = c.g; //Green
   FBptr[(x*4 + y*IMAGE_WIDTH*4)+2] = c.b; //Blue
   FBptr[(x*4 + y*IMAGE_WIDTH*4)+3] = c.a; //ALPHA

}


void Reta(int x0,int y0,int x1, int y1,color c)
{

   color aux;
      aux.r = c.r;
      aux.g = c.g;
      aux.b = c.b;
      aux.a = c.a;

      aux.rf = c.rf;
      aux.gf = c.gf;
      aux.bf = c.bf;
      aux.af = c.af;




   int dx = x1 - x0;
   int dy = y1 - y0;

 if(x0==x1 && y0 > y1)
   {
     Reta(x0,y1,x1,y0,c);
     return;
   }else
   {
   if(x0>x1)
   {
     Reta(x1,y1,x0,y0,c);
     return;
   }
   }

   interpolacao(dx,dy,&c);

   int d ;
   int incr_e ;
   int incr_ne;

   int x = x0;
   int y = y0;

   PutPixel(x , y , c);

      if(dx > dy  && dy > 0)
      {
         
         d = (2 * dy - dx);
         incr_e = 2 * dy;
         incr_ne = 2 * (dy - dx);
        
         while(x != x1)
            {
               if (d <= 0) 
               {
                  d += incr_e;
                  x ++;
               } 
               else 
               {
                  d += incr_ne;
                  y ++;
                  x ++;
               }

             
               PutPixel(x, y, c);

               c.r += c.varR;
               c.g += c.varG;
               c.b += c.varB;
               c.a += c.varA;

            }

      }
      else
      {
         if(dy > 0 )
         {
         d = (2 * dx - dy);
           incr_e = 2 * dx;
           incr_ne = 2 * (dx - dy);

            while(y != y1)
            {
               if (d <= 0) 
               {
                  d += incr_e;
                  y ++;
               } 
               else 
               {
                  d += incr_ne;
                  y ++;
                  x ++;
               }
               
               PutPixel(x, y, c);
               c.r += c.varR;
               c.g += c.varG;
               c.b += c.varB;
               c.a += c.varA;
            }
      
         }
         else
         {
            if(fabs(dx) >= fabs(dy))
              {   
                  dy = -dy;
                  d = (2 * dy - dx);
                  incr_e = 2 * dy;
                  incr_ne = 2 * (dy - dx);

                  while(x != x1)
                  {
                     if (d <= 0) 
                     {
                        d += incr_e;
                        x ++;
                     } 
                     else 
                     {
                        d += incr_ne;
                        y --;
                        x ++;
                     }
 
                     PutPixel(x, y, c);
                     c.r += c.varR;
                     c.g += c.varG;
                     c.b += c.varB;
                     c.a += c.varA;
                  }
               }
               else
               {

                  dy = -dy;
                  d = (2 * dx - dy);
                  incr_e = 2 * dx;
                  incr_ne = 2 * (dx - dy);

                  while(y != y1)
                  {
                     if (d <= 0) 
                     {
                        d += incr_e;
                        y --;
                      
                     } 
                     else 
                     {
                        d += incr_ne;
                        y --;
                        x ++;
                     }

                     PutPixel(x, y, c);

                     c.r += c.varR;
                     c.g += c.varG;
                     c.b += c.varB;
                     c.a += c.varA;



                  }
               }
            }

      }

      c.r = aux.r;
      c.g = aux.g;
      c.b = aux.b;
      c.a = aux.a;

      c.rf = aux.rf;
      c.gf = aux.gf;
      c.bf = aux.bf;
      c.af = aux.af;

}


void DrawTriangle(int x0,int y0,int x1,int y1,int x2,int y2,color c)
{

   Reta(x0,y0,x1,y1,c);
   Reta(x1,y1,x2,y2,c);
   Reta(x2,y2,x0,y0,c);

}




#endif // _MYGL_H_
