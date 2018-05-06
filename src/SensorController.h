/***************
 * SensorController Class Declaration
 ***************/

#ifndef SENSORCONTROLLER_H
#define SENSORCONTROLLER_H

#include <Encoder.h>
#include "Arduino.h"
#include "const.h"

namespace SensorController {

extern double irSmooth[3];
extern double sensorMean[3];
extern double sensorSigma[3];

extern double input;
extern double output;
extern double setpoint;

extern Encoder leftEncoder;
extern Encoder rightEncoder;

void sample(int nSamples);
void printSensors();
void calibrate();
}  // namespace SensorController

#endif
