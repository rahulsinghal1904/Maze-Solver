#ifndef __IMAZEREADER__
#define __IMAZEREADER__

#include <cstdlib>

class IMazeReader {
public:
	/*

		top down left right : set to true if cell has path to the specified direction
		outer : set to true if cell is part of start or end goal
	*/
	virtual void isVertex(int y, int x, bool & top, bool & down, bool & left, bool & right, bool & isGoal) = 0;

	/*
		set row and col to size of maze
	*/
	virtual void setSize(size_t & row, size_t & col) = 0;

};

#endif
