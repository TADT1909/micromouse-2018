//test_Encoder_lib.ino
/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.

 KHONG DUOC SUA
 CHI DOC
 */

#define encode_B_1 1 // dem xung
#define encode_B_2 14
#define encode_A_1 0 // dem xung
#define encode_A_2 16

#define AIN1 18
#define BIN1 20
#define AIN2 19
#define BIN2 21
#define PWMA 9
#define PWMB 10
#define STBY 15

const int offsetA = 1;
const int offsetB = -1;

#define ENCODER_USE_INTERRUPTS

#include <Sparkfun_TB6612FNG.h>
#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder encode_A(encode_A_1, encode_A_2);
// Encoder encode_B(encode_B_1, encode_B_2);
Motor motorA = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
// Motor motorB = Motor(BIN1, BIN2, PWMB, offsetB, STBY);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(115200);
  Serial.println("Basic Encoder Test:");
}

long oldPosition  = -999;

void loop() {
  long newPosition = encode_A.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }
  motorA.drive(20, 500);
}
