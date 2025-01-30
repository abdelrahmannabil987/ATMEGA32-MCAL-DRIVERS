/*************************************************/
/******************* A.NABIL *********************/
/*******************   MCAL  *********************/
/***************** TWI_INTERFACE_H_ ****************/
/*************************************************/
/*************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum //enum:numbers only //enum is like #define
{
    NoError,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MstrWriteByteERROR,
	MstrReadByteError,
}TWI_ErrorStatus;


void TWI_voidMasterINIT(u8 Copy_u8SlaveAddress);/*Pass 0 in slave address argument in master init if master will not be addressed */

void TWI_voidSlaveINIT(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus TWI_SendStartCondition(void);

TWI_ErrorStatus TWI_SendRepeatedStart(void);

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copt_u8SlaveAddress);

TWI_ErrorStatus TWI_SendSlaveAddressWithRead(u8 Copt_u8SlaveAddress);

TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrorStatus TWI_MasterReadDataByte(u8* Copy_pu8DataByte);

void TWI_SendStopCondition(void);

#endif
