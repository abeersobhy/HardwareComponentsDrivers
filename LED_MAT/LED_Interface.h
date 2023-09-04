/*
 * LED_Interface.h
 * Author: Abeer Sobhy
 */

#ifndef HAL_LED_MAT_LED_INTERFACE_H_
#define HAL_LED_MAT_LED_INTERFACE_H_


/**************************************************************************
 * Function Name    	: LED_MX_Init
 * Function Input   	: void
 * Function Return  	: void
 * Function Description : Initialize the LED Matrix.
 * **************************************************************************/
void LED_MX_Init();
/**************************************************************************
 * Function Name    	: LED_MX_CLR_CL
 * Function Input   	: void
 * Function Return  	: void
 * Function Description : Clear The Column of the LED Matrix.
 * **************************************************************************/
void LED_MX_CLR_CL();
/**************************************************************************
 * Function Name    	: LED_MX_CLR_RW
 * Function Input   	: void
 * Function Return  	: void
 * Function Description : Clear The Raw of the LED Matrix.
 * **************************************************************************/
void LED_MX_CLR_RW();
/**************************************************************************
 * Function Name    	: LED_MX_Display
 * Function Input   	: The address of dataFram array which contain the frame of data to display
 * Function Return  	: void
 * Function Description : Display the a frame of data.
 * **************************************************************************/
void LED_MX_Display(uint8_t* dataFram);
/**************************************************************************
 * Function Name    	: LED_MX_RW_VAL
 * Function Input   	: (uint8_t) frame of data
 * Function Return  	: void
 * Function Description : Display the value of each frame to the rows
 * **************************************************************************/
void LED_MX_RW_VAL(uint8_t frame);
/**************************************************************************
 * Function Name    	: LED_MX_CLR_DISPLAY
 * Function Input   	: void
 * Function Return  	: void
 * Function Description : Clear the matrix
 * **************************************************************************/
void LED_MX_CLR_DISPLAY();

#endif /* HAL_LED_MAT_LED_INTERFACE_H_ */
