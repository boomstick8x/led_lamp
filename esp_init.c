#include <string.h>
#include <stdint.h>
#include "usart.h"
uint8_t N=1;

void ESP_Init()
	{
		char *initstring1="AT";
		char *initstring2="AT+CWMODE=1";
		char *initstring3="AT+CWJAP=\"kaa\",\"19562876\" ";
		char *initstring4="AT+CIFSR";
		char *initstring5="AT+CIPMODE=0";
		char *initstring6="AT+CIPMUX=1";
		char *initstring7="AT+CIPSERVER=1,8888";	
		char *initstring8="AT+CIPSTATUS";	
		char *ESP_Init_Array[]={initstring1, initstring2, initstring3, initstring4, initstring5, initstring6, initstring7, initstring8};
		if(N>7)
			return;
		USART1_SendString(ESP_Init_Array[N]);
		N++;
		for(uint32_t i; i<30000; i++);
		
		
	}
	



