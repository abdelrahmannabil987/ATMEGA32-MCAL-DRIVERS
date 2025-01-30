#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SPI_interface.h"

void main(void)
{

	/*Master Program*/
	PORT_voidInit();
	SPI_voidInitMaster();
	while(1)
	{

		SPI_u8Transceive(1);
		_delay_ms(10);
	}
}
