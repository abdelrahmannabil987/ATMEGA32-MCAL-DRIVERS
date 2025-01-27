/*****************************************/
/*****************************************/
/***************  MHAL LAYER  ************/
/***************  A.NABIL    *************/
/***************  ADC_INTERFACE_H_ ********/
/*****************************************/
/*****************************************/


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef struct
{
	u8* Channel;
	u16* Result;
	u8 Chain_Size;
	void(*Notification_FUNC)(void);

}Chain_t;

void ADC_voidInit(void);


u16 ADC_u16StartConversionSynch(u8 Copy_u8Channel , u16* Copy_Ptru16Reading);
u16 ADC_u16StartConversionAsynch(u8 Copy_u8Channel , u16* Copy_Ptru16Reading,void(*Copy_pvNotificationFUNC)(void));
u8 ADC_u8StartChainAsynchronous(Chain_t *Copy_Chain);
s32 Mapping(s32 Input_MIN,s32 Input_MAX,s32 Output_MIN,s32 Output_MAX,s32 Input_Value); //A function of a straight line

/*Choosing the channel to get bits
 Options:

  Single Ended Input

  1-ADC0
  2-ADC1
  3-ADC2
  4-ADC3
  5-ADC4
  6-ADC5
  7-ADC6
  8-ADC7
  Differential Channelsö
1-ADC0_ADC0_10x
2-ADC1_ADC0_10x
3-ADC0_ADC0_200x
4-ADC1_ADC0_200x
5-ADC2_ADC2_10x
6-ADC3_ADC2_10x
7-ADC2_ADC2_200x
8-ADC3_ADC2_200x
9-ADC0_ADC1_1x
10-ADC1_ADC1_1x
11-ADC2_ADC1_1x
12-ADC3_ADC1_1x
13-ADC4_ADC1_1x
14-ADC5_ADC1_1x
15-ADC6_ADC1_1x
16-ADC7_ADC1_1x
17-ADC0_ADC2_1x
18-ADC1_ADC2_1x
19-ADC2_ADC2_1x
20-ADC3_ADC2_1x
21-ADC4_ADC2_1x
  */


#define Input_Channel ADC0 //  Differential Channelsö is Better to decrease noise


#define ADC0 00000
#define ADC1 00001
#define ADC2 00010
#define ADC3 00011
#define ADC4 00100
#define ADC5 00101
#define ADC6 00110
#define ADC7 00111


#define ADC0_ADC0_10x  01000
#define ADC1_ADC0_10x  01001
#define ADC0_ADC0_200x 01010
#define ADC1_ADC0_200x 01011
#define ADC2_ADC2_10x  01100
#define ADC3_ADC2_10x  01101
#define ADC2_ADC2_200x 01110
#define ADC3_ADC2_200x 01111
#define ADC0_ADC1_1x   10000
#define ADC1_ADC1_1x  10001
#define ADC2_ADC1_1x  10010
#define ADC3_ADC1_1x  10011
#define ADC4_ADC1_1x  10100
#define ADC5_ADC1_1x  10101
#define ADC6_ADC1_1x  10110
#define ADC7_ADC1_1x  10111
#define ADC0_ADC2_1x  11000
#define ADC1_ADC2_1x  11001
#define ADC2_ADC2_1x  11010
#define ADC3_ADC2_1x  11011
#define ADC4_ADC2_1x  11100

#endif
