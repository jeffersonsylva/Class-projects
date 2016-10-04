//*********************************************************************
// CSPC 2620 Spring 2015 Prof: Robert
// File : main3.cc
// Written by: jefferson sylva-iriogbe
// Date : April 03, 2015
// This program implements main function for the sudoku game code
// it implements some of the major functions declared in the code sudoku.cc 
//*********************************************************************


#include <iostream>
#include <fstream>
#include <string>
#include "sudoku.h"
#include<istream>
using namespace std;
// main function declaration that allows processing command line
// arguments
Sudoku h;
int main(int argc, char* argv[]) {
  // argc represents the number of command line arguments, including
  // the name of the executable itself.
  std::cout << "argc is " << argc << std::endl;
  for (int i = 0; i<argc; i++)
     std::cout << "argv[" << i << "] is " << argv[i] << std::endl;

  ifstream fin;
  fin.open(argv[1]);
  if (!fin.good())
  {
     cout << "Error opening file [" << argv[1] << "]"<< endl;
     return 0;

  }
  else
  {
  h.readPuzzle(fin);
  h.printPuzzle();
  cout << endl;
  h.solve();
  if(!h.solve())
  {
     cout << "No solution found.";
     return 0;
  }
  cout << "SOLUTION" << endl;

  h.printPuzzle();
  fin.close();
  }
  return 0;
}
