///*
// * fsm_automatic.c
// *
// *  Created on: Nov 1, 2024
// *      Author: MY LE
// */
//
#include "fsm_automatic.h"

enum LEDState {RED, YELLOW, GREEN};

extern int count1, count2;          // Biến được khai báo ở file led_display.c
extern enum LEDState state1, state2; // khai báo để sử dụng lại từ file led_display.c

extern int red_value, yellow_value, green_value;

void NormalMode() {
	count1--;
	count2--;
	switch (state1) {
		case RED:
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
			if (count1 < 0) {
				count1 = green_value - 1;
				state1 = GREEN;
				HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
			}
			break;
		case YELLOW:
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
			if (count1 < 0) {
				count1 = red_value - 1;
				state1 = RED;
				HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
			}
			break;
		case GREEN:
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
			if (count1 < 0) {
				count1 = yellow_value - 1;
				state1 = YELLOW;
				HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
			}
			break;
		default:
			break;
	}
	switch (state2) {
		case RED:
			HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
			if (count2 < 0) {
				count2 = green_value - 1;
				state2 = GREEN;
				HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
			}
			break;
		case YELLOW:
			HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
			if (count2 < 0) {
				count2 = red_value - 1;
				state2 = RED;
				HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
			}
			break;
		case GREEN:
			HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
			if (count2 < 0) {
				count2 = yellow_value - 1;
				state2 = YELLOW;
				HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
			}
			break;
		default:
			break;
	}

}

void fsm_automatic() {
	switch (mode) {
		case 1:
			if (get_timer1_flag()) {
				setTimer1(250);
				NormalMode();
			}
			break;
		case 2:
			if (get_timer1_flag()) {
				setTimer1(200);
				HAL_GPIO_TogglePin(R1_GPIO_Port, R1_Pin);
				HAL_GPIO_TogglePin(R2_GPIO_Port, R2_Pin);
				HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
			}
			break;
		case 3:
			if (get_timer1_flag()) {
				setTimer1(200);
				HAL_GPIO_TogglePin(Y1_GPIO_Port, Y1_Pin);
				HAL_GPIO_TogglePin(Y2_GPIO_Port, Y2_Pin);
				HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
			}
			break;
		case 4:
			if (get_timer1_flag()) {
				setTimer1(200);
				HAL_GPIO_TogglePin(G1_GPIO_Port, G1_Pin);
				HAL_GPIO_TogglePin(G2_GPIO_Port, G2_Pin);
				HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
			}
			break;
		default:
			break;
	}
}
