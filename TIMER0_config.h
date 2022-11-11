/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer : MCAL                  *****************/
/**************       SWC:     TIMER0                  *****************/
/**************       Version : 2.0                 *****************/
/********************************************************************/
/********************************************************************/

/* file guard */

#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H_

/* Waveform Generation Mode */
/*SELECT :
NORMAL_MODE  or  CTC_MODE   or  PWM_FAST_MODE or  PWM_PHASE_MODE*/
#define  TIMER0_MODE           NORMAL_MODE

/*TIMER0 prescaler */
/*SELECT :
N0_CLOCK_SOURSE   or NO_PRESCALER  or  DIVBY_8  OR  DIVBY_64   or DIVBY_256  or  DIVBY_1024
*/
#define  TIMER0_PRESCALER      DIVBY_64

/*timer0 preload at normal mode */
#define  OVERFLOW_PRELOAD      131

/*compare match value */
#define  CTC_VALUE             25  

/*OC0 CONFIG */
/* SELECT :
OC0_DISCONNECTED  OR  OC0_TOGGEL  OR  OC0_CLEAR OR OC0_SET*/
#define OC0_NOPWM        OC0_DISCONNECTED
#define OC0_FASTPWM      OC0_NONINVERTING
#define OC0_PHASEPWM     OC0_DISCONNECTED
  
#endif