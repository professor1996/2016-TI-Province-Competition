#ifndef __output_
#define __output_


#include "stm32f10x.h"
#include "FlashSpeed.h"
///**********电子时钟**********/

/****将引脚与IO口对应****/
#define UP_1() do{GPIO_SetBits(GPIOC, GPIO_Pin_15);}while(0);
#define DOWN_1() do{GPIO_ResetBits(GPIOC, GPIO_Pin_15);}while(0);
#define UP_2() do{GPIO_SetBits(GPIOC, GPIO_Pin_13);}while(0);
#define DOWN_2() do{GPIO_ResetBits(GPIOC, GPIO_Pin_13);}while(0);
#define UP_3() do{GPIO_SetBits(GPIOE, GPIO_Pin_5);}while(0);
#define DOWN_3() do{GPIO_ResetBits(GPIOE, GPIO_Pin_5);}while(0);
#define UP_4() do{GPIO_SetBits(GPIOE, GPIO_Pin_9);}while(0);
#define DOWN_4() do{GPIO_ResetBits(GPIOE, GPIO_Pin_9);}while(0);
#define UP_5() do{GPIO_SetBits(GPIOE, GPIO_Pin_11);}while(0);
#define DOWN_5() do{GPIO_ResetBits(GPIOE, GPIO_Pin_11);}while(0);
#define UP_6() do{GPIO_SetBits(GPIOE, GPIO_Pin_13);}while(0);
#define DOWN_6() do{GPIO_ResetBits(GPIOE, GPIO_Pin_13);}while(0);
#define UP_7() do{GPIO_SetBits(GPIOE, GPIO_Pin_10);}while(0);
#define DOWN_7() do{GPIO_ResetBits(GPIOE, GPIO_Pin_10);}while(0);
#define UP_8() do{GPIO_SetBits(GPIOE, GPIO_Pin_12);}while(0);
#define DOWN_8() do{GPIO_ResetBits(GPIOE, GPIO_Pin_12);}while(0);
#define UP_9() do{GPIO_SetBits(GPIOE, GPIO_Pin_14);}while(0);
#define DOWN_9() do{GPIO_ResetBits(GPIOE, GPIO_Pin_14);}while(0);
#define UP_10() do{GPIO_SetBits(GPIOC, GPIO_Pin_14);}while(0);
#define DOWN_10() do{GPIO_ResetBits(GPIOC, GPIO_Pin_14);}while(0);
#define UP_11() do{GPIO_SetBits(GPIOE, GPIO_Pin_6);}while(0);
#define DOWN_11() do{GPIO_ResetBits(GPIOE, GPIO_Pin_6);}while(0);
#define UP_12() do{GPIO_SetBits(GPIOE, GPIO_Pin_4);}while(0);
#define DOWN_12() do{GPIO_ResetBits(GPIOE, GPIO_Pin_4);}while(0);


/****将数字与引脚对应****/
/****第一位****/
#define LED_0_one() do{DOWN_1();DOWN_2();UP_3();DOWN_4();UP_5();DOWN_6();DOWN_7();DOWN_8();DOWN_9();DOWN_10();DOWN_11();UP_12();}while(0);
#define LED_1_one() do{UP_1();UP_2();UP_3();DOWN_4();UP_5();DOWN_6();DOWN_7();DOWN_8();DOWN_9();UP_10();UP_11();UP_12();}while(0);
#define LED_2_one() do{DOWN_1();DOWN_2();UP_3();UP_4();DOWN_5();DOWN_6();DOWN_7();DOWN_8();DOWN_9();UP_10();DOWN_11();UP_12();}while(0);
#define LED_3_one() do{UP_1();DOWN_2();UP_3();DOWN_4();DOWN_5();DOWN_6();DOWN_7();DOWN_8();DOWN_9();UP_10();DOWN_11();UP_12();}while(0);
#define LED_4_one() do{UP_1();UP_2();UP_3();DOWN_4();DOWN_5();DOWN_6();DOWN_7();DOWN_8();DOWN_9();DOWN_10();UP_11();UP_12();}while(0);
#define LED_5_one() do{UP_1();DOWN_2();UP_3();DOWN_4();DOWN_5();DOWN_6();UP_7();DOWN_8();DOWN_9();DOWN_10();DOWN_11();UP_12();}while(0);
#define LED_6_one() do{DOWN_1();DOWN_2();UP_3();DOWN_4();DOWN_5();DOWN_6();UP_7();DOWN_8();DOWN_9();DOWN_10();DOWN_11();UP_12();}while(0);
#define LED_7_one() do{UP_1();UP_2();UP_3();DOWN_4();UP_5();DOWN_6();DOWN_7();DOWN_8();DOWN_9();UP_10();DOWN_11();UP_12();}while(0);
#define LED_8_one() do{DOWN_1();DOWN_2();UP_3();DOWN_4();DOWN_5();DOWN_6();DOWN_7();DOWN_8();DOWN_9();DOWN_10();DOWN_11();UP_12();}while(0);
#define LED_9_one() do{UP_1();DOWN_2();UP_3();DOWN_4();DOWN_5();DOWN_6();DOWN_7();DOWN_8();DOWN_9();DOWN_10();DOWN_11();UP_12();}while(0);

