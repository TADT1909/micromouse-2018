#ifndef __CONFIG_H
#define __CONFIG_H
// motorA - dong co ben trai
// motorB - dong co ben phai
//
// IR sensor pins must be analog pins
// đã đổi lại chân - đổi giữa trái và phải
#define IR_front_pin 2 // Digital - 1 là không có vật cản, 0 là có.
#define IR_right_pin 8 //6 // A7 //7 //Analog
#define IR_left_pin 21 //6 //8 //A8 // Analog

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
#define BIN2 6 //21
#define PWMA 9
#define PWMB 10
#define STBY 15

#define MAP 3 // Công tắc
#define LED 4 // Công tắc

#endif /* __CONFIG_H */
