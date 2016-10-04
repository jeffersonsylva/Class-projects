//*********************************************************************
// CSPC 2620 Spring 2015 Prof: Robert
// File : exp2.cc
// Written by: jefferson sylva-iriogbe
// Date : April 03, 2015
//This program performs some calculations using recursion 
//*********************************************************************

#include <iostream>
using namespace std;



double exponential(double b,int x)
{

   double var;
   if(x==0)
      return 1;
   
   else if(x % 2 == 0)
   {
      
      var = exponential(b,x/2);

      return var * var;
      
   }

   else if(x % 2 != 0)
   {
 
      return b * exponential(b,x-1);

   }
   
}
