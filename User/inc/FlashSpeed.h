#ifndef _FlashSpeed_H_
#define _FlashSpeed_H_





#include "stm32f10x.h"
#include "time2.h"
#include "PID.h"
#include "GlobalVars.h"
#include "VisualScope.h"
#include "LDC1000.h"
#include "Encoder_Left.h"
#include "Encoder_Right.h"



void Motor_PWM_Run_Left(int give_pulse,int max_pulse);
void Motor_Free_Left(void);
void Motor_Break_Left(void);

void Motor_PWM_Run_Right(int give_pulse,int max_pulse);
void Motor_Free_Right(void);
void Motor_Break_Right(void);

extern int Encoder_Ratio    ;   //光栅条数为448线  , 电机减速比为  1：30 

extern float Real_Speed_Left  ;
extern float Want_Speed_Left  ;
extern int  Want_Pwm_Left ;
extern float Real_Location_Left  ;
extern float Want_Location_Left  ;

extern float Real_Speed_Right  ;
extern float Want_Speed_Right  ;
extern int  Want_Pwm_Right ;
extern float Real_Location_Right  ;
extern float Want_Location_Right  ;

extern int First_Start_value  ;
extern int First_Start_Flag ;

extern int Delay_value ;
extern int Delay_Flag ;

extern int Coin_Get_Flag ;

#endif










