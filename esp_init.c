#include <string.h>
#include <stdint.h>
#include "usart.h"
uint8_t N=0;

void ESP_Init(char *CmdDataArrayPtr)
	{
		char *initstring1="AT+CWMODE=1//station mode\n\r";
		char *initstring2="AT+CIPMODE=0//full duplex transmisson mode\n\r";
		char *initstring3="AT+CIPMUX=0//single connection mode\n\r";
		char *ESP_Init_Array[]={initstring1, initstring2, initstring3};

		if(strcmp(CmdDataArrayPtr, "start")==0)
			{
				USART1_SendString("Starting ESP8266 initialization...\n\r");
				return;
			}
		USART1_SendString(ESP_Init_Array[N]);
		N++;
		if(N==4)
			USART1_SendString("ESP8266 online...");
	}
	



