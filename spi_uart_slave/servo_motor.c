/*
 * servo_motor.c
 *
 * Created: 1/14/2021 02:11:24 ص
 *  Author: REHAM
 */ 
#include "servo_motor.h"
#include <avr/io.h>

void Servo_Init(void){
	TCCR1A=(1<<COM1A1)|(1<<WGM11);
	TCCR1B=(1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
	ICR1=4999;
	
	
}
void servo_angle(long angle){
	OCR1A= (long)(((MAX_count - MIN_count)*(angle - MIN_angle))/(MAX_angle - MIN_angle))+MIN_count -1;
	
}