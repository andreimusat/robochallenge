/*
 * helper.h
 *
 * Created: 4/20/2014 12:46:59 PM
 *  Author: johnny
 */ 


#ifndef HELPER_H_
#define HELPER_H_

#include <avr/io.h>

#define SPEED_LOW 17
#define SPEED_MED 60
#define SPEED_MED2 80  
#define SPEED_HALF 127
#define SPEED_MAX 255
#define FRONT 1
#define BACK 2
#define STOP 0

#define PIN_LEFT_BOTTOM PC2
#define PIN_LEFT_MIDDLE PD1
#define PIN_LEFT_TOP PC1
#define PIN_MIDDLE_TOP PD2
#define PIN_RIGHT_TOP PC0
#define PIN_RIGHT_MIDDLE PD4
#define PIN_RIGHT_BOTTOM PD5


#define LEFT_BOTTOM (PINC & (1<<PIN_LEFT_BOTTOM))
#define LEFT_MIDDLE (PIND & (1<<PIN_LEFT_MIDDLE))
#define LEFT_TOP (PINC & (1<<PIN_LEFT_TOP))
#define MIDDLE_TOP (PIND & (1<<PIN_MIDDLE_TOP))
#define RIGHT_TOP (PINC & (1<<PIN_RIGHT_TOP))
#define RIGHT_MIDDLE (PIND & (1<<PIN_RIGHT_MIDDLE))
#define RIGHT_BOTTOM (PIND & (1<<PIN_RIGHT_BOTTOM))



#define PIN_LINE1 PD0
#define PIN_LINE2 PD1
 
#define LEFT_LINE (PIND & (1<<PIN_LINE1))
#define RIGHT_LINE (PIND & (1<<PIN_LINE2))
  

void left(int speed);
void front(int left_speed, int right_speed);
void back(int speed);
void right(int speed);
void stop();
void balls_stop();
void balls_gather();
void balls_scatter();

void initMotors();
void initIO();  


#endif /* HELPER_H_ */
