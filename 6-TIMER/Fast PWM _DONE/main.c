#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"
#include "util/delay.h"
void main(void)
{
	u8 Local_u8Iterator;
	PORT_voidInit();
	TIMER0_voidInit();
	PreScalar();
	GIE_voidEnable();
	while(1)
	{
		for(Local_u8Iterator=0;Local_u8Iterator<255;Local_u8Iterator++)
		{
		TIMER0_voidSetCompareMatchValue(Local_u8Iterator);
		_delay_ms(10);
		}

	}
}

