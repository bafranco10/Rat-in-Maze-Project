// File: MazeTest.cpp
// Brian Franco, Transy U
// CS 2444, Fall 2021
//
// Test driver for Maze Class
#include <iostream>
#include <fstream>
#include "Maze.h"
using namespace std;
//
/// main program
// collaborated with Aarom Bell and Olivia Greinke
int main (void) {
	ifstream	inFile;
	Maze	Maze;

	inFile.open ("inMaze.txt"); // open a file from project folder
	if (!inFile.is_open()) { // if file is not opened then return false and gracefully crash program
		cout << "ERROR: couldn't open inMaze.txt input file" << endl;
		exit (1);
	}
	// reads .txt file 
	Maze.read(inFile); 
	// prints the content of the maze if a solution is found 
	// otherwise it prints an error message
	// starts at 1,1 because of bouncy wall
	Maze.print();
	if (!Maze.openSpace (1,1)) {
		cout << endl << "ERROR: NO MAZE SOLUTIONS " << " ";
	}
	else {
		cout << "FOUND A SOLUTION " << endl; 
		Maze.change (); 
		Maze.print (); 
	}
}
