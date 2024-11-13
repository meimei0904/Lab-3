//#ifndef INC_TIMER_H_
//#define INC_TIMER_H_
//
//#include "main.h"
//
//#define TIMER_CYCLE 1
//
//extern int timer1_flag;
//extern int timer2_flag;
//extern int timer3_flag;
//extern int timer4_flag;
//extern int timer5_flag;
//
//void setTimer1(int duration);
//void setTimer2(int duration);
//void setTimer3(int duration);
//void setTimer4(int duration);
//void setTimer5(int duration);
//void timerRun();
//
//#endif /* INC_TIMER_H_ */


#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include "input_reading.h"

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
