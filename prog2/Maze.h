// File Maze.h
// Brian Franco, Transy U
// Cs 2444, Fall 2021
//		Interface: Maze Class
//
#ifndef		MAZE_H
#define		MAZE_H 

#include <iostream>
#include <fstream>
using namespace std;

class Maze {

public: 
	/// public member functions
	Maze (void);
	~Maze (void);
	// mutators
	bool read (ifstream& inFile);
	bool openSpace (int r, int c); 
	void clean (void);
	void change (void); 

	// accessor
	void print (void) const; 

private:
// private member functions and private variables 

	// symbolic constants
	enum {
		MAX = 52,
		PASSAGEWAY = '?',
		BLOCKED = 'X',
		SUCESSFULSPOT = '.',
		RED = 4,
		ORANGE = 2,
		BLUE = 3, 
		GREEN = 1,
		BLACK = 0
	};

	// variables
	char grid[MAX][MAX];
	int rowsAndCols;
};
#endif 