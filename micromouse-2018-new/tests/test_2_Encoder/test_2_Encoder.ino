//test_2_Encoder.ino
/* Encoder Library - TwoKnobs Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */
#define encode_A_1 0 // dem xung
#define encode_A_2 16
#define encode_B_1 1 // dem xung
#define encode_B_2 14

#define AIN1 18
#define BIN1 20
#define AIN2 19
#define BIN2 21
#define PWMA 9
#define PWMB 10
#define STBY 15

const int offsetA = 1;
const int offsetB = -1;

#include <Sparkfun_TB6612FNG.h>
#include <Encoder.h>

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder knobLeft(encode_A_1, encode_A_2);
Encoder knobRight(encode_B_1, encode_B_2);
Motor motorA = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motorB = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(115200);
  // Serial.println("TwoKnobs Encoder Test:");
}

long positionLeft  = -999;
long positionRight = -999;

void loop() {
  long newLeft, newRight;
  newLeft = knobLeft.read();
  newRight = knobRight.read();
  if (newLeft != positionLeft || newRight != positionRight) {
    Serial.print("Left = ");
    Serial.print(newLeft);
    Serial.print(", Right = ");
    Serial.print(newRight);
    Serial.println();
    positionLeft = newLeft;
    positionRight = newRight;
  }
  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
    Serial.println("Reset both knobs to zero");
    knobLeft.write(0);
    knobRight.write(0);
  }
  // motorA.drive(20, 500);
  motorB.drive(20, 500);
}
