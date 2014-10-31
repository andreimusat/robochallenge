/*
 * adc_helper.c
 *
 * Created: 10/29/2014 9:45:34 PM
 *  Author: ioan
 */ 
#include "adc_helper.h"



uint16_t read_sensor(uint8_t channel){
	
	ADMUX = (ADMUX & ~(0x1f << MUX0)) | channel;

	ADCSRA |= (1 << ADSC);
	while(ADCSRA & (1 << ADSC));

	return ADC;
}
 
void init_adc(){
	
	DDRF = 0x00;
	DDRK = 0x00;
	
	ADMUX = (1 << REFS0);
	ADCSRA = 0;
	ADCSRA |= _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0); //set clock prescaler at 128
	ADCSRA |= _BV(ADEN);         // enable ADC
	ADCSRA |= _BV(ADSC);          //start first conversion
}