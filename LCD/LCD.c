/*
 * LCD.c
 *  Author: Abeer Sobhy
 */

#include "LCD.h"
void LCD_4BIT_inti(void)
{
	INTI_LCD_PINS();
	LCD_Write_4BIT_Command(0x3);
	delay_ms(4);
	LCD_Write_4BIT_Command(0x3);
	delay_ms(4);
	LCD_Write_4BIT_Command(0x3);
	delay_ms(4);
	LCD_Write_4BIT_Command(MOOD4);
	LCD_Write_4BIT_Command(LCD_4BIT_2LINE);
	LCD_Write_4BIT_Command(DISPLAY_OFF_CURSER_OFF);
	LCD_Write_4BIT_Command(LCD_Clear);
	LCD_Write_4BIT_Command(LCD_CURSER_INC_RIGHT);
	LCD_Write_4BIT_Command(LCD_Clear);
	LCD_Write_4BIT_Command(LCD_TurnOnDisplay);
}

void LCD_Write_4BIT_Command(uint8_t cmd){
	RS(0);/*Select Command register.*/
    D7(READ_BIT(cmd,BIT7)); 
	D6(READ_BIT(cmd,BIT6));    /*Send the most four bit to data pins.*/
	D5(READ_BIT(cmd,BIT5));
	D4(READ_BIT(cmd,BIT4)); 
	TRIGGER_LCD(); /*Enable EN for 1 ms then disable it for 1ms.*/
	D7(READ_BIT(cmd,BIT3));
	D6(READ_BIT(cmd,BIT2));   /*Send the least four bit to data pins.*/
	D5(READ_BIT(cmd,BIT1));
	D4(READ_BIT(cmd,BIT0));
	TRIGGER_LCD(); /*Enable EN for 1 ms then disable it for 1ms.*/
}
void LCD_Write_Char(uint8_t data)
{
	RS(1);
	D7(READ_BIT(data,BIT7));
	D6(READ_BIT(data,BIT6));    /*Send the most four bit to data pins.*/
	D5(READ_BIT(data,BIT5));
	D4(READ_BIT(data,BIT4));
	TRIGGER_LCD(); /*Enable EN for 1 ms then disable it for 1ms.*/
	D7(READ_BIT(data,BIT3));
	D6(READ_BIT(data,BIT2));   /*Send the least four bit to data pins.*/
	D5(READ_BIT(data,BIT1));
	D4(READ_BIT(data,BIT0));
	TRIGGER_LCD(); /*Enable EN for 1 ms then disable it for 1ms.*/

}
void LCD_Write_String(uint8_t *txt)
{
    uint8_t index = 0;
	while(txt[index] != '\0')
	{
	    LCD_Write_Char(txt[index]);
		index++;
	}
}
void LCD_Write_Number(int32_t number)
{
	if(number == 0)
	{
		LCD_Write_Char('0');
	}
	else if(number > 0)
	{
		uint8_t arr_num[10] = {0};
		int8_t i = 0;
		while(number > 0)
		{
			arr_num[i] = (number % 10) + 48;
			number /= 10;
			i++;
		}
		for(int8_t j = (i-1) ; j >= 0 ; j--)
		{
			LCD_Write_Char(arr_num[j]);
		}
	}
	else
	{
		number*= -1;
		uint8_t arr_num[10] = {0};
		int8_t i = 0;
		while(number > 0)
		{
			arr_num[i] = (number % 10) + 48;
			number /= 10;
			i++;
		}
		LCD_Write_Char('-');
		for(int8_t j = (i-1) ; j >= 0 ; j--)
		{
			LCD_Write_Char(arr_num[j]);
		}
	}
}
void LCD_Display_Number(double number)
{
	int32_t NUM_First = number;
	int32_t NUM_Second = (number - NUM_First)*100;
	uint8_t arr_num[10] = {0};
	uint8_t arr_num2[10] = {0};
	int8_t i = 0 , k = 0;
	if(number == 0)
	{
		LCD_Write_Char('0');
	}
	else if(number > 0) /*Positive numbers.*/
	{
		while(NUM_First > 0)
		{
			arr_num[i] = (NUM_First % 10) + 48;
			NUM_First /= 10;
			i++;
		}
		for(int8_t j = (i-1) ; j >= 0 ; j--)
		{
			LCD_Write_Char(arr_num[j]);
		}
		if(NUM_Second != 0)
		{
			LCD_Write_Char('.');
		}
		/*Float number.*/
		while(NUM_Second > 0)
		{
			arr_num2[k] = (NUM_Second % 10) + 48; /* 255 % 10 = 5 */
			NUM_Second /= 10;
			k++;
		}
		for(int8_t j = (k-1) ; j >= 0 ; j--)
		{
			LCD_Write_Char(arr_num2[j]);
		}	
	}
	else /*Negative numbers.*/
	{
		NUM_First*= -1;
		while(NUM_First > 0)
		{
			arr_num[i] = (NUM_First % 10) + 48;
			NUM_First /= 10;
			i++;
		}
		LCD_Write_Char('-');
		for(int8_t j = (i-1) ; j >= 0 ; j--)
		{
			LCD_Write_Char(arr_num[j]);
		}
		if(NUM_Second != 0)
		{
			LCD_Write_Char('.');
		}
		/*Float number.*/
		while(NUM_Second > 0)
		{
			arr_num2[k] = (NUM_Second % 10) + 48; /* 255 % 10 = 5 */
			NUM_Second /= 10;
			k++;
		}
		for(int8_t j = (k-1) ; j >= 0 ; j--)
		{
			LCD_Write_Char(arr_num2[j]);
		}
	}
}