/****第二位****/
#define LED_0_two() do{DOWN_1();DOWN_2();DOWN_3();DOWN_4();UP_5();DOWN_6();DOWN_7();DOWN_8();UP_9();DOWN_10();DOWN_11();DOWN_12();}while(0);
#define LED_1_two() do{UP_1();UP_2();DOWN_3();DOWN_4();UP_5();DOWN_6();DOWN_7();DOWN_8();UP_9();UP_10();UP_11();DOWN_12();}while(0);
#define LED_2_two() do{DOWN_1();DOWN_2();DOWN_3();UP_4();DOWN_5();DOWN_6();DOWN_7();DOWN_8();UP_9();UP_10();DOWN_11();DOWN_12();}while(0);
#define LED_3_two() do{UP_1();DOWN_2();DOWN_3();DOWN_4();DOWN_5();DOWN_6();DOWN_7();DOWN_8();UP_9();UP_10();DOWN_11();DOWN_12();}while(0);
#define LED_4_two() do{UP_1();UP_2();DOWN_3();DOWN_4();DOWN_5();DOWN_6();DOWN_7();DOWN_8();UP_9();DOWN_10();UP_11();DOWN_12();}while(0);
#define LED_5_two() do{UP_1();DOWN_2();DOWN_3();DOWN_4();DOWN_5();DOWN_6();UP_7();DOWN_8();UP_9();DOWN_10();DOWN_11();DOWN_12();}while(0);
#define LED_6_two() do{DOWN_1();DOWN_2();DOWN_3();DOWN_4();DOWN_5();DOWN_6();UP_7();DOWN_8();UP_9();DOWN_10();DOWN_11();DOWN_12();}while(0);
#define LED_7_two() do{UP_1();UP_2();DOWN_3();DOWN_4();UP_5();DOWN_6();DOWN_7();DOWN_8();UP_9();UP_10();DOWN_11();DOWN_12();}while(0);
#define LED_8_two() do{DOWN_1();DOWN_2();DOWN_3();DOWN_4();DOWN_5();DOWN_6();DOWN_7();DOWN_8();UP_9();DOWN_10();DOWN_11();DOWN_12();}while(0);
#define LED_9_two() do{UP_1();DOWN_2();DOWN_3();DOWN_4();DOWN_5();DOWN_6();DOWN_7();DOWN_8();UP_9();DOWN_10();DOWN_11();DOWN_12();}while(0);

/****第三位****/
#define LED_0_three() do{DOWN_1();DOWN_2();UP_3();DOWN_4();UP_5();DOWN_6();DOWN_7();UP_8();DOWN_9();DOWN_10();DOWN_11();DOWN_12();}while(0);
#define LED_1_three() do{UP_1();UP_2();UP_3();DOWN_4();UP_5();DOWN_6();DOWN_7();UP_8();DOWN_9();UP_10();UP_11();DOWN_12();}while(0);
#define LED_2_three() do{DOWN_1();DOWN_2();UP_3();UP_4();DOWN_5();DOWN_6();DOWN_7();UP_8();DOWN_9();UP_10();DOWN_11();DOWN_12();}while(0);
#define LED_3_three() do{UP_1();DOWN_2();UP_3();DOWN_4();DOWN_5();DOWN_6();DOWN_7();UP_8();DOWN_9();UP_10();DOWN_11();DOWN_12();}while(0);
#define LED_4_three() do{UP_1();UP_2();UP_3();DOWN_4();DOWN_5();DOWN_6();DOWN_7();UP_8();DOWN_9();DOWN_10();UP_11();DOWN_12();}while(0);
#define LED_5_three() do{UP_1();DOWN_2();UP_3();DOWN_4();DOWN_5();DOWN_6();UP_7();UP_8();DOWN_9();DOWN_10();DOWN_11();DOWN_12();}while(0);
#define LED_6_three() do{DOWN_1();DOWN_2();UP_3();DOWN_4();DOWN_5();DOWN_6();UP_7();UP_8();DOWN_9();DOWN_10();DOWN_11();DOWN_12();}while(0);
#define LED_7_three() do{UP_1();UP_2();UP_3();DOWN_4();UP_5();DOWN_6();DOWN_7();UP_8();DOWN_9();UP_10();DOWN_11();DOWN_12();}while(0);
#define LED_8_three() do{DOWN_1();DOWN_2();UP_3();DOWN_4();DOWN_5();DOWN_6();DOWN_7();UP_8();DOWN_9();DOWN_10();DOWN_11();DOWN_12();}while(0);
#define LED_9_three() do{UP_1();DOWN_2();UP_3();DOWN_4();DOWN_5();DOWN_6();DOWN_7();UP_8();DOWN_9();DOWN_10();DOWN_11();DOWN_12();}while(0);

