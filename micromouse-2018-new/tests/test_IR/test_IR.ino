//test_IR.ino

int analogPin = 9;     // potentiometer wiper (middle terminal) connected to analog pin 3
                       // outside leads to ground and +5V
int val = 0;           // variable to store the value read

void setup()
{
  Serial.begin(115200);              //  setup serial
}

void loop()
{
  val = analogRead(analogPin);     // read the input pin
  Serial.println(val);             // debug value
 delay(100);
}
