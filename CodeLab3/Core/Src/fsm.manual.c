///*
// * fsm.manual.c
// *
// *  Created on: Nov 13, 2024
// *      Author: MY LE
// */
//
//
//#include "fsm_manual.h"
//
//enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
//enum ButtonState buttonState[3] = {BUTTON_RELEASED};
//
//void manualOperation() {
//    // Button 0: Update Mode
//    switch (buttonState[0]) {
//        case BUTTON_RELEASED:
//            if (is_button_pressed(0)) {
//                buttonState[0] = BUTTON_PRESSED;
//                mode++;
//                if (mode > 4) {
//                    mode = 1;
//                    resetCountValue();
//                }
//            }
//            break;
//        case BUTTON_PRESSED:
//            if (!is_button_pressed(0)) {
//                buttonState[0] = BUTTON_RELEASED;
//            }
//            break;
//        default:
//            break;
//    }
//
//    // Button 1: Increase Draft Value
//    switch (buttonState[1]) {
//        case BUTTON_RELEASED:
//            if (is_button_pressed(1)) {
//                buttonState[1] = BUTTON_PRESSED;
//                increaseDraftValue();
//            }
//            break;
//        case BUTTON_PRESSED:
//            if (!is_button_pressed(1)) {
//                buttonState[1] = BUTTON_RELEASED;
//            }
//            if (is_button_pressed_1s(1)) {
//                buttonState[1] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
//                increaseDraftValue();
//            }
//            break;
//        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
//            if (!is_button_pressed(1)) {
//                buttonState[1] = BUTTON_RELEASED;
//            }
//            if (is_button_held(1)) {
//                reset_flagForButtonHold(1);
//                increaseDraftValue();
//            }
//            break;
//        default:
//            break;
//    }
//
//    // Button 2: Set Duration Value
//    switch (buttonState[2]) {
//        case BUTTON_RELEASED:
//            if (is_button_pressed(2)) {
//                buttonState[2] = BUTTON_PRESSED;
//                setDurationValue();
//            }
//            break;
//        case BUTTON_PRESSED:
//            if (!is_button_pressed(2)) {
//                buttonState[2] = BUTTON_RELEASED;
//            }
//            break;
//        default:
//            break;
//    }
//}
