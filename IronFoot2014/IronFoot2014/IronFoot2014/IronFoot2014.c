/*
 * IronFoot2014.c
 *
 * Created: 10/29/2014 6:03:51 PM
 *  Author: ioan
 */ 


#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#include "helper.h"
#include "adc_helper.h"

int main(void)
{
	initMotors();
	initIO(); 
	init_adc();
	front(100, 100);
	while(1)
    {
        //TODO:: Please write your application code 
		//uint16_t value = read_sensor(2);
		//if(value > 660 && value < 690) {
			//balls_gather();
			//_delay_ms(300);
		//} else {
			//balls_stop();	
		//}
    }
}
