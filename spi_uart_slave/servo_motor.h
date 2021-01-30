/*
 * servo_motor.h
 *
 * Created: 1/14/2021 02:11:52 ص
 *  Author: REHAM
 */ 


#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#define MAX_angle 180
#define MIN_angle 0
#define MAX_count 500
#define MIN_count 250

void Servo_Init(void); // Timer1
void servo_angle(long angle);




#endif /* SERVO_MOTOR_H_ */