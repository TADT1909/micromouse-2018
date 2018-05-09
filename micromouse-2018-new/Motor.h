// Motor.h
#include "config.h"
#ifndef MOTOR_H
#define MOTOR_H
static int calibrated_speed_turn_left = normal_speed;
static int calibrated_speed_turn_right = normal_speed;
#include "Arduino.h"
// gặp ngã 4, cho đọc xung encoder
// gặp ngã 3, dùng hàm ngắt, gọi hàm turn_left, turn_right
void turn_left(){
	count_B = 0;
	motorA.drive(-idle_speed,0);
for (int i = 0; i < (max_speed - normal_speed); i+=1 ){
	motorB.drive(normal_speed + i, 0);
	if (count_B >= rotate_const) break;
}

}
void turn_right(){
	count_A = 0;
	motorB.drive(-idle_speed,0);
	for (int i = 0; i < (max_speed - normal_speed); i+=1 ){
		motorA.drive(normal_speed + i, 0);
		if (count_B >= rotate_const) break;
	}
}
void go_forward(){
	// forward(motorA, motorB, normal_speed);
	if (IR_left() <= IR_wall_threshold){ // bên trái có tường
	for (int i = 0; i < (max_speed - normal_speed); i+=1 ){
		calibrated_speed_turn_left += i;
		calibrated_speed_turn_right -= i;
		motorA.drive(calibrated_speed_turn_left, 0);
		motorB.drive(calibrated_speed_turn_right, 0);
		if (IR_left() > IR_wall_threshold) break;
		}
	}
	if (IR_right() <= IR_wall_threshold){ // bên phải có tường
	for (int i = 0; i < (max_speed - normal_speed); i+=1 ){
		calibrated_speed_turn_left -= i;
		calibrated_speed_turn_right += i;
		motorA.drive(calibrated_speed_turn_left, 0);
		motorB.drive(calibrated_speed_turn_right, 0);
		if (IR_right() > IR_wall_threshold) break;
		}
	}
	motorA.drive(calibrated_speed_turn_left, 0);
	motorB.drive(calibrated_speed_turn_right, 0);
}
void go_back(){
	back(motorA, motorB, normal_speed);
}
#endif
