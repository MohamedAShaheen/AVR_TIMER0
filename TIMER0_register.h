/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen    *****************/
/**************       Layer : MCAL                  *****************/
/**************       SWC:  8BIT TIMER0             *****************/
/**************       Version : 2.0                 *****************/
/********************************************************************/
/********************************************************************/


/* file guard  */

#ifndef TIMER0_REGISTER_H_ 
#define TIMER0_REGISTER_H_

/*TIMER0 Control Register */
#define _TCCR0			    *((volatile uint8 *) 0x53 )
#define _TCCR0_FOC0             7   

/*Waveform Generation Mode */
#define _TCCR0_WGM00            6

#define _TCCR0_COM01            5              //Compare Match Output Mode
#define _TCCR0_COM00            4

#define _TCCR0_WGM01            3              

#define _TCCR0_CS02             2               // Clock Select prescaller
#define _TCCR0_CS01             1
#define _TCCR0_CS00             0

/* Timer / Counter Register */

#define _TCNT0			    *((volatile uint8 *) 0x52 )

/* CTC Mode Register */
#define _OCR0			    *((volatile uint8 *) 0x5C )


/* Interruot Mask Register */
#define _TIMSK			    *((volatile uint8 *) 0x59 )
#define _TIMSK_OCIE0             1                          // CTC SPE
#define _TIMSK_TOIE0             0                          // oVERFLOW SPE

/* FLAG Register */
#define _TIFR			    *((volatile uint8 *) 0x58 )
#define _TIFR_OCF0             1                           // CTC Flag
#define _TIFR_TOV0             0                           // oVERFLOW flag
												     
#endif