#ifndef __CONST_H
#define __CONST_H

#define IR_WALL_THRESHOLD  147 //tinh chỉnh
#define IR_NO_WALL_THRESHOLD 500 //tinh chỉnh

#define MAX_SPEED 208 // tinh chỉnh
#define NORMAL_SPEED 240 //190 // tinh chỉnh
#define IDLE_SPEED 50 // tinh chỉnh
#define TURNING_SPEED 20 // tinh chỉnh
#define ROTATE_CONST 550

//Takes 2 motors and goes forward, if it does not go forward adjust offset
//values until it does.  These will also take a negative number and go backwards
const int offsetA = 1;
const int offsetB = -1;

#endif /* __CONST_H */
