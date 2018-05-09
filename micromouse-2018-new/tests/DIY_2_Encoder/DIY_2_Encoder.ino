//DIY_2_encoder.ino
// đọc được encoder, ổn định
// KHÔNG ĐƯỢC SỬA
#include <Sparkfun_TB6612FNG.h>

#define AIN1 18
#define BIN1 20
#define AIN2 19
#define BIN2 21
#define PWMA 9
#define PWMB 10
#define STBY 15

const int offsetA = 1;
const int offsetB = -1;

Motor motorA = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motorB = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

#define encoder_A_1 1 // dem xung
#define encoder_A_2 14
#define encoder_B_1 0 // dem xung
#define encoder_B_2 16

long count_A = 0;
long count_B = 0;
long oldPosition_A  = -999;
long oldPosition_B  = -999;

void pulse_A()
{
    if(digitalRead(encoder_A_2) == LOW)
      count_A++;
    else
      count_A--;
}
void pulse_B()
{
    if(digitalRead(encoder_B_2) == LOW)
      count_B++;
    else
      count_B--;
}

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(encoder_A_1, INPUT); 
    pinMode(encoder_A_2, INPUT); 
    pinMode(encoder_B_1, INPUT); 
    pinMode(encoder_B_2, INPUT); 
    attachInterrupt(digitalPinToInterrupt(encoder_A_1), pulse_A, FALLING); //Ngắt cạnh xuống DC A
    attachInterrupt(digitalPinToInterrupt(encoder_B_1), pulse_B, FALLING); //Ngắt cạnh xuống DC B
}

void loop() {
  // put your main code here, to run repeatedly:
  if (count_A != oldPosition_A || count_B != oldPosition_B) {
    Serial.print("Encoder A = ");
    Serial.print(count_A);
    Serial.print(", Encoder B = ");
    Serial.print(count_B);
    Serial.println();
    oldPosition_A = count_A;
    oldPosition_B = count_B;
  }
   motorA.drive(40,100);
   motorB.drive(40,100);
   TXLED1; //TX LED is not tied to a normally controlled pin so a macro is needed, turn LED OFF
}