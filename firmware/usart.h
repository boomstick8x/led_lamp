#include "stdint.h"
void USART_Init(uint8_t);
void USART1_SendChar(char);
void USART1_SendString(char *);
void USART_SetCB_Data_Received_Ptr(void *);