/****第四位****/
#define LED_0_four() do{DOWN_1();DOWN_2();UP_3();DOWN_4();UP_5();UP_6();DOWN_7();DOWN_8();DOWN_9();DOWN_10();DOWN_11();DOWN_12();}while(0);
#define LED_1_four() do{UP_1();UP_2();UP_3();DOWN_4();UP_5();UP_6();DOWN_7();DOWN_8();DOWN_9();UP_10();UP_11();DOWN_12();}while(0);
#define LED_2_four() do{DOWN_1();DOWN_2();UP_3();UP_4();DOWN_5();UP_6();DOWN_7();DOWN_8();DOWN_9();UP_10();DOWN_11();DOWN_12();}while(0);
#define LED_3_four() do{UP_1();DOWN_2();UP_3();DOWN_4();DOWN_5();UP_6();DOWN_7();DOWN_8();DOWN_9();UP_10();DOWN_11();DOWN_12();}while(0);
#define LED_4_four() do{UP_1();UP_2();UP_3();DOWN_4();DOWN_5();UP_6();DOWN_7();DOWN_8();DOWN_9();DOWN_10();UP_11();DOWN_12();}while(0);
#define LED_5_four() do{UP_1();DOWN_2();UP_3();DOWN_4();DOWN_5();UP_6();UP_7();DOWN_8();DOWN_9();DOWN_10();DOWN_11();DOWN_12();}while(0);
#define LED_6_four() do{DOWN_1();DOWN_2();UP_3();DOWN_4();DOWN_5();UP_6();UP_7();DOWN_8();DOWN_9();DOWN_10();DOWN_11();DOWN_12();}while(0);
#define LED_7_four() do{UP_1();UP_2();UP_3();DOWN_4();UP_5();UP_6();DOWN_7();DOWN_8();DOWN_9();UP_10();DOWN_11();DOWN_12();}while(0);
#define LED_8_four() do{DOWN_1();DOWN_2();UP_3();DOWN_4();DOWN_5();UP_6();DOWN_7();DOWN_8();DOWN_9();DOWN_10();DOWN_11();DOWN_12();}while(0);
#define LED_9_four() do{UP_1();DOWN_2();UP_3();DOWN_4();DOWN_5();UP_6();DOWN_7();DOWN_8();DOWN_9();DOWN_10();DOWN_11();DOWN_12();}while(0);







/**********路程显示**********/
/****将引脚与IO口对应****/
#define LUP_1() do{GPIO_SetBits(GPIOD, GPIO_Pin_0);}while(0);
#define LDOWN_1() do{GPIO_ResetBits(GPIOD, GPIO_Pin_0);}while(0);
#define LUP_2() do{GPIO_SetBits(GPIOD, GPIO_Pin_1);}while(0);
#define LDOWN_2() do{GPIO_ResetBits(GPIOD, GPIO_Pin_1);}while(0);
#define LUP_3() do{GPIO_SetBits(GPIOD, GPIO_Pin_5);}while(0);
#define LDOWN_3() do{GPIO_ResetBits(GPIOD, GPIO_Pin_5);}while(0);
#define LUP_4() do{GPIO_SetBits(GPIOD, GPIO_Pin_7);}while(0);
#define LDOWN_4() do{GPIO_ResetBits(GPIOD, GPIO_Pin_7);}while(0);
#define LUP_5() do{GPIO_SetBits(GPIOE, GPIO_Pin_0);}while(0);
#define LDOWN_5() do{GPIO_ResetBits(GPIOE, GPIO_Pin_0);}while(0);
#define LUP_6() do{GPIO_SetBits(GPIOB, GPIO_Pin_4);}while(0);
#define LDOWN_6() do{GPIO_ResetBits(GPIOB, GPIO_Pin_4);}while(0);
#define LUP_7() do{GPIO_SetBits(GPIOB, GPIO_Pin_3);}while(0);
#define LDOWN_7() do{GPIO_ResetBits(GPIOB, GPIO_Pin_3);}while(0);
#define LUP_8() do{GPIO_SetBits(GPIOE, GPIO_Pin_1);}while(0);
#define LDOWN_8() do{GPIO_ResetBits(GPIOE, GPIO_Pin_1);}while(0);
#define LUP_9() do{GPIO_SetBits(GPIOB, GPIO_Pin_5);}while(0);
#define LDOWN_9() do{GPIO_ResetBits(GPIOB, GPIO_Pin_5);}while(0);
#define LUP_10() do{GPIO_SetBits(GPIOD, GPIO_Pin_2);}while(0);
#define LDOWN_10() do{GPIO_ResetBits(GPIOD, GPIO_Pin_2);}while(0);
#define LUP_11() do{GPIO_SetBits(GPIOD, GPIO_Pin_3);}while(0);
#define LDOWN_11() do{GPIO_ResetBits(GPIOD, GPIO_Pin_3);}while(0);
#define LUP_12() do{GPIO_SetBits(GPIOD, GPIO_Pin_6);}while(0);
#define LDOWN_12() do{GPIO_ResetBits(GPIOD, GPIO_Pin_6);}while(0);


