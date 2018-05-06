/***************
 * MovementController Class Declaration
 ***************/

#ifndef MOVEMENTCONTROLLER_H
#define MOVEMENTCONTROLLER_H

#include <Encoder.h>
#include <Math.h>
#include <PID_v1.h>
#include "Arduino.h"
#include "Maze.h"
#include "Motor.h"
#include "SensorController.h"
#include "const.h"

namespace MovementController {

extern double moveSpeedRight;
extern double moveSpeedLeft;
extern double input;
extern double output;
extern double setpoint;

extern Motor* right;
extern Motor* left;

// extern PID * pidEncoder;
// extern PID * pidIR;

void updatePID(int state);
double adjustPower(int follow);

void go(int forward, int duration, int power);
void goStraight();
void goBack();
void brake(int state);
void turn(int dir);
void accel(int startPow, int endPow, int time);
void straighten();
void calibrate();
}  // namespace MovementController

#endif
