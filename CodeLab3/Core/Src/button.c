#include <button.h>

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonState[3] = {BUTTON_RELEASED};

//----------------------input_reading (đọc nút nhấn và chống nhiễu)-------------
#define NO_OF_BUTTONS					3

#define DURATION_FOR_AUTO_INCREASING	200 / TIMER_CYCLE
#define DURATION_FOR_HOLD				50 / TIMER_CYCLE

#define BUTTON_IS_PRESSED				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED				GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];

static GPIO_PinState debounceButtonBufer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBufer2[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBufer3[NO_OF_BUTTONS];

static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
static uint8_t flagForButtonHold[NO_OF_BUTTONS];
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];
static uint16_t counterForButtonHold[NO_OF_BUTTONS];

//---------------------------------------------------------------

void fsm_manual() {
    // Update mode logic (from UpdateMode)
    switch (buttonState[0]) {
        case BUTTON_RELEASED:
            if (is_button_pressed(0)) {
                buttonState[0] = BUTTON_PRESSED;
                mode++;
                if (mode > 4) {
                    mode = 1;
                    resetCountValue();
                }
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(0)) {
                buttonState[0] = BUTTON_RELEASED;
            }
            break;
        default:
            break;
    }

    // Increase draft value based on mode (from UpdateDurationValue and increaseDraftValue)
    switch (buttonState[1]) {
        case BUTTON_RELEASED:
            if (is_button_pressed(1)) {
                buttonState[1] = BUTTON_PRESSED;
                switch (mode) {
                    case 2:
                        red_draft++;
                        if (red_draft > 99) red_draft = 0;
                        break;
                    case 3:
                        yellow_draft++;
                        if (yellow_draft > 99) yellow_draft = 0;
                        break;
                    case 4:
                        green_draft++;
                        if (green_draft > 99) green_draft = 0;
                        break;
                    default:
                        break;
                }
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(1)) {
                buttonState[1] = BUTTON_RELEASED;
            }
            if (is_button_pressed_1s(1)) {
                buttonState[1] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
                switch (mode) {
                    case 2:
                        red_draft++;
                        if (red_draft > 99) red_draft = 0;
                        break;
                    case 3:
                        yellow_draft++;
                        if (yellow_draft > 99) yellow_draft = 0;
                        break;
                    case 4:
                        green_draft++;
                        if (green_draft > 99) green_draft = 0;
                        break;
                    default:
                        break;
                }
            }
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(1)) {
                buttonState[1] = BUTTON_RELEASED;
            }
            if (is_button_held(1)) {
                reset_flagForButtonHold(1);
                switch (mode) {
                    case 2:
                        red_draft++;
                        if (red_draft > 99) red_draft = 0;
                        break;
                    case 3:
                        yellow_draft++;
                        if (yellow_draft > 99) yellow_draft = 0;
                        break;
                    case 4:
                        green_draft++;
                        if (green_draft > 99) green_draft = 0;
                        break;
                    default:
                        break;
                }
            }
            break;
        default:
            break;
    }

    // Set duration values based on mode (from UpdateDurationValue and setDurationValue)
    switch (buttonState[2]) {
        case BUTTON_RELEASED:
            if (is_button_pressed(2)) {
                buttonState[2] = BUTTON_PRESSED;
                int diff = 0;
                switch (mode) {
                    case 2:
                        diff = red_draft - red_value;
                        red_value = red_draft;
                        green_value += diff;
                        green_draft += diff;
                        break;
                    case 3:
                        diff = yellow_draft - yellow_value;
                        yellow_value = yellow_draft;
                        red_value += diff;
                        red_draft += diff;
                        break;
                    case 4:
                        diff = green_draft - green_value;
                        green_value = green_draft;
                        green_value += diff;
                        green_draft += diff;
                        break;
                    default:
                        break;
                }
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(2)) {
                buttonState[2] = BUTTON_RELEASED;
            }
            break;
        default:
            break;
    }
}


