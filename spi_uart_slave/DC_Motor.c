/*
 * DC_Motor.c
 *
 * Created: 1/13/2021 11:40:33 م
 *  Author: REHAM
 */ 
#include "DC_motor.h"
#include <avr/io.h>

void DCmotor_Init(unsigned short ocr){
	
	TCCR2=(1<<WGM20)|(1<<WGM21)|(1<<COM21)|(1<<CS22)|(1<<COM20);
	OCR2 =ocr;
	TIFR=(1<<OCF2);
}