// pseudo_code.cpp
#ifndef PSEUDO_CODE_CPP
#define PSEUDO_CODE_CPP
#include "pseudo_code.h"
void initial_maze() {
  for (int i = 0; i < MAZE_WIDTH; i++) {
    wall[i][i] = NONE;
    pass[i][i] = NONE;
  }
}
void updateMaze() {}
// add walls for current direction and nearby ones
void addWalls(int row, int col, int direction) {
  setWall(row, col, direction);
  switch (direction) {
    case NORTH:
      // do something
      setWall(row + 1, col, SOUTH);
      break;
    case EAST:
      // do something
      setWall(row, col + 1, WEST);
      break;
    case SOUTH:
      // do something
      setWall(row - 1, col, NORTH);
      break;
    case WEST:
      // do something
      setWall(row, col - 1, EAST);
      break;
    default:
      return;
      // do something
  }
}
// set wall for current direction only
void setWall(int row, int col, int direction) {
  // if current block not over maze size
  // then add walls
  if (row > MAZE_WIDTH || col > MAZE_WIDTH) return;
  	else wall[row][col] = direction;
}

int getCurrentDirection(int _PREVIOUS_DIRECTION, int _TURNS){
	int newD
	switch (_TURNS) {
	    case -3:
	      // do something
	      break;
	    case -2:
	      // do something
	      break;
	    case -1:
	      // do something
	      {
	      	switch (_PREVIOUS_DIRECTION) {
	      	    case :
	      	      // do something
	      	      break;
	      	    case :
	      	      // do something
	      	      break;
	      	    case :
	      	      // do something
	      	      break;
	      	    case :
	      	      // do something
	      	      break;
	      	    default:
	      	      // do something
	      	}
	      }
	      break;
	    case 0:
	    return _PREVIOUS_DIRECTION;
	      // do something
	      break;
	    case 1:
	      // do something
	      break;
	    case 2:
	      // do something
	      break;
	    case 3:
	      // do something
	      break;
	    default:
	      // do something
	}
}

#endif