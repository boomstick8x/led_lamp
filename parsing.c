#include <string.h>
#include <stdint.h>
#include <cstdlib>
#include "parsing.h"
#include "cmdstructure.h"
#include "color_control.h"
#include "esp_init.h"
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
		uint8_t i=0;
		char *p=strtok(CmdDataArray, ",");
		LampCmdStructure.CmdStructArr[0]=atoi(p);//array to structure cycle
		while(p)
			{	
				p=strtok(NULL, ",");
				LampCmdStructure.CmdStructArr[++i]=atoi(p);				
			}
		ExecuteCommand();			
	}

void Data_Received(char data)
	{
		if(data==0x0D && CmdDataArray[0]=='+')//НЕ РАБОТАЕТ, НАДО ПОДУМАТЬ НАД ПРИЁМОМ СООБЩЕНИЙ
			{
				CmdDataArray[ArrI]=0;
				Usart_Parsing();
				ArrI=0;
			}
			if(data==0x0D && CmdDataArray[--ArrI]=='K')//ПРОВЕРКА НА ОК ДЛЯ СКРИПТА ИНИЦИАЛИЗАЦИИ
		{
					ESP_Init();
					return;			
		}
		else
			{
			CmdDataArray[ArrI]=data;
			ArrI++;
			}
			
	}
