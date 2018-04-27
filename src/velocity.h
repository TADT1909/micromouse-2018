// velocity.h

// Encoder myEnc(5, 6);
// long newPosition;  // new position get from encoder
// long oldPosition = 0;
// unsigned long newTime;
// unsigned long oldTime = 0;
// long vel;  // velocity
#ifndef VELOCITY_H
#define VELOCITY_H
    long
    velocity(Encoder myEnc) {
  unsigned long newTime = millis();
  unsigned long oldTime;
  long oldPosition = 0;
  long newPosition = myEnc.read();
  long vel = (newPosition - oldPosition) * 1000 / (newTime - oldTime);
  oldPosition = newPosition;
  oldTime = newTime;
  return vel;
}

#endif  // VELOCITY_H
