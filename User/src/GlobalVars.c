#include "GlobalVars.h"



PidTypeDef PidDataSpeed_Left;
PidTypeDef PidDataSpeed_Right;
PidTypeDef PidDataStation;



void PID_InitALL(void)                //初始化位置环，速度环参数
{
	
	PID_Init(&PidDataSpeed_Left);
 	PID_SetParam(&PidDataSpeed_Left , 10.0 , 0.03 , 0 , 4000 , 4000 , 0 , 0 , 0 , 4500);		             // P I D Beta Outbeta Dif_prior Kaff Kvff Full_beta
	
	PID_Init(&PidDataSpeed_Right);
 	PID_SetParam(&PidDataSpeed_Right , 40.0 , 0.02 , 0 , 4000 , 4000 , 0 , 0 , 0 , 4500);		             // P I D Beta Outbeta Dif_prior Kaff Kvff Full_beta

//	PID_Init(&PidDataStation);
// 	PID_SetParam(&PidDataStation , 0.1 , 0.05 , 0 , 4000 , 100 , 0 , 0 , 0 , 4500);		             // P I D Beta Outbeta Dif_prior Kaff Kvff Full_beta

}


