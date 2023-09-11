/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  MCAL          ***************/
/**************   SWC:    Timer0        ***************/
/**************   Version: 1.00         ***************/
/******************************************************/
/******************************************************/

#ifndef   TIMER0_PRIVATE_H_
#define   TIMER0_PRIVATE_H_


#define    NORMAL_MODE                                   1
#define    PWM_PHASE_CORRECT_MODE                        2
#define    CTC_MODE                                      3  //clear timer on compare match
#define    FAST_PWM_MODE                                 4


#define    NO_PRESCALER                                  1
#define    NO_CLOCK_SOURCE                               1
#define    PRESCALER_8                                   8
#define    PRESCALER_64                                  64
#define    PRESCALER_256                                 256
#define    PRESCALER_1024                                1024
#define    EXTERNAL_T0PIN_FALLING_EDGE                   17
#define    EXTERNAL_T0PIN_RISING_EDGE                    18



#define   DISCONNECT_OC0                                 33
#define   TOGGLE_OC0                                     44
#define   SET_OC0                                        55
#define   CLEAR_OC0                                      66

#define   FAST_PWM_CLEAR_CTC_SET_TOP                     10   //Non Inverted Mode
#define   FAST_PWM_SET_CTC_CLEAR_TOP                     20   //Inverted Mode


#define   PHASE_PWM_SET_UP_CLEAR_DOWN                    30   //Inverted Mode
#define   PHASE_PWM_CLEAR_UP_SET_DOWN                    40  //Non Inverted Mode



#define   OVF_COUNTS                                     256



#define   NO_VALUE                                       0


#endif
