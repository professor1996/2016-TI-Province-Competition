#include "Time2.h"


void TIM2_Configuration(void)
{
	TIM_TimeBaseInitTypeDef  tim;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef         nvic;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
  GPIO_Init(GPIOA, &GPIO_InitStructure);

	nvic.NVIC_IRQChannel = TIM2_IRQn;
	nvic.NVIC_IRQChannelPreemptionPriority = 0 ;
	nvic.NVIC_IRQChannelSubPriority = 0 ;
	nvic.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic);

	tim.TIM_Prescaler = 36 - 1;  //72Khz/9= 8Khz  
	tim.TIM_CounterMode = TIM_CounterMode_Up;
	tim.TIM_ClockDivision = TIM_CKD_DIV1;
	tim.TIM_Period = 4000 - 1;				//  2ms
	TIM_TimeBaseInit(TIM2,&tim);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;             //设置TIM2  A0 A1口为PWM输出模式
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0 ;//         
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
  TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;
  TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
  TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;	
  TIM_OC1Init(TIM2 , &TIM_OCInitStructure);
  TIM_OC1PreloadConfig(TIM2 , TIM_OCPreload_Enable);
	
	TIM_OC2Init(TIM2 , &TIM_OCInitStructure);
  TIM_OC2PreloadConfig(TIM2 , TIM_OCPreload_Enable);
  TIM_ARRPreloadConfig(TIM2 , ENABLE);   
	
	TIM2_Start();
}

void TIM2_Dis()
{
	TIM_Cmd(TIM2 , DISABLE) ;
	TIM_ITConfig(TIM2 , TIM_IT_Update , DISABLE) ;
	TIM_ClearFlag(TIM2 , TIM_FLAG_Update) ; 
	
}

void TIM2_Start()
{
	TIM_Cmd(TIM2 , ENABLE) ;
	TIM_ITConfig(TIM2 , TIM_IT_Update , ENABLE) ;
	TIM_ClearFlag(TIM2 , TIM_FLAG_Update) ; 
}



