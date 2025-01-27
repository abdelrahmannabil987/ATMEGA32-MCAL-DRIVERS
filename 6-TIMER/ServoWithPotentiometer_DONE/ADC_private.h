/*****************************************/
/*****************************************/
/***************  MHAL LAYER  ************/
/***************  A.NABIL    *************/
/***************  ADC_PRIVATE_H_ ********/
/*****************************************/
/*****************************************/


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define External 1
#define AVCC 2
#define Internal 3

#define Left_Adj 1
#define Right_Adj 2

#define IDLE       1
#define BUSY       2

#define Division_By_Two                  1
#define Division_By_Four                 2
#define Division_By_Eight                3
#define Division_By_Six_Teen             4
#define Division_By_Thirty_Two           5
#define Division_By_Sixty_Four           6
#define Division_By_One_Twenty_Eight     7

#define enabled   1
#define disabled  2


#define EIGHT_BITS 1
#define TEN_BITS   2

#define SingleChannelAsynch  0
#define ChainAsynch          1


#define PreScalar_Masking 0b11111000
#define InputChannel_Masking 0b1100000




#define Free_Running                        1
#define Analog_Comparator                   2
#define External_Interrupt_Request0         3
#define Timer_Counter0_Compare_Match        4
#define Timer_Counter0_Overflow             5
#define Timer_Counter_Compare_Match_B       6
#define Timer_Counter1_Overflow             7
#define Timer_Counter1_Capture_Event        8






#endif
