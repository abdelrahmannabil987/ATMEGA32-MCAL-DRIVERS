#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI_.register.h"
#include "TWI_config.h"
#include "TWI_interface.h"
#include "TWI_private.h"



void TWI_voidMasterINIT(u8 Copy_u8SlaveAddress)/*Pass 0 in slave address argument in master init if master will not be addressed */
{
	/*Set CLK frequency to 400 kbps*/
	/*SET TWBR to 2*/
	TWBR=2;
	/*CLR the 2 bits of TWPS*/
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);
	/*Initialize the node address*/
	if(Copy_u8SlaveAddress !=0)
	{
		TWAR=Copy_u8SlaveAddress<<1;
	}

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidSlaveINIT(u8 Copy_u8SlaveAddress)
{
	/*Initialize the node address*/
	TWAR=Copy_u8SlaveAddress<<1;

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ErrorStatus TWI_SendStartCondition(void)
{
	TWI_ErrorStatus Local_ErrorStatus =NoError;

	/*Send Start Condition in the Bus*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt Flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==1);

	if((TWSR&0xf8) != (START_ACK)) //masking LSB 3 bits in TWSR //checking it's really the operation that happened
	{
		Local_ErrorStatus=StartConditionError;
	}
	else
	{
		//Do thing
	}

	return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrorStatus Local_ErrorStatus =NoError;

	/*Send Start Condition in the Bus*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt Flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==1);

	if((TWSR&0xf8) != (REP_START_ACK)) //masking LSB 3 bits in TWSR
	{
		Local_ErrorStatus=RepeatedStartError;
	}
	else
	{
		//Do thing
	}

	return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copt_u8SlaveAddress)
{
	TWI_ErrorStatus Local_ErrorStatus =NoError;
	/*Clear the start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Set the slave address in the 7 MSB in the data register*/
	TWDR = Copt_u8SlaveAddress<<1;
	CLR_BIT(TWDR,0);//for write request

	/*Clear the interrupt Flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==1);

	/*Check the operation status in the status register*/
	if((TWSR&0xf8) != (SLAVE_ADD_AND_WR_ACK)) //masking LSB 3 bits in TWSR
	{
		Local_ErrorStatus=SlaveAddressWithWriteError;
	}
	else
	{
		//Do thing
	}

	return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithRead(u8 Copt_u8SlaveAddress)
{
	TWI_ErrorStatus Local_ErrorStatus =NoError;
	/*Clear the start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);
	/*Set the slave address in the 7 MSB in the data register*/
	TWDR = Copt_u8SlaveAddress<<1;

	SET_BIT(TWDR,0);//for read request

	/*Clear the interrupt Flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==1);

	/*Check the operation status in the status register*/
	if((TWSR&0xf8) != (SLAVE_ADD_AND_RD_ACK)) //masking LSB 3 bits in TWSR
	{
		Local_ErrorStatus=SlaveAddressWithReadError;
	}
	else
	{
		//Do thing
	}
	return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrorStatus Local_ErrorStatus =NoError;

	/*write the data byte*/
	TWDR=Copy_u8DataByte;

	/*Clear the interrupt Flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==1);

	/*Check the operation status in the status register*/
	if((TWSR&0xf8) != (MSTR_WR_BYTE_ACK)) //masking LSB 3 bits in TWSR
	{
		Local_ErrorStatus=MstrWriteByteERROR;
	}
	else
	{
		//Do thing
	}
	return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_MasterReadDataByte(u8* Copy_pu8DataByte)
{
	TWI_ErrorStatus Local_ErrorStatus =NoError;

	/*Enable MSTR generating ACK bit after Receiving the data*/
	SET_BIT(TWCR,TWCR_TWEA);

	/*Clear the interrupt Flag to Start the Slave Sending data*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==1);

	/*Check the operation status in the status register*/
	if((TWSR&0xf8) != (MSTR_RD_BYTE_WITH_ACK)) //masking LSB 3 bits in TWSR
	{
		Local_ErrorStatus=MstrReadByteError;
	}
	else
	{
		/*Read the received data*/
		*Copy_pu8DataByte=TWDR;
	}
	return Local_ErrorStatus;
}

void TWI_SendStopCondition(void)
{
	/*generate Stop Condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTO);

	/*Clear the interrupt Flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

}
