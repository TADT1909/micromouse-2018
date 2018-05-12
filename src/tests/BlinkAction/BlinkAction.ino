//BlinkAction.ino
#include <TimedAction.h>
 void blink_A();
 void blink_TXLED();
//this initializes a TimedAction class that will change the state of an LED every second.
TimedAction timedAction_A = TimedAction(1000,blink_A);
TimedAction timedAction_TXLED = TimedAction(2000,blink_TXLED);
 
//pin / state variables
#define ledPin 17
boolean ledState_A = false;
boolean ledState_B = false;
 
void setup(){
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,ledState_A);
}
 
void loop(){
  timedAction_A.check();
  timedAction_TXLED.check();
}
 
void blink_A(){
  ledState_A ? ledState_A=false : ledState_A=true;
  digitalWrite(ledPin,ledState_A);
}

void blink_TXLED(){
  ledState_B ? ledState_B=false : ledState_B=true;
  ledState_B ? TXLED1 : TXLED0;
  // digitalWrite(ledPin,ledState_B);
}