/*
 * global_variables.c
 *
 *  Created on: Nov 15, 2023
 *      Author: Hieu
 */

#include "global_variables.h"

int VT_traffic_status = 0;
int HZ_traffic_status = 0;
int traffic_status = 0;
int led7SEG_status = 1;
int led7SEG_buffer[4] = {0};
int blink_state = 1;
int red_duration = 5;
int yellow_duration = 2;
int green_duration = 3;
int red_mode = 5;
int yellow_mode = 2;
int green_mode = 3;
