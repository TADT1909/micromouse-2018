#ifndef __CONFIG_H
#define __CONFIG_H
// motorA - dong co ben trai
// motorB - dong co ben phai
//
// IR sensor pins must be analog pins
#define IR_front_pin 2 // Digital
#define IR_left_pin 8 //A8 // Analog
#define IR_right_pin 6 // A7 //7 //Analog

#define IR_wall_threshold  147//tùy chỉnh
#define IR_no_wall_threshold 500//tùy chỉnh

// encoder pins should be interrupt pins to get best performance
#define encoder_A_1 1 // dem xung
#define encoder_A_2 14
#define encoder_B_1 0 // dem xung
#define encoder_B_2 16

/*
TB6612FNG DC motor controller
Pins for all inputs, keep in mind the PWM defines must be on PWM pins
*/
#define AIN1 18
#define BIN1 20
#define AIN2 19
#define BIN2 21
#define PWMA 9
#define PWMB 10
#define STBY 15

#define max_speed 208 // tùy chỉnh
#define normal_speed 180 // tùy chỉnh
#define idle_speed 50 // tùy chỉnh
#define turning_speed 20 // tùy chỉnh
#define rotate_const 550

#define MAP 3 // Công tắc
#define LED 4 // Công tắc

//Takes 2 motors and goes forward, if it does not go forward adjust offset
//values until it does.  These will also take a negative number and go backwards
const int offsetA = 1;
const int offsetB = -1;

#endif /* __CONFIG_H */
