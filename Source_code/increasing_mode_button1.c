/*
 * increasing_mode_button1.c
 *
 *  Created on: Nov 15, 2023
 *      Author: Hieu
 */

#include "main.h"
#include "button.h"
#include "software_timer.h"
#include "global_variables.h"
#include "increasing_mode_button1.h"

void mode1(){
	// Vertical Traffic Lights (R2, Y2, G2)
	switch(VT_traffic_status){
	case 0:
		led7SEG_buffer[0] = red_duration / 10;
		led7SEG_buffer[1] = red_duration % 10 + 1;
		setTimer(red_duration*1000, 2);
		VT_traffic_status = 1;
		break;
	case 1:
		HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, SET);
		HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
		HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);

		if(timer_flag[2] == 1){
			led7SEG_buffer[0] = green_duration / 10;
			led7SEG_buffer[1] = green_duration % 10 + 1;
			setTimer(green_duration*1000, 2);
			VT_traffic_status = 2;
		}
		break;
	case 2:
		HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
		HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, SET);
		HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);

		if(timer_flag[2] == 1){
			led7SEG_buffer[0] = yellow_duration / 10;
			led7SEG_buffer[1] = yellow_duration % 10 + 1;
			setTimer(yellow_duration*1000, 2);
			VT_traffic_status = 3;
		}
		break;
	case 3:
		HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
		HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
		HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);

		if(timer_flag[2] == 1){
			led7SEG_buffer[0] = red_duration / 10;
			led7SEG_buffer[1] = red_duration % 10 + 1;
			setTimer(red_duration*1000, 2);
			VT_traffic_status = 1;
		}
		break;
	default:
		break;
	}
	// Horizontal Traffic Lights (R1, Y1, G1)
	switch(HZ_traffic_status){
	case 0:
		led7SEG_buffer[2] = green_duration / 10;
		led7SEG_buffer[3] = green_duration % 10 + 1;
		setTimer(green_duration*1000, 3);
		HZ_traffic_status = 2;
		break;
	case 1:
		HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
		HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
		HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);

		if(timer_flag[3] == 1){
			led7SEG_buffer[2] = green_duration / 10;
			led7SEG_buffer[3] = green_duration % 10 + 1;
			setTimer(green_duration*1000, 3);
			HZ_traffic_status = 2;
		}
		break;
	case 2:
		HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
		HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET);
		HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);

		if(timer_flag[3] == 1){
			led7SEG_buffer[2] = yellow_duration / 10;
			led7SEG_buffer[3] = yellow_duration % 10 + 1;
			setTimer(yellow_duration*1000, 3);
			HZ_traffic_status = 3;
		}
		break;
	case 3:
		HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
		HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
		HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);

		if(timer_flag[3] == 1){
			led7SEG_buffer[2] = red_duration / 10;
			led7SEG_buffer[3] = red_duration % 10 + 1;
			setTimer(red_duration*1000, 3);
			HZ_traffic_status = 1;
		}
		break;
	default:
		break;
	}
	if(timer_flag[4] == 1){
		led7SEG_buffer[1]--;
		led7SEG_buffer[3]--;
		if(led7SEG_buffer[1] < 0){
			led7SEG_buffer[0]--;
			led7SEG_buffer[1] = 9;
			if(led7SEG_buffer[0] < 0){
				led7SEG_buffer[0] = 0;
			}
		}
		if(led7SEG_buffer[3] < 0){
			led7SEG_buffer[2]--;
			led7SEG_buffer[3] = 9;
			if(led7SEG_buffer[2] < 0){
				led7SEG_buffer[2] = 0;
			}
		}
		setTimer(1000, 4);
	}
}

// Control Red Lights
void mode2(){
	if(timer_flag[5] == 1){
		HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, blink_state);
		HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, blink_state);
		HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
		HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
		HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);
		HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
		blink_state = 1 - blink_state;
		setTimer(250, 5);
	}
	if(isButtonPressed(1) == 1){
		red_mode++;
		if(red_mode > 99){
			red_mode = 0;
		}
	}
	if(isButtonPressed(2) == 1){
		red_duration = red_mode;
	}
}

// Control Amber Lights
void mode3(){
	if(timer_flag[5] == 1){
		HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
		HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
		HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, blink_state);
		HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, blink_state);
		HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);
		HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
		blink_state = 1 - blink_state;
		setTimer(250, 5);
	}
	if(isButtonPressed(1) == 1){
		yellow_mode++;
		if(yellow_mode > 99){
			yellow_mode = 0;
		}
	}
	if(isButtonPressed(2) == 1){
		yellow_duration = yellow_mode;
	}
}

// Control Green Lights
void mode4(){
	if(timer_flag[5] == 1){
		HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
		HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
		HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
		HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
		HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, blink_state);
		HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, blink_state);
		blink_state = 1 - blink_state;
		setTimer(250, 5);
	}
	if(isButtonPressed(1) == 1){
		green_mode++;
		if(green_mode > 99){
			green_mode = 0;
		}
	}
	if(isButtonPressed(2) == 1){
		green_duration = green_mode;
	}
}

void increasing_mode_button1(){
	switch(traffic_status){
	case 0:
		traffic_status = 1;
		VT_traffic_status = 0;
		break;
	case 1:
		mode1();
		if(isButtonPressed(0) == 1){
			traffic_status = 2;
			mode2();
			led7SEG_buffer[0] = red_mode / 10;
			led7SEG_buffer[1] = red_mode % 10;
			led7SEG_buffer[2] = 0;
			led7SEG_buffer[3] = 2;
		}
		break;
	case 2:
		mode2();
		led7SEG_buffer[0] = red_mode / 10;
		led7SEG_buffer[1] = red_mode % 10;
		led7SEG_buffer[2] = 0;
		led7SEG_buffer[3] = 2;
		if(isButtonPressed(0) == 1){
			red_mode = red_duration;
			traffic_status = 3;
			mode3();
			led7SEG_buffer[0] = green_mode / 10;
			led7SEG_buffer[1] = green_mode % 10;
			led7SEG_buffer[2] = 0;
			led7SEG_buffer[3] = 3;
		}
		break;
	case 3:
		mode3();
		led7SEG_buffer[0] = green_mode / 10;
		led7SEG_buffer[1] = green_mode % 10;
		led7SEG_buffer[2] = 0;
		led7SEG_buffer[3] = 3;
		if(isButtonPressed(0) == 1){
			green_mode = green_duration;
			traffic_status = 4;
			mode4();
			led7SEG_buffer[0] = yellow_mode / 10;
			led7SEG_buffer[1] = yellow_mode % 10;
			led7SEG_buffer[2] = 0;
			led7SEG_buffer[3] = 4;
		}
		break;
	case 4:
		mode4();
		led7SEG_buffer[0] = yellow_mode / 10;
		led7SEG_buffer[1] = yellow_mode % 10;
		led7SEG_buffer[2] = 0;
		led7SEG_buffer[3] = 4;
		if(isButtonPressed(0) == 1){
			yellow_mode = yellow_duration;
			traffic_status = 1;
			VT_traffic_status = 0;
			HZ_traffic_status = 0;
		}
		break;
	default:
		break;
	}
}
