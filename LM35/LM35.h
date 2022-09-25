/*
 * LM35.h
 *
 * Created: 23/09/2022 12:03:24 ص
 *  Author: user
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "../../MCAL/ADC/ADC.h"
void LM35_Init();
uint8_t LM35_Read(uint8_t pinNumber);


#endif /* LM35_H_ */