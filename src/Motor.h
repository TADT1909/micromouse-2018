// Motor.h
#ifndef MOTOR_H
#define MOTOR_H

#include "config.h"
#include "const.h"
#include "IR.h"

static int calibrated_speed_turn_left = NORMAL_SPEED;
static int calibrated_speed_turn_right = NORMAL_SPEED;

Motor motorA = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motorB = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

void turn_left(){
	count_B = 0;
	motorA.drive(-IDLE_SPEED,0);
for (int i = 0; i < (MAX_SPEED - NORMAL_SPEED); i+=1 ){
	motorB.drive(NORMAL_SPEED + i, 0);
	if (count_B >= ROTATE_CONST) break;
}

}
void turn_right(){
	count_A = 0;
	motorB.drive(-IDLE_SPEED,0);
	for (int i = 0; i < (MAX_SPEED - NORMAL_SPEED); i+=1 ){
		motorA.drive(NORMAL_SPEED + i, 0);
		if (count_B >= ROTATE_CONST) break;
	}
}
void go_forward(){
	if (IR_left() < IR_right()){ // bên trái có tường
	// for (int i = 0; i < (MAX_SPEED - NORMAL_SPEED); i+=1 ){
		calibrated_speed_turn_left++;
		if (calibrated_speed_turn_left >= 255) calibrated_speed_turn_right--;
		// calibrated_speed_turn_right -= i;
		motorA.drive(calibrated_speed_turn_left, 0);
		motorB.drive(calibrated_speed_turn_right, 0);
		// if (IR_left() >= IR_right()) break;
		// }
	}
	if (IR_left() > IR_right()){ // bên phải có tường
	// for (int i = 0; i < (MAX_SPEED - NORMAL_SPEED); i+=1 ){
		// calibrated_speed_turn_left -= i;
		calibrated_speed_turn_right++;
		if (calibrated_speed_turn_right >= 255) calibrated_speed_turn_left--;
		motorA.drive(calibrated_speed_turn_left, 0);
		motorB.drive(calibrated_speed_turn_right, 0);
		// if (IR_left() <= IR_right()) break;
		// }
	}
	motorA.drive(calibrated_speed_turn_left, 0);
	motorB.drive(calibrated_speed_turn_right, 0);
}
void go_back(){
	back(motorA, motorB, NORMAL_SPEED);
}
void front_interrupt_ir(){
}
#endif // MOTOR_H
