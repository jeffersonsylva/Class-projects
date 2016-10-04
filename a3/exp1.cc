//*********************************************************************
// CSPC 2620 Spring 2015 Prof: Robert
// File : exp1.cc
// Written by: jefferson sylva-iriogbe
// Date : April 03, 2015
//This program performs some calculations using recursion 
//*********************************************************************
#include <iostream>

using namespace std;


double exponential(double b,int x)
{
   
   if (x==0)
      return 1;
     
   else if(x > 1 || x == 1)
   {
      
      return b * (exponential(b,x-1));	 
   }
   
}
