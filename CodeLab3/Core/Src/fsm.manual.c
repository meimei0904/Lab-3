/*
 * fsm.manual.c
 *
 *  Created on: Nov 13, 2024
 *      Author: MY LE
 */


#include "fsm_manual.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonState[3] = {BUTTON_RELEASED};

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
