#include <string.h>
#include <stdint.h>
#include <cstdlib>
#include "parsing.h"
#include "cmdstructure.h"
#include "color_control.h"
#include "esp_init.h"
#include "usart.h"
#include "timers.h"

char CmdDataArray[100];
uint8_t ArrI=0;

void ExecuteCommand()
	{
		Color_SetR(*RED);
		Color_SetG(*GREEN);
		Color_SetB(*BLUE);
	}
void Usart_Parsing()
	{
		if(strcmp(CmdDataArray,"ready")==0)
		{
			for(uint8_t i=0; i<8; i++){
			ESP_Init("init");
			}
		}

	}

void Data_Received(char data)
	{
		
		if(data==0x0A && CmdDataArray[ArrI-1]==0x0D)
			{
				CmdDataArray[ArrI-1]=0;	
				Usart_Parsing();
				ArrI=0;
			CmdDataArray[0]=0;
			}		
		else
		{
		CmdDataArray[ArrI]=data;
		ArrI++;
		}
	}
