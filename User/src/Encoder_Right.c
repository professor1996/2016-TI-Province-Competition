#include "Encoder_Right.h"



void Encoder_Configuration_Right(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4 , ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    TIM_EncoderInterfaceConfig(TIM4 , TIM_EncoderMode_TI12 , TIM_ICPolarity_Falling , TIM_ICPolarity_Falling);
    TIM_Cmd(TIM4,ENABLE);	
	
	  TIM4->CNT = 0x7fff;

}

int Encoder_Get_CNT_Right(void)
{
    int cnt = 0;
 
    static unsigned char first_flag = 0;
    
    if(first_flag == 0)
    {
        first_flag = 1;
        return 0;
    }
		
    cnt =0x7fff-(TIM4->CNT);
    TIM4->CNT = 0x7fff;
    return cnt;		
}



