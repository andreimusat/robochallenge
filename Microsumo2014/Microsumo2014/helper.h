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

#define DIST1 PD0
#define DIST2 PD1
#define DIST3 PD2
#define DIST4 PD3
#define DIST5 PD4

#define LINE1 PC0
#define LINE2 PC1

#define START PB6
#define KILL  PB7
 
#define BACK_LEFT (PIND & (1<< DIST1))
#define FRONT_LEFT (PIND & (1<< DIST2))
#define FRONT_SENSOR (PIND & (1<< DIST4))
#define FRONT_RIGHT (PIND & (1<< DIST3)) 
#define BACK_RIGHT (PIND & (1<< DIST5))

#define LEFT_LINE (PINC & (1<<LINE1))
#define RIGHT_LINE (PINC & (1<<LINE2))

#define START_ROBO (PINB & (1 << START))
#define KILL_ROBO (PINB & (1 << KILL))

void left(int speed);
void front(int speed);
void back(int speed);
void right(int speed);
void stop();
void initMotors();
void initIO();
int waitForStartSignal();
void kill();


#endif /* HELPER_H_ */