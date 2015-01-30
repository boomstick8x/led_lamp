#include <stm32l1xx.h>
#include <stdint.h>
#include "color_control.h"
#include "usart.h"
#include "cmdstructure.h"
	CmdData mystruct;
	CmdData *cmd=&mystruct;
	
int main(){
	Color_Init();
	Color_SetR(0);
	Color_SetG(0);
	Color_SetB(0);
	USART_Init();
	
  RCC->AHBENR |= RCC_AHBENR_GPIOBEN | RCC_AHBENR_GPIOAEN;;
  GPIOB->MODER |= GPIO_MODER_MODER7_0 | GPIO_MODER_MODER6_0;
  GPIOB->OTYPER &= ~GPIO_OTYPER_OT_7 | GPIO_OTYPER_OT_6;
  GPIOB->PUPDR &= ~GPIO_PUPDR_PUPDR7 | GPIO_PUPDR_PUPDR6;
  GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR7 | GPIO_OSPEEDER_OSPEEDR6;
  GPIOB->ODR |= GPIO_ODR_ODR_7;
	
	
	
	/*GPIOA->MODER |= GPIO_MODER_MODER2_0;
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT_2;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR2;
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2;
	GPIOA->ODR |= GPIO_ODR_ODR_2;
	GPIOA->ODR &= ~GPIO_ODR_ODR_2;*/

while(1){
	
//Color_SetB(cmd->b);
	}
	
	
}


/*void TIM2_IRQHandler()//Функция обработчика прерывания от таймера 2
	{
	TIM2->SR &= ~ TIM_SR_UIF;//clear update interrupt flag bit
	GPIOB->ODR ^= GPIO_ODR_ODR_7;//Инвертируем состояние выхода - зажигаем или гасим светодиод
	//GPIOA->ODR ^= GPIO_ODR_ODR_2;//Инвертируем состояние выхода - зажигаем или гасим светодиод
	}*/


