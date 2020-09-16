//  partA.c

//	Sets up AVR as serial device and checks/sets state of connected switches or LEDs,
//	accepting input and returning results to/from a serial terminal.

//	USB serial code courtesy of LUFA library & Bruce Segee.

//  Christian Knight, Nikko Noble
//  ECE 477 Lab 5
//  3/31/17

#include <stdio.h>
#include <avr/io.h>
#include <stdlib.h>
#include "VirtualSerial.h"

#define LED0 1<<DDB0  
#define LED1 1<<DDB1
#define LED2 1<<DDB2
#define LED3 1<<DDB3
#define LED4 1<<DDB4
#define LED5 1<<DDB5
#define LED6 1<<DDB6
#define LED7 1<<DDB7

#define SW0 1<<DDD0
#define SW1 1<<DDD1
#define SW2 1<<DDD2
#define SW3 1<<DDD3
#define SW4 1<<DDC4
#define SW5 1<<DDC5
#define SW6 1<<DDC6
#define SW7 1<<DDC7

#define INPUTS_C (SW4|SW5|SW6|SW7)
#define INPUTS_D (SW0|SW1|SW2|SW3)
#define OUTPUTS (LED0|LED1|LED2|LED3|LED4|LED5|LED6|LED7)

extern USB_ClassInfo_CDC_Device_t VirtualSerial_CDC_Interface;

#define CONNECTED (VirtualSerial_CDC_Interface.State.ControlLineStates.HostToDevice & CDC_CONTROL_LINE_OUT_DTR)

static FILE USBSerialStream;

void USB_check(void);
void USB_init(void);

int main(void)  {
	USB_init(); // initialize serial over USB

	DDRB |= OUTPUTS;	// set all bits of port B as outputs (DDRB = 0xFF)
	// set correct bits of ports C and D as inputs (DDRC = 0x0X, DDRD = 0xX0)
	DDRC &= ~INPUTS_C;
	DDRD &= ~INPUTS_D;
	// set inputs of ports C and D as pull-up (PORTC = 0xFX, PORTD = 0xXF)
	PORTC |= INPUTS_C;
	PORTD |= INPUTS_D;

	while(1)  {
		while(!CONNECTED) {	// do nessisary tasks to connect serial over USB
			CDC_Device_USBTask(&VirtualSerial_CDC_Interface);
			USB_USBTask();
		}
		USB_check();  // continuously monitor serial for I/O
	}
}

