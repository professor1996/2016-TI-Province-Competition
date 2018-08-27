#include "LDC1000.h"

unsigned char RPMAX =0x05; 
unsigned char RPMIN =0x39;
unsigned char RFREQ =0xD1;

unsigned char orgVal[12]={0};
unsigned int rpi_max = 2;
unsigned char proximtyData[2]={0};
unsigned long proximtyDataTEMP=0,proximtyDataMAX,proximtyDataMIN,proximtyDataSUM,proximtyDataAVE,proximtyDataAVE_LAS;

long int LDC_val=1;

void LDC_GPIO_Configuration(void)
{
	  GPIO_InitTypeDef GPIO_InitStructure;
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO, ENABLE);	 		   

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOE, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	    
}

void delay_us(int ms)//为防止time_delay_ms();与lpt冲突编写的延时
{
  int j1,k_1;int i1;
  i1=ms;
  for(j1=0;j1<i1;j1++)   
    for(k_1=0;k_1<8;k_1++);
}

void LDC_Init(void)
{
      while(orgVal[1]!=RPMAX||orgVal[2]!=RPMIN||orgVal[3]!=RFREQ)//一旦在此循环说明初始化不成功
      {  
          
		 CSN=1;
         SCK=0;
         MOSI=1;   
         delay_us(30);
         Singal_SPI_Write(LDC1000_CMD_RPMAX, RPMAX);
         Singal_SPI_Write(LDC1000_CMD_RPMIN, RPMIN);//0x14
         Singal_SPI_Write(LDC1000_CMD_SENSORFREQ,  RFREQ);  //谐振频率计算方法见《浮点科技电轨传感器调试手册》
         Singal_SPI_Write(LDC1000_CMD_LDCCONFIG,   0x17);  /********/
         Singal_SPI_Write(LDC1000_CMD_CLKCONFIG,   0x00);  //L配置LDC1000的输出速率 0x00
         Singal_SPI_Write(LDC1000_CMD_THRESHILSB,  0x50);  /********/
      	 Singal_SPI_Write(LDC1000_CMD_THRESHIMSB,  0x14);
      	 Singal_SPI_Write(LDC1000_CMD_THRESLOLSB,  0xC0);
      	 Singal_SPI_Write(LDC1000_CMD_THRESLOMSB,  0x12);
         Singal_SPI_Write(LDC1000_CMD_INTCONFIG,   0x02);
         Singal_SPI_Write(LDC1000_CMD_PWRCONFIG,   0x01);
         SPI_Read_Buf(LDC1000_CMD_REVID,&orgVal[0],12);//orgVal[]对应上面写入的值说明初始化正常
       
      }
} 



int ldc_read_avr(void)
{

    char rpi=0;  //取rpi次平均值    
    for (rpi=0;rpi<rpi_max;rpi++)
    {

      SPI_Read_Buf(LDC1000_CMD_PROXLSB,&proximtyData[0],2);  
      proximtyDataTEMP = ((unsigned char)proximtyData[1]<<8) + proximtyData [0]; 
      proximtyDataSUM += proximtyDataTEMP;
      if (proximtyDataTEMP < proximtyDataMIN)   //在100个proximtyDataTEMP中取最大，最小
        proximtyDataMIN = proximtyDataTEMP;
      if (proximtyDataTEMP > proximtyDataMAX)
        proximtyDataMAX = proximtyDataTEMP;
    }
     proximtyDataAVE = proximtyDataSUM /rpi_max;
     proximtyDataSUM=0;
     proximtyDataAVE_LAS=proximtyDataAVE;
  
    return   proximtyDataAVE; 

}


 
unsigned char SPI_RW(unsigned char rwdata)
{  
    
    	unsigned char spi_rw_i=0;	
        unsigned char temp=0;
     for(spi_rw_i=0;spi_rw_i<8;spi_rw_i++)   	// output 8-bit
   	 {
   	        
	    if(rwdata & 0x80)
              MOSI=1;
   		else 
              MOSI=0;

   		rwdata<<=1;           		// shift next bit to MSB
        temp<<=1;
		SCK=1;             //Set SCK high    Rising up 
               
   		if(MISO) 
           temp|=1;
   		SCK=0;            //set  SCK low     Falling down
                
   	}
    return(temp);           		  		// return read byte
    
 
}

unsigned char Singal_SPI_Read(unsigned char reg)
{
	unsigned char rdata;
	
	CSN=0;                        // CSN low, initialize SPI communication...
       
        delay_us(2);
         
         reg=reg|0x80;         //read com
	SPI_RW(reg);            // Select register to read from..
         
         
	rdata = SPI_RW(0);    // then read registervalue
       
        delay_us(170);
	CSN=1;                 // CSN high, terminate SPI communication
	
	return rdata;         // return register value
}

void Singal_SPI_Write(unsigned char reg,unsigned char wdata)
{
	
	CSN=0;                // CSN low, initialize SPI communication...
      
        delay_us(2);//2us
        reg=reg&~0x80;
	SPI_RW(reg);            // Select register to read from..
         
        
	SPI_RW(wdata);    // ..then read registervalue
        delay_us(170);//875us
	CSN=1;              // CSN high, terminate SPI communication
       
	
}


void SPI_Read_Buf(unsigned char reg, unsigned char *pBuf, unsigned char len)
{
	unsigned char spi_rw_i;
	
	CSN=0;                   		// Set CSN low, init SPI tranaction
       
        reg=reg|0x80;                            //read
	SPI_RW(reg);       		// Select register to write to and read status unsigned char
	
	for(spi_rw_i=0;spi_rw_i<len;spi_rw_i++)
    {  
	  pBuf[spi_rw_i] = SPI_RW(0);    
	}

	CSN=1;     
       

}

