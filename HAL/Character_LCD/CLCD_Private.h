/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: HAL           ***************/
/**************   SWC: CLCD            ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/


#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H_

#define EIGHT_BIT   0
#define FOUR_BIT    1

/*Function Set 0b00111000*/
#define FUNCTION_SET_EIGHT_BIT   0x38

/*Function Set 0b00011000*/
#define FUNCTION_SET_FOUR_BIT   0x28


/*Display on/off 0b00001100*/
#define DISPLAY_ON_OFF  0x0c

/*Display Clear  0b00000001*/
#define DISPLAY_CLEAR  0x01

/*Entry Mode Set  0b00000001*/
#define ENTRY_MODE_SET   0x06


static ES_t CLCD_u8Latch(u8 Copy_u8Data);

static inline ES_t CLCD_inu8SendCommand(u8 copy_u8Command);


#endif

