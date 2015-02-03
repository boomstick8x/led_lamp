#include <stm32l1xx.h>

void (*CallBack_Data_Received)(char);//возвращает void, передаёт char

void USART_SetCB_Data_Received_Ptr(void (*CBPtr)(char))//принимаем указатель на начала Data_Received
	{
		CallBack_Data_Received=CBPtr;//объявляем и инициализируем указатель на функцию
	}
	
void Usart_SendChar(char data)
	{
		while(!(USART1->SR & USART_SR_TC));//Проверка завершения передачи предыдущих данных
		USART1->DR=(data);
	}
	
void Usart_SendString(char *data)
	{
		while(*data)
		{
			while(!(USART1->SR & USART_SR_TC));//Проверка завершения передачи предыдущих данных
			USART1->DR=(*data);
			data++;
		}
	}
	
void USART_Init()
	{
		RCC->CR |= RCC_CR_HSION; //Включаем тактовый генератор HSI
		while(!(RCC->CR & RCC_CR_HSIRDY)); //Ждем его стабилизации
		RCC->CFGR |= RCC_CFGR_SW_HSI; //Выбираем источником тактовой частоты SYSCLK генератор HSI
		RCC->CR &= ~RCC_CR_MSION; //Отключаем генератор MSI.

		//GPIOA CONFIGURATION
		RCC -> AHBENR |= RCC_AHBENR_GPIOAEN;	
		GPIOA -> MODER |= (GPIO_MODER_MODER9_1 | GPIO_MODER_MODER10_1);//AF for PA9 and PA10
		GPIOA -> OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR9_1 | GPIO_OSPEEDER_OSPEEDR10_1);
		GPIOA -> OTYPER &= ~(GPIO_OTYPER_OT_9);//push-pull for output
		GPIOA -> PUPDR &= ~(GPIO_PUPDR_PUPDR10);//no pull-up, ?pull-down? for input
		GPIOA -> AFR[1] |= (0x770);//afio7 for pa9 - USART1_TX and pa10 - USART1_RX
	
		//USART CONFIGURATION
		NVIC_EnableIRQ (USART1_IRQn);//Usart enable IRQ
		RCC -> APB2ENR |= RCC_APB2ENR_USART1EN;//USART CLOCK ENABLE
		USART1 -> BRR = 0x683; //9600 baud rate 0x683
		USART1 -> CR1  |= USART_CR1_RE | USART_CR1_TE | USART_CR1_RXNEIE | USART_CR1_UE ;//| USART_CR1_TXEIE;//enable: recive, transimt, USART, Interrupt Read Data not empty
		//	USART1 -> CR1  |= USART_CR1_RE | USART_CR1_RXNEIE | USART_CR1_UE ;//enable: recive, IRQ Data not empty, USART	
		Usart_SendString("USART1 ready\n\r");
		
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

