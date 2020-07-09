#ifndef __MAZEPRINT__
#define __MAZEPRINT__

#include <chrono>
#include <thread>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include "Maze.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::stringstream;
using std::flush;


class MazePrint {

	Maze * maze;
	vector<string> maze_txt; // used for animation

public:

	void setMaze(Maze &m, vector<string>& maze_text) {
		maze = &m;
		maze_txt = maze_text;
	}

	void printAt(Vertex * v, char c) {
		if (!v)	return;
		maze_txt[(v->getRow() * 2) + 1][(v->getColumn() * 4) + 2] = c;
	}

	void printMaze() {
		for (auto & x : maze_txt)
			cout << x << '\n';
		cout << '\n';
	}

	void printNodes() {
		for (auto it = maze->begin(); it != maze->end(); ++it)
			printAt(*it, '#');
	}

#ifdef animation

	}
#else
	void printPath(const list<Vertex*> &path) {
		for (auto & x : path)
			printAt(x, '#');
		for (auto & x : maze_txt)
			cout << x << '\n';
		cout << '\n';
	}
#endif

	void reset() {
		for(auto & x : *maze)
			maze_txt[(x->getRow() * 2) + 1][(x->getColumn() * 4) + 2] = ' ';
	}

	void printVisted() {
		for (auto & x : *maze)
			if (x->isVisted()) printAt(x, '*');
	}



};

#endif
