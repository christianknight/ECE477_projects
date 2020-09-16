//	partB.c

//	Displays 4 distinct illumination patterns on 9 LEDs connected to pins 
//	on ports B and C of the AT90USB162 microcontroller based on positions 
//	of the input switches on pins of port B.

//	Christian Knight, Nikko Noble
//	ECE 477 Lab 4
//	3/3/17

#define F_CPU 1000000UL  // 1 MHz CPU speed for delay function

#include <stdio.h>
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

// positions of each LED
#define LED0 1<<DDB0
#define LED1 1<<DDB1
#define LED2 1<<DDB2
#define LED3 1<<DDB3
#define LED4 1<<DDC2
#define LED5 1<<DDC4
#define LED6 1<<DDC5
#define LED7 1<<DDC6
#define LED8 1<<DDC7

#define INPUTS ((1<<DDB7)|(1<<DDB6)|(1<<DDB5)|(1<<DDB4))
#define C_OUTPUTS (LED8|LED7|LED6|LED5|LED4)
#define B_OUTPUTS (LED3|LED2|LED1|LED0)

#define DELAY 150	// time, in ms, to delay

void toggleLED (unsigned char LED, char PORT); // toggles given LED on given PORT
void setLED (unsigned char LED, char PORT); // sets given LED on given PORT
void clearLED (unsigned char LED, char PORT); // clears given LED on given PORT

void main(void){
	unsigned char LEDVALUE;	// 4 bit value corresponding to LEDs on or off

	// set lower 4 bits of port B as outputs, and the upper 4 as inputs (DDRB = 0x0F)
	DDRB |= B_OUTPUTS;
	DDRB &= ~INPUTS;

	// set available bits of port C as outputs
	DDRC |= C_OUTPUTS;

	// set input bits of port B as pull-up (PORTB |= 0xF0)
	PORTB |= INPUTS;

	int i;	// just for indexing

	// array containing LED positions
	unsigned char LED[9] = {LED0,LED1,LED2,LED3,LED4,LED5,LED6,LED7,LED8};

	while(1){
		LEDVALUE = (PINB & INPUTS) >> 4; // get LEDVALUE based on which switch is on

		// no LEDs on
		if (LEDVALUE == 0) {
			PORTB &= ~B_OUTPUTS;
			PORTC &= ~C_OUTPUTS;
		}

		// all LEDs on
		else if (LEDVALUE == 1)	{
			PORTB |= B_OUTPUTS;
			PORTC |= C_OUTPUTS;
		}

		// one LED on at a time, right to left
		else if (LEDVALUE == 2){
			for (i = 0; i < 4; i++) {
				toggleLED(LED[i],'B');
				_delay_ms(DELAY);
				toggleLED(LED[i],'B');
				_delay_ms(DELAY);
			}
			for (i = 4; i < 9; i++) {
				toggleLED(LED[i],'C');
				_delay_ms(DELAY);
				toggleLED(LED[i],'C');
				_delay_ms(DELAY);
			}
		}

		// toggle each LED one at a time, right to left
		else if (LEDVALUE == 4){
			for (i = 0; i < 4; i++) {
				toggleLED(LED[i],'B');
				_delay_ms(DELAY);
			}
			for (i = 4; i < 9; i++) {
				toggleLED(LED[i],'C');
				_delay_ms(DELAY);
			}
		}

		// K.I.T.T. from Knight Rider (right to left to right)
		else if (LEDVALUE == 8){
			toggleLED(LED[0],'B');
			for (i = 1; i < 4; i++) {
				toggleLED(LED[i],'B');
				toggleLED(LED[i-1],'B');
				_delay_ms(DELAY);
			}
			toggleLED(LED[3],'B');
			toggleLED(LED[4],'C');
			_delay_ms(DELAY);
			for (i = 5; i < 9; i++) {
				toggleLED(LED[i],'C');
				toggleLED(LED[i-1],'C');
				_delay_ms(DELAY);
			}
			for (i = 8; i > 4; i--) {
				toggleLED(LED[i-1],'C');
				toggleLED(LED[i],'C');
				_delay_ms(DELAY);
			}
			toggleLED(LED[3],'B');
			toggleLED(LED[4],'C');
			_delay_ms(DELAY);
			for (i = 3; i > 0; i--) {
				toggleLED(LED[i-1],'B');
				toggleLED(LED[i],'B');
				_delay_ms(DELAY);
			}
			toggleLED(LED[0],'B');
		}
	}
}

void toggleLED (unsigned char LED, char PORT)	{
	if (PORT == 'B')
		PORTB ^= LED;
	else if (PORT == 'C')
		PORTC ^= LED;
}
