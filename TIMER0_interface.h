/*********************************************************************/
/*********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer : MCAL                   *****************/
/**************       SWC:     TIMER0                *****************/
/**************       Version : 2.0                  *****************/
/*********************************************************************/
/*********************************************************************/

/* file guard */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_



/*Functon Prototypes *******************************************/
/*
* Description : This function is used to initialize TIMER 0
* Parameters  : void
*               
* Return      : void
*/

void TIMER0_voidINIT(void);


/*Functon Prototypes *******************************************/
/*
* Description : This function is used to call back ISR of timer0
* Parameters  : pointer to function
*               
* Return      : void
*/
void TIMER0_voidCallBackNotification(void (*Copy_pvCallbackFun)(void));

#endif