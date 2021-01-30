/*
 * SPI_SLAVE.c
 *
 * Created: 1/8/2021 06:04:35 م
 * Author : REHAM
 */ 

#include "SPI.h"
#include "ADC.h"
#include "DC_motor.h"
#include "servo_motor.h"
#include "LCD.h"

#include <stdlib.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    
   DIO_Init();
   LCD_Init();
   ADC_Init();
   Servo_Init();
   DCmotor_Init(OCR2);
   
   SPI_InitType InitData ={Slave,MSB};
   SPI_Init(&InitData);
   
   Uint8 data_recv=0;
   Uint8 data_DC=0;
   Uint8 data_Servo=0;
   
   int temp;
   char string [50];
   
    while (1) 
    {
		_delay_ms(350);
		LCD_Clear();
		temp=ADC_Read(DIO_ChannelA1);
		temp=temp/4;
		itoa(temp,string,10);
		LCD_SendString(string);
		data_recv=SPI_TXRX(temp);
		if (data_recv=='W'){
			OCR2=10;
			DIO_WriteChannel(DIO_ChannelC4,STD_High);
			DIO_WriteChannel(DIO_ChannelC3,STD_Low);
			servo_angle(180);
			
		}
		
		else{
			if(data_DC!='2') {
				 OCR2=0XFF;
				 DIO_WriteChannel(DIO_ChannelC3,STD_Low);
				 DIO_WriteChannel(DIO_ChannelC4,STD_Low);
				 }
			if(data_Servo !='4'){
			servo_angle(0);
			OCR1A=0;}
			
			
		}
		if((data_recv=='2')||(data_recv=='3')){
			data_DC=data_recv;
		}
		if((data_recv=='4')||(data_recv=='5')){
			data_Servo=data_recv;
		}
		
		if (data_recv=='1'){
			
			DIO_WriteChannel(DIO_ChannelC0,STD_High);
			
		}
		else if (data_recv=='0'){
			
			DIO_WriteChannel(DIO_ChannelC0,STD_Low);
			
		}
		 if (data_DC=='2'){
			OCR2=10;
			DIO_WriteChannel(DIO_ChannelC4,STD_High);
			DIO_WriteChannel(DIO_ChannelC3,STD_Low);
		}
		else if((data_DC=='3')&&(data_recv!='W')){
			 OCR2=0XFF;
			 DIO_WriteChannel(DIO_ChannelC3,STD_Low);
			 DIO_WriteChannel(DIO_ChannelC4,STD_Low);
		
		}
		if (data_Servo=='4'){
			servo_angle(180);
			
		}
		 
		else if((data_Servo=='5')&&(data_recv!='W')){
			servo_angle(0);
			OCR1A=0;
			
		}
		
	
		
    
}
}
