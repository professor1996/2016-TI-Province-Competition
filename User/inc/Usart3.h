#ifndef __Usart3_H
#define __Usart3_H	



#include "stm32f10x.h"
#include "Queue.h"
#include "stdio.h"
#include "stdarg.h"
#include "string.h"


void Usart3_init(void);
void USART3_printf(const char *fmt, ...);
void USART3_sendData(u8 *a,u8 count);


extern uint8_t aTxBuffer_UART3[50] ;			
extern QueueTypeDef TxBuffer_UART3;		


#endif











