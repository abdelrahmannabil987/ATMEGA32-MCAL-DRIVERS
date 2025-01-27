#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"
void main(void)
{
	//u16 Local_u16Iterator;
	u16 digital;
	s32 after_map;
	PORT_voidInit();
	TIMER1_ServoInit();
	Timer1_voidSetICR_TopValue(20000);
	ADC_voidInit();
	GIE_voidEnable();
	while(1)
	{
		ADC_u16StartConversionSynch(0,&digital);
		after_map=Mapping(0,255,750,2500,digital);
		Timer1_voidSetChannelA_Compare_Match(after_map);
	}
}

