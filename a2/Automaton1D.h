//*********************************************************************
// CSPC 2620 Spring 2015 Prof: Robert
// File : Automaton1D.h
// Written by: jefferson sylva-iriogbe
// Date : March 4, 2015
//*********************************************************************


#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <string>

using namespace std;
class Automaton1D

{
private:
   int *dynamic1;
   int *dynamic2;
   int size1;
   // int size2;

public:
   Automaton1D();
   ~Automaton1D();
   int size();
   void setCell(int , bool); //set the value of the cell to 1 or 0 depending on the truth value of the boolean expression. cells are indexed from 0 to size -1
   void run(); //changes the current state of the automaton according to the boolean formula ( c'=(!L && C) || (L && !c))
   string str(); //a representation of the current state of the automaton. value 0 is represented by space and value 1 by *
   
 };



 #endif
