/************************************************/
/************************************************/
/*****************   A.NABIL   ******************/
/*****************   MCAL       *****************/
/*****************   SPI_REGISTERT_H_   *********/
/************************************************/
/************************************************/


#ifndef SPI_REGISTERT_H_
#define SPI_REGISTERT_H_

#define  SPDR           *((volatile u8*)0x2F) /*SPI Data Register*/

#define  SPSR           *((volatile u8*)0x2E) /*SPI Status Register*/   
#define  SPSR_SPIF      7                     /*SPI Interrupt Flag*/
#define  SPSR_SPI2X     0                     /*Prescalar bit 2*/


#define  SPCR           *((volatile u8*)0x2D) /*SPI Control Register*/
#define  SPCR_SPE       6                     /*SPI Enable*/
#define  SPCR_MSTR      4                     /*Master bit*/
#define  SPCR_SPR1      1                     /*Prescalar bit 1*/
#define  SPCR_SPR0      0                     /*Prescalar bit 0*/


#endif
