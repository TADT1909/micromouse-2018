//micromouse-2018-new.ino
//trong hàm interrupt đọc encoder
//tự tính, đếm số ô
#include <Sparkfun_TB6612FNG.h>
#include "config.h"
#include "const.h"
#include "encoder.h"
#include "motor.h"
#include "IR.h"

void setup() {
  // put your setup code here, to run once:
  	/*pinMode(encoder_A_1, INPUT); 
    pinMode(encoder_A_2, INPUT); 
    pinMode(encoder_B_1, INPUT); 
    pinMode(encoder_B_2, INPUT); 
    attachInterrupt(digitalPinToInterrupt(encoder_A_1), pulse_A, FALLING); //Ngắt cạnh xuống DC A
    attachInterrupt(digitalPinToInterrupt(encoder_B_1), pulse_B, FALLING); //Ngắt cạnh xuống DC B*/
    // attachInterrupt(digitalPinToInterrupt(IR_front_pin), front_interrupt_ir, FALLING); // ngắt cảm biến hồng ngoại trước
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // TEST MOVEMENT CONTROL 
  go_forward();
}
