/*
 * button.h
 *
 *  Created on: Nov 15, 2023
 *      Author: Hieu
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button_flag[3];
extern int long_button_flag[3];
extern int timeOutForKeyPressed[3];

int isButtonPressed(int id);
int isButtonLongPressed(int id);

void getKeyInput0();
void getKeyInput1();
void getKeyInput2();

#endif /* INC_BUTTON_H_ */
