/*
 * led.h
 *
 * Created: 29/08/2022 06:59:33 م
 *  Author: user
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"

void LED_init(uint8_t ledPort , uint8_t ledPin);
void LED_on(uint8_t ledPort , uint8_t ledPin);
void LED_off(uint8_t ledPort , uint8_t ledPin);
void LED_toggle(uint8_t ledPort , uint8_t ledPin);


#endif /* LED_H_ */