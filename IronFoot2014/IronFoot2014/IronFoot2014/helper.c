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
		OCR2A = speed;
		OCR2B = 0;
		break;
		
		case FRONT:
		
		OCR2A = 0;
		OCR2B = speed;
		break;
		
		default:
		OCR2A = 0;
		OCR2B = 0;
		
		break;
	}
}
void set_left_motor(int type, int speed){
		switch(type){
			case BACK:
			OCR1A = speed;
			OCR1B  = 0;
			break;
			
			case FRONT:
			OCR1A = 0;
			OCR1B  = speed;
			
			break;
			
			default:
			
			OCR1A = 0;
			OCR1B  = 0;
			break;
		}
}

void left(int speed) {
	set_right_motor(FRONT,speed);
	set_left_motor(BACK,speed);
}

void front(int left_speed, int right_speed) {
	set_right_motor(FRONT, right_speed);
	set_left_motor(FRONT, left_speed);
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

void balls_gather(){
	
	OCR0A = 124;
	OCR0B  = 0;
}

void balls_stop() {
	
	OCR0A = 0;
	OCR0B  = 0;
}

void balls_scatter() {
	
	OCR0A = 0;
	OCR0B  = 70;
}

void initTimers() {
	TCCR0A = (1<<COM0A1) | (1<<COM0B1) | (1 << WGM00) | (1 << WGM01);
	TCCR0B =  (1<< CS02) ;


	TCCR1A = (1<<COM1A1) | (1<<COM1B1) | (1 << WGM10);
	TCCR1B =  (1<< CS12) | (1<<WGM12);
	
	
	TCCR2A = (1<<COM2A1) | (1<<COM2B1) | (1<< WGM21) | (1 << WGM20);
	TCCR2B =  (1<< CS22) | (1<<CS21) ;
	
	
	OCR0A = 0;
	OCR0B = 0;
	OCR1A = 0;
	OCR1B = 0;
	OCR2A = 0;
	OCR2B = 0;
}

void initMotors(){
	
	DDRH |= (1 << PH6);
	
	DDRG |= (1 << PG5);
	
	DDRB |= (1<<PB4) | (1<<PB5) | (1<<PB6) | (1<<PB7);
	
	initTimers();
}

void initIO() {
	
	DDRD =0x00;
	//PORTD =0xFF;
	
	DDRC &= ~((1<< PIN_LEFT_BOTTOM) | (1<<PIN_LEFT_TOP)| (1<<PIN_RIGHT_TOP));
	//PORTC |= (1<< PIN_LEFT_BOTTOM) | (1<<PIN_LEFT_TOP)| (1<<PIN_RIGHT_TOP);
}
