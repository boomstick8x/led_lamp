#include <stm32l1xx.h>
#include <stdint.h>
#include "color_control.h"
#include "timers.h"
extern uint8_t *R_current, *R_received, *G_current, *G_received, *B_current, *B_received, *ChangeTime;


void Blur()
{
//	TIM7->ARR=*ChangeTime;
/*	
if(*R_current<*R_received)
	while(*R_current<*R_received)
	{
		*R_current=*R_current+1;
		Color_SetR(*R_current);
		Delay_msec(*ChangeTime);
	}
	
if(*R_current>*R_received)
	while(*R_current>*R_received)
	{
		*R_current=*R_current-1;
		Color_SetR(*R_current);
		Delay_msec(*ChangeTime);
	}
	//if(*CmdByte=='s')*/
}

