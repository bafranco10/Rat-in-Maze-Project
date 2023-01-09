// File: Maze.cpp 
// Brian Franco, Transy U
// CS 2444, Fall 2021
// 
// Implementation: OilField Class
// 
#include	"Maze.h"
// constructor, destructor

Maze::Maze (void) { }
Maze::~Maze (void) { }

// mutators
// collaborated with Aaron Bell and Olivia Greinke on my openSpace function and change function 

//read
// Read the contents of a grid array from an open file
// convert to array of int 0's and 1's
//
bool Maze::read (ifstream& inpt) {
	// read dimenstions and check that they are not 0
	inpt >> rowsAndCols;
	if ((!rowsAndCols || rowsAndCols > MAX - 2)) {
		return false;
	}
	// set grid array to all 0's 
	clean ();

	// convert input to 0s and 1s insetting inside a "bouncy wall" of 0's
	char temp;
	for (int r = 1; r <= rowsAndCols; ++r) {
		for (int c = 1; c<= rowsAndCols; ++ c) {
			inpt >> temp; 
			if (temp == PASSAGEWAY) {
				grid [r][c] = GREEN;
			}
			else { // blocked passageway is the other option
				grid [r][c] = BLACK;
				}
			}
		}
	// file is read successfully
	return true; 
}

// clean 
// set all elements of a grid to 0
//
void Maze::clean (void) {
	for (int r = 0; r < MAX; ++r) {
		for (int c = 0; c < MAX; ++c) {
			grid [r][c] = 0;
		}
	}
}
// change fn
// Checks the color of the spots in maze to convert to characters for output file
// symbolic constants all defined in header file
void Maze::change(void) {
	for (int r=0; r<MAX; r++) {
		for (int c=0; c<MAX; c++) {
			if (grid[r][c] == ORANGE) { // part of the solution
				grid [r][c] = SUCESSFULSPOT;
			}
			else if (grid[r][c] == BLACK) { // spot in maze is blocked
			grid [r][c] = BLOCKED; 
			}
			else {
			grid [r][c] = PASSAGEWAY; // open spaces that were never reached
			}
		}
		
	}
}
// openSpace
// We will look for available spots and find our way around tbe maze recursively
// returns true or false to indicate if the square is part of the solution

bool Maze::openSpace (int r, int c) {
	// base cases if path is blocked, or a color other than green
	if (grid [r][c] == BLACK || grid [r][c] == ORANGE || grid [r][c] == BLUE) {
		return false; 
	}
	// sets first square to orange to show it has been visited
	grid [r][c] = ORANGE;
	// base case we have reached the end of the maze
	if (c== rowsAndCols && r==rowsAndCols) {
		return true; 
	}
	// all these return true to parent square if it is a part of the solution
	if (openSpace (r-1, c)) {
		return true; 
	}
	else if (openSpace (r+1, c)) {
		return true;
	}
	else if (openSpace (r,c -1)) {
		return true;
	}
	else if (openSpace (r,c+1)) {
		return true; 
	}
	else {
		// if square is not part of the path then it is blue and returns false
		grid [r][c] = BLUE; 
		return false; 
	}
}
	
// accessors 
//print 
// print the solution to the maze
// output file format is taken from codeBlocks 
void Maze::print (void) const {
	ofstream myFile;
	myFile.open ("outMaze.txt");
	for (int r=1; r<= rowsAndCols; r++) {
		for (int c=1; c<=rowsAndCols; c++) {
			cout << grid [r][c] << " ";
			myFile << grid [r][c] << " ";
		}
		cout << endl; 
		myFile << endl;
	}
	myFile.close();
}