/*
 * MOTOR.c
 *
 * Created: 23/09/2022 12:04:08 ص
 *  Author: user
 */ 
#include "MOTOR.h"

void MOTOR_Init()
{
	PWM_OC1A_FM_init();	
}
void MOTOR_Speed(uint8_t speed)
{
	PWM_OC1A_FM_setDuty(speed);
}