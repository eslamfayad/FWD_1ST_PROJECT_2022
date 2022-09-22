/*
* A program that uses  timer to toggle blue LED
    on Tiva C
		DEVOLOPED BY ENG/ESLAM FAYAD 
		
		FOR FWD EMBEDED DIPLOMA 1ST PROJECT
*
*/
///////////////////////////************////////////////////////////////////
#include "Std_Types.h"
#include "GPIO_interface.h"
#include "TIMERS_interface.h"
#include "SYSCNTRL_interface.h"

#define LED_ON (1U<<5)





int main(void) {
    RCGCGPIO |= (1U<<5); /*Enable clock for Port F*/
    RCGCTIMER |= (1U<<0); /*Enable clock for timer0*/

    GPIO_vidSetPinDirection(GPIO_PORTF,GPIO_PIN3,GPIO_OUTPUT); 				// set PIN3 PORT F TO OUTPUT
    GPIO_vidSetPinDigEnable(GPIO_PORTF,GPIO_PIN3,GPIO_DEN_SET);				// ENABLE PIN 3 AS A DIGITAL 

    while(1) {

          GPIO_vidSetPinValue(GPIO_PORTF,GPIO_PIN3,STD_LOW);         // TURN OFF GREEN LED   
          TIMERS_vidStartOneShoot(160);
          GPIO_vidSetPinValue(GPIO_PORTF,GPIO_PIN3,STD_HIGH);				// TURN ON GREEN LED
          TIMERS_vidStartOneShoot(160);

    }
}
