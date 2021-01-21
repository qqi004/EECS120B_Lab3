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
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
	unsigned char tmpa = 0x00; // Temporary variable to hold the value of C

while(1) {
		// 1) Read input
		tmpa = PINA & 0x7F;
		tmpA = PINA & 0x0F;
		tmpC = 0x00;

// Set the light of C to express each fuel level:
	// fuel level: 13-15:
	if((tmpA>12)&&(tmpA<16)){
		tmpC = tmpC | 0x3F; // fuel level 13-15 -> PC5,PC4,PC3,PC2,PC1,PC0=1, fuel level > 4 -> PC6=0, 0x3E:0011 1111
	}	
	// fuel level: 10-12:
	else if((tmpA>9)&&(tmpA<13)){
		tmpC = tmpC | 0x3E; // fuel level 10-12 -> PC5,PC4,PC3,PC2,PC1=1, fuel level > 4 -> PC6=0, 0x3E:0011 1110
	}
	// fuel level: 7-9:
	else if((tmpA>6)&&(tmpA<10)){
		tmpC = tmpC | 0x3C; // fuel level 7-9 -> PC5,PC4,PC3,PC2=1, fuel level > 4 -> PC6=0, 0x3C:0011 1100
	}
	// fuel level: 5,6:
	else if((tmpA>4)&&(tmpA<7)){
		tmpC = tmpC | 0x38; // fuel level 5-6 -> PC5,PC4,PC3=1, fuel level > 4 -> PC6=0, 0x38:0011 1000
	}
	// fuel level: 3,4:
	else if((tmpA>2)&&(tmpA<5)){ 
		tmpC = tmpC | 0x70; // fuel level 3-4 -> PC5,PC4=1, fuel level <= 4 -> PC6=1, 0x70:0111 0000
	}
	// fuel level: 1,2:
	else if((tmpA>0)&&(tmpA<3)){ 
		tmpC = tmpC | 0x60;// // fuel level 1-2 -> PC5=1, fuel level <= 4 -> PC6=1, 0x60:0110 0000
	}
	else if(tmpA == 0x00){
		tmpC = tmpC | 0x40;// fuel level 0 -> PC5,PC4,PC3,PC2,PC1,PC0=0, fuel level <= 4 -> PC6=1, 0x40:0100 0000
	}


// Set the "Fasten Seatbelt" icon:
//	if(((tmpa & 0x30) == 0x30) && (tmpa & 0x40) != 0x40) {
//		tmpC = tmpC | 0x80;
//	}	
//		
	// 3) Write output
		PORTC = tmpC;	
	}
	return 0;
}

