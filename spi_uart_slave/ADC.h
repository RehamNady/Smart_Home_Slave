﻿/*
 * ADC.h
 *
 * Created: 12/19/2020 06:14:27 م
 *  Author: REHAM
 */ 


#ifndef ADC_H_
#define ADC_H_


#include <avr/io.h>

void ADC_Init();


unsigned short ADC_Read(unsigned char channel); 




#endif /* ADC_H_ */