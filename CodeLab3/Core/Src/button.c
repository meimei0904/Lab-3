///*
// * button.c
// *
// *  Created on: Nov 1, 2024
// *      Author: MY LE
// */
//
//#include "button.h"
//int KeyReg0 = NORMAL_STATE;
//int KeyReg1 = NORMAL_STATE;
//int KeyReg2 = NORMAL_STATE;
//
//int button1_flag = 0;
//
//int KeyReg3 = NORMAL_STATE;
//int TimerForKeyPress = 200;
//
//int isButton1Pressed() {
//	if (button1_flag == 1) {
//		button1_flag = 0;
//		return 1;
//	}
//	return 0;
//}
//
//void subKeyProcess() {
//	//TODO
////	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//	button1_flag = 1;
//}
//
//void getKeyInput() {
//	KeyReg0 = KeyReg1;
//	KeyReg1 = KeyReg2;
//	KeyReg2 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
//	if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)) {
//		if (KeyReg3 != KeyReg2) {
//			KeyReg3 = KeyReg2;
//			if (KeyReg2 == PRESSED_STATE) {
//				//TODO
//				subKeyProcess();
//				TimerForKeyPress = 200;
//			}
//		} else {
//			TimerForKeyPress--;
//			if (TimerForKeyPress == 0) {
//				//TODO
//				KeyReg3 = NORMAL_STATE;
//			}
//		}
//	}
//}
//
////#include "button.h"
////
////int button1_flag = 0;
////
////// Khai báo trạng thái của các nút nhấn
////int KeyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
////int KeyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
////int KeyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
////int KeyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
////int TimerForKeyPress[3] = {200, 200, 200};  // Thời gian đếm cho mỗi nút nhấn
////
////int isButton1Pressed() {
////	if (button1_flag == 1) {
////		button1_flag = 0;
////		return 1;
////	}
////	return 0;
////}
////
////// Hàm thực hiện tác vụ khi một nút nhấn được nhấn
////void subKeyProcess(int buttonIndex) {
////    switch(buttonIndex) {
////        case 0:
//////            HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//////            break;
////        	button1_flag = 1;
////        case 1:
////            HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
////            break;
////        case 2:
////            HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
////            break;
////        default:
////            break;
////    }
////}
////
////// Hàm đọc trạng thái các nút nhấn và xử lý
////void getKeyInput() {
////    // Duyệt qua từng nút nhấn để đọc và xử lý trạng thái
////    for (int i = 0; i < 3; i++) {
////        // Cập nhật bộ đệm trạng thái khử rung
////        KeyReg0[i] = KeyReg1[i];
////        KeyReg1[i] = KeyReg2[i];
////
////        // Đọc trạng thái của từng nút nhấn
////        if (i == 0) {
////            KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
////        } else if (i == 1) {
////            KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
////        } else if (i == 2) {
////            KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);
////        }
////
////        // Kiểm tra trạng thái ổn định của nút nhấn
////        if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
////            if (KeyReg3[i] != KeyReg2[i]) {
////                KeyReg3[i] = KeyReg2[i];
////                if (KeyReg2[i] == PRESSED_STATE) {
////                    // Gọi hàm xử lý tác vụ khi nút được nhấn
////                    subKeyProcess(i);
////                    TimerForKeyPress[i] = 200; // Đặt lại bộ đếm thời gian cho nút nhấn
////                }
////            } else {
////                // Đếm ngược bộ đếm cho thao tác giữ nút
////                TimerForKeyPress[i]--;
////                if (TimerForKeyPress[i] == 0) {
////                    KeyReg3[i] = NORMAL_STATE; // Đặt lại trạng thái sau khi đếm hết thời gian giữ nút
////                }
////            }
////        }
////    }
////}
//
//
