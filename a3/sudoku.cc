//*********************************************************************
// CSPC 2620 Spring 2015 Prof: Robert
// File : sudoku.cc
// Written by: jefferson sylva-iriogbe
// Date : April 03, 2015
// This code implements the game of sudoku using recursive backtracking
//***y******************************************************************

#include "sudoku.h"
#include <iostream>

using namespace std;
Sudoku::Sudoku()
{
   clearPuzzle();
}


bool Sudoku::readPuzzle(std::istream & istr) {
   clearPuzzle();  // start fresh
   char a;

   // add appropriate code here

   for(int x=0; x < 9; x++)
   {
      for(int y=0; y < 9; y++)
      {
	 istr >> a;

	 if(a == '.')
	 {
	    board[y][x].state = Sudoku::SudokuEntry::UNSPECIFIED;
	    board[y][x].value = 0;
      	 }
	 else
	 {
	    definePuzzleEntry(x, y, a-'0');
	    board[y][x].state = Sudoku::SudokuEntry::GIVEN;
 	 }

	 if(x == 8 && y==8)
	 return true;
      }
   }
   return false;
}



bool Sudoku::solve() {

   int x=0, y=0;
   return recursive(x, y);  // change appropriately
}

void Sudoku::printPuzzle() const {
   // add code here

    for (int x = 0; x < 9; x++)
   {
      for (int y = 0; y < 9; y++)
      {
	 cout << board[y][x].value;
      }
      cout << endl;

   }
}

// **************** helper functions *****************************
// these are fully implemented


bool Sudoku::recursive(int a, int b) // helper recursive function
{
   int x;
  
   while (b <= 9 && board[a][b].value != 0)
   {
      a++;
      if(a == 9)
      {  b++; a=0;}
     
      if (b==9)
	 return true;
  
      for (x = 1; x < 10; x++)
      {
   
	 if (!conflicts(b,a,x) && recursive(a,b))
	 {  definePuzzleEntry(b,a,x); }
      }
   }
   return true;
}


void Sudoku::definePuzzleEntry(int x, int y, int val) {
   board[y][x].value = val;
   board[y][x].state = Sudoku::SudokuEntry::GIVEN;
}


void Sudoku::clearPuzzle() {
   for (int x = 0; x < 9; x++)
      for (int y = 0; y < 9; y++) {
	 board[y][x].value = 0;
	 board[y][x].state = Sudoku::SudokuEntry::UNSPECIFIED;
      }
}


bool Sudoku::conflicts(int x, int y, int val) const {
   return existsOnRow(y, val) || existsOnCol(x, val) ||
      existsInBox(x, y, val);
}


bool Sudoku::existsOnRow(int y, int val) const {
   for (int x = 0; x<9; x++) {
      if (!isUnspecified(x, y) && getVal(x, y) == val)
	 return true;
   }
   return false;
}


bool Sudoku::existsOnCol(int x, int val) const {
   for (int y = 0; y < 9; y++) {
      if (!isUnspecified(x,y) && getVal(x,y) == val)
	 return true;
   }
   return false;
}


bool Sudoku::existsInBox(int x, int y, int val) const {
   int boxx = (x/3)*3;  // the box top left corner coords
   int boxy = (y/3)*3;
	
   for (int i=0; i<3; i++)  // traverse all bx elements
      for (int j=0; j<3; j++)
	 // if the box element is given or tentative and if the value
	 // matches the query, then we have conflict 
	 if (!isUnspecified(boxx+i, boxy+j) && getVal(boxx+i, boxy+j) == val)
	    return true;

   return false;
}


void Sudoku::setTentative(int x, int y, int val) {
   if (!isGiven(x,y)) {
      board[y][x].value = val;
      board[y][x].state = Sudoku::SudokuEntry::TENTATIVE;
   }
}


bool Sudoku::isGiven(int x, int y) const {
   return board[y][x].state == Sudoku::SudokuEntry::GIVEN;
}


bool Sudoku::isUnspecified(int x, int y) const {
   return board[y][x].state == Sudoku::SudokuEntry::UNSPECIFIED;
}


int Sudoku::getVal(int x, int y) const {
   return board[y][x].value;
}


void Sudoku::clearEntry(int x, int y) {
   if (!isGiven(x,y)) {
      board[y][x].state = Sudoku::SudokuEntry::UNSPECIFIED;
      board[y][x].value = 0;
   }
}

