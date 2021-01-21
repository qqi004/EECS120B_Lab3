/*	Author: lab
 *  Partner(s) Name: Qi Qi
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif	

int main(void) {
	DDRD = 0x00; PORTD = 0xFF; // Configure port D's 8 pins as inputs
	DDRB = 0x01;PORTB = 0x00; // Set the PB0 be input and the rest bits be outputs
	
	unsigned char tmpB_input = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpB_output = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpD = 0x00; // Temporary variable to hold the value of D
	unsigned short weight = 0x0000; //Temporary variable to hold the value of total weight

while(1) {
		// 1) Read input
		tmpD = PIND & 0xFF;
		tmpB_input = PINB & 0x01;
		tmpB_output = 0x00;
		weight = (tmpD << 1) | tmpB_input;
	
	if(weight >= 70){
		tmpB_output = 0x02;
	}
	else if((weight > 5) && (weight < 70)){
		tmpB_output = 0x04;
	}
	else{
		tmpB_output = 0x00;
	}
		
		
	
		
	// 3) Write output
		PORTB = tmpB_output;
	}
	return 0;
}

