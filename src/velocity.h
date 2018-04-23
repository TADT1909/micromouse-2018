// velocity.h
Encoder myEnc(5, 6);
long newPosition;  // new position get from encoder
long oldPosition = 0;
unsigned long newTime;
unsigned long oldTime = 0;
long vel;  // velocity

long velocity(){
  newTime = millis();
  newPosition = myEnc.read();
  vel = (newPosition - oldPosition) * 1000 / (newTime - oldTime);
  oldPosition = newPosition;
  oldTime = newTime;
  return vel;
}
