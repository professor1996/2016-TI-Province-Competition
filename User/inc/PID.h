#ifndef __PID_H
#define __PID_H	



#include "stm32f10x.h"


typedef struct
{
	//PID 三个参数 
	double Kp;
	double Ki;
	double Kd;
	//积分分离
	double beta;//0就是不带积分分离， 如果不为零那么就是积分范围 
	double outbeta;//0就是不带输出限幅，如果不为零那么就是限幅范围
	//微分先行
	int dif_prior;//0是不带微分先行 
	//变速积分 
	//PID输出值
	double last_U; //上一次的输出值 
	double delta_U;//增量式PID
	double U;//位置式PID
	//设定值
	double s[3]; 
	//误差
	double e[3];//每次的误差2是最新的1是上一次的0是大上次
	//实际值
	double r[3];
	//前馈参数
	double Kvff; 
	double Kaff;
	double full_beta;
	 
}PidTypeDef;


void PID_Init(PidTypeDef * pid);

void PID_SetParam(PidTypeDef * pid,double p, double i, double d, double beta, double outbeta,int dif_prior,double kaff, double kvff,double full_beta);

void PID_Calc(PidTypeDef * pid, double rel_val, double set_val);






#endif
