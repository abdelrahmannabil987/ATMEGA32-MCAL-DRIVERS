#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SPI_interface.h"

void main(void)
{
	/*Slave Program*/
	u8 Local_u8ReceivedData;
	PORT_voidInit();
	SPI_voidInitSlave();
	while(1)
	{

		Local_u8ReceivedData=SPI_u8Transceive(10);//argument is any thing just to exchange with Master
		_delay_ms(10);
		if(Local_u8ReceivedData==1)
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}
	}

}
