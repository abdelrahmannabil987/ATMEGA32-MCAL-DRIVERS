/*****************************************/
/*****************************************/
/***************  MHAL LAYER  *************/
/***************  A.NABIL    *************/
/***************  EXTI_CONFIG_H_ **********/
/*****************************************/
/*****************************************/



#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_



//prebuild config

/*
 * options
1-LOW_LEVEL
2-ON_CHANGE
3-FALLING_EDGE
4-RISING_EDGE
 */

/*Choose Sense Control from the ABOVE macros if you use INT0 or INT1*/
/*NOTE That for INT2 is FALLING EDG AND RISING EDGE ONLY*/


#define INT0_Sense     RISING_EDGE
#define INT1_Sense     FALLING_EDGE
#define INT2_Sense     FALLING_EDGE

/*
 options
 1-Enable
 2-Disable
  */
#define         INT0_INITIAL_STATE              Enable
#define         INT1_INITIAL_STATE              Enable
#define         INT2_INITIAL_STATE              Disable


//INT0 is D2 in our MC
//INT1 is D3 in our MC
//INT2 is B2 in our MC

#endif
