#include "Usart3.h"

#define abs(x) ((x)>0? (x):(-(x)))


uint8_t aTxBuffer_UART3[50] = {0};			
QueueTypeDef TxBuffer_UART3;		


void Usart3_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure ;
	NVIC_InitTypeDef  nvic;
	DMA_InitTypeDef   dma;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init(GPIOB , &GPIO_InitStructure) ;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING ;
	GPIO_Init(GPIOB , &GPIO_InitStructure) ; 	
	
	USART_DeInit(USART3);
	USART_InitStructure.USART_BaudRate = 115200 ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None ;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx ;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_StopBits = USART_StopBits_1 ;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b ;
	USART_Init(USART3 , &USART_InitStructure);
	
	USART_ClearFlag (USART3 , USART_IT_RXNE);
	USART_ClearITPendingBit(USART3,USART_IT_RXNE);
	USART_ITConfig(USART3 , USART_IT_RXNE,ENABLE);
	
	DMA_DeInit(DMA1_Channel2);

	dma.DMA_PeripheralBaseAddr = (uint32_t)(&(USART3->DR));
	dma.DMA_MemoryBaseAddr = (uint32_t)aTxBuffer_UART3;
	dma.DMA_DIR = DMA_DIR_PeripheralDST ;
	dma.DMA_BufferSize = 0;
	dma.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	dma.DMA_MemoryInc = DMA_MemoryInc_Enable;
	dma.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	dma.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;
	dma.DMA_Mode = DMA_Mode_Normal;
	dma.DMA_Priority = DMA_Priority_Low;
	dma.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel2, &dma);
	
	DMA_ITConfig(DMA1_Channel2, DMA_IT_TC, ENABLE);  
	//设置USART为DMA发送
	USART_DMACmd(USART3, USART_DMAReq_Tx, ENABLE);
	//配置NVIC
	nvic.NVIC_IRQChannel = USART3_IRQn;          
	nvic.NVIC_IRQChannelPreemptionPriority = 3; 
	nvic.NVIC_IRQChannelSubPriority = 4;        
	nvic.NVIC_IRQChannelCmd = ENABLE;           
	NVIC_Init(&nvic);   
	
	nvic.NVIC_IRQChannel = DMA1_Channel2_IRQn;          
	nvic.NVIC_IRQChannelPreemptionPriority = 4; 
	nvic.NVIC_IRQChannelSubPriority = 4;        
	nvic.NVIC_IRQChannelCmd = ENABLE;           
	NVIC_Init(&nvic);   
	//使能USART
	USART_Cmd(USART3, ENABLE);
	
	
}









