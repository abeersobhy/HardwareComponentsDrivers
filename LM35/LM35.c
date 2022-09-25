/*
 * LM35.c
 *
 * Created: 23/09/2022 12:02:51 ص
 *  Author: user
 */ 
#include "LM35.h"
void LM35_Init()
{
	ADC_init();
}
uint8_t LM35_Read(uint8_t pinNumber)
{
	return ADC_read(pinNumber);
}