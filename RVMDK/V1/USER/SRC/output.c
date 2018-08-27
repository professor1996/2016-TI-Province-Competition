#include "output.h"

    u16 tim_bit;
    u8 a_bit,ten_bit,hundr_bit,thoud_bit,station_bit;     //数字时钟的全局变量
    u8 La_bit,Lten_bit,Lhundr_bit,Lthoud_bit;            //路程的全局变量

void output(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;       /*****初始化GPIO*****/
    SystemInit();                              /*****打开GPIO时钟*****/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO,ENABLE);
	
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);

    
    SysTick_Config(72000);        //每1毫秒产生一次中断
    station_bit = 1;               //位选标志位

/*****时钟各位标志*****/
    tim_bit = 0;                   
    a_bit = 0;
    ten_bit = 0;
    hundr_bit = 0;
    thoud_bit = 0;
	
/*****位置显示各标志位*****/
    La_bit = 0;
    Lten_bit = 0;
    Lhundr_bit = 0;
    Lthoud_bit = 0;
	
/*****路程GPIO*****/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOE,&GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOD,&GPIO_InitStructure);


/*****时钟GPIO*****/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC,&GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOE,&GPIO_InitStructure);

}


void SysTick_Handler(void)
{
    u16 left_move,right_move,total_move;
	
	
	
	
	
/********时钟各项进位********/		
    tim_bit++;                 //中断标志位自加
    if(tim_bit == 1000)         //1S时个位进一
    {
        tim_bit = 0;
        a_bit++;
		}

		if(a_bit == 10)            //10S时十位进一
    {
        a_bit = 0;
        ten_bit++;			
		}
		
		if(ten_bit == 6)
    {
        ten_bit = 0;
        hundr_bit++;
		}
		
		if(hundr_bit == 10)
    {
        hundr_bit = 0;
        thoud_bit++;
		}
		
		if(thoud_bit == 10)
    {
        thoud_bit = 0;
		}
		
		
/*****路程各项进位*****/	
//   left_move = Real_Left_Location;
//		right_move = Real_Right_Location;

		total_move = (left_move + right_move)*0.12;
		La_bit = total_move % 10;
		Lten_bit = (total_move % 100)/10;
		Lhundr_bit = (total_move % 1000)/100; 
		Lthoud_bit = total_move/1000;
		

		
		
/******选择点亮的数字******/
		
    		/***个位显视***/
		if(station_bit == 1)                
    {
        switch (a_bit)                    //时钟
        {
        case 0: LED_0_four(); break;
        case 1: LED_1_four(); break;
        case 2: LED_2_four(); break;
        case 3: LED_3_four(); break;
        case 4: LED_4_four(); break;
        case 5: LED_5_four(); break;
        case 6: LED_6_four(); break;
        case 7: LED_7_four(); break;
        case 8: LED_8_four(); break;
        case 9: LED_9_four(); break;
		    }
				
				switch (La_bit)                    //路程
        {
        case 0: LED_0_fourL(); break;
        case 1: LED_1_fourL(); break;
        case 2: LED_2_fourL(); break;
        case 3: LED_3_fourL(); break;
        case 4: LED_4_fourL(); break;
        case 5: LED_5_fourL(); break;
        case 6: LED_6_fourL(); break;
        case 7: LED_7_fourL(); break;
        case 8: LED_8_fourL(); break;
        case 9: LED_9_fourL(); break;
		    }
			}		
				
        		
    /***十位显视***/				
    else if(station_bit == 2)
		     {
             switch (ten_bit)                   //时钟
             {
                 case 0: LED_0_three(); break;
                 case 1: LED_1_three(); break;
                 case 2: LED_2_three(); break;
                 case 3: LED_3_three(); break;
                 case 4: LED_4_three(); break;
                 case 5: LED_5_three(); break;
                 case 6: LED_6_three(); break;
                 case 7: LED_7_three(); break;
                 case 8: LED_8_three(); break;
                 case 9: LED_9_three(); break;
				     }
						 
						 switch (Lten_bit)                  //路程
             {
                 case 0: LED_0_threeL(); break;
                 case 1: LED_1_threeL(); break;
                 case 2: LED_2_threeL(); break;
                 case 3: LED_3_threeL(); break;
                 case 4: LED_4_threeL(); break;
                 case 5: LED_5_threeL(); break;
                 case 6: LED_6_threeL(); break;
                 case 7: LED_7_threeL(); break;
                 case 8: LED_8_threeL(); break;
                 case 9: LED_9_threeL(); break;
				     }
					}
				 
					
    /***百位显视***/									
    else if(station_bit == 3)
		     {
             switch (hundr_bit)               //时钟
             {
                 case 0: LED_0_two(); break;
                 case 1: LED_1_two(); break;
                 case 2: LED_2_two(); break;
                 case 3: LED_3_two(); break;
                 case 4: LED_4_two(); break;
                 case 5: LED_5_two(); break;
                 case 6: LED_6_two(); break;
                 case 7: LED_7_two(); break;
                 case 8: LED_8_two(); break;
                 case 9: LED_9_two(); break;
				     }
						 
						 switch (Lhundr_bit)              //路程
             {
                 case 0: LED_0_twoL(); break;
                 case 1: LED_1_twoL(); break;
                 case 2: LED_2_twoL(); break;
                 case 3: LED_3_twoL(); break;
                 case 4: LED_4_twoL(); break;
                 case 5: LED_5_twoL(); break;
                 case 6: LED_6_twoL(); break;
                 case 7: LED_7_twoL(); break;
                 case 8: LED_8_twoL(); break;
                 case 9: LED_9_twoL(); break;
				     }
					}
				 
				
    /*****千位显示*****/													
    else if(station_bit == 4)
		     {
             switch (thoud_bit)                    //时钟
             {
                 case 0: LED_0_one(); break;
                 case 1: LED_1_one(); break;
                 case 2: LED_2_one(); break;
                 case 3: LED_3_one(); break;
                 case 4: LED_4_one(); break;
                 case 5: LED_5_one(); break;
                 case 6: LED_6_one(); break;
                 case 7: LED_7_one(); break;
                 case 8: LED_8_one(); break;
                 case 9: LED_9_one(); break;
				     }
						 
						 switch (Lthoud_bit)                        //路程
             {
                 case 0: LED_0_oneL(); break;
                 case 1: LED_1_oneL(); break;
                 case 2: LED_2_oneL(); break;
                 case 3: LED_3_oneL(); break;
                 case 4: LED_4_oneL(); break;
                 case 5: LED_5_oneL(); break;
                 case 6: LED_6_oneL(); break;
                 case 7: LED_7_oneL(); break;
                 case 8: LED_8_oneL(); break;
                 case 9: LED_9_oneL(); break;
				     }
					}
    
    station_bit++;
    if(station_bit == 5)
        station_bit = 1;
}

