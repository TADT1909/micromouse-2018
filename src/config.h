#ifndef __CONFIG_H
#define __CONFIG_H

/*
3 cảm biến hồng ngoại (analog) - for PID controlling
4 đầu đọc cho 2 encoder 334 xung (digital)
7 chân mạch điều khiển động cơ
2 công tắc chọn chế độ

Arduino Pro Micro
   pin 3 maps to interrupt 0
   pin 2 is interrupt 1
   pin 0 is interrupt 2
   pin 1 is interrupt 3
   pin 7 is interrupt 4

   PWM pins: 3,5,6,9,10

not used pins: 15, 18
 */

// IR sensor pins must be analog pins
#define IR_left 19
#define IR_right 20
#define IR_front 21

// encoder pins should be interrupt pins to get best performance
#define encoder_left_A 1
#define encoder_left_B 0
#define encoder_right_A 2
#define encoder_right_B 3

/*
TB6612FNG DC motor controller
Pins for all inputs, keep in mind the PWM defines must be on PWM pins
*/
#define left_IN1 4
#define right_IN1 7
#define left_IN2 8
#define right_IN2 9
#define PWM_left 5
#define PWM_right 6
#define STBY 10

#define contact1 16
#define contact2 14

//Takes 2 motors and goes forward, if it does not go forward adjust offset
//values until it does.  These will also take a negative number and go backwards
const int offset_left = 1;
const int offset_right = 1;

#endif /* __CONFIG_H */
