// MicroMouse-499198.ino
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
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <PID_v1.h>
#include <Encoder.h>
#include <Sparkfun_TB6612FNG.h>

#define IR_left 19
#define IR_right 20
#define IR_front 21

// encoder pins should be interrupt pins to get best performance
#define encoder_left_A 2
#define encoder_left_B 18
#define encoder_right_A 3
#define encoder_right_B 15

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

#define contact1 14
#define contact2 16

//Takes 2 motors and goes forward, if it does not go forward adjust offset
//values until it does.  These will also take a negative number and go backwards
const int offset_left = 1;
const int offset_right = 1;

Motor left_motor = Motor(left_IN1, left_IN2, PWM_left, offset_left, STBY);
Motor right_motor = Motor(right_IN1, right_IN2, PWM_right, offset_right, STBY);
Encoder enc_left(encoder_left_A, encoder_left_B);
Encoder enc_right(encoder_right_A, encoder_right_B);

int speed = 205; // 80% of highest capability of speed

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:

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
}
