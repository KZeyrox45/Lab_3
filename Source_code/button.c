/*
 * button.c
 *
 *  Created on: Nov 15, 2023
 *      Author: Hieu
 */

#include "main.h"
#include "button.h"

int button_flag[3] = {0};
int long_button_flag[3] = {0};
int timeOutForKeyPressed[3] = {200, 200, 200};

int isButtonPressed(int id){
	if(button_flag[id] == 1){
		button_flag[id] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int id){
	if(long_button_flag[id] == 1){
		long_button_flag[id] = 0;
		return 1;
	}
	return 0;
}

int keyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

void getKeyInput0(){
  keyReg2[0] = keyReg1[0];
  keyReg1[0] = keyReg0[0];
  keyReg0[0] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);

  if((keyReg1[0] == keyReg0[0]) && (keyReg1[0] == keyReg2[0])){
    if(keyReg2[0] != keyReg3[0]){
      keyReg3[0] = keyReg2[0];
      if(keyReg3[0] == PRESSED_STATE){
        timeOutForKeyPressed[0] = 200;
        button_flag[0] = 1;
      }
    }/*else{
       TimeOutForKeyPress --;
        if (TimeOutForKeyPress == 0){
        	TimeOutForKeyPress = 500;
			subKeyProcess();
        }
    }*/
  }
}

void getKeyInput1(){
  keyReg2[1] = keyReg1[1];
  keyReg1[1] = keyReg0[1];
  keyReg0[1] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);

  if((keyReg1[1] == keyReg0[1]) && (keyReg1[1] == keyReg2[1])){
    if(keyReg2[1] != keyReg3[1]){
      keyReg3[1] = keyReg2[1];
      if(keyReg3[1] == PRESSED_STATE){
        timeOutForKeyPressed[1] = 200;
        button_flag[1] = 1;
      }
    }/*else{
       TimeOutForKeyPress --;
        if (TimeOutForKeyPress == 0){
        	TimeOutForKeyPress = 500;
			subKeyProcess();
        }
    }*/
  }
}

void getKeyInput2(){
  keyReg2[2] = keyReg1[2];
  keyReg1[2] = keyReg0[2];
  keyReg0[2] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);

  if((keyReg1[2] == keyReg0[2]) && (keyReg1[2] == keyReg2[2])){
    if(keyReg2[2] != keyReg3[2]){
      keyReg3[2] = keyReg2[2];
      if(keyReg3[2] == PRESSED_STATE){
        timeOutForKeyPressed[2] = 200;
        button_flag[2] = 1;
      }
    }/*else{
       TimeOutForKeyPress --;
        if (TimeOutForKeyPress == 0){
        	TimeOutForKeyPress = 500;
			subKeyProcess();
        }
    }*/
  }
}