/****将数字与引脚对应****/
/****第一位****/
#define LED_0_oneL() do{LDOWN_1();LDOWN_2();LUP_3();LDOWN_4();LUP_5();LDOWN_6();LDOWN_7();LDOWN_8();LDOWN_9();LDOWN_10();LDOWN_11();LUP_12();}while(0);
#define LED_1_oneL() do{LUP_1();LUP_2();LUP_3();LDOWN_4();LUP_5();LDOWN_6();LDOWN_7();LDOWN_8();LDOWN_9();LUP_10();LUP_11();LUP_12();}while(0);
#define LED_2_oneL() do{LDOWN_1();LDOWN_2();LUP_3();LUP_4();LDOWN_5();LDOWN_6();LDOWN_7();LDOWN_8();LDOWN_9();LUP_10();LDOWN_11();LUP_12();}while(0);
#define LED_3_oneL() do{LUP_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LDOWN_6();LDOWN_7();LDOWN_8();LDOWN_9();LUP_10();LDOWN_11();LUP_12();}while(0);
#define LED_4_oneL() do{LUP_1();LUP_2();LUP_3();LDOWN_4();LDOWN_5();LDOWN_6();LDOWN_7();LDOWN_8();LDOWN_9();LDOWN_10();LUP_11();LUP_12();}while(0);
#define LED_5_oneL() do{LUP_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LDOWN_6();LUP_7();LDOWN_8();LDOWN_9();LDOWN_10();LDOWN_11();LUP_12();}while(0);
#define LED_6_oneL() do{LDOWN_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LDOWN_6();LUP_7();LDOWN_8();LDOWN_9();LDOWN_10();LDOWN_11();LUP_12();}while(0);
#define LED_7_oneL() do{LUP_1();LUP_2();LUP_3();LDOWN_4();LUP_5();LDOWN_6();LDOWN_7();LDOWN_8();LDOWN_9();LUP_10();LDOWN_11();LUP_12();}while(0);
#define LED_8_oneL() do{LDOWN_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LDOWN_6();LDOWN_7();LDOWN_8();LDOWN_9();LDOWN_10();LDOWN_11();LUP_12();}while(0);
#define LED_9_oneL() do{LUP_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LDOWN_6();LDOWN_7();LDOWN_8();LDOWN_9();LDOWN_10();LDOWN_11();LUP_12();}while(0);

/****第二位****/
#define LED_0_twoL() do{LDOWN_1();LDOWN_2();LDOWN_3();LDOWN_4();LUP_5();LDOWN_6();LDOWN_7();LDOWN_8();LUP_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_1_twoL() do{LUP_1();LUP_2();LDOWN_3();LDOWN_4();LUP_5();LDOWN_6();LDOWN_7();LDOWN_8();LUP_9();LUP_10();LUP_11();LDOWN_12();}while(0);
#define LED_2_twoL() do{LDOWN_1();LDOWN_2();LDOWN_3();LUP_4();LDOWN_5();LDOWN_6();LDOWN_7();LDOWN_8();LUP_9();LUP_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_3_twoL() do{LUP_1();LDOWN_2();LDOWN_3();LDOWN_4();LDOWN_5();LDOWN_6();LDOWN_7();LDOWN_8();LUP_9();LUP_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_4_twoL() do{LUP_1();LUP_2();LDOWN_3();LDOWN_4();LDOWN_5();LDOWN_6();LDOWN_7();LDOWN_8();LUP_9();LDOWN_10();LUP_11();LDOWN_12();}while(0);
#define LED_5_twoL() do{LUP_1();LDOWN_2();LDOWN_3();LDOWN_4();LDOWN_5();LDOWN_6();LUP_7();LDOWN_8();LUP_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_6_twoL() do{LDOWN_1();LDOWN_2();LDOWN_3();LDOWN_4();LDOWN_5();LDOWN_6();LUP_7();LDOWN_8();LUP_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_7_twoL() do{LUP_1();LUP_2();LDOWN_3();LDOWN_4();LUP_5();LDOWN_6();LDOWN_7();LDOWN_8();LUP_9();LUP_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_8_twoL() do{LDOWN_1();LDOWN_2();LDOWN_3();LDOWN_4();LDOWN_5();LDOWN_6();LDOWN_7();LDOWN_8();LUP_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_9_twoL() do{LUP_1();LDOWN_2();LDOWN_3();LDOWN_4();LDOWN_5();LDOWN_6();LDOWN_7();LDOWN_8();LUP_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);

/****第三位****/
#define LED_0_threeL() do{LDOWN_1();LDOWN_2();LUP_3();LDOWN_4();LUP_5();LDOWN_6();LDOWN_7();LUP_8();LDOWN_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_1_threeL() do{LUP_1();LUP_2();LUP_3();LDOWN_4();LUP_5();LDOWN_6();LDOWN_7();LUP_8();LDOWN_9();LUP_10();LUP_11();LDOWN_12();}while(0);
#define LED_2_threeL() do{LDOWN_1();LDOWN_2();LUP_3();LUP_4();LDOWN_5();LDOWN_6();LDOWN_7();LUP_8();LDOWN_9();LUP_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_3_threeL() do{LUP_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LDOWN_6();LDOWN_7();LUP_8();LDOWN_9();LUP_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_4_threeL() do{LUP_1();LUP_2();LUP_3();LDOWN_4();LDOWN_5();LDOWN_6();LDOWN_7();LUP_8();LDOWN_9();LDOWN_10();LUP_11();LDOWN_12();}while(0);
#define LED_5_threeL() do{LUP_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LDOWN_6();LUP_7();LUP_8();LDOWN_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_6_threeL() do{LDOWN_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LDOWN_6();LUP_7();LUP_8();LDOWN_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_7_threeL() do{LUP_1();LUP_2();LUP_3();LDOWN_4();LUP_5();LDOWN_6();LDOWN_7();LUP_8();LDOWN_9();LUP_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_8_threeL() do{LDOWN_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LDOWN_6();LDOWN_7();LUP_8();LDOWN_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_9_threeL() do{LUP_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LDOWN_6();LDOWN_7();LUP_8();LDOWN_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);


/****第四位****/
#define LED_0_fourL() do{LDOWN_1();LDOWN_2();LUP_3();LDOWN_4();LUP_5();LUP_6();LDOWN_7();LDOWN_8();LDOWN_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_1_fourL() do{LUP_1();LUP_2();LUP_3();LDOWN_4();LUP_5();LUP_6();LDOWN_7();LDOWN_8();LDOWN_9();LUP_10();LUP_11();LDOWN_12();}while(0);
#define LED_2_fourL() do{LDOWN_1();LDOWN_2();LUP_3();LUP_4();LDOWN_5();LUP_6();LDOWN_7();LDOWN_8();LDOWN_9();LUP_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_3_fourL() do{LUP_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LUP_6();LDOWN_7();LDOWN_8();LDOWN_9();LUP_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_4_fourL() do{LUP_1();LUP_2();LUP_3();LDOWN_4();LDOWN_5();LUP_6();LDOWN_7();LDOWN_8();LDOWN_9();LDOWN_10();LUP_11();LDOWN_12();}while(0);
#define LED_5_fourL() do{LUP_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LUP_6();LUP_7();LDOWN_8();LDOWN_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_6_fourL() do{LDOWN_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LUP_6();LUP_7();LDOWN_8();LDOWN_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_7_fourL() do{LUP_1();LUP_2();LUP_3();LDOWN_4();LUP_5();LUP_6();LDOWN_7();LDOWN_8();LDOWN_9();LUP_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_8_fourL() do{LDOWN_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LUP_6();LDOWN_7();LDOWN_8();LDOWN_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);
#define LED_9_fourL() do{LUP_1();LDOWN_2();LUP_3();LDOWN_4();LDOWN_5();LUP_6();LDOWN_7();LDOWN_8();LDOWN_9();LDOWN_10();LDOWN_11();LDOWN_12();}while(0);



void output(void);

#endif
