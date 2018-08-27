#ifndef _QUEUE_H_
#define _QUEUE_H_





#if defined(STM32F10X_LD)||defined (STM32F10X_LD_VL)||defined (STM32F10X_MD)||defined (STM32F10X_MD_VL)||defined (STM32F10X_HD)||defined (STM32F10X_HD_VL)||defined (STM32F10X_XL)||defined (STM32F10X_CL) 
#include "stm32f10x.h"
#elif defined(STM32F4XX)
#include "stm32f4xx.h"
#endif 

#include "string.h"
#define QUEUE_SIZE    200  
#define ARRAY_SIZE    (QUEUE_SIZE + 1) 

typedef struct  
{
    int     front;   
    int     rear; 
    uint8_t Data[ARRAY_SIZE];    
}QueueTypeDef;

void SetEmpty(QueueTypeDef * queue);
void EnQueue(QueueTypeDef * queue,uint8_t Data);
void DeQueue(QueueTypeDef * queue,uint8_t * Data);
uint8_t GetQueueLength(QueueTypeDef * queue);

#endif /*_QUEUE_H_*/