void USB_check(void)  {
	FILE *fp, *fpr;

	unsigned char input[10] = {0,0,0,0,0,0,0,0,0,0};	// buffer for input string
	unsigned char value[5];	// buffer for desired LED value
	unsigned char LED_VAL;	// value corresponding to LEDs on or off
	unsigned char SW_VAL_C;	// value corresponding to port C switches on or off
	unsigned char SW_VAL_D;	// value corresponding to port D switches on or off

	fp=stdout;
	fpr=stdin;

	while(fscanf(fpr,"%s",&input) != 1) fscanf(fpr,"%*s");  // wait for input string

	if ((input[0] == 'L') || (input[0] == 'l')) {	// check if LEDs were specified
		if (input[1] == '?')  {
			if (input[2] == '\0')	{
				LED_VAL = (PINB & OUTPUTS); // get LED_VAL based on which LEDs from port B are on
				fprintf(fp,"\r0x%02X\r\n",LED_VAL);	// print to serial which LEDs are enabled
			}
			else fprintf(fp,"\rWrong usage!!!\r\n");	// give error message
		}
	    else if ((input[1] == '0') && (input[2] == 'x') && ((input[4] == '\0') || (input[5] == '\0'))) {	// input given as hex
    		for (int i = 0; i < 3; i++) {   // remove leading 'L0x' from input string
	  			value[i]=input[i+3];
	  		}	// 'value[]' is now a string with hex value
	  		LED_VAL = (unsigned char)strtol(value, NULL, 16);	// convert hex string to decimal
	  		PORTB &= ~OUTPUTS;  // clear all LEDs
	  		PORTB |= (LED_VAL & OUTPUTS);   // set LEDs that need to be on
	  		fprintf(fp,"\r0x%02X\r\n",LED_VAL);	// print back to serial which LEDs are enabled
	  	}
	  	else if ((input[1] == '0') && ((input[3] == '\0') || (input[4] == '\0') || (input[5] == '\0')))	{	// input given as octal
	  		for (int i = 0; i < 3; i++) {   // remove leading 'L0' from input string
	  			value[i]=input[i+2];
	  		}	// 'value[]' is now a string with octal value
	  		LED_VAL = (unsigned char)strtol(value, NULL, 8);	// convert octal string to decimal
	  		PORTB &= ~OUTPUTS;  // clear all LEDs
	  		PORTB |= (LED_VAL & OUTPUTS);   // set LEDs that need to be on
	  		fprintf(fp,"\r0x%02X\r\n",LED_VAL);	// print back to serial which LEDs are enabled
	  	}
	    else if (isdigit(input[1]) && (isdigit(input[2]) || (input[2] == '\0')) && (isdigit(input[3]) || (input[3] == '\0')) || (input[4] == '\0'))	{
		  	for (int i = 0; i < 4; i++) {	// remove leading 'L' from input string
		  		value[i]=input[i+1];
	      	}	// 'value[]' is now a string with decimal value
	      	LED_VAL = (unsigned char)strtol(value, NULL, 10);	// convert decimal string to decimal
	      	PORTB &= ~OUTPUTS;  // clear all LEDs
	      	PORTB |= (LED_VAL & OUTPUTS);   // set LEDs that need to be on
	      	fprintf(fp,"\r0x%02X\r\n",LED_VAL);	// print back to serial which LEDs are enabled
	    }
	    else fprintf(fp,"\rWrong usage!!!\r\n");	// give error message
	}

    else if (((input[0] == 'S') || (input[0] == 's')) && (input[1] == '?') && (input[2] == '\0'))  {	// check if switches were specified
	    SW_VAL_C = (PINC & INPUTS_C);	// get switch values from ports C
	    SW_VAL_D = (PIND & INPUTS_D);	// get switch values from ports D
	    fprintf(fp,"\r0x%02X\r\n", SW_VAL_C | SW_VAL_D);	// print back to serial which switches are enabled
	}

	else fprintf(fp,"\rWrong usage!!!\r\n");	// give error message
}

void USB_init(void) {
	wdt_disable();     //Make sure the Watchdog doesn't reset us
	USB_Init();  // Lufa library call to initialize USB
	/* Create a stream for the interface */
	CDC_Device_CreateBlockingStream(&VirtualSerial_CDC_Interface,&USBSerialStream);
	stdin=&USBSerialStream;  //By setting stdin and stdout to point to the stream we
	stdout=&USBSerialStream; //can use regular printf and scanf calls
	GlobalInterruptEnable();      // interrupts need to be enabled
}

/* When the USB library throws a Configuration Changed event we need to calls */
/* CDC_Device_ConfigureEndpoints */
void EVENT_USB_Device_ConfigurationChanged(void)  {
	CDC_Device_ConfigureEndpoints(&VirtualSerial_CDC_Interface);
}

/* When we get a Control Request from the USB library we need to call */
/* CDC_Device_ProcessControlRequest. */
void EVENT_USB_Device_ControlRequest(void)  {
	CDC_Device_ProcessControlRequest(&VirtualSerial_CDC_Interface);
}

USB_ClassInfo_CDC_Device_t VirtualSerial_CDC_Interface =  {
  .Config = {
    .ControlInterfaceNumber   = INTERFACE_ID_CDC_CCI,
    .DataINEndpoint           = {
      .Address          = CDC_TX_EPADDR,
      .Size             = CDC_TXRX_EPSIZE,
      .Banks            = 1,
    },
    .DataOUTEndpoint =  {
      .Address          = CDC_RX_EPADDR,
      .Size             = CDC_TXRX_EPSIZE,
      .Banks            = 1,
    },
    .NotificationEndpoint = {
      .Address          = CDC_NOTIFICATION_EPADDR,
      .Size             = CDC_NOTIFICATION_EPSIZE,
      .Banks            = 1,
    },
  },
};
