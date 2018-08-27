#include "Usart3_Interrupt.h"



u8 USART_RX_BUF[32];
u8 USART_RX_STA = 0;
u8 Receive_start_flag = 0;
u8 Receive_end_flag = 0;
u8 fuction_start_flag = 0;
u8 temp = 0;


void USART3_IRQHandler(void)
{

	if(USART_GetITStatus(USART3 , USART_IT_RXNE) == SET)	//接收寄存器非空
	{
		
		USART_ClearFlag (USART3,USART_IT_RXNE);			//清除中断标志
		USART_ClearITPendingBit(USART3 , USART_IT_RXNE);		
		temp = USART_ReceiveData(USART3);
		
		if(Receive_start_flag == 1)
		{
			
			USART_RX_BUF[USART_RX_STA] = temp ;
			USART_RX_STA++;
			
		  if(temp == 0x2F)
	  	{
	  		Receive_end_flag = 1;
	  	}
			
		}
		
		if(temp == '#')
		{
			Receive_start_flag = 1;
		}
		
		if(Receive_end_flag == 1)
		{
			Receive_end_flag = 0;
			fuction_start_flag = 0;
			Receive_start_flag = 0;
	
		}	 
		
			 
	 }												
		
  
	
}

