/*
 * Keypad.c
 *  Author: Abeer Sobhy.
 */ 
#include "Keypad.h"

const uint8_t keypad_matrix[] = 
{
	 'C' , 7 , 8 , 9 , '*' , '/',
	 'A' , 4 , 5 , 6 , '-' , 'B',
	 '%' , 1 , 2 , 3 , '+' , 'D',
	 'F' , 0 ,'.','=', '+' , 'E'
};
void Keypad_Inti(void)
{
	INIT_KEYPAD();
}
uint8_t Keypad_Read()
{
	uint8_t i;
	for(i = 0; i < 4; i++)
	{
		switch(i)
		{
			case 0: KP0(0); KP1(1); KP2(1); KP3(1); break;
			case 1: KP0(1); KP1(0); KP2(1); KP3(1); break;
			case 2: KP0(1); KP1(1); KP2(0); KP3(1); break;
			case 3: KP0(1); KP1(1); KP2(1); KP3(0); break;
		}
		if(KP4() == 0) return keypad_matrix[0+6*i];
		if(KP5() == 0) return keypad_matrix[1+6*i];
		if(KP6() == 0) return keypad_matrix[2+6*i];
		if(KP7() == 0) return keypad_matrix[3+6*i];
		if(KP8() == 0) return keypad_matrix[4+6*i];
		if(KP9() == 0) return keypad_matrix[5+6*i];
		delay_ms(1);
	}
	return -1;
} 