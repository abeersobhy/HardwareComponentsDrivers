/*
 * STP_Interface.h
 * Author: Abeer Sobhy
 */

#ifndef HAL_STP_STP_INTERFACE_H_
#define HAL_STP_STP_INTERFACE_H_

/*************************************************************
*Function Name: STP_Init
*Function Input Parameter: (uint8_t)portPin , (GPIO_PIN_Config_t) address of the data pin struct,(GPIO_PIN_Config_t) address of the shift register pin struct, Latch register pin
*Function Return Value: void
*Function Description: Function to Initialize the the STP driver.
********************************************************************/
void STP_Init(uint8_t portPin ,GPIO_PIN_Config_t DATA_PIN, GPIO_PIN_Config_t SH_CK, GPIO_PIN_Config_t LAT_CK);
/*************************************************************
*Function Name: STP_sendData
*Function Input Parameter: (GPIO_PIN_Config_t) address of the data pin struct,(GPIO_PIN_Config_t) address of the shift register pin struct, Latch register pin
*Function Return Value: void
*Function Description: Function to send serial 8 bit of data to the 74HC595 IC.
***************************************************************************/
void STP_sendData(uint8_t uint8_tData, GPIO_PIN_Config_t DATA_PIN, GPIO_PIN_Config_t SH_CK, GPIO_PIN_Config_t LAT_CK);



#endif /* HAL_STP_STP_INTERFACE_H_ */
