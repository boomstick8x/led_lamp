#include <stm32l1xx.h>
#include <stdint.h>
#include "color_control.h"
#include "timers.h"
extern uint8_t *R_current, *R_received, *G_current, *G_received, *B_current, *B_received, *ChangeTime;
#include "color_control.h"
uint8_t DeltaR, DeltaG, DeltaB;

void Blur()
{

	if(*R_current<*R_received)
	DeltaR=((*R_received)-(*R_current))/(*ChangeTime);
	if(*R_current>*R_received)
	DeltaR=((*R_current)-(*R_received))/(*ChangeTime);
	
	if(*G_current<*G_received)
	DeltaG=((*G_received)-(*G_current))/(*ChangeTime);
	if(*G_current>*G_received)
	DeltaG=((*G_current)-(*G_received))/(*ChangeTime);
	
	if(*B_current<*B_received)
	DeltaB=((*B_received)-(*B_current))/(*ChangeTime);
	if(*B_current>*B_received)
	DeltaB=((*B_current)-(*B_received))/(*ChangeTime);
	
	
}

