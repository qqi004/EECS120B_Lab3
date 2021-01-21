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
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
	
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpC = 0x00; // Temporary variable to hold the value of C

while(1) {
		// 1) Read input
		tmpA = PINA & 0xFF;
		tmpB = 0x00;
		tmpC = 0x00;

	//Set the upper nibble of PINA and map it to the lower nibble of PORTB
		tmpB = tmpA >> 4;
	//Set the lower nibble of PINA and map it to the upper nibble of PORTC
		tmpC = tmpA << 4;
		
	// 3) Write output
		PORTC = tmpC;
		PORTB = tmpB;	
	}
	return 0;
}

