#ifndef __ENCODER_H
#define __ENCODER_H

#include "config.h"
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
#endif /* __ENCODER_H */
