/*
 * software_timer.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Hieu
 */
#include "software_timer.h"

int timer_counter[6] = {0};
int timer_flag[6] = {0};

int time_cycle = 10;

void setCycle(int cycle){
	time_cycle = cycle;
}

void setTimer(int duration, int i){
	timer_counter[i] = duration / time_cycle;
	timer_flag[i] = 0;
}

void timerRun(){
	if(timer_counter[0] > 0){
		timer_counter[0]--;
		if(timer_counter[0] <= 0){
			timer_flag[0] = 1;
		}
	}
	if(timer_counter[1] > 0){
		timer_counter[1]--;
		if(timer_counter[1] <= 0){
			timer_flag[1] = 1;
		}
	}
	if(timer_counter[2] > 0){
		timer_counter[2]--;
		if(timer_counter[2] <= 0){
			timer_flag[2] = 1;
		}
	}
	if(timer_counter[3] > 0){
		timer_counter[3]--;
		if(timer_counter[3] <= 0){
			timer_flag[3] = 1;
		}
	}
	if(timer_counter[4] > 0){
		timer_counter[4]--;
		if(timer_counter[4] <= 0){
			timer_flag[4] = 1;
		}
	}
	if(timer_counter[4] > 0){
		timer_counter[4]--;
		if(timer_counter[4] <= 0){
			timer_flag[4] = 1;
		}
	}
}
