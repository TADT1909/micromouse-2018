// pseudo_code.h
#ifndef PSEUDO_CODE_H
#define PSEUDO_CODE_H
int currentLocation_X = 0,
	currentLocation_Y = 0;
#define MAZE_WIDTH 8  // 8x8
int dist[MAZE_WIDTH][MAZE_WIDTH],
	wall[MAZE_WIDTH][MAZE_WIDTH],
    pass[MAZE_WIDTH][MAZE_WIDTH];
#define NONE 0
#define NORTH 2
#define EAST 4
#define SOUTH 6
#define WEST 8
#define ALL NORTH | EAST | SOUTH | WEST;
int TURNS = 0; // đếm số lần xoay đầu -3 -2 -1 0 1 2 3
int CURRENT_DIRECTION = NORTH;

void initial_maze();

void floodfill();

void updateMaze();

int getCurrentDirection();

void addWalls(int row, int col, int direction);

void setWall(int row, int col, int direction);

void getBestDirection();

void nextStep();
#endif