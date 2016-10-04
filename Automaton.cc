#ifndef AUTOMATON_H
#define AUTOMATON_H
#include <cstring>
#include <string>
#include <memory>
#include <iostream>
#include <vector>

class Automaton1D
{
private:
   int *dynamic1;
   int *dynamic2;
   int size1;
   // int size2;

public:
   Automaton1D(int);
   ~Automaton1D();
   int size();
   void setCell(int , bool); //set the value of the cell to 1 or 0 depending on the truth value of the boolean expression. cells are indexed from 0 to size -1
   void run(); //changes the current state of the automaton according to the boolean formula ( c'=(!L && C) || (L && !c))
   string str(); //a representation of the current state of the automaton. value 0 is represented by space and value 1 by *
   
 };

Automaton1D::Automaton1D(int n)
{
   size1=n;
   //size2=b;
   dynamic1 = new int(n);
   dynamic2 = new int(n);
}

Automaton1D::~Automaton1D()
{
   delete []dynamic1;
   //dynamic1=nullptr;
   delete []dynamic2;
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
      dynamic2[index] = 1;
   }

   else
      dynamic2[index] = 0;
}


void Automaton1D::run()
{
   int i=0;
   bool j;
   std::string bee;
   
   j = ((!dynamic1[size1] && dynamic1[0]) || (dynamic1[size1] && !dynamic1[0]));

   setCell(0 , j);
	
		  
   for (i=1; i < size1; i++)
   {
      j= ((!dynamic1[i-1] && dynamic1[i]) || (dynamic1[i-1] && !dynamic1[i]));     //	  (!C=(!L && C) || (L && !c))

      setCell(i,j);
   }

   bee = str();
   
   int *temp= dynamic1;
   dynamic2=dynamic1;
   dynamic1=temp;
   
}


std::string Automaton1D::str()
   {
      std::string rep;

      for (int i=0; i < size1; i++)
      {
	 if (dynamic2[i]==1)
	    rep += '*';
	 else
	    rep += ' ';
	 
      }
      
      return rep;
   }
int main()
{
   
   return 0;
}



 #endif

   
