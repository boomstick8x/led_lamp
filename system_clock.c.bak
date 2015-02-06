#include <stm32l1xx.h>
void SystemClock_Init()
	{
		RCC->CR |= RCC_CR_HSION; //Включаем тактовый генератор HSI
		while(!(RCC->CR & RCC_CR_HSIRDY)); //Ждем его стабилизации
		RCC->CFGR |= RCC_CFGR_SW_HSI; //Выбираем источником тактовой частоты SYSCLK генератор HSI
		RCC->CR &= ~RCC_CR_MSION; //Отключаем генератор MSI.
	}
