//test_stepper_new_lib.ino
// RUN GOOD
#include <Stepper.h>

// StepperMotor motor(8,9,10,11);
// StepperMotor motor(6,7,8,9);
StepperMotor motor(2,3,4,5);

void setup(){
  Serial.begin(9600);
  motor.setStepDuration(1);
}

void loop(){
  motor.step(572624);
  delay(2000);
  motor.step(-1000);
  delay(2000);
}