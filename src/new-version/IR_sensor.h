// IR_sensor.h
#ifndef IR_SENSOR_H
#define IR_SENSOR_H
// too easy - should use analogRead() to improve performance
/*void readSensor(int &pin){
	analogRead(pin);
}*/
void initiate_IR(){
	pinMode(IR_front_left, INPUT); 
	pinMode(IR_front_right, INPUT); 
	pinMode(IR_left, INPUT); 
	pinMode(IR_right, INPUT); 
}
#endif //IR_SENSOR_H
