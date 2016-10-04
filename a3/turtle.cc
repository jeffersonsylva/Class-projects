//*******************************************************************
// CPSC2620 Spring 2015 Prof: Robert
// Implementation File for Turtle class
// Purpose: To create the Turtle Class functions
// Written by: Arie
// Revised by: RB
// Date: Feb 6. 2015
//*******************************************************************
#include"turtle.h"
#include"CImg.h" // graphic package
#include<cmath>
#include<iostream>
using namespace std;
using namespace cimg_library;

// set pallette upon which to draw to be 500,500
const int LENGTH = 500;
const int WIDTH = 500;
// create the "pallette" on which to draw (white background)
CImg<unsigned char> image(LENGTH,WIDTH,1,3,255);
const unsigned char color[]={0,0,0}; // black

const double PI = 3.14159265359;
const double DEG_IN_RAD = PI/180.0;

// Default constructor
Turtle::Turtle()
{
   x = LENGTH/2;
   y = WIDTH/2;
   angle = 90;
   penDown = true;
}

// Second constructor that takes to ints designating the starting x,y location
Turtle::Turtle(int a, int b)
{
   x = a;
   y = b;
   angle = 90;
   penDown = true;
}

// Pen Down function
void Turtle::pu()
{
   penDown = false;
}

// Pen up function
void Turtle::pd()
{
   penDown = true;
}

// Move forward function
void Turtle::fd(double amt) // move forward
{
   double newX,newY;
   newX=(x-(amt * cos(angle * DEG_IN_RAD)));
   newY=(y-(amt * sin(angle * DEG_IN_RAD)));
   if(penDown)
      image.draw_line(x,y,newX,newY,color);
   x = newX;
   y = newY;
}

// move turtle to home position (center of pallette)
void Turtle::home()
{
   double newX = LENGTH/2;
   double newY = WIDTH/2;
   if(penDown)
      image.draw_line(x,y,newX,newY,color);
   x = newX;
   y = newY;
   angle = 90;
}

// goTo function that allows user to move turtle to new x,y position
void Turtle::goTo(double xVal, double yVal)
{
   if(penDown)
      image.draw_line(x,y,xVal,yVal,color);
   x = xVal;
   y = yVal;
}

// setAngle function that resets angle
void Turtle::setAngle(int ang)
{
   angle = ang;
}

// backwards function (simply calls fd function with - argument
void Turtle::bk(double amt) // move back
{
   fd(-amt);
}

// turtle display function
void Turtle::display() const
{
   CImgDisplay main_disp(image,"Turtle");
   while(!main_disp.is_closed())
      main_disp.wait();
}

// turn right function
void Turtle::rt(int amt)
{
   angle += amt;
}
// turn left function
void Turtle::lt(int amt)
{
   angle -= amt;
}


