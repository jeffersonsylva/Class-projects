//*********************************************************************
// CSPC 2620 Spring 2015 Prof: Robert
// File : turtle.cc
// Purpose : Creates a turtle program which can be used to draw objects of
//           different shapes and sizes
// Written by: jefferson sylva-iriogbe
// Date : Feb 3, 2015
//*********************************************************************


#include<iostream>
#include"/home/lib2620/lect/include/CImg.h"
#include<cmath>
#include<string>
#include<iomanip>
#include"turtle.h"

using namespace std;
using namespace cimg_library;


const double PI= 3.14159;
CImg<unsigned char> blank(700,700,1,3,255);
const unsigned char color1[]={0,0,0};


turtle::turtle()
{
   x=350; y=350; penDown = true; orientation = 270;
}

turtle::turtle(double xx, double yy , bool penn , int orientationn)
{
   x = xx; y = yy; penDown = penn; orientation = orientationn;
 }
void turtle::fd(int b)
{
   double xx, yy;

   xx = x+(b  * cos(orientation * PI / 180.0));
   yy = y+(b  * sin(orientation * PI / 180.0));

   if (penDown)
   {
      blank.draw_line(x,y,xx,yy,color1);
   }

   x=xx;
   y=yy;
}

void turtle::bk(int c)
{
   double xx, yy;

   xx = x - (c  * cos(orientation * PI / 180.0));
   yy = y - (c  * sin(orientation * PI / 180.0));

   if (penDown)
   {
      blank.draw_line(x,y,xx,yy,color1);
   }

   x=xx;
   y=yy;
}

void turtle::home()
{
   if (penDown)
   {
      blank.draw_line(x,y,350,350,color1);
   }

   x=350;
   y=350;
   orientation = 0;
   
}

void turtle::rt(int xx)
{  
 
   orientation += xx;
   
   if (orientation > 360)
      
      orientation = orientation % 360;
   
   
   
}
void turtle::lt(int xx)
{

   orientation -= xx;

   if (orientation < 0)
   {
      orientation += 360;
   }

   if (orientation > 360)
   {
      orientation %= 360;
   }
}

void turtle::pu()
{
   penDown = false;
}
void turtle::pd()
{
   penDown = true;
}

void turtle::display()
{
   CImgDisplay main_disp(blank,"Blank Image");
   while(!main_disp.is_closed())
      main_disp.wait();
}

void turtle::circle(turtle r)
{

   r={500   ,200 , true ,0};
   for(int x=0; x < 360; x++)
   {
     
      r.lt(1);
      r.fd(1);
   }     

}


void turtle::semicircle(turtle b)
{
   b={100, 600 , true , 270};
   
   for(int x=0; x < 180; x++)
   {
     
      b.rt(1);
      b.fd(1);
      
   }   
}

void turtle::leaf(turtle c)
{
   c={440, 500 , true ,   0};
   for(int i=0; i < 4; i++)
   {
   for(int x=0; x < 180  ; x++)
   {
      c.rt(1);
      c.fd(1); 
      
   }
   c.rt(90);
   }

}
void turtle::triangle(turtle a)
{
   a= {100, 200 ,true , 0};
   a.lt(90);
   for (int i=0; i < 3; i++)
   {
      a.fd(110);
      a.rt(120);
    }
   
}
void turtle::thing(turtle t)
{
   t={280, 280,true ,0};
   for (int i=0; i< 8; i++)
   {
      t.rt(45);
      for (int j=0; j<2; j++)
      {
	 for(int k=0; k<90; k++)
	 {
	    t.fd(2);
	    t.rt(2);
	 }
	 t.rt(90);
       }
   }

}
