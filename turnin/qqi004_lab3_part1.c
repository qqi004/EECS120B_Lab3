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
	DDRB = 0x00; PORTB = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpC = 0x00; // Temporary variable to hold the value of C

while(1) {
		// 1) Read input
		tmpA = PINA & 0xFF;
		tmpB = PINB & 0xFF;
		tmpC = 0x00;

// count the number of 1's in A and B:

		for (int i=0; i<8; i++){
			if((tmpA&0x01)==0x01){
				tmpC = tmpC +1;
				tmpA = tmpA>>1;
			}
			else{		
				tmpA = tmpA>>1;
			}
		}

		for (int i=0; i<8; i++){
			if((tmpB&0x01)==0x01){
				tmpC = tmpC +1;
				tmpB = tmpB>>1;
			}
			else{		
				tmpB = tmpB>>1;
			}
		}
		

		
	// 3) Write output
		PORTC = tmpC;	
	}
	return 0;
}