//void UpdateMode() {
//	switch (buttonState[0]) {
//		case BUTTON_RELEASED:
//			if (is_button_pressed(0)) {
//				buttonState[0] = BUTTON_PRESSED;
//				mode++;
//				if (mode > 4) {
//					mode = 1;
//					resetCountValue();
//				}
//			}
//			break;
//		case BUTTON_PRESSED:
//			if (!is_button_pressed(0)) {
//				buttonState[0] = BUTTON_RELEASED;
//			}
//			break;
//		default:
//			break;
//	}
//}
//
//static void increaseDraftValue() {
//	switch (mode) {
//		case 2:
//			red_draft++;
//			if (red_draft > 99) red_draft = 0;
//			break;
//		case 3:
//			yellow_draft++;
//			if (yellow_draft > 99) yellow_draft = 0;
//			break;
//		case 4:
//			green_draft++;
//			if (green_draft > 99) green_draft = 0;
//			break;
//		default:
//			break;
//	}
//}
//
//static void setDurationValue() {
//	int diff = 0;
//	switch (mode) {
//		case 2:
//			diff = red_draft - red_value;
//			red_value = red_draft;
//			green_value += diff;
//			green_draft += diff;
//			break;
//		case 3:
//			diff = yellow_draft - yellow_value;
//			yellow_value = yellow_draft;
//			red_value += diff;
//			red_draft += diff;
//			break;
//		case 4:
//			diff = green_draft - green_value;
//			green_value = green_draft;
//			green_value += diff;
//			green_draft += diff;
//			break;
//		default:
//			break;
//	}
//}
//
//void UpdateDurationValue() {
//	switch (buttonState[1]) {
//		case BUTTON_RELEASED:
//			if (is_button_pressed(1)) {
//				buttonState[1] = BUTTON_PRESSED;
//				increaseDraftValue();
//			}
//			break;
//		case BUTTON_PRESSED:
//			if (!is_button_pressed(1)) {
//				buttonState[1] = BUTTON_RELEASED;
//			}
//			if (is_button_pressed_1s(1)) {
//				buttonState[1] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
//				increaseDraftValue();
//			}
//			break;
//		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
//			if (!is_button_pressed(1)) {
//				buttonState[1] = BUTTON_RELEASED;
//			}
//			if (is_button_held(1)) {
//				reset_flagForButtonHold(1);
//				increaseDraftValue();
//			}
//			break;
//		default:
//			break;
//	}
//
//	switch (buttonState[2]) {
//		case BUTTON_RELEASED:
//			if (is_button_pressed(2)) {
//				buttonState[2] = BUTTON_PRESSED;
//				setDurationValue();
//			}
//			break;
//		case BUTTON_PRESSED:
//			if (!is_button_pressed(2)) {
//				buttonState[2] = BUTTON_RELEASED;
//			}
//			break;
//		default:
//			break;
//	}
//}

//-------------------input_reading (đọc nút nhấn và chống nhiễu)------------------


void init_buffer() {
	for (int i = 0; i < NO_OF_BUTTONS; i++) {
		buttonBuffer[i] = BUTTON_IS_RELEASED;
		debounceButtonBufer1[i] = BUTTON_IS_RELEASED;
		debounceButtonBufer2[i] = BUTTON_IS_RELEASED;
		debounceButtonBufer3[i] = BUTTON_IS_RELEASED;
		flagForButtonPress1s[i] = 0;
		flagForButtonHold[i] = 0;
		counterForButtonPress1s[i] = 0;
		counterForButtonHold[i] = 0;
	}
}

void button_reading(void) {
	for (int i = 0; i < NO_OF_BUTTONS; i++) {
		debounceButtonBufer3[i] = debounceButtonBufer2[i];
		debounceButtonBufer2[i] = debounceButtonBufer1[i];
		debounceButtonBufer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, (1U << i));

		if (debounceButtonBufer1[i] == debounceButtonBufer2[i] && debounceButtonBufer3[i] == debounceButtonBufer2[i])
			buttonBuffer[i] = debounceButtonBufer1[i];

		if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
			if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
				counterForButtonPress1s[i]++;
			}
			else {
				flagForButtonPress1s[i] = 1;
				//TO DO
				if (counterForButtonHold[i] < DURATION_FOR_HOLD) {
					counterForButtonHold[i]++;
					if (counterForButtonHold[i] >= DURATION_FOR_HOLD) {
						counterForButtonHold[i] = 0;
						flagForButtonHold[i] = 1;
					}
				}
			}
		}
		else {
			counterForButtonPress1s[i] = 0;
			flagForButtonPress1s[i] = 0;
			counterForButtonHold[i] = 0;
			flagForButtonHold[i] = 0;
		}
	}
}

unsigned char is_button_pressed(unsigned char index) {
	if (index >= NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_1s(unsigned char index) {
	if (index >= NO_OF_BUTTONS) return 0;
	return (flagForButtonPress1s[index] == 1);
}

unsigned char is_button_held(unsigned char index) {
	if (index >= NO_OF_BUTTONS) return 0;
	return (flagForButtonHold[index] == 1);
}

void reset_flagForButtonHold(unsigned char index) {
	flagForButtonHold[index] = 0;
}
