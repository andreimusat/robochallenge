/*
 * helper.c
 *
 * Created: 4/20/2014 12:47:10 PM
 *  Author: johnny
 */ 

#include "helper.h"

void set_right_motor(int type, int speed){
	switch(type){
		case BACK:
			OCR0A = speed;
			OCR0B  = 0;
		break;
		
		case FRONT:
			OCR0A = 0;
			OCR0B  = speed;
		
		break;
		
		default:
		
			OCR0A = 0;
			OCR0B  = 0;
		break;
	}
}
void set_left_motor(int type, int speed){
	switch(type){
		case BACK:
		
			OCR1A = speed;
			OCR1B = 0;
		break;
		
		case FRONT:
		
			OCR1A = 0;
			OCR1B = speed;
		break;
		
		default:
			OCR1A = 0;
			OCR1B = 0;
		
		break;
	}
}

void left(int speed){
	set_right_motor(FRONT,speed);
	set_left_motor(BACK,speed);
}

void front(int speed){
	set_right_motor(FRONT,speed);
	set_left_motor(FRONT,speed);
}

void back(int speed){
	
	set_right_motor(BACK,speed);
	set_left_motor(BACK,speed);
}


void right(int speed){
	set_right_motor(BACK,speed);
	set_left_motor(FRONT,speed);
}

void stop(){
	set_left_motor(STOP,0);
	set_right_motor(STOP,0);
}

void initTimers() {
	TCCR0A = (1<<COM0A1) | (1<<COM0B1) | (1 << WGM00) | (1 << WGM01);
	TCCR0B =  (1<< CS02) | (1<<CS00) ;

	TCCR1A = (1<<COM1A1) | (1<<COM1B1) | (1 << WGM10);
	TCCR1B =  (1<< CS12)  | (1<<CS10) | (1<< WGM12);
	
	OCR0A = 0;
	OCR0B = 0;
	OCR1A = 0;
	OCR1B = 0;
}
void initMotors(){
	DDRD |= (1<<PD5) | (1 << PD6);
	DDRB |= (1<<PB1) | (1<<PB2);
	initTimers();
}

void initIO() {
	DDRC &= ~((1<< DIST1) | (1<< DIST2) | (1<< DIST3) | (1<< DIST4) | (1<< DIST5) | (1<<DIST6));
//	PORTC |= (1<< DIST1) | (1<< DIST2) | (1<< DIST3) | (1<< DIST4) | (1<< DIST5) | (1<<DIST6);
	
	DDRD &= ~((1<< LINE1) | (1<<LINE2));
	PORTD |= (1<< LINE1) | (1<<LINE2);
}

void initADC() {
	ADMUX = (1 << REFS0);
	ADCSRA = (1 << ADEN) | (7 << ADPS0);
}

int ADC_get(uint8_t channel)
{
	ADMUX = (ADMUX & ~(0x1f << MUX0)) | channel;

	ADCSRA |= (1 << ADSC);
	while(ADCSRA & (1 << ADSC));

	return ADC;
}

int waitForStartSignal() {
	if ( START_ROBO == 0 )
		return 0;
	else
		return 1;
}

void kill() {
	if (KILL_ROBO == 0) {
		while (1) {
			stop();
		}
	}
}

