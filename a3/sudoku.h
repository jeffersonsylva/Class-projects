/* Sudoku solver class
	 CPSC 2620 Assignment 3 Solution
	 Author: Robert Benkoczi
*/
#include <istream>


class Sudoku {
  private:
   bool recursive(int, int);
   bool puzzleRecursive(int x, int y);
	// the Sudoku board. An entry on the board can be one of: a) state
	// GIVEN, value [1-9] - it is part of the problem and cannot be
	// changed
	// b) state UNSPECIFIED, value arbitrary - the puzzle requires that
	// we find a value for such entry.
	// c) state TENTATIVE, value [1-9] - any unspecified entry can be
	// set a tentative value as part of the solving algorithm; tentative
	// entries can be erased (set as UNSPECIFIED) or assigned other
	// tentative values
	struct SudokuEntry {
		enum State {GIVEN, TENTATIVE, UNSPECIFIED}; // type of a Sudoku entry

		int value;  // legal values [1-9]
		State state;  // state as per description above
	};

	// the 9x9 board
	SudokuEntry board[9][9];

public:
	// default constructor; initializes the board with all entries
	// unspecified. 
	Sudoku();

	// reads the puzzle from input stream istr. The input consists of 9
	// strings of size 9 each containing either a digit or character
	// . for an unspecified entry. The first string corresponds to row
	// with coordinate y=0, the second to row with y=1, etc. The first
	// character in a string corresponds to an entry with coordinate
	// x=0, the second character to x=1, etc.
	// NOTE: does not check if the entries given are conflicting.
	// RETURN: true, if puzzle is successfuly read,
	//         false, in case of errors; the Sudoku object is cleared in
	// this case.
	bool readPuzzle(std::istream & istr);

	// solves the puzzle: if a solution exists, the unspecified entries
	// are assigned values in such a way that these entries obey sudoku
	// constraints.
	// return: true if a solution exists and is found
	//         false if a solution doesn't exist.
	bool solve();

	// prints the puzzle to std::cout
	// all tentative and given entries display the value of each entry,
	// unspecified entries are displayed by '.'. The output uses the
	// same data representation discussed for function readPuzzle.
	void printPuzzle() const;

private:
	// add one recursive function called by solve() and any helper
	// functions you think are necessary

	// a set of helper methods is declared below to assist you in
	// writing the recursive function to generate a solution for the
	// Sudoku puzzle.
	
	// This function can be used to define the puzzle: sets one entry
  // with coordinates x,y to value val and state GIVEN; the entry
  // remains set until clearPuzzle() is called.  NOTE: coordinates x
  // and y must be integers in the interval [0, 8].  NOTE 2: does not
  // check if val for entry x,y is conflicting
	void definePuzzleEntry(int x, int y, int val);

	// clears the Sudoku puzzle definition (all entries are set as
	// "unspecified").
	// NOTE: useful in conjunction with definePuzzleEntry
	void clearPuzzle();

	// returns true if  a value of val at coordinates x and y conflicts
	// with other entries that are given or tentative
  // PRECONDITION: entry x,y should NOT contain value val that is
	// tested, otherwise the function returns true 
	// NOTE: the Sudoku object remains unchanged
	// NOTE 2: typical usage - x,y is unspecified and function conflicts
	// is called to identify which values can possibly be set for x,y
	bool conflicts(int x, int y, int val) const;

	// returns true if val is present on row y
	bool existsOnRow(int y, int val) const;

	// returns true if val is present on colmn x
	bool existsOnCol(int x, int val) const;

	// returns true if val exists in box containing element with coords
	// x and y
	bool existsInBox(int x, int y, int val) const;

	// sets the board entry to value val ** tentatively **
	// NOTE: does nothing if the x,y entry is GIVEN
	void setTentative(int x, int y, int val);

	// the inverse of setTentative. When clearEntry is called, if the
	// entry has state TENTATIVE, it makes it UNSPECIFIED; does nothing when
	// the entry has state GIVEN.
	void clearEntry(int x, int y);

	// returns true if entry x,y has state GIVEN (it is part of the input)
	bool isGiven(int x, int y) const;

	// returns true if entry x,y has state UNSPECIFIED
	bool isUnspecified(int x, int y) const;

	// returns the value of entry x,y
	int getVal(int x, int y) const;
};
