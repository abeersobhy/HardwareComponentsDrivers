/*
 * BUZZER.c
 *
 * Created: 23/09/2022 12:05:07 ص
 *  Author: user
 */ 
#include "BUZZER.h"

void BUZZER_Init(uint8_t PORT , uint8_t pinNumber)
{
	DIO_init(PORT , pinNumber , OUTPUT);	
}
void BUZZER_on(uint8_t PORT , uint8_t pinNumber)
{
	DIO_write(PORT , pinNumber , HIGH);
}
void BUZZER_off(uint8_t PORT , uint8_t pinNumber)
{
	DIO_write(PORT , pinNumber , LOW);
}