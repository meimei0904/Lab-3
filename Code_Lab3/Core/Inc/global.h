/*
 * global.h
 *
 *  Created on: Nov 1, 2024
 *      Author: MY LE
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

void LedTimeDurationInit();
extern int mode;
extern int red_value, yellow_value, green_value;
extern int red_draft, yellow_draft, green_draft;

#define RED_INIT		30
#define YELLOW_INIT		5
#define GREEN_INIT		25

#endif /* INC_GLOBAL_H_ */
