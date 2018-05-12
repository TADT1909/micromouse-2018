// new-version.h
#include <CheapStepper.h>
#include "pinouts.h"
#include "IR_sensor.h"
#include "motor.h"

// #include "pseudo_code.h"
// CheapStepper stepper_left(IN_A_1, IN_A_2, IN_A_3, IN_A_4);
// CheapStepper stepper_right(IN_B_1, IN_B_2, IN_B_3, IN_B_4);
// stepper_left.setRpm(RPM);
// stepper_right.setRpm(RPM);
void setup(){
Serial.begin(115200);
initiate_IR();
stepper_left.setRpm(RPM);
stepper_right.setRpm(RPM);
}

void loop(){

}