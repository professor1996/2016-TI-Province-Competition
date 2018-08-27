#include "PID.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//初始化PID 
void PID_Init(PidTypeDef * pid)
{
	memset(pid, 0, sizeof(PidTypeDef));
}

//设置参数 
void PID_SetParam(PidTypeDef * pid,double p, double i, double d, double beta, double outbeta, int dif_prior,double kaff, double kvff,double full_beta)
{
	pid->Kp = p;
	pid->Ki = i;
	pid->Kd = d;
	pid->beta = beta;
	pid->outbeta = outbeta;
	pid->dif_prior = dif_prior;
	pid->Kaff = kaff;
	pid->Kvff = kvff;
	pid->full_beta = full_beta;
}



//PID计算 
void PID_Calc(PidTypeDef * pid, double rel_val, double set_val)
{
	double p = 0,
         i = 0,
         d = 0,
         kaff = 0,
         kvff = 0;
	pid->s[2] = set_val;
	pid->e[2] = set_val - rel_val; //获取当前误差
	pid->r[2] = rel_val; //获取当前值

	
	/*计算增量*/
	p = pid->Kp * (pid->e[2] - pid->e[1]);
	
	
	//抗积分饱和
	if(pid->full_beta != 0)
	{
		if(pid->e[1] > pid->full_beta)
			{
				pid->e[2] = ((pid->e[2])>0?0:pid->e[2]);
			}
		else if(pid->e[1] < -pid->full_beta)
			{
				pid->e[2] = ((pid->e[2])>0?pid->e[2]:0);
			}
	}

	
		 //积分分离
	if (pid->beta == 0)
	{
		i = pid->Ki * (pid->e[2]);
	}
	else
	{
		if (pid->e[2] <= pid->beta && pid->e[2] >= -pid->beta) 
			i = pid->Ki * (pid->e[2]);
		else 
			i = 0;	
	} 
	
	//微分先行 
	if (pid->dif_prior)
	{
		d = pid->Kd * (pid->r[2] - 2 * pid->r[1] + pid->r[0]); 
	}	 
	else
	{
		d = pid->Kd * (pid->e[2] - 2 * pid->e[1] + pid->e[0]); 
	}
	
	kvff = (pid->s[2] - pid->s[1]) * pid->Kvff;//速度前馈 
	kaff = (pid->s[2] - 2 * pid->s[1] + pid->s[0]) * pid->Kaff;//加速度前馈 
	
	pid->delta_U = p + i + d + kvff + kaff; //增量式PID 

	
	pid->U = pid->last_U + pid->delta_U; //位置式PID
	
  if(pid->outbeta != 0)
	{
		if(pid->U>pid->outbeta)
			pid->U=pid->outbeta;
		else if(pid->U<-pid->outbeta)
			pid->U=-pid->outbeta;
	}
	
	
	
	/*记录上一次输出*/
	pid->last_U = pid->U;
	/*迭代设定值*/
	pid->s[0] = pid->s[1];
	pid->s[1] = pid->s[2]; 
	/*迭代误差*/
	pid->e[0] = pid->e[1];
	pid->e[1] = pid->e[2]; 
 	/*迭代实际值*/
	pid->r[0] = pid->r[1];
	pid->r[1] = pid->r[2];   
}






