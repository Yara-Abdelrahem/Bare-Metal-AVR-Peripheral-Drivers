/*
 * Layered_Architecture.c
 *
 * Created: 12/17/2024 1:31:14 PM
 * Author : yaraa
 */ 

#include <avr/io.h>
#include "./MCAL/MDIO/MDIO.h"
#include "./MCAL/MPORT/MPORT.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#define F_CPU 8000000UL
int main(void)
{
	MDIO_enuErrorStatus_t stat1 , stat2, stat3;
	u8 res1 , res2 , res3 , count=0;
	//MDIO_vInit();
	MPORT_vInit();
	//MPORT_enuSetPinDirection(PIN_A0 , MPORT_OUTPUT);
		while (1)
		{			
			stat1 = MDIO_enuGetPinValue(MDIO_PORTA , MDIO_enuPIN3, &res1);
			//portA0
			stat1=MDIO_enuSetPinValue(MDIO_PORTA , MDIO_enuPIN0 , res1);
			
			stat2 = MDIO_enuGetPinValue(MDIO_PORTA , MDIO_enuPIN4, &res2);
			//PORT A1
			stat2=MDIO_enuSetPinValue(MDIO_PORTA , MDIO_enuPIN1 , res2);
			
			stat3 = MDIO_enuGetPinValue(MDIO_PORTA , MDIO_enuPIN5, &res3);
			//PORT A2
			stat3=MDIO_enuSetPinValue(MDIO_PORTA , MDIO_enuPIN2 , res3);
			_delay_ms(1000);

		}
}

