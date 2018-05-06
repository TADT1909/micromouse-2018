/***************
 * Motor Class Declaration
 ***************/

#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"

class Motor {
 public:
  Motor(int pin1, int pin2, int enablePin);
  void setState(int state, double power);

  int enablePin;
  int pin1;
  int pin2;
  int state;
  double power;
};

#endif
