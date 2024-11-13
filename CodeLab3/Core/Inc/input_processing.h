#ifndef __INPUT_PROCESSING_H_
#define __INPUT_PROCESSING_H_

#include "main.h"
//#include "input_reading.h"
#include "led_display.h"
#include "timer.h"
#include "global.h"

void UpdateMode();
void LedTimeDurationInit();
void UpdateDurationValue();

//---------------------------input_reading (đọc nút nhấn và chống nhiễu)----------
void init_buffer();
void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);
unsigned char is_button_held(unsigned char index);
void reset_flagForButtonHold(unsigned char index);

#endif /* INC_INPUT_PROCESSING_H_ */
