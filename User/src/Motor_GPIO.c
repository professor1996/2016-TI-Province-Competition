#include "Motor_GPIO.h"



void Motor_GPIO_Init(void)                          //双电机驱动H桥IO口配置
{
	GPIO_InitTypeDef GPIO_InitStructure;	
		
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOC, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_SetBits(GPIOC,GPIO_Pin_2); // AO1
	GPIO_SetBits(GPIOC,GPIO_Pin_5);  // AO2
	
  GPIO_SetBits(GPIOC,GPIO_Pin_3);	 //BO1
	GPIO_SetBits(GPIOC,GPIO_Pin_4);	  //BO2

	//GPIO_SetBits(GPIOA,GPIO_Pin_9);  // AO2

}

