/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  MCAL          ***************/
/**************   SWC:    Timer0        ***************/
/**************   Version: 1.00         ***************/
/******************************************************/
/******************************************************/

#ifndef   TIMER0_CONFIG_H_
#define   TIMER0_CONFIG_H_

#include "Timer0_Private.h"


//Freq in KHZ
#define   TIMER_F_CPU             (1000UL)  //1 Mega HZ

#define   MODE_OF_OPERATION       PWM_PHASE_CORRECT_MODE


#define   CLOCK_SOURCE            PRESCALER_8

#define   TIMER_PRESCALER         PRESCALER_8

/*
 * If you Choose  CTC Mode set next values
 *   1-software counter
 *   2-prescaler that is suitable to get time required
 *   3-OCR0 Value
 * equation to calculate OCR0 Value .....(Tovf*TimerFreq)/prescaler
 * Tovf be calculated from this equation   (timeRequired/SWCounter)
 *
 *
 * EX:  Time = 5s  , SWCounter = 1000
 *      TOVF = 5/1000 = 5ms
 *      OCR0_VALUE = (5m*1000KHZ)/8 = 625  not in the range
 *      OCR0_VALUE = (5m*1000KHZ)/64 = 78  in the range
 *    prescaler used is 64
 *
 *
 *if you didn't choose ctc Mode set next values with NO_VALUE
 */

#define   SW_COUNTER               NO_VALUE
#define   OCR0_VALUE               NO_VALUE





/*
 ****For Normal/CTC(Non_PWM)  Mode
 *   ->DISCONNECT_OC0
 *   ->Toggle_OC0
 *   ->Clear_OC0
 *   ->Set_OC0
 *
 ****For Fast PWM  Mode
 *   ->DISCONNECT_OC0
 *   ->FAST_PMW_CLEAR_CTC_SET_TOP  ...this will clear OC0 on compare match , set OC0 at TOP
 *   ->FAST_PMW_SET_CTC_CLEAR_TOP  ...this will set OC0 on compare match , clear OC0 at TOP
 *
 ****For Phase Correct PWM  Mode
 *   ->DISCONNECT_OC0
 *   ->Clear_OC0  ...this will clear OC0 on compare match when up_counting , set OC0 on compare match when down_counting
 *   ->Set_OC0    ...this will set OC0 on compare match when up_counting , clear OC0 on compare match when down_counting
 *
 */
#define   OC0_MODE                PHASE_PWM_CLEAR_UP_SET_DOWN



#endif
