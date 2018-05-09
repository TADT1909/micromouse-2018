//micromouse-2018-new.ino
#include <Sparkfun_TB6612FNG.h>
#include "config.h"
#include "encoder.h"
#include "IR.h"

Motor motorA = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motorB = Motor(BIN1, BIN2, PWMB, offsetB, STBY);
void setup() {
  // put your setup code here, to run once:
  	pinMode(encoder_A_1, INPUT); 
    pinMode(encoder_A_2, INPUT); 
    pinMode(encoder_B_1, INPUT); 
    pinMode(encoder_B_2, INPUT); 
    attachInterrupt(digitalPinToInterrupt(encoder_A_1), pulse_A, FALLING); //Ngắt cạnh xuống DC A
    attachInterrupt(digitalPinToInterrupt(encoder_B_1), pulse_B, FALLING); //Ngắt cạnh xuống DC B
}

void loop() {
  // put your main code here, to run repeatedly:
}
