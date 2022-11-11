/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer : MCAL                  *****************/
/**************       SWC:     TIMER0                  *****************/
/**************       Version : 2.0                 *****************/
/********************************************************************/
/********************************************************************/

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

/*Waveform Generatuon Mode of Timer0 */
#define NORMAL_MODE            1
#define CTC_MODE               2
#define PWM_FAST_MODE          3
#define PWM_PHASE_MODE         4

/* TIMER PRESCALER */
#define N0_CLOCK_SOURSE        1
#define NO_PRESCALER           2
#define DIVBY_8                3
#define DIVBY_64               4
#define DIVBY_256              5
#define DIVBY_1024             6


/*OC0 PIN Config */
#define OC0_DISCONNECTED       	1
#define OC0_TOGGEL			    2
#define OC0_CLEAR			    3
#define OC0_SET				    4
#define OC0_NONINVERTING        5
#define OC0_INVERTING           6


#endif