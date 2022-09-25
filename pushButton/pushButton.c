/*
 * pushButton.c
 *
 * Created: 29/08/2022 08:18:08 م
 *  Author: user
 */ 
#include "pushButton.h"
void PB_init(uint8_t buttonPort , uint8_t buttonPin)
{
	DIO_init(buttonPort , buttonPin , INPUT);
}
void PB_read(uint8_t buttonPort  , uint8_t buttonPin , uint8_t* value)
{
	DIO_read(buttonPort , buttonPin , value);
}