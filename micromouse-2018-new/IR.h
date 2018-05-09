// IR.h
#include "config.h"
#ifndef IR_H
#define IR_H
int IR_left(){
	return analogRead(IR_left_pin);
}
int IR_right(){
	return analogRead(IR_right_pin);
}

#endif