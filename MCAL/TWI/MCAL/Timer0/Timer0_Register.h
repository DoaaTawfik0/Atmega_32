/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  MCAL          ***************/
/**************   SWC:    Timer0        ***************/
/**************   Version: 1.00         ***************/
/******************************************************/
/******************************************************/

#ifndef   TIMER0_REGISTER_H_
#define   TIMER0_REGISTER_H_



/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                Timer counter control Register -> TCCR0                  **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/



#define      TCCR0               *((volatile u8*) 0x53)

//Bits 4,5  Compare Matvh O/P Mode
#define      TCCR0_COM00         4
#define      TCCR0_COM01         5

//Bits 3,6  WaveForm Generation Mode
#define      TCCR0_WGM00         6
#define      TCCR0_WGM01         3

//Bits 0:2  Clock Select
#define      TCCR0_CS00          0
#define      TCCR0_CS01          1
#define      TCCR0_CS02          2

//Bit 7  Force O/P Compare
#define      TCCR0_FOC0          7


/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                Timer counter Register -> TCNT0                          **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/


#define      TCNT0               *((volatile u8*) 0x52)


/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                Output Compare Register -> OCR0                          **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/

#define      OCR0                *((volatile u8*) 0x5C)



/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                Timer Counter Interrupt Mask Register -> TIMSK           **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/

#define      TIMSK               *((volatile u8*) 0x59)

//Bit 0  OverFlow Interrupt Enable
#define      TIMSK_TOIE0         0

//Bit 1  Output Compare Match Interrupt Enable
#define      TIMSK_OCIE0         1


/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                Timer Counter Interrupt Flag Register -> TIFR            **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/


#define      TIFR                *((volatile u8*) 0x58)

//Bit 0  OverFlow Flag 0
#define      TIFR_TOV0           0

//Bit 1  O/P Compare Flag 0
#define      TIFR_OCF0           1







#endif
