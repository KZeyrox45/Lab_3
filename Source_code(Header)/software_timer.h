/*
 * software_timer.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Hieu
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[6];
/* Each index presenting as following:
 * 0: LED_RED port
 * 1: Index Segment
 * 2: Vertical traffic lights (R2, Y2, G2)
 * 3: Horizontal traffic lights (R1, Y1, G1)
 * 4: Counter Segment
 * 5: Blink Mode
 */

void setCycle(int cycle);
void setTimer(int duration, int i);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
