#ifndef __CONFIG_H
#define __CONFIG_H

/*
3 cảm biến hồng ngoại (digital)
2 đầu đọc encoder 20 xung (digital)
7 chân mạch điều khiển động cơ
2 công tắc cho chọn chế độ

IR Sensor:
  digitalRead(sensor); // HIGH - No obstacle; LOW - obstacle presents

Arduino Pro Micro
   pin 3 maps to interrupt 0
   pin 2 is interrupt 1
   pin 0 is interrupt 2
   pin 1 is interrupt 3
   pin 7 is interrupt 4

   PWM pins: 3,5,6,9,10
 */

#define IR_left 14
#define IR_right 15
#define IR_front 16

// encoder pins should be interrupt pins to get best performance
#define encoder_left_A 2
#define encoder_left_B 20
#define encoder_right_A 3
#define encoder_right_B 21

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

#define contact1 18
#define contact2 19

//Takes 2 motors and goes forward, if it does not go forward adjust offset
//values until it does.  These will also take a negative number and go backwards
const int offset_left = 1;
const int offset_right = 1;

int speed = 205; // 80% of highest capability of speed

#endif /* _CONFIG_H */
