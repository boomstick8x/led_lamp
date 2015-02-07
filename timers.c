#include <stm32l1xx.h>
#include "color_control.h"
#include "blur.h"

void TIM6_Init()
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM6EN;
	NVIC_EnableIRQ(TIM6_IRQn);
	//NVIC_SetPriority(TIM6_IRQn, 3);
	TIM6->CR1 |= TIM_CR1_ARPE;
	TIM6->CR1 &= ~TIM_CR1_UDIS;//UEV disable bit
	//TIM6->DIER  |=TIM_DIER_UIE;//
	TIM6->ARR=1000;//1000-1sec.
	TIM6->PSC=16000-1;//16mHz
	//TIM6->CR1 |= TIM_CR1_CEN;
}

void TIM7_Init()
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM7EN;
	NVIC_EnableIRQ(TIM7_IRQn);
	//NVIC_SetPriority(TIM6_IRQn, 3);
	TIM7->CR1 |= TIM_CR1_ARPE;
	TIM7->CR1 &= ~TIM_CR1_UDIS;//UEV disable bit
	TIM7->DIER  |=TIM_DIER_UIE;//
	TIM7->ARR=100;//1000-1sec, 100-10/sec
	TIM7->PSC=16000-1;//16mHz
	TIM7->CR1 |= TIM_CR1_CEN;
}

void Delay_msec(uint8_t z)
{
	TIM6->ARR=z*1;
	TIM6->EGR|=TIM_EGR_UG;
	TIM6->SR &= ~ TIM_SR_UIF;
	TIM6->CR1 |= TIM_CR1_OPM | TIM_CR1_CEN;
	while(!(TIM6->SR & TIM_SR_UIF));                          // Дождаться конца задержки
	TIM6->SR &= ~TIM_SR_UIF;      	
}

extern uint8_t *ChangeTime, *R_current, *R_received, *G_current, *G_received, *B_current, *B_received;
extern uint8_t DeltaR, DeltaG, DeltaB;
void TIM7_IRQHandler(void)
{
	TIM7->SR &= ~ TIM_SR_UIF;//clear update interrupt flag bit
	
	if(*R_current<*R_received)
	*R_current=*R_current+DeltaR;
	if(*R_current>*R_received)
	*R_current=*R_current-DeltaR;
	
	if(*G_current<*G_received)
	*G_current=*G_current+DeltaG;
	if(*G_current>*G_received)
	*G_current=*G_current-DeltaG;
	
	 if(*B_current<*B_received)
	*B_current=*B_current+DeltaB;
	if(*B_current>*B_received)
	*B_current=*B_current-DeltaB;

	Color_SetR(*R_current);
	Color_SetG(*G_current);
	Color_SetB(*B_current);
	
	//Y=(X^2)/256	
//Y=((X+15)^2)/256	
}



void TIM6_IRQHandler(void)
{
	TIM6->SR &= ~ TIM_SR_UIF;//clear update interrupt flag bit
	//GPIOB->ODR ^= GPIO_ODR_ODR_6;	
}


