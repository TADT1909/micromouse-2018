//test_IR.ino

#define IR_front_pin 2 // Digital
#define IR_right_pin 8//6 // A7 //7 //Analog
#define IR_left_pin 21 //6 //8 //A8 // Analog
// int analogPin = IR_right_pin;     // potentiometer wiper (middle terminal) connected to analog pin 3
                       // outside leads to ground and +5V
// int val = 0;           // variable to store the value read

void setup()
{
  Serial.begin(115200);              //  setup serial
  pinMode(IR_front_pin, INPUT_PULLUP);
  pinMode(IR_right_pin, INPUT_PULLUP);
  pinMode(IR_left_pin, INPUT_PULLUP);
}

void loop()
{
  // val = analogRead(IR_right_pin);     // read the input pin
  // Serial.println(val);             // debug value
  /*Serial.print("Front IR: ");
  Serial.print(digitalRead(IR_front_pin));
  Serial.print(", Left IR: ");
  Serial.print(digitalRead(IR_left_pin));
  Serial.print(", Right IR: ");
  Serial.println(digitalRead(IR_right_pin));*/
	Serial.print("Front IR: ");
	Serial.print(digitalRead(IR_front_pin));
	Serial.print(", Left IR: ");
	Serial.print(analogRead(IR_left_pin));
	Serial.print(", Right IR: ");
	Serial.print(analogRead(IR_right_pin));
	Serial.println();
 delay(500);
}
