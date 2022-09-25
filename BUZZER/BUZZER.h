/*
 * MOTOR.h
 *
 * Created: 23/09/2022 12:04:49 ص
 *  Author: user
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "../../MCAL/DIO/DIO.h"

void BUZZER_Init(uint8_t PORT , uint8_t pinNumber);
void BUZZER_on(uint8_t PORT , uint8_t pinNumber);
void BUZZER_off(uint8_t PORT , uint8_t pinNumber);


#endif /* MOTOR_H_ */