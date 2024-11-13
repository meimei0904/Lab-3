#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include "button.h"

#define TIMER_CYCLE			1

int get_timer0_flag();
void setTimer0(int duration);
int get_timer1_flag();
void setTimer1(int duration);
int get_timer2_flag();
void setTimer2(int duration);
int get_timer3_flag();
void setTimer3(int duration);

#endif /* INC_TIMER_H_ */
