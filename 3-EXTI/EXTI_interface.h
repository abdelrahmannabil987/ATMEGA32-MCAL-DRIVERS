/*****************************************/
/*****************************************/
/***************  MHAL LAYER  *************/
/***************  A.NABIL    *************/
/***************  EXTI_INTERFACE **********/
/*****************************************/
/*****************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*******************************************************************/
//pre build config

void EXTI_voidInt0INIT(void);

void EXTI_voidInt1INIT(void);

void EXTI_voidInt2INIT(void);

/*******************************************************************/

#define INT0        6
#define INT1        7
#define INT2        5

//post build configuration

/* Description: A FN to set the required sense control of INT0 using POSTBUILD Configuration
 * inputs:Copy_u8Sense
 * Options: 1-LOW_LEVEL
            2-ON_CHANGE
            3-FALLING_EDGE
            4-RISING_EDGE
   outputs:Error Status with type u8*/

#define      LOW_LEVEL            1
#define      ON_CHANGE            2
#define      FALLING_EDGE         3
#define      RISING_EDGE          4

u8 EXTI_u8Int0SerSenseControl(u8 Copy_u8Sense); //first was rising edge then falling and so on
u8 EXTI_u8Int1SerSenseControl(u8 Copy_u8Sense);
u8 EXTI_u8Int2SerSenseControl(u8 Copy_u8Sense);


u8 EXTI_u8EnableInterrupt(u8 Copy_u8IntNum);


/*Two functions to Enable OR Disable the PIE of INT0 INT1 INT2*/
/*Options in Arguments
 * INT0_PIE
 * INT1_PIE
 * INT2_PIE
 * */

#define INT0_PIE       1
#define INT1_PIE       2
#define INT2_PIE       3


u8 EXTI_u8IntEnable(u8 Copy_u8Int);
u8 EXTI_u8IntDisnable(u8 Copy_u8Int);

u8 EXTI_u8DisableInterrupt(u8 Copy_u8IntNum);

/*******************************************************************/


u8 EXTI_u8Int0SetCallBack(void(*Copy_PVINT0FUNC)(void));




#endif
