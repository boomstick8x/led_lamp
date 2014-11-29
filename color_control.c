#include "stm32l1xx.h"
void PWM_Init();

void PWM_Init(){
	RCC->AHBENR |=RCC_AHBENR_GPIOAEN;
	GPIOA->MODER|=GPIO_MODER_MODER1_1|GPIO_MODER_MODER2_1|GPIO_MODER_MODER3_1;//enable alternate functions for PA1, PA2, PA3
	GPIOA->OTYPER&=~GPIO_OTYPER_OT_1|GPIO_OTYPER_OT_2|GPIO_OTYPER_OT_3;//push-pull
	GPIOA->OSPEEDR|=GPIO_OSPEEDER_OSPEEDR1|GPIO_OSPEEDER_OSPEEDR2|GPIO_OSPEEDER_OSPEEDR3;//high speed
	GPIOA->PUPDR|=GPIO_PUPDR_PUPDR1_1|GPIO_PUPDR_PUPDR2_1|GPIO_PUPDR_PUPDR3_1;//pull-down
	GPIOA->AFR[0]|=0x1110;//AFIO1 for TIM2_CH2,3,4
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->CR1 |= TIM_CR1_ARPE;//auto-reload enable
	TIM2->CCMR2 |= TIM_CCMR2_OC3PE;//preload channel 3 Compare enable
	TIM2->CCMR1 |= TIM_CCMR1_OC2PE;//preload channel 2 Compare enable
	TIM2->CCMR2 |= 0x60;//PWM mode 1 for channel 3
	TIM2->CCMR1 |= 0x6000;//PWM mode 1 for channel 2
	TIM2->ARR = 254;//auto reload value
	TIM2->CCER |= TIM_CCER_CC2E;//output channel 2 enable
	TIM2->CCER |= TIM_CCER_CC3E;//output channel 3 enable
	TIM2->CCER |= TIM_CCER_CC4E;//output channel 4 enable
	TIM2->CR1 |= TIM_CR1_CEN;//Enable counter
	
	TIM2->CCR2 = 1;//RED Duty cycle
  TIM2->CCR3 = 1;//GREEN Duty cycle
	//TIM2->CCR4 = 1;//BLUE Duty cycle
	//TIM2->DIER |= TIM_DIER_UIE;//interrupt enable
	//NVIC_SetPriority(TIM2_IRQn, 1); //Приоритет прерывания
	//NVIC_EnableIRQ(TIM2_IRQn); //Разрешаем обработку прерывания от таймера 2
	
	//TIM2->CR1 &= ~ TIM_CR1_DIR;//upcounter

	}
