/*
 * pushButton.h
 *
 * Created: 29/08/2022 08:18:38 م
 *  Author: user
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
#include "../../MCAL/DIO/DIO.h"

void PB_init(uint8_t buttonPort , uint8_t buttonPin);
void PB_read(uint8_t buttonPort  , uint8_t buttonPin , uint8_t* value);

#endif /* PUSHBUTTON_H_ */