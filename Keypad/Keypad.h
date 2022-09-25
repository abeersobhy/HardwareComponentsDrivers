/*
 * Keypad.h
 *  Author: Abeer Sobhy
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
/*
-------------------------
|     |     |     |     | ---------- KP0
-------------------------
|     |     |     |     | ---------- KP1
-------------------------
|     |     |     |     | ---------- KP2
-------------------------
|     |     |     |     | ---------- KP3
-------------------------
|     |     |     | PULL UP
|     |     |     |
KP4   KP5   KP6   KP7

KP (0 TO 3) INPUT   ==> PD0,1,2,3  OUTPUT
KP (4 TO 7) OUTPUT  ==> PD4,5,6,7  INPUT PULL UPD

*/
#define INIT_KEYPAD() DDRD = 0x0f; PORTD = 0xff; DDRC = 0x00; PORTC = 0x0f;  // pull up PD4,5,6,7

#define KP0(val) if(val == 0)  CLR_BIT(PORTD,0); else  SET_BIT(PORTD,0);
#define KP1(val) if(val == 0)  CLR_BIT(PORTD,1); else  SET_BIT(PORTD,1);
#define KP2(val) if(val == 0)  CLR_BIT(PORTD,2); else  SET_BIT(PORTD,2);
#define KP3(val) if(val == 0)  CLR_BIT(PORTD,3); else  SET_BIT(PORTD,3);

#define KP4()  GET_BIT(PIND,4)
#define KP5()  GET_BIT(PIND,5)
#define KP6()  GET_BIT(PIND,6)
#define KP7()  GET_BIT(PIND,7)
#define KP8()  GET_BIT(PINC,0)
#define KP9()  GET_BIT(PINC,1)

#include "../headers.h"
/*****************************************************************************
* Function Name: keypad_init
* Purpose      : initialize keypad pins
* Parameters   : void
* Return value : void
*****************************************************************************/
void Keypad_Inti(void);
/*****************************************************************************
* Function Name: keypad_Read.
* Purpose      : Read_pressed key of keypad buttons.
* Parameters   : void
* Return value : number of the pressed button.
*****************************************************************************/
uint8_t Keypad_Read(); 
#endif /* KEYPAD_H_ */