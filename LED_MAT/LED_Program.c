/*
 * LED_Program.c
 * Author: Abeer Sobhy
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "../../MCAL/SysTick/SysTick_Interface.h"
#include "../../MCAL/RCC/RCC_Interface.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "LED_Interface.h"
#include "LED_Private.h"
#include "LED_Config.h"

GPIO_PIN_Config_t CL1 =
{
	.portNumber = LED_MX_CL_PORT,
	.pinNumber = LED_MX_CL1,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t CL2 =
{
	.portNumber = LED_MX_CL_PORT,
	.pinNumber = LED_MX_CL2,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t CL3 =
{
	.portNumber = LED_MX_CL_PORT,
	.pinNumber = LED_MX_CL3,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t CL4 =
{
	.portNumber = LED_MX_CL_PORT,
	.pinNumber = LED_MX_CL4,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t CL5 =
{
	.portNumber = LED_MX_CL_PORT,
	.pinNumber = LED_MX_CL5,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t CL6 =
{
	.portNumber = LED_MX_CL_PORT,
	.pinNumber = LED_MX_CL6,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t CL7 =
{
	.portNumber = LED_MX_CL_PORT,
	.pinNumber = LED_MX_CL7,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t CL8 =
{
	.portNumber = LED_MX_CL_PORT,
	.pinNumber = LED_MX_CL8,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
/****************/
GPIO_PIN_Config_t RW1 =
{
	.portNumber = LED_MX_RW_PORT,
	.pinNumber = LED_MX_RW1,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t RW2 =
{
	.portNumber = LED_MX_RW_PORT,
	.pinNumber = LED_MX_RW2,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t RW3 =
{
	.portNumber = LED_MX_RW_PORT,
	.pinNumber = LED_MX_RW3,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t RW4 =
{
	.portNumber = LED_MX_RW_PORT,
	.pinNumber = LED_MX_RW4,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t RW5 =
{
	.portNumber = LED_MX_RW_PORT,
	.pinNumber = LED_MX_RW5,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t RW6 =
{
	.portNumber = LED_MX_RW_PORT,
	.pinNumber = LED_MX_RW6,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t RW7 =
{
	.portNumber = LED_MX_RW_PORT,
	.pinNumber = LED_MX_RW7,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
GPIO_PIN_Config_t RW8 =
{
	.portNumber = LED_MX_RW_PORT,
	.pinNumber = LED_MX_RW8,
	.pinOutputType = PUSH_PULL,
	.pinDirection = OUTPUT,
	.pinSpeed = LOW_SPEED,
};
/*******************************************/
/**************************************************************************
 * Function Name    	: LED_MX_Init
 * Function Input   	: void
 * Function Return  	: void
 * Function Description : Initialize the LED Matrix.
 * **************************************************************************/
void LED_MX_Init()
{
	STK_void_Init();
	/*Initialize the Columns as outputs.*/
	MGPIO_vSetPinDirection(&CL1);
	MGPIO_vSetPinDirection(&CL2);
	MGPIO_vSetPinDirection(&CL3);
	MGPIO_vSetPinDirection(&CL4);
	MGPIO_vSetPinDirection(&CL5);
	MGPIO_vSetPinDirection(&CL6);
	MGPIO_vSetPinDirection(&CL7);
	MGPIO_vSetPinDirection(&CL8);
	/*Initialize the Raws as outputs.*/
	MGPIO_vSetPinDirection(&RW1);
	MGPIO_vSetPinDirection(&RW2);
	MGPIO_vSetPinDirection(&RW3);
	MGPIO_vSetPinDirection(&RW4);
	MGPIO_vSetPinDirection(&RW5);
	MGPIO_vSetPinDirection(&RW6);
	MGPIO_vSetPinDirection(&RW7);
	MGPIO_vSetPinDirection(&RW8);
}
/******************************************/
/**************************************************************************
 * Function Name    	: LED_MX_CLR_DISPLAY
 * Function Input   	: void
 * Function Return  	: void
 * Function Description : Clear the matrix
 * **************************************************************************/
void LED_MX_CLR_DISPLAY()
{
	/*Initialize the Column with ZERO Volt.*/
	MGPIO_vSetPinVal(&CL1, PIN_HIGH);
	MGPIO_vSetPinVal(&CL2, PIN_HIGH);
	MGPIO_vSetPinVal(&CL3, PIN_HIGH);
	MGPIO_vSetPinVal(&CL4, PIN_HIGH);
	MGPIO_vSetPinVal(&CL5, PIN_HIGH);
	MGPIO_vSetPinVal(&CL6, PIN_HIGH);
	MGPIO_vSetPinVal(&CL7, PIN_HIGH);
	MGPIO_vSetPinVal(&CL8, PIN_HIGH);
	/*Initialize the Raws with ZERO Volt.*/
	MGPIO_vSetPinVal(&RW1, PIN_LOW);
	MGPIO_vSetPinVal(&RW2, PIN_LOW);
	MGPIO_vSetPinVal(&RW3, PIN_LOW);
	MGPIO_vSetPinVal(&RW4, PIN_LOW);
	MGPIO_vSetPinVal(&RW5, PIN_LOW);
	MGPIO_vSetPinVal(&RW6, PIN_LOW);
	MGPIO_vSetPinVal(&RW7, PIN_LOW);
	MGPIO_vSetPinVal(&RW8, PIN_LOW);
}
/**************************************************************************
 * Function Name    	: LED_MX_CLR_RW
 * Function Input   	: void
 * Function Return  	: void
 * Function Description : Clear The Raw of the LED Matrix.
 * **************************************************************************/
void LED_MX_CLR_CL()
{
	/*Initialize the Column with ZERO Volt.*/
	MGPIO_vSetPinVal(&CL1, PIN_HIGH);
	MGPIO_vSetPinVal(&CL2, PIN_HIGH);
	MGPIO_vSetPinVal(&CL3, PIN_HIGH);
	MGPIO_vSetPinVal(&CL4, PIN_HIGH);
	MGPIO_vSetPinVal(&CL5, PIN_HIGH);
	MGPIO_vSetPinVal(&CL6, PIN_HIGH);
	MGPIO_vSetPinVal(&CL7, PIN_HIGH);
	MGPIO_vSetPinVal(&CL8, PIN_HIGH);
}
/**************************************************************************
 * Function Name    	: LED_MX_CLR_RW
 * Function Input   	: void
 * Function Return  	: void
 * Function Description : Clear The Raw of the LED Matrix.
 * **************************************************************************/
void LED_MX_CLR_RW()
{
	/*Initialize the Raws with ZERO Volt.*/
	MGPIO_vSetPinVal(&RW1, PIN_LOW);
	MGPIO_vSetPinVal(&RW2, PIN_LOW);
	MGPIO_vSetPinVal(&RW3, PIN_LOW);
	MGPIO_vSetPinVal(&RW4, PIN_LOW);
	MGPIO_vSetPinVal(&RW5, PIN_LOW);
	MGPIO_vSetPinVal(&RW6, PIN_LOW);
	MGPIO_vSetPinVal(&RW7, PIN_LOW);
	MGPIO_vSetPinVal(&RW8, PIN_LOW);
}
/**************************************************************************
 * Function Name    	: LED_MX_Display
 * Function Input   	: The address of dataFram array which contain the frame of data to display
 * Function Return  	: void
 * Function Description : Display the a frame of data.
 * **************************************************************************/
void LED_MX_Display(uint8_t* dataFram)
{
	LED_MX_CLR_CL();
	MGPIO_vSetPinVal(&CL1, PIN_LOW);
	LED_MX_RW_VAL(dataFram[0]);
	STK_voidSetBusyWait(LED_FRAME_DELAY);
	/*********************************************/
	LED_MX_CLR_CL();
	MGPIO_vSetPinVal(&CL2, PIN_LOW);
	LED_MX_RW_VAL(dataFram[1]);
	STK_voidSetBusyWait(LED_FRAME_DELAY);
	/*********************************************/
	LED_MX_CLR_CL();
	MGPIO_vSetPinVal(&CL3, PIN_LOW);
	LED_MX_RW_VAL(dataFram[2]);
	STK_voidSetBusyWait(LED_FRAME_DELAY);
   /**********************************************/
	LED_MX_CLR_CL();
	MGPIO_vSetPinVal(&CL4, PIN_LOW);
	LED_MX_RW_VAL(dataFram[3]);
	STK_voidSetBusyWait(LED_FRAME_DELAY);
	/**********************************************/
	LED_MX_CLR_CL();
	MGPIO_vSetPinVal(&CL5, PIN_LOW);
	LED_MX_RW_VAL(dataFram[4]);
	STK_voidSetBusyWait(LED_FRAME_DELAY);
	/**********************************************/
	LED_MX_CLR_CL();
	MGPIO_vSetPinVal(&CL6, PIN_LOW);
	LED_MX_RW_VAL(dataFram[5]);
	STK_voidSetBusyWait(LED_FRAME_DELAY);
	/**********************************************/
	LED_MX_CLR_CL();
	MGPIO_vSetPinVal(&CL7, PIN_LOW);
	LED_MX_RW_VAL(dataFram[6]);
	STK_voidSetBusyWait(LED_FRAME_DELAY);
	/**********************************************/
	LED_MX_CLR_CL();
	MGPIO_vSetPinVal(&CL8, PIN_LOW);
	LED_MX_RW_VAL(dataFram[7]);
	STK_voidSetBusyWait(LED_FRAME_DELAY);
}
/**************************************************************************
 * Function Name    	: LED_MX_RW_VAL
 * Function Input   	: (uint8_t) frame of data
 * Function Return  	: void
 * Function Description : Display the value of each frame to the rows
 * **************************************************************************/
void LED_MX_RW_VAL(uint8_t frame)
{
	MGPIO_vSetPinVal(&RW1, READ_BIT(frame,0));
	MGPIO_vSetPinVal(&RW2, READ_BIT(frame,1));
	MGPIO_vSetPinVal(&RW3, READ_BIT(frame,2));
	MGPIO_vSetPinVal(&RW4, READ_BIT(frame,3));
	MGPIO_vSetPinVal(&RW5, READ_BIT(frame,4));
	MGPIO_vSetPinVal(&RW6, READ_BIT(frame,5));
	MGPIO_vSetPinVal(&RW7, READ_BIT(frame,6));
	MGPIO_vSetPinVal(&RW8, READ_BIT(frame,7));
}

