/*
 * STP_Program.c
 *  Author: Abeer Sobhy
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "../../MCAL/RCC/RCC_Interface.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/SysTick/SysTick_Interface.h"
#include "STP_Interface.h"
#include "STP_Config.h"

/*************************************************************
*Function Name: STP_Init
*Function Input Parameter: (uint8_t)portPin , (GPIO_PIN_Config_t) address of the data pin struct,(GPIO_PIN_Config_t) address of the shift register pin struct, Latch register pin
*Function Return Value: void
*Function Description: Function to Initialize the the STP driver.
*****************************************************************************/
void STP_Init(uint8_t portPin ,GPIO_PIN_Config_t DATA_PIN, GPIO_PIN_Config_t SH_CK, GPIO_PIN_Config_t LAT_CK)
{
	RCC_voidInitSysClc(); /*RCC initialize*/
	RCC_voidEnablePrepheralCLK(AHB1, portPin); /*Enable the clock of the selected port.*/
	mSysTick_Init(); /*initialize THE SysTick.*/

	MGPIO_vSetPinDirection(&DATA_PIN); /*Set the direction of the selected data pin as output.*/
	MGPIO_vSetPinDirection(&SH_CK);   /*Set the direction of the selected shift register clock pin as output.*/
	MGPIO_vSetPinDirection(&LAT_CK);  /*Set the direction of the selected latch register clock pin as output.*/
}
/*************************************************************
*Function Name: STP_sendData
*Function Input Parameter: (GPIO_PIN_Config_t) address of the data pin struct,(GPIO_PIN_Config_t) address of the shift register pin struct, Latch register pin
*Function Return Value: void
*Function Description: Function to send serial 8 bit of data to the 74HC595 IC.
****************************************************************************/
void STP_sendData(uint8_t uint8_tData, GPIO_PIN_Config_t DATA_PIN, GPIO_PIN_Config_t SH_CK, GPIO_PIN_Config_t LAT_CK)
{
	int8_t counter = 0;
	for(counter = 7; counter >= 0; counter--)
	{
		MGPIO_vSetPinVal(&DATA_PIN, READ_BIT(uint8_tData, counter)); /*Send the data bit by bit each two system tick.*/
		MGPIO_vSetPinVal(&SH_CK, PIN_HIGH); /*Make the pin high for 2 system tick.*/
		mSysTick_BusyWait(2);
		MGPIO_vSetPinVal(&SH_CK, PIN_LOW); /*Make the pin low for 2 system tick.*/
		mSysTick_BusyWait(2);
	}
	MGPIO_vSetPinVal(&LAT_CK, PIN_HIGH); /*Make the pin high for 2 system tick.*/
	mSysTick_BusyWait(2);
	MGPIO_vSetPinVal(&LAT_CK, PIN_LOW); /*Make the pin low for 2 system tick.*/
	mSysTick_BusyWait(2);
}
