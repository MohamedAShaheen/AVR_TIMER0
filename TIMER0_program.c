/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer : MCAL                  *****************/
/**************       SWC:     DIO                  *****************/
/**************       Version : 2.0                 *****************/
/********************************************************************/
/********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "TIMER0_register.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"


/* Global pointer to function */
static void (*Global_pvPtrFun)(void);


void TIMER0_voidINIT(void){
/*************** TIMER0 NORMAL MODE *************/
	#if TIMER0_MODE == NORMAL_MODE
	 
	   CLR_BIT(_TCCR0,_TCCR0_WGM00);
	   CLR_BIT(_TCCR0,_TCCR0_WGM01);
	   
	   /*TIMER0_OVERFLOW INTERRUPT_ENABLE */
	   SET_BIT(_TIMSK, _TIMSK_TOIE0);
	   
	   /* MAKE TIMER Register Start From Preload */
	  _TCNT0 = OVERFLOW_PRELOAD;
	   
/*************** Compare Match Mode ***********/
	#elif TIMER0_MODE == CTC_MODE
	
	   CLR_BIT(_TCCR0,_TCCR0_WGM00);
	   SET_BIT(_TCCR0,_TCCR0_WGM01);
	   
	   /****** CONFIG OC0 PIN ******/
	   #if  OC0_NOPWM    OC0_DISCONNECTED
	   
	     CLR_BIT(_TCCR0,_TCCR0_COM00);
	     CLR_BIT(_TCCR0,_TCCR0_COM01);
		 
	   #elif OC0_NOPWM   OC0_TOGGEL
	   
	      SET_BIT(_TCCR0,_TCCR0_COM00);
	      CLR_BIT(_TCCR0,_TCCR0_COM01);
		  
	   #elif OC0_NOPWM   OC0_CLEAR
	   
	      CLR_BIT(_TCCR0,_TCCR0_COM00);
	      SET_BIT(_TCCR0,_TCCR0_COM01);
		  
	   #elif OC0_NOPWM   OC0_SET
	   
	      SET_BIT(_TCCR0,_TCCR0_COM00);
	      SET_BIT(_TCCR0,_TCCR0_COM01);
		#endif
	   
/*** TIMER0_CTC INTERRUPT_ENABLE */
	   SET_BIT(_TIMSK, _TIMSK_OCIE0);

    /* COMPARE MATCH VALUE **/	   
	   _OCR0=CTC_VALUE;

/****************** PWM Fast Mode  ****************/	
	#elif TIMER0_MODE == PWM_FAST_MODE
	    
		/*PWM Fast Mode*/
		SET_BIT(_TCCR0,_TCCR0_WGM00);
		SET_BIT(_TCCR0,_TCCR0_WGM01);
		
      /********* OC0 at FASTPWM MODE *****/
      /******    CONFIG OC0 PIN ******/
		#if  OC0_FASTPWM  ==  OC0_DISCONNECTED
		
		CLR_BIT(_TCCR0,_TCCR0_COM00);
		CLR_BIT(_TCCR0,_TCCR0_COM01);
		
		#elif OC0_FASTPWM == OC0_NONINVERTING
		
		CLR_BIT(_TCCR0,_TCCR0_COM00);
		SET_BIT(_TCCR0,_TCCR0_COM01);
		
		#elif OC0_FASTPWM ==  OC0_INVERTING
		
		SET_BIT(_TCCR0,_TCCR0_COM00);
		SET_BIT(_TCCR0,_TCCR0_COM01);
		#endif
		
		/*SET CTC VALUE After calculation for pwm fast mode */
		_OCR0=CTC_VALUE;

/*************** PWM Phase Correct Mode ******************/		
	#elif TIMER0_MODE == PWM_PHASE_MODE
	   
	   /*PWM Phase Correct Mode */
	   SET_BIT(_TCCR0,_TCCR0_WGM00);
	   CLR_BIT(_TCCR0,_TCCR0_WGM01);
	   
	   /********* OC0 at FASTPWM MODE *****/
	   /******    CONFIG OC0 PIN ******/
	   #if  OC0_PHASEPWM == OC0_DISCONNECTED
	   
	   CLR_BIT(_TCCR0,_TCCR0_COM00);
	   CLR_BIT(_TCCR0,_TCCR0_COM01);
	   
	   #elif OC0_PHASEPWM == OC0_NONINVERTING
	   
	   CLR_BIT(_TCCR0,_TCCR0_COM00);
	   SET_BIT(_TCCR0,_TCCR0_COM01);
	   
	   #elif OC0_PHASEPWM == OC0_INVERTING
	   
	   SET_BIT(_TCCR0,_TCCR0_COM00);
	   SET_BIT(_TCCR0,_TCCR0_COM01);
	   #endif
	   
	   /*SET CTC VALUE After calculation */
		_OCR0=CTC_VALUE;
 /*  in pwm no interrupt needed*/
 
#endif


/*ENABLE TIMER0 By Select prescaler */

    #if TIMER0_PRESCALER == N0_CLOCK_SOURSE
     
	  CLR_BIT(_TCCR0,_TCCR0_CS00);
	  CLR_BIT(_TCCR0,_TCCR0_CS01);
	  CLR_BIT(_TCCR0, _TCCR0_CS02);
	  
	#elif TIMER0_PRESCALER == NO_PRESCALER
	  
	  SET_BIT(_TCCR0,_TCCR0_CS00);
	  CLR_BIT(_TCCR0,_TCCR0_CS01);
	  CLR_BIT(_TCCR0, _TCCR0_CS02);
	  	
	#elif TIMER0_PRESCALER == DIVBY_8
	
	CLR_BIT(_TCCR0,_TCCR0_CS00);
	SET_BIT(_TCCR0,_TCCR0_CS01);
	CLR_BIT(_TCCR0, _TCCR0_CS02);
	
	#elif TIMER0_PRESCALER == DIVBY_64
	
	SET_BIT(_TCCR0,_TCCR0_CS00);
	SET_BIT(_TCCR0,_TCCR0_CS01);
	CLR_BIT(_TCCR0, _TCCR0_CS02);
	
	#elif TIMER0_PRESCALER == DIVBY_256
	
	CLR_BIT(_TCCR0,_TCCR0_CS00);
	CLR_BIT(_TCCR0,_TCCR0_CS01);
	SET_BIT(_TCCR0, _TCCR0_CS02);
	
	#elif TIMER0_PRESCALER == DIVBY_1024
	
	SET_BIT(_TCCR0,_TCCR0_CS00);
	CLR_BIT(_TCCR0,_TCCR0_CS01);
	SET_BIT(_TCCR0, _TCCR0_CS02);

	#endif

 
	
}


void TIMER0_voidCallBackNotification(void (*Copy_pvCallbackFun)(void)){
	
	if(Copy_pvCallbackFun!=NULL){
	
	Global_pvPtrFun=Copy_pvCallbackFun;
	}
	
	}

 /* ISR Fun for Timer0 overflow mode*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void){
	
	if(Global_pvPtrFun!=NULL){
	Global_pvPtrFun();
	}  
}

/* ISR Func for Timer0 CTC Mode */
void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	
	if(Global_pvPtrFun!=NULL){
		Global_pvPtrFun();
	}
}