
#ifndef _LDC1000_H_
#define _LDC1000_H_

#include "stm32f10x.h"


/****************寄存器地址区*******************/
#define LDC1000_CMD_REVID 		0x00
#define LDC1000_CMD_RPMAX 		0x01
#define LDC1000_CMD_RPMIN 		0x02
#define LDC1000_CMD_SENSORFREQ 	0x03
#define LDC1000_CMD_LDCCONFIG 	0x04
#define LDC1000_CMD_CLKCONFIG 	0x05
#define LDC1000_CMD_THRESHILSB 	0x06
#define LDC1000_CMD_THRESHIMSB 	0x07
#define LDC1000_CMD_THRESLOLSB 	0x08
#define LDC1000_CMD_THRESLOMSB 	0x09
#define LDC1000_CMD_INTCONFIG 	0x0A
#define LDC1000_CMD_PWRCONFIG 	0x0B
#define LDC1000_CMD_STATUS	 	0x20
#define LDC1000_CMD_PROXLSB 	0x21
#define LDC1000_CMD_PROXMSB 	0x22
#define LDC1000_CMD_FREQCTRLSB	0x23
#define LDC1000_CMD_FREQCTRMID	0x24
#define LDC1000_CMD_FREQCTRMSB	0x25

// LDC BITMASKS
#define LDC1000_BIT_AMPLITUDE    0x18
#define LDC1000_BIT_RESPTIME     0x07
#define LDC1000_BIT_CLKSEL       0x02
#define LDC1000_BIT_CLKPD        0x01
#define LDC1000_BIT_INTMODE      0x07
#define LDC1000_BIT_PWRMODE      0x01
#define LDC1000_BIT_STATUSOSC    0x80
#define LDC1000_BIT_STATUSDRDYB  0x40
#define LDC1000_BIT_STATUSWAKEUP 0x20
#define LDC1000_BIT_STATUSCOMP   0x10

#define TEST_RPMAX_MAX 	0x13			  /**< maximum calibration value for RPMAX */
#define TEST_RPMAX_MIN 	0x10			  /**< minimum calibration value for RPMAX */
#define TEST_RPMAX_INIT TEST_RPMAX_MIN+1  /**< RPMAX initial value */
#define TEST_RPMIN_MAX 	0x3D   			  /**< maximum calibration value for RPMIN */
#define TEST_RPMIN_MIN 	0x3A    		  /**< minimum calibration value for RPMIN */
#define TEST_RPMIN_INIT TEST_RPMIN_MIN+1  /**< RPMIN initial value */
// Final Test Range
#define TEST_RP_MSB_MAX 0x12	/**< maximum value for proximity data */
#define TEST_RP_MSB_MIN 0x0A	/**< minimum value for proximity data */
#define TEST_FC_MAX 0x0D5D		/**< maximum value for frequency counter */
#define TEST_FC_MIN 0x0D39		/**< minimum value for frequency counter */


/****************宏定义区*******************/
#define LDC_CSN_HIGH()     GPIO_SetBits(GPIO_LDC, GPIO_LDC_CSN_Pin)
#define LDC_CSN_LOW()      GPIO_ResetBits(GPIO_LDC, GPIO_LDC_CSN_Pin)		 //csn置低
#define LDC_Read_IRQ()		GPIO_ReadInputDataBit (GPIO_LDC, GPIO_LDC_IQ_Pin) //中断引脚



#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//IO口地址映射
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C 
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C 
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C 
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C    

#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808 
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08 
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08 
 


//IO口操作,只对单一的IO口!
//确保n的值小于16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //输出 
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //输入 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //输出 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //输入

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //输出 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //输入


#define MISO  PBin(0)
#define MOSI  PBout(1)
#define CSN   PEout(7)
#define SCK   PEout(8)
/****************函数声明区*******************/




int ldc_read_avr(void);
void LDC_Init(void);
unsigned char SPI_RW(unsigned char rwdata);
unsigned char Singal_SPI_Read(unsigned char reg);
void Singal_SPI_Write(unsigned char reg,unsigned char wdata);
void SPI_Read_Buf(unsigned char reg, unsigned char *pBuf, unsigned char len);
void LDC_GPIO_Configuration(void);

extern long int LDC_val ;



#endif


