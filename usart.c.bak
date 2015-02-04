#include <stm32l1xx.h>

void (*CallBack_Data_Received)(char);//возвращает void, передаёт char

void USART_SetCB_Data_Received_Ptr(void (*CBPtr)(char))//принимаем указатель на начала Data_Received
	{
		CallBack_Data_Received=CBPtr;//объявляем и инициализируем указатель на функцию
	}
	
void USART1_SendChar(char data)
	{
		while(!(USART1->SR & USART_SR_TC));//Проверка завершения передачи предыдущих данных
		USART1->DR=(data);
	}
	
void USART1_SendString(char *data)
	{
		while(*data)
		{
			USART1_SendChar(*data);
			data++;
		}
		USART1_SendChar(0X0D);
	}
	
void USART_Init(uint8_t x)
	{
		USART_TypeDef * USARTX;
		switch (x)
		{
			case 1:
				NVIC_EnableIRQ (USART1_IRQn);
				USARTX=  ((USART_TypeDef *) USART1);
				break;
			case 2:
				NVIC_EnableIRQ (USART2_IRQn);
				USARTX=  ((USART_TypeDef *) USART2);
				break;
			case 3:
				NVIC_EnableIRQ (USART3_IRQn);
				USARTX=  ((USART_TypeDef *) USART3);
				break;
		}
		//--usart1 part
		RCC -> APB2ENR |= RCC_APB2ENR_USART1EN;
		USARTX -> BRR = 0x683; //9600 baud rate 0x683
		//enable: recive, transimt, USART, DR not empty Interrupt
		USARTX -> CR1  |= USART_CR1_RE | USART_CR1_TE | USART_CR1_RXNEIE | USART_CR1_UE ;//| USART_CR1_TXEIE;прерывание по опустошению
		USART1_SendString("USART1 ready\n\r");
		//--usart3 part
		RCC -> APB1ENR |= RCC_APB1ENR_USART3EN;
	
	}

void USART1_IRQHandler(void)
	{
		if (USART1->SR & USART_SR_RXNE)//Rx register not empty
		{
			GPIOB->ODR ^= GPIO_ODR_ODR_7;
			if (CallBack_Data_Received)
				(*CallBack_Data_Received)(USART1->DR);		
		}
	}
	

void USART3_IRQHandler(void)
	{
		GPIOB->ODR ^= GPIO_ODR_ODR_6;
		if (USART3->SR & USART_SR_RXNE)//Rx register not empty
			while(!(USART3->SR & USART_SR_TC));
			USART3->DR=USART3->DR;
	}
	
	
	
	
	
	
