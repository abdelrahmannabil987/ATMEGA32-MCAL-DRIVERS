/*************************************************/
/******************* A.NABIL *********************/
/*******************   MCAL  *********************/
/***************** TWI_REGISTER_H_ ***************/
/*************************************************/
/*************************************************/


#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define TWCR      *((volatile u8*)0x56)  /*TWI control register*/
#define TWCR_TWINT  7                    /*Interrupt Flag*/
#define TWCR_TWEA   6                    /*Enable ACKnowledge*/
#define TWCR_TWSTA  5                    /*Start condition*/
#define TWCR_TWSTO  4                    /*Stop condition*/
#define TWCR_TWWC   3                    /*Write collision*/
#define TWCR_TWEN   2                    /*Enable*/
#define TWCR_TWIE   0                    /*Interrupt Flag*/


#define TWDR    *((volatile u8*)0x23)    /*TWI Data register*/

#define TWAR    *((volatile u8*)0x22)    /*TWI Address register*/
#define TWAR_TWGCE  0                    /*General call recognition enable*/


#define TWSR    *((volatile u8*)0x21)   /*TWI Status register*/
#define TWSR_TWPS0  0                   /*Prescalar bit0*/
#define TWSR_TWPS1  1                   /*Prescalar bit1*/

#define TWBR    *((volatile u8*)0x20)   /*TWI BitRate register*/

#endif 
