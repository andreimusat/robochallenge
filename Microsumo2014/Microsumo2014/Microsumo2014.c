/*
 * Microsumo2014.c
 *
 * Created: 4/20/2014 12:45:31 PM
 *  Author: johnny
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include "helper.h"

int flag = 0;

void line() {
	
	front(SPEED_LOW);
	
	
	if(RIGHT_LINE == 0) {
		//back(SPEED_MAX);
		//_delay_ms(100);
		//left(SPEED_MED);
		stop();
		_delay_ms(100);
	} 
	if(LEFT_LINE == 0) {
		//back(SPEED_MAX);
		//_delay_ms(100);
		//right(SPEED_MED);
		//_delay_ms(100);
		stop();
		_delay_ms(100);
	}
	//front(SPEED_LOW);
	
}

void lineFront() {
	
	if(RIGHT_LINE == 0) {
		back(SPEED_MAX); //Back full speeed ?
		_delay_ms(100);
		left(SPEED_MED);
		_delay_ms(100);
	}
	if(LEFT_LINE == 0) {
		back(SPEED_MAX);
		_delay_ms(100);
		right(SPEED_MED);
		_delay_ms(100);
	}
	
}

void dist(){
	//front(SPEED_MED);
	if ((ADC_get(3) > 500) || (ADC_get(4) > 500) || (ADC_get(0) > 500) || (ADC_get(1) > 500) || (ADC_get(2) > 500) || (ADC_get(5) > 500)) {
		front(SPEED_MED);
		_delay_ms(100);
		stop();
	}
	
	/*if( FRONT_SENSOR == 0 ) {
		
		if ( FRONT_LEFT == 0 ) {
			left(SPEED_MED);
			_delay_ms(10);
		} else if ( FRONT_RIGHT == 0 ) {
			right(SPEED_MED);
			_delay_ms(10);
		}
		
		flag = 1;
		front(SPEED_MAX);
		_delay_ms(10);
		lineFront();
		_delay_ms(10);
		return;
	}
	
	if(flag)
	{
		flag = 0;
		//back(SPEED_MED2);
		//_delay_ms(100);
		return;
	}
	
		if( FRONT_LEFT == 0 ) {
			if( FRONT_RIGHT == 0 ) {
				flag = 1;
				front(SPEED_MAX);
				_delay_ms(10);
				lineFront();
				_delay_ms(10);
				return;
			}			
			left(SPEED_MED);
			_delay_ms(10);
			return;
		}

		if( FRONT_RIGHT == 0 ) {
			
			if( FRONT_LEFT == 0 ) {
				flag = 1;
				front(SPEED_MAX);
				_delay_ms(10);
				lineFront();
				_delay_ms(10);
				return;
			}
			
			right(SPEED_MED);
			_delay_ms(10);
			return;
		}
	
	if( FRONT_LEFT == 0 ) {
		left(SPEED_MED);
		_delay_ms(10);
		return;
	}

	if( FRONT_RIGHT == 0 ) {
		
		right(SPEED_MED);
		_delay_ms(10);
		return;
	}
	
	if( BACK_LEFT == 0 ) {	
		left(SPEED_MED);
		_delay_ms(25);
		return;
	}
	if( BACK_RIGHT == 0 ) {
		
		right(SPEED_MED);
		_delay_ms(25);
		return;
	}*/
	//stop();
}

int main(void)
{
	//_delay_ms(2000);
	initMotors();
	initIO(); 
	initADC();
		
	//while ( waitForStartSignal() == 0 );
		
    while(1)
    {
		//front(SPEED_MED);
		dist();
		//line();
		//kill();
    }
	return 0;
}
