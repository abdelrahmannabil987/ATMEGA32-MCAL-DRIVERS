/**************************************************************/
/**************************************************************/
/********************* AUTHOR: A.NABIL ************************/
/********************* LAYER : MCAL    ************************/
/********************* SWC : TIMER_H_  ********************/
/**************************************************************/
/**************************************************************/


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

/*                      Timer0 Registers             */

#define TCNT0             *((volatile u8*)0x52)//Timer/Counter0 Register (8 Bits)

#define TCCR0              *((volatile u8*)0x53) //TIMER0 CONTROL REG
#define TCCR0_WGM00       6     //Waveform Generation Mode bit0
#define TCCR0_WGM01       3     //Waveform Generation Mode bit1
#define COM00             4     //Compare Output Mode bit0 on OC0(PIN B3)//Another Action on OC0 beside Interrupt
#define COM01             5     //Compare Output Mode bit1 on OC0(PIN B3)
#define TCCR0_CS02        2     //prescalar bit2
#define TCCR0_CS01        1     //prescalar bit1
#define TCCR0_CS00        0     //prescalar bit0

#define OCR0              *((volatile u8*)0x5C)  //OUTPUT Compare REG 0 

/************************************************************************/

/*                     Timer1 Registers                        */

#define TCNT1             *((volatile u16*)0x4C)  /*timer/counter1 register*/

#define TCCR1A              *((volatile u8*)0x4F)
#define TCCR1A_WGM10    0
#define TCCR1A_WGM11    1
#define TCCR1A_COM1A0   6
#define TCCR1A_COM1A1   7



#define TCCR1B            *((volatile u8*)0x4E)  //TIMER1 CONTROL REG
#define TCCR1B_WGM13    4
#define TCCR1B_WGM12    3
#define TCCR1B_ICES1    6   /*Input Capture Edge Select*/

#define OCR1A              *((volatile u16*)0x4A)

#define ICR1              *((volatile u16*)0x46)  /*Input Capture Register*/

/************************************************************************/

/*                         General Registers                      */

#define TIMSK             *((volatile u8*)0x59)  //Timer Mask (ALL Interrupts Enable in the 3 TIMERS)
#define TIMSK_TOIE0       0    //TIMER/Counter0 Overflow Interrupt Enable
#define TIMSK_OCIE0       1    //TIMER/Counter0 OUTPUT CompareMatch interrupt Enable
#define TIMSK_TICIE1      5

#define TIFR              *((volatile u8*)0x58)  //TIMER Flags(ALL Flags) //not used


#endif
