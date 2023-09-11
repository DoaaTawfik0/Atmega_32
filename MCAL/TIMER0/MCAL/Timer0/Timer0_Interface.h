/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  MCAL          ***************/
/**************   SWC:    Timer0        ***************/
/**************   Version: 1.00         ***************/
/******************************************************/
/******************************************************/

#ifndef   TIMER0_INTERFACE_H_
#define   TIMER0_INTERFACE_H_


ES_t  TIMER0_enuInitialize(void);

ES_t  TIMER0_enuSetPreload(u8 Copy_u8Preload);

ES_t  TIMER0_enuSynchDelay_ms(u32 Copy_u32DelayTime);//Polling  End of Jop

ES_t  TIMER0_enuASynchDelay_ms(u32 Copy_u32DelayTime ,volatile void(*Copy_pfunAppFun)(void*) , void* Copy_pvidAppParameter);//Interrupt ISR

ES_t  TIMER0_enuSetCTC(u8 Copy_u8OCR0Value);

ES_t TIMER0_enuGeneratePWM(u8  Copy_u8DutyCycle);




#endif
