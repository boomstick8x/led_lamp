#include <stdint.h>
#include "color_control.h"

extern uint8_t *R_current, *G_current, *B_current, *StayTime, *ChangeTime, *Enable_Random;

void Defaults()
{
	*R_current=0;
	*G_current=0;
	*B_current=0;
	*StayTime=1;
	*ChangeTime=5;
	*Enable_Random=0;
	Color_SetR(*R_current);
	Color_SetG(*G_current);
	Color_SetB(*B_current);
}

