// Motor.h
#ifndef MOTOR_H
#define MOTOR_H

#include "config.h"
#include "const.h"
#include "IR.h"

static int calibrated_speed_turn_left = NORMAL_SPEED;
static int calibrated_speed_turn_right = NORMAL_SPEED;
// gặp ngã 4, cho đọc xung encoder
// gặp ngã 3, dùng hàm ngắt, gọi hàm turn_left, turn_right

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
	// forward(motorA, motorB, NORMAL_SPEED);
	motorA.drive(calibrated_speed_turn_left, 0);
	motorB.drive(calibrated_speed_turn_right, 0);
	if (IR_left() <= IR_WALL_THRESHOLD){ // bên trái có tường
	for (int i = 0; i < (MAX_SPEED - NORMAL_SPEED); i+=1 ){
		calibrated_speed_turn_left += i;
		calibrated_speed_turn_right -= i;
		motorA.drive(calibrated_speed_turn_left, 0);
		motorB.drive(calibrated_speed_turn_right, 0);
		if (IR_left() > IR_WALL_THRESHOLD) break;
		}
	}
	if (IR_right() <= IR_WALL_THRESHOLD){ // bên phải có tường
	for (int i = 0; i < (MAX_SPEED - NORMAL_SPEED); i+=1 ){
		calibrated_speed_turn_left -= i;
		calibrated_speed_turn_right += i;
		motorA.drive(calibrated_speed_turn_left, 0);
		motorB.drive(calibrated_speed_turn_right, 0);
		if (IR_right() > IR_WALL_THRESHOLD) break;
		}
	}
	motorA.drive(calibrated_speed_turn_left, 0);
	motorB.drive(calibrated_speed_turn_right, 0);
}
void go_back(){
	back(motorA, motorB, NORMAL_SPEED);
}

void front_interrupt_ir(){
	// Có tường bên trái và trống bên phải
	// thì rẽ phải
	if (IR_left() <= IR_WALL_THRESHOLD && IR_right() > IR_NO_WALL_THRESHOLD)
		turn_right();
	// Có tường bên trái và trống bên phải
	// thì rẽ phải
	else if (IR_right() <= IR_WALL_THRESHOLD && IR_left() > IR_NO_WALL_THRESHOLD)
		turn_left();
	// Có tường cả 2 bên
	// thì đi lùi
	else if (IR_left() <= IR_WALL_THRESHOLD && IR_right() <= IR_WALL_THRESHOLD)
			go_back();
}
#endif // MOTOR_H
