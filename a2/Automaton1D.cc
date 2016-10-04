//*********************************************************************
// CSPC 2620 Spring 2015 Prof: Robert
// File : Automaton1D.cc
// Written by: jefferson sylva-iriogbe
// Date : March 4, 2015
//*********************************************************************



#include "Automaton1D.h"
#include <cstring>
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include <cstdlib>
//using namespace std;
Automaton1D::Automaton1D()
{
   int n;
   cout << "Enter a positive integer representing the size of the Automaton : " ;
   cin >> n;
   size1=n;
   //size2=b;
   dynamic1 = new int[n];
   dynamic2 = dynamic1;

   for (int c=0; c < n; c++)
   {
      setCell(c , false);
   }
   int runs;
   cout << "Enter the number of iterations that the automation will run : ";
   cin >> runs;
   
   int g;
   cout << "Enter the sequence of cells that are to be initialized to 1 : ";
   cin >> g;
   setCell(g , true);

      while (g > 0)
   {
      cin >> g;
      setCell(g,true);
   }

      for (int b=0; b < runs; b++)
      {
	 run();
	 cout << endl;
      }
dynamic1 = NULL;
   dynamic2 = NULL;
      //~Automaton1D();

}

Automaton1D::~Automaton1D()
{
   dynamic1 = NULL;
   dynamic2 = NULL;
   //delete [] dynamic1;
   //dynamic1=nullptr;
   //delete [] dynamic2;
   //dynamic2=nullptr;
}

int Automaton1D::size()
{
    
   return size1;
}

void Automaton1D::setCell(int index, bool value)
{
   if (value)
   {
      dynamic1[index] = 1;
   }

   else
      dynamic1[index] = 0;
}


void Automaton1D::run()
{
   
   int i=0;
   bool j,f;
   string bee;
   
   
   /* if(runs > 0)
   {
       for (g=0; g < runs; g++)
       {
   */
   
	  for (i=0; i < size1; i++)
	  {
	     if (i==0)
	     {
	  j = ((!dynamic1[size1-1] && dynamic1[i]) || (dynamic1[size1] && !dynamic1[i]));
	     
	  setCell(0 , j);
	     }
	  
	     f = ((!dynamic1[i-1] && dynamic1[i]) || (dynamic1[i-1] && !dynamic1[i]));    
	     
	     setCell(i,f);
	     
	  
      
	     cout << str() << endl;
       
      int *temp= dynamic1;
      
      dynamic2=dynamic1;
      
      dynamic1=temp;
	  }
      

}
   




string Automaton1D::str()
   {
      string rep;

      for (int i=0; i < size1; i++)
      {
	 if (dynamic1[i]==1)
	    rep += '*';
	 else
	    rep += ' ';
	 
      }
      
      return rep;
   }
