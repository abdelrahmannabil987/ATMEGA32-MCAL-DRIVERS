#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_register.h"

void SPI_voidInitMaster(void)
{

	/*Master Initialization*/
	SET_BIT(SPCR,SPCR_MSTR);

	/*Clock Prescalar divide by 16*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidInitSlave(void)
{

	/*Slave Initialization*/
	CLR_BIT(SPCR,SPCR_MSTR);

	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);

}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{

	/*Send the data*/
	SPDR=Copy_u8Data;

	/*Busy Waiting until Transfer Complete*/
	while (GET_BIT(SPSR,SPSR_SPIF)==0);

	/*Get the exchanged data*/
	return SPDR;//Accessing SPDR is replacing to make it 0 again

}

