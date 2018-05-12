//test_interrupt_IR.ino
#define IR_front_pin 2 // Digital
// boolean ledState_B = false;
void blink_TXLED(){
  // ledState_B ? ledState_B=false : ledState_B=true;
  // ledState_B ? TXLED1 : TXLED0;
// while (1){
TXLED1;
delay(100000);
TXLED0;
delay(100000);
// }
  // digitalWrite(ledPin,ledState_B);
}
void setup() {
  // put your setup code here, to run once:
  // Serial.begin(115200);              //  setup serial
  // pinMode(IR_front_pin, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(IR_front_pin), blink_TXLED, FALLING); // ngắt cảm biến hồng ngoại trước
  // 
}

void loop() {
  // put your main code here, to run repeatedly:
  // TXLED0;
  // delay(1000);
}