/********************************************************/
/********************************************************/
/**************   Author: Doaa Tawfik     ***************/
/**************   Layer:  MCAL            ***************/
/**************   SWC:    SPI             ***************/
/**************   Version: 1.00           ***************/
/********************************************************/
/********************************************************/

#ifndef  SPI_PRIVATE_H_
#define  SPI_PRIVATE_H_

#define   NORMAL_SPEED_MODE                     4
#define   DOUBLE_SPEED_MODE                     5

#define   LSB_FIRST                             1
#define   MSB_FIRST                             2

#define   MASTER                                6
#define   SLAVE                                 7

#define   LEADING_RISING_EDGE                   70
#define   LEADING_FALLING_EDGE                  80

#define   LEADING_SAMPLE                        30  //Sample = receive
#define   LEADING_SETUP                         20  //Setup = send


#define   NORMAL_BY_4_DOUBLE_BY_2               11
#define   NORMAL_BY_16_DOUBLE_BY_8              12
#define   NORMAL_BY_64_DOUBLE_BY_32             13
#define   NORMAL_BY_128_DOUBLE_BY_64            14





#endif

