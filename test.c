#include "main.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h";


#define sgn(x) ((x<0)?-1:((x>0)?1:0)) //macro to return the sign of a

void line_fast(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color)
{
  int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;

  dx=x2-x1;      /* the horizontal distance of the line */
  dy=y2-y1;      /* the vertical distance of the line */
  dxabs=abs(dx);
  dyabs=abs(dy);
  sdx=sgn(dx);
  sdy=sgn(dy);
  x=dyabs>>1;
  y=dxabs>>1;
  px=x1;
  py=y1;


  if (dxabs>=dyabs) /* the line is more horizontal than vertical */
  {
    for(i=0;i<dxabs;i++)
    {
      y+=dyabs;
      if (y>=dxabs)
      {
        y-=dxabs;
        py+=sdy;
      }
      px+=sdx;

      UB_VGA_SetPixel(px,py,color);
    }
  }
  else /* the line is more vertical than horizontal */
  {
    for(i=0;i<dyabs;i++)
    {
      x+=dxabs;
      if (x>=dyabs)
      {
        x-=dyabs;
        px+=sdx;
      }
      py+=sdy;
      UB_VGA_SetPixel(px,py,color);
    }
  }
}
