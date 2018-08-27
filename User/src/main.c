#include "stm32f10x.h"
#include "stdint.h"
#include "Encoder_Left.h"
#include "Encoder_Right.h"
#include "Time2.h"
#include "Delay1.h"
#include "Motor_GPIO.h"
#include "PID.h"
#include "Usart3.h"
#include "GlobalVars.h"
#include "VisualScope.h"
#include "Queue.h"
#include "Usart3_Tx.h"
#include "Usart3_Interrupt.h"
#include "FlashSpeed.h"
#include "LDC1000.h"
#include "DigitalTube.h"
#include "Buzzer.h"


int i;
int flag = 1;
int Central_Set_Station = 0;
int Turning_flag = 0;
int Central_Cross_flag = 0;
int Err = 0;
int Init_flag = 1;

int main(void)
{

  SystemInit();
	output();
	PID_InitALL();	
  Encoder_Configuration_Left();
	Encoder_Configuration_Right();	
  TIM2_Configuration();
  Motor_GPIO_Init();
	Usart3_init();
//	Buzzer_GPIO_Init();
//	LDC_GPIO_Configuration();
//	Delay(99999999);                        //使LDC充分上电
//	LDC_Init();
//	Delay(999999);
//	
	
	
	while(1)
	{
		
		LDC_val = ldc_read_avr();           //  采样滤波，更新LDC数值
		
		if(Init_flag)
		{
			Delay(999999);                         //    标准：Delay(999999);
			for(i = 0 ; i <= 1000 ; i++)
			{
				LDC_val += ldc_read_avr();          
			}
			Central_Set_Station = LDC_val / 1000 ;                //得到初始中心位置
			Err = Central_Set_Station - 300;                            // 200   100
			TIM2_Start();            		             	//启动两电机
			
			
			Coin_Get_Flag = 1 ;		
			while(Coin_Get_Flag)
			{
				GPIO_SetBits(GPIOA , GPIO_Pin_9); 
			}
			GPIO_ResetBits(GPIOA , GPIO_Pin_9); 
			
			Want_Speed_Left = 15;
			Want_Speed_Right = 35;
			while(First_Start_Flag);
			Turning_flag = 2;
			
			Init_flag = 0;
		}
				
		
		
		
		if( Turning_flag == 1 )           //左偏
		{
		  Want_Speed_Left = 10;                                           //10
			Want_Speed_Right = 70;                                          //50
			
			if( ((Central_Set_Station - 155) < LDC_val) && (LDC_val < (Central_Set_Station + 155)) )     //   100    60
			{
				Central_Cross_flag = 1 ;
			}
			
			
			if(Central_Cross_flag)
			{
				Want_Speed_Left = 15;                                           //15
				Want_Speed_Right = 55;                                            //30
				
				if( LDC_val < Err )
				{
					Turning_flag = 2;
					Central_Cross_flag = 0;
				}	
				
			}		
			
		  
		}
		
		
		if(Turning_flag == 2)        //右偏
		{
			Want_Speed_Left = 70;                                 // 50
			Want_Speed_Right = 10;                                   //10
			
			if( ((Central_Set_Station - 155) < LDC_val) && (LDC_val < (Central_Set_Station + 155)) )   //100  60
			{
				Central_Cross_flag = 1 ;
			}

			if(Central_Cross_flag)
			{
				Want_Speed_Left = 55;                                 //30
				Want_Speed_Right = 15;				                         // 15
				
				if( LDC_val < Err )
				{
					Turning_flag = 1;
					Central_Cross_flag = 0;
				}	
				
		  }		
						
			
		}
		


		
		
		
		
			
  }
}
	
		
		
		
		
	

	







