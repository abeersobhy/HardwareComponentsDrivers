/*
 * LCD.h
 *  Author: Abeer Sobhy
 */ 


#ifndef LCD_H_
#define LCD_H_
/*
D7 : PORTA 7
D6 : PORTA 6
D5 : PORTA 5
D4 : PORTA 4
RS : PORTA 3 
EN : PORTA 2
*/
#define F_CPU 1000000UL
#include <util/delay.h>
//#include "../../Utilities/std_types.h"
#include "../../Utilities/bit_math.h"
#include "../../Utilities/register.h"

#define INTI_LCD_PINS()  DDRA |= 0b11111100; \
                         PORTA &= 0b00000011; /* Set BIT0 & BIT1 ON PORTA .*/
						 
#define D7(val) if(val == 0)  CLR_BIT(PORTA,7); else  SET_BIT(PORTA,7);
#define D6(val) if(val == 0)  CLR_BIT(PORTA,6); else  SET_BIT(PORTA,6);
#define D5(val) if(val == 0)  CLR_BIT(PORTA,5); else  SET_BIT(PORTA,5);
#define D4(val) if(val == 0)  CLR_BIT(PORTA,4); else  SET_BIT(PORTA,4);
#define RS(val) if(val == 0)  CLR_BIT(PORTA,3); else  SET_BIT(PORTA,3);
#define EN(val) if(val == 0)  CLR_BIT(PORTA,2); else  SET_BIT(PORTA,2);
   		
#define TRIGGER_LCD()  EN(1);  _delay_ms(1);  EN(0);  _delay_ms(1); 
#define LCD_Clear 0x01 /*Clear LCD.*/
#define LCD_TurnOnDisplay 0x0C /*Turn on the Display.*/
#define LCD_CURSER_INC_RIGHT 0x06 /* MAKE CURSER INCREAMENT RIGHT.*/
#define DISPLAY_OFF_CURSER_OFF 0x8 /*DISPLAY OFF CURSER OFF "NO WRITING".*/
#define Shift_left 0x18
#define Shift_right 0x1C
#define LINE_TWO 0xc0
#define LINE_ONE 0x02
/*4 BIT MOOD.*/
#define MOOD4 0x2 
#define LCD_4BIT_2LINE 0x28 /*USING TWO LINE TO WRITE.*/
#define LCD_4BIT_1LINE  0x20 /*USING ONR LINE TO WRITE.*/
/*8 BIT MOOD.*/
#define LCD_8BIT_2LINE 0x38 /*USING TWO LINE TO WRITE.*/
#define LCD_8BIT_1LINE 0x30 /*USING ONR LINE TO WRITE.*/
#define delay_ms(time_ms) _delay_ms(time_ms) 
 	   				 
/***************************************************
* Function name :  LCD_Inti                         
* Purpose :  initialize LCD to work in 4 bit         
* Parameters :   (void) No parameters               
* Return value :  void                              
***************************************************/
void LCD_4BIT_inti(void);
/***************************************************
* Function name : LCD_Write_Command               
* Purpose :  Send specific command to LCD ( using 4 bit mood ).       
* Parameters :  cmd (Command to be done by LCD).           
* Return value : (void)                        
***************************************************/
void LCD_Write_4BIT_Command(uint8_t cmd);
/***************************************************
* Function name :  LCD_Write_Char                    
* Purpose :  Send specific char to LCD ( using 4 bit mood ).       
* Parameters :   data(character to be write on LCD.)          
* Return value :  void                             
***************************************************/
void LCD_Write_Char(uint8_t data);
/***************************************************
* Function name :  LCD_Write_String                      
* Purpose :  Send String (as an array of character assume the end of the array is null )to LCD ( using 4 bit mood ).
* Parameters :   txt(String to be write on LCD).
* Return value :  void                       
***************************************************/
void LCD_Write_String(uint8_t *txt);
/***************************************************
* Function name : LCD_Write_Number
* Purpose :  Send number to LCD to be Written
* Parameters :   number 
* Return value :  void
***************************************************/
void LCD_Write_Number(int32_t number);
/***************************************************
* Function name : LCD_Display_Number.
* Purpose : Display float and decimal numbers on the LCD. 
* Parameters : (double)number
* Return value :  void
***************************************************/
void LCD_Display_Number(double number);
#endif /* LCD_H_ */