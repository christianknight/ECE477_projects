//  partB.c

//	Sets up AVR as serial device and checks for input strings, flashing
//	the morse code representation of the strings on an LED.

//  Christian Knight, Nikko Noble
//  ECE 477 Lab 5
//  3/31/17

#define F_CPU 8000000  // 1 MHz CPU speed for delay function

#include <stdio.h>
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "VirtualSerial.h"

#define LED0 1<<DDB0
#define OUTPUT LED0

#define DOT 50	// time, in ms, to delay for a 1 unit morse code "dot"
#define DASH 150 //time, in ms, to delay for a 3 unit morse code "dash"

extern USB_ClassInfo_CDC_Device_t VirtualSerial_CDC_Interface;

#define CONNECTED (VirtualSerial_CDC_Interface.State.ControlLineStates.HostToDevice & CDC_CONTROL_LINE_OUT_DTR)

static FILE USBSerialStream;

void USB_check(void);
void USB_init(void);
void Morse(char input);

int main(void)  {

	USB_init(); // initialize serial over USB

	DDRB |= OUTPUT; // set all bits of port B as outputs (DDRB = 0xFF)
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
	fp=stdout;
	fpr=stdin;
	unsigned char input[20];// buffer for input string
	unsigned char value[5];	// buffer for desired LED value

	while(fscanf(fpr,"%s",&input)!=1) fscanf(fpr,"%*s");  // wait for input string
	int i=0;
	for (i = 0; i < strlen(input); i++)	{
		Morse(input[i]);
	}	
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

/* When the USB library throws a Configuration Changed event we need to call */
/* CDC_Device_ConfigureEndpoints                                                                    */
void EVENT_USB_Device_ConfigurationChanged(void)  {
	CDC_Device_ConfigureEndpoints(&VirtualSerial_CDC_Interface);
}

/* When we get a Control Request from the USB library we need to call         */
/* CDC_Device_ProcessControlRequest.                                                        */
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

void Morse(char input) {
	FILE *fp, *fpr;
	fp=stdout;
	fpr=stdin;

	char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char big_letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	//A
if((input == big_letters[0]) || (input == letters[0]))  {
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//B
else if((input == big_letters[1]) || (input == letters[1]))  {
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//C
else if((input == big_letters[2]) || (input == letters[2]))  {
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}	
//D	
else if((input == big_letters[3]) || (input == letters[3]))  {
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
 }
//E
else if((input == big_letters[4]) || (input == letters[4]))  {
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}

//F
else if((input == big_letters[5]) || (input == letters[5]))  {
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);	
	}
//G
else if((input == big_letters[6]) || (input == letters[6])) {
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
	}	
		
//H
else if((input == big_letters[7]) || (input == letters[7])) 
{
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}

//I	
else if((input == big_letters[8]) || (input == letters[8])) 
{
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}

//J
else if((input == big_letters[9]) || (input == letters[9])) 
{
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}	
//K	
else if((input == big_letters[10]) || (input == letters[10])) 	
{
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);	
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//L
else if((input == big_letters[11]) || (input == letters[11])) 
{
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//M 
else if((input == big_letters[12]) || (input == letters[12])) 
{
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//N	
else if((input == big_letters[13]) || (input == letters[13])) 	
{
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//O
else if((input == big_letters[14]) || (input == letters[14])) 
{
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);		
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//P
else if((input == big_letters[15]) || (input == letters[15])) 
{
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);		
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);	
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//Q
else if((input == big_letters[16]) || (input == letters[16])) 	
{
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);		
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//R	
else if((input == big_letters[17]) || (input == letters[17])) 
{
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);	
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//S	
else if((input == big_letters[18]) || (input == letters[18])) 
{
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);	
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//T	
else if((input == big_letters[19]) || (input == letters[19])) 
{
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//U
else if((input == big_letters[20]) || (input == letters[20])) 
{
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//V
else if((input == big_letters[21]) || (input == letters[21])) 
{
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//W
else if((input == big_letters[22]) || (input == letters[22])) 
{
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//X
else if((input == big_letters[23]) || (input == letters[23])) 	
{
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//Y
else if((input == big_letters[24]) || (input == letters[24])) 
{
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
//Z
else if((input == big_letters[25]) || (input == letters[25])) 
{
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT);	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
}
}


