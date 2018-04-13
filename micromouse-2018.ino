// MicroMouse-499198.ino
/*
3 Cảm biến hồng ngoại (digital)
2 đầu đọc encoder 20 xung (digital)
2 chân PWM
4 chân I/O vào mạch điều khiển động cơ
3 hoặc 2 công tắc cho chọn chế độ

3 IR Sensor:
  digitalRead(sensor); // HIGH - No obstacle; LOW - obstacle presents

Arduino Pro Micro
   pin 3 maps to interrupt 0
   pin 2 is interrupt 1
   pin 0 is interrupt 2
   pin 1 is interrupt 3
   pin 7 is interrupt 4
 */
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

#define IR_left 14
#define IR_right 15
#define IR_front 16

// encoder pins should be interrupt pins to get best performance
#define encoder_left 18
#define encoder_right 19

#define pwm1 9
#define pwm2 10
/*
TB6612FNGs DC motor controller
Pins for all inputs, keep in mind the PWM defines must be on PWM pins
*/
#define AIN1 2
#define BIN1 7
#define AIN2 4
#define BIN2 8
#define PWMA 5
#define PWMB 6
#define STBY 3

#define contact1 20
#define contact2 21

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
