// IR.h
#ifndef IR_H
#define IR_H

#include "config.h"

int IR_left(){
	return analogRead(IR_left_pin);
}
int IR_right(){
	return analogRead(IR_right_pin);
}

#endif