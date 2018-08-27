#include "Usart3_Tx.h"


void USART3_sendData(u8 *a,u8 count)
{
	uint8_t i = 0,j = 0,data;
	for (i = 0; i < count; i++)
	{
		EnQueue(&TxBuffer_UART3,a[i]);//把a[i]里面的数据给&TxBuffer_UART2
	} 	
	if (DMA_GetCurrDataCounter(DMA1_Channel2) == 0)
	{
		j = GetQueueLength(&TxBuffer_UART3);
		if (j > 50) j = 50;
		for (i = 0; i < j; i++)
		{
				DeQueue(&TxBuffer_UART3,&data);
				aTxBuffer_UART3[i] = data;
		}
		DMA_Cmd(DMA1_Channel2, DISABLE); 							//F4中不需要
		DMA_SetCurrDataCounter(DMA1_Channel2,j);
		DMA_Cmd(DMA1_Channel2, ENABLE);  
	}
}


void USART3_TxHandler(void)
{
	uint8_t i = 0,j = 0,data;
	j = GetQueueLength(&TxBuffer_UART3);
	if (j > 20) j = 20;
	else if (j == 0) return;
	for (i = 0; i < j; i++)
	{
			DeQueue(&TxBuffer_UART3,&data);//把队列TxBuffer_UART2的数据给data
			aTxBuffer_UART3[i] = data;
	}
	DMA_Cmd(DMA1_Channel2, DISABLE); 							//F4中不需要
	DMA_SetCurrDataCounter(DMA1_Channel2,j);
	DMA_Cmd(DMA1_Channel2, ENABLE);  
}


void DMA1_Channel2_IRQHandler(void)
{
	if(DMA_GetITStatus(DMA1_IT_TC2) != RESET)
	{
		DMA_ClearFlag (DMA1_IT_TC2);					//清除中断标志
		DMA_ClearITPendingBit(DMA1_IT_TC2);
		USART3_TxHandler();
	}
}


void USART3_printf(const char *fmt, ...)
{	
	va_list ap;
	uint16_t len;
	uint8_t buf[128];
	va_start(ap, fmt);
	len = vsprintf((char *)buf, (char *)fmt, ap);
	va_end(ap);	
	while (len >= (50 - GetQueueLength(&TxBuffer_UART3)));
	USART3_sendData(buf,len);
}










