/*
 * IncFile1.h
 *
 * Created: 10/29/2014 9:45:42 PM
 *  Author: ioan
 */ 


#ifndef ADC_HELPER_H_
#define ADC_HELPER_H_

#include <avr/io.h>

#define LIGHT1 PF0
#define LIGHT2 PF1
#define LIGHT3 PF2
#define LIGHT4 PF3
#define LIGHT5 PF4
#define LIGHT6 PF5
#define LIGHT7 PF6
#define LIGHT8 PF7
#define LIGHT9 PK0
#define LIGHT10 PK1
#define LIGHT11 PK2
#define LIGHT12 PK3
#define LIGHT13 PK4
#define LIGHT14 PK5
#define LIGHT15 PK6
#define LIGHT16 PK7



uint16_t read_sensor(uint8_t sensor);
void init_adc();


#endif /* INCFILE1_H_ */