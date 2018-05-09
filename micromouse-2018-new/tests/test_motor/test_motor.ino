/******************************************************************************
test_motor.ino

motorA - left motor - offset = 1
motorB - right motor - offset = -1
******************************************************************************/

// This is the library for the TB6612 that contains the class Motor and all the
// functions
#include <Sparkfun_TB6612FNG.h>

// Pins for all inputs, keep in mind the PWM defines must be on PWM pins
// the default pins listed are the ones used on the Redbot (ROB-12097) with
// the exception of STBY which the Redbot controls with a physical switch
#define AIN1 18
#define BIN1 20
#define AIN2 19
#define BIN2 21
#define PWMA 9
#define PWMB 10
#define STBY 15

// these constants are used to allow you to make your motor configuration 
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
const int offsetB = -1;

// Initializing motors.  The library will allow you to initialize as many
// motors as you have memory for.  If you are using functions like forward
// that take 2 motors as arguements you can either write new functions or
// call the function more than once.
Motor motorA = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motorB = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

void setup()
{
 //Nothing here
 Serial.begin(9600);
}


void loop()
{
   // Serial.write("Motor A forward\n");
   // motorA.drive(20,1000);
   // delay(500);
   // Serial.write("Motor B forward\n");
   motorB.drive(20,1000);
   delay(500);
   // forward(motorA, motorB, 20);

   /*
   //Use of the drive function which takes as arguements the speed
   //and optional duration.  A negative speed will cause it to go
   //backwards.  Speed can be from -255 to 255.  Also use of the 
   //brake function which takes no arguements.
   Serial.write("Motor A full speed forward\n");
   motorA.drive(255,1000);
   Serial.write("Motor A full speed backward\n");
   motorA.drive(-255,1000);
   Serial.write("Motor A brake\n");
   motorA.brake();
   delay(1000);
   
   //Use of the drive function which takes as arguements the speed
   //and optional duration.  A negative speed will cause it to go
   //backwards.  Speed can be from -255 to 255.  Also use of the 
   //brake function which takes no arguements.
   Serial.write("Motor B full speed forward\n");
   motorB.drive(255,1000);
   Serial.write("Motor B full speed backward\n");
   motorB.drive(-255,1000);
   Serial.write("Motor B brake\n");
   motorB.brake();
   delay(1000);
   
   //Use of the forward function, which takes as arguements two motors
   //and optionally a speed.  If a negative number is used for speed
   //it will go backwards
   Serial.write("Move forward\n");
   forward(motorA, motorB, 150);
   delay(1000);
   
   //Use of the back function, which takes as arguments two motors 
   //and optionally a speed.  Either a positive number or a negative
   //number for speed will cause it to go backwards
   Serial.write("Move backward\n");
   back(motorA, motorB, -150);
   delay(1000);
   
   //Use of the brake function which takes as arguments two motors.
   //Note that functions do not stop motors on their own.
   Serial.write("Stop!\n");
   brake(motorA, motorB);
   delay(1000);
   
   //Use of the left and right functions which take as arguements two
   //motors and a speed.  This function turns both motors to move in 
   //the appropriate direction.  For turning a single motor use drive.
   Serial.write("Turn left\n");
   left(motorA, motorB, 100);
   delay(1000);
   Serial.write("Turn right\n");
   right(motorA, motorB, 100);
   delay(1000);
   
   //Use of brake again.
   Serial.write("Stop!\n");
   brake(motorA, motorB);
   delay(1000);
*/   
}
