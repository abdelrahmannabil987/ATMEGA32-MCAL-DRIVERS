/*****************************************/
/*****************************************/
/***************  MHAL LAYER  ************/
/***************  A.NABIL    *************/
/***************  ADC_CONFIG_H_ ********/
/*****************************************/
/*****************************************/


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*Voltage Reference Selection*/
/*Choose on of the Options
1-External -->    AREF, Internal Vref turned off
2-AVCC     -->    AVCC with external capacitor at AREF pin
3-Internal -->    Internal 2.56V Voltage Reference with external capacitor at AREF pin
 */
#define AREF_VOLTAGE AVCC

/*Data Result Registers options are Left Adjust or Right Adjust
  Left Adjust if i want only 8 bits -->Get them from ADCH only
  Right Adjust if i want 10 bits -->Read ADCL and ADCH

  Options :
  1-Left_Adj  (if you read 8 bits this is better ,make *u8 to ADCH)
  2-Right_Adj (if you read 10 bits this is better to make *u16 to ADCL)
 */
#define Data_Result Right_Adj


/*Choose Prescalar division factor
  Options:
    1-Division_By_Two
    2-Division_By_Four
    3-Division_By_Eight
    4-Division_By_Six_Teen
    5-Division_By_Thirty_Two
    6-Division_By_Sixty_Four
    7-Division_By_One_Twenty_Eight
 */
#define Prescalar_Factor Division_By_One_Twenty_Eight


/*Trigger Mode : There are two modes to make conversion
  POLLING (Start Conversion Mode) and AUTO_Trigger(then choose the interrupt source of the auto trigger )
  Options
  Single Conversion AND Auto Trigger
  Single Conversion BY POLLING
  Auto Trigger BY Interrupt

  So We Make Options According to Auto Trigger :
  1-disabled : POLLING   //Start Conversion bit trigger the ADC and take a screen shoot of the analog value now
  2-enabled : AUTO_Trigger //another source trigger the ADC ((INTERRUPR))then check start conversion or auto trigger
  */
#define AUTO_Trigger disabled

/*if Auto trigger is enabled Choose the Auto trigger source
 Options :
 1-Free_Running
 2-Analog_Comparator
 3-External_Interrupt_Request0
 4-Timer_Counter0_Compare_Match
 5-Timer_Counter0_Overflow
 6-Timer_Counter_Compare_Match_B
 7-Timer_Counter1_Overflow
 8-Timer_Counter1_Capture_Event
*/

#define ADC_Trigger Free_Running


/*OUR MC ADC Resolution is 10 bits in two registers
 we can read 8 bits only in ADCH
 Options:
 1-EIGHT_BITS
 2-TEN_BITS
 */

#define BITS_READ EIGHT_BITS


#define ADC_u32TimeOUT       50000

#endif
