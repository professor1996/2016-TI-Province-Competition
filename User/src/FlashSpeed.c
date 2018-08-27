#include "FlashSpeed.h"


int Encoder_Ratio  = 448 ;   //光栅条数为448线  , 电机减速比为  1：30 

float Real_Speed_Left = 0.0;
float Want_Speed_Left = 0;          //500
int  Want_Pwm_Left = 0;
float Real_Location_Left = 0.0;
float Want_Location_Left = 0.0;

float Real_Speed_Right = 0.0;
float Want_Speed_Right = 0;    //515
int  Want_Pwm_Right = 0;
float Real_Location_Right = 0.0;
float Want_Location_Right = 0.0;

float All_time = 0.0;
int All_time_flag = 0;

float All_distance = 0.0  ;

int First_Start_value = 1 ;
int First_Start_Flag = 1;

int Delay_value = 1;
int Delay_Flag = 1;

int Coin_Get_Flag = 0;

#define abs(x) ((x)>0? (x):(-(x)))


void TIM2_IRQHandler()                      //更新转速和位置
{
	int Pwm_Cnt_Left = 0;	
	int Pwm_Cnt_Right = 0;
	
	if(TIM_GetITStatus(TIM2 , TIM_IT_Update) != RESET)
	{

		TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	
	  Pwm_Cnt_Left = Encoder_Get_CNT_Left();
   	Real_Speed_Left = Pwm_Cnt_Left*750/Encoder_Ratio ;	
		Real_Location_Left += Encoder_Get_CNT_Left() ;
	
		PID_Calc(&PidDataSpeed_Left , Real_Speed_Left , Want_Speed_Left);         //控制左电机转速
		Want_Pwm_Left  = PidDataSpeed_Left.U;
		Motor_PWM_Run_Left(Want_Pwm_Left  , 4000);
		
		Pwm_Cnt_Right = Encoder_Get_CNT_Right();	
	  Real_Speed_Right = Pwm_Cnt_Right*750/Encoder_Ratio ;                 		
		Real_Location_Right += Encoder_Get_CNT_Right();
		
  	PID_Calc(&PidDataSpeed_Right , Real_Speed_Right , Want_Speed_Right);         //控制右电机转速
	  Want_Pwm_Right = PidDataSpeed_Right.U;
		Motor_PWM_Run_Right(Want_Pwm_Right , 4000);
	
		
	  First_Start_value++;
		if(First_Start_value == 2400)
		{
			First_Start_Flag = 0;
			First_Start_value = 1;
		}
		
		if(Coin_Get_Flag)
		{
				Delay_value++;
				if(Delay_value == 500)
				{
					Delay_value = 1;
					Coin_Get_Flag = 0;
				}

	  }
		
		All_time_flag++;
		All_time = 0.002 * All_time_flag ;                                    //得到总运行时间
		if(All_time > 60)
		{
			All_time_flag = 0;
		}

	}
}

//左电机驱动使能

void Motor_PWM_Run_Left(int give_pulse,int max_pulse)
{
    max_pulse = abs(max_pulse);
    
    if(give_pulse < 0)
		{
			
			GPIO_ResetBits(GPIOC,GPIO_Pin_5);   // AO1
			GPIO_SetBits(GPIOC,GPIO_Pin_2);        // AO2
			
			if(give_pulse < (-max_pulse))
			{
				give_pulse = (-max_pulse);
			}
			
    }
		
    else 
    {
					
			GPIO_SetBits(GPIOC,GPIO_Pin_5); // AO1
			GPIO_ResetBits(GPIOC,GPIO_Pin_2);  // AO2
			
			if(give_pulse > max_pulse)
			{
				give_pulse = max_pulse;
			}
			
    }												  
		
    TIM2->CCR2 = abs(give_pulse);

}

void Motor_Free_Left(void)
{
	TIM2->CCR2 = 0;
	GPIO_ResetBits(GPIOC,GPIO_Pin_2);
	GPIO_ResetBits(GPIOC,GPIO_Pin_5);		
}

void Motor_Break_Left(void)
{
	TIM2->CCR2 = 4000;
	GPIO_ResetBits(GPIOC,GPIO_Pin_2);
	GPIO_ResetBits(GPIOC,GPIO_Pin_5);
}



//右电机驱动使能

void Motor_PWM_Run_Right(int give_pulse,int max_pulse)
{
    max_pulse = abs(max_pulse);
    
    if(give_pulse < 0)
		{
			
			GPIO_SetBits(GPIOC,GPIO_Pin_3);	 //BO1
			GPIO_ResetBits(GPIOC,GPIO_Pin_4);	  //BO2
			
			if(give_pulse < (-max_pulse))
			{
				give_pulse = (-max_pulse);
			}
			
    }
		
    else 
    {
							
			GPIO_ResetBits(GPIOC,GPIO_Pin_3);	 //BO1
			GPIO_SetBits(GPIOC,GPIO_Pin_4);	  //BO2
			
			if(give_pulse > max_pulse)
			{
				give_pulse = max_pulse;
			}
			
    }												  
		
    TIM2->CCR1 = abs(give_pulse);

}

void Motor_Free_Right(void)
{
	TIM2->CCR1 = 0;
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);	 //BO1
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);	  //BO2
}

void Motor_Break_Right(void)
{
	TIM2->CCR1 = 4000;
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);	 //BO1
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);	  //BO2
}

