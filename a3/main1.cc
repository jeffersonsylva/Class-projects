//*********************************************************************
// CSPC 2620 Spring 2015 Prof: Robert
// File : main1y.cc
// Written by: jefferson sylva-iriogbe
// Date : April 03, 2015
//This program performs implements the recursion calculations defined in
//my other codes exp1.cc and .cc
//*********************************************************************

#include <iostream>
#include <stdexcept>
using namespace std;
// the exponential function.
// OBS: the prototype is unique but there exist two different
// implementations in files exp1.cc and exp2.cc.
double exponential(double, int);

int main() {


   double x;
   int y;
   cout << "give me a number" << endl;
   cin >> x;
   cout << "give me another number " << endl;
   cin >> y;

   try
   {
      if (y < 0)
	 throw runtime_error("");
      else
	 cout << exponential(x,y);
   }
   
   
   catch(runtime_error)
   {
      cout << "negative exponent" << endl;
   }
   

   
	// write the code for your main function here.
	// this main function will be used for both 1.a and 1.b problems
	
	return 0;
}
