//	partA.c

//	Enables or disables LEDs connected to output pins configured on port B 
//	on the AT90USB162 based on switches connected to input pins configured on port B.

//	Christian Knight, Nikko Noble
//	ECE 477 Lab 4
//	3/3/17

#include <stdio.h>
#include <avr/io.h>
#include <stdlib.h>

#define INPUTS ((1<<DDB7)|(1<<DDB6)|(1<<DDB5)|(1<<DDB4))
#define OUTPUTS ((1<<DDB3)|(1<<DDB2)|(1<<DDB1)|(1<<DDB0))

void main(void){
	unsigned char LEDVALUE;	// 4 bit value corresponding to LEDs on or off

	// set lower 4 bits of port B as outputs, and the upper 4 as inputs (DDRB = 0x0F)
	DDRB |= OUTPUTS;
	DDRB &= ~INPUTS;
	
	// set input bits of port B as pull-up (PORTB |= 0xF0)
	PORTB |= INPUTS;

	while(1){
		LEDVALUE = (PINB & INPUTS) >> 4; // get LEDVALUE based on which switches are on
		PORTB |= (LEDVALUE & OUTPUTS);	 // set LEDs that need to be on
		PORTB &= ~(LEDVALUE & OUTPUTS);	 // clear LEDs that need to be off
	}
}