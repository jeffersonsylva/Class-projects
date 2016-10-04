//*********************************************************************
// CSPC 2620 Spring 2015 Prof: Robert
// File : koch.cc
// Written by: jefferson sylva-iriogbe
// Date : April 03, 2015
// This program implements the drawing of koch lines using recursive functions
// with the help of cimg
//*********************************************************************




#include <iostream>
#include "turtle.h"
using namespace std;

void koch(int , double);

double width=480;
 Turtle k;
int main()
{
   int order;
   k.pu();
   k.goTo(10,290);
   k.rt(90);

   cout << " Enter the desired order " << endl;
   cin >> order;

   koch(order , width);

   k.display();
   return 0;
}

void koch(int order2 , double width2)
{
   if (order2==0)
   {
      k.pd();
      k.fd(width2);
   }

   else
   {
      k.pd();
      koch(order2-1, width/3);
      k.lt(60);

      koch(order2-1, width/3);
      k.rt(120);

      koch(order2-1 , width/3);
      k.lt(60);

      koch(order2-1 , width/3);
   }

}
