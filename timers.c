#include <stm32l1xx.h>
#include <stdint.h>
#include "color_control.h"
#include "blur.h"
#include "cie1931.h"


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

void Delay_msec(uint8_t z)
{
	TIM6->ARR=z*1;
	TIM6->EGR|=TIM_EGR_UG;
	TIM6->SR &= ~ TIM_SR_UIF;
	TIM6->CR1 |= TIM_CR1_OPM | TIM_CR1_CEN;
	while(!(TIM6->SR & TIM_SR_UIF));                          // Дождаться конца задержки
	TIM6->SR &= ~TIM_SR_UIF;      	
}

void TIM7_Init()
{
	RCC->APB1ENR|=RCC_APB1ENR_TIM7EN;
	NVIC_EnableIRQ(TIM7_IRQn);
	//NVIC_SetPriority(TIM6_IRQn, 3);
	TIM7->CR1 |= TIM_CR1_ARPE;
	TIM7->CR1 &= ~TIM_CR1_UDIS;//UEV disable bit
	TIM7->DIER  |=TIM_DIER_UIE;//
	TIM7->ARR=1;//1000-1sec, 100-10/sec, 10-100/sec
	TIM7->PSC=16000-1;//16mHz
	TIM7->CR1 |= TIM_CR1_CEN;
}

extern uint8_t *ChangeTime, *R_current, *R_received, *G_current, *G_received, *B_current, *B_received;
extern uint8_t DeltaR, DeltaG, DeltaB;
uint8_t cieI;
uint32_t iR, iG, iB;

void TIM7_IRQHandler(void)
{

	if(*R_current<*R_received)
	iR+=DeltaR;
	if(*R_current>*R_received)
	iR-=DeltaR;	
	if(*G_current<*G_received)
	iG+=DeltaG;
	if(*G_current>*G_received)
	iG-=DeltaG;
	if(*B_current<*B_received)
	iB+=DeltaB;
	if(*B_current>*B_received)
	iB-=DeltaB;

	*R_current=cie[iR/((*ChangeTime*1000))];
	*G_current=cie[iG/((*ChangeTime*1000))];
	*B_current=cie[iB/((*ChangeTime*1000))];

	Color_SetR(cie[*R_current]);
	Color_SetG(cie[*G_current]);
	Color_SetB(cie[*B_current]);
	TIM7->SR &= ~ TIM_SR_UIF;//clear update interrupt flag bit
/*if(cie[*R_current]<cie[*R_received])	
	*R_current=cie[cieI++];
if(cie[*R_current]>cie[*R_received])
	*R_current=cie[cieI--];*/
}



void TIM6_IRQHandler(void)
{
	TIM6->SR &= ~ TIM_SR_UIF;//clear update interrupt flag bit
	//GPIOB->ODR ^= GPIO_ODR_ODR_6;	
}


