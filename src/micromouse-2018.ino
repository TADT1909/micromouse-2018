// MicroMouse-499198.ino

#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>
#include <PID_v1.h>
#include <Sparkfun_TB6612FNG.h>
#include "config.h"  //configure pinouts
#include "velocity.h"  //calculate velocity function
#include "turns.h"  // robot turning functions

Motor left_motor = Motor(left_IN1, left_IN2, PWM_left, offset_left, STBY);
Motor right_motor = Motor(right_IN1, right_IN2, PWM_right, offset_right, STBY);
Encoder enc_left(encoder_left_A, encoder_left_B);
Encoder enc_right(encoder_right_A, encoder_right_B);
long v_left, v_right;

double Setpoint, Input, Output;
double Kp=2, Ki=5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
int speed = 205; // 80% of highest capability of speed


void setup() {
  // put your setup code here, to run once:
  pinMode(IR_left, INPUT);
  pinMode(IR_right, INPUT);
  pinMode(IR_front, INPUT);

  Setpoint = 100;
  myPID.SetMode(AUTOMATIC);

}

void loop() {
  // drive robot forward with speed
  // If a negative number is used for speed
  // it will go backwards
  forward(left_motor, right_motor, speed);

  // EITHER a positive number or a negative
  // number for speed will cause it to go backwards
  back(left_motor, right_motor, -speed);

  // Use of the brake function which takes as arguments two motors.
  // Note that functions do not stop motors on their own.
  brake(left_motor, right_motor);

  // Use of the left and right functions which take as arguements two
  // motors and a speed.
  // This function turns both motors to move in the appropriate direction.
  left(left_motor, right_motor, speed);
  right(left_motor, right_motor, speed);

  v_right = velocity(enc_right);
}
