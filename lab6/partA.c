//  partA.c

//	Sets up AVR as serial device and detects IR remote signals, sending over serial
//	the length of each burst and gap.

//	USB serial code courtesy of LUFA library & Bruce Segee.

//  Christian Knight, Nikko Noble
//  ECE 477 Lab 6
//  4/21/17

#include <stdio.h>
#include <avr/io.h>
#include <stdlib.h>
#include "VirtualSerial.h"

#define CONNECTED (VirtualSerial_CDC_Interface.State.ControlLineStates.HostToDevice & CDC_CONTROL_LINE_OUT_DTR)

#define TIMER TCNT1
#define IR_PULSE (!(PINC & (1<<PC7)))
#define GOT_PULSE (!(!(TIFR1 & (1<< ICF1))))
#define CLEAR_PULSE (TIFR1 |= (1<<ICF1))

void USB_init(void);
void timer_init(void);
void wait_for_connect(void);
void USB_run(void);
void echo_LED(void);
char measure_dark(void);
void measure_burst(void);

extern USB_ClassInfo_CDC_Device_t VirtualSerial_CDC_Interface;
static FILE USBSerialStream;

volatile int dark_gap,last_pulse_time,count;
int arr[150];	// buffer to store times of pulses and gaps

int main(void)  {
	char flag;	// indicates when an input sequence has ended
	int i;		// indexing variable

	USB_init(); 	// initialize serial over USB
	timer_init();	// initialize timer 1

	wait_for_connect();	// wait for serial connection over USB

	while(1)  {
		for(i = 0; i < 5000; i++)	{
			USB_run();	// send serial data over USB
			echo_LED();	// update LEDs to reflect IR status
		}
		printf("Starting...\n\r");
		for(i = 0; i < 5000; i++)	{
			USB_run();	// send serial data over USB
			echo_LED();	// update LEDs to reflect IR status
		}
		i = 0;
		flag = 0;
		while(!flag)	{
			while(!measure_dark()) echo_LED();
			measure_burst();
			arr[i++] = last_pulse_time;
			flag = !measure_dark();
			arr[i++] = dark_gap;
			if(i > 148) break;	// leave loop if buffer is filled
		}
		USB_run();	// send serial data over USB
		printf("Done!\n\r");
		USB_run();	// send serial data over USB
		printf("Index is %d\n\r",i);
		for(count = 0; count < i; count++)	{
			printf("%d:%d\n\r",count,arr[count]);
			printf("Starting again...\n\r");
			USB_run();	// send serial data over USB
		}
	}
}

void timer_init(void)	{
	TCCR1B = 1;			// set prescaler to 1, capture edge to falling
	DDRC &= ~(1<<PC7);  // set pin PC7 to input (for phototransistor)
	PORTC |= 1<<PC7;	// enable pullup on PC7
	DDRD |= (1<<PD6) | (1<<PD4);	// set pins PD6 and PD4 to output (for board LEDs)
	if(IR_PULSE) PORTD |= 1<<PD6;	// set LED on PD6 if an IR pulse is present
	else PORTD &= ~(1<<PD6);		// clear LED on PD6 if no IR pulse is present
	// while(1)	{
	// 	if(TIMER & 0x8000)	{
	// 		PORTD |= (1<<PD6);
	// 		PORTD &= ~(1<<PD4);
	// 	}
	// 	else	{
	// 		PORTD &= ~(1<<PD6);
	// 		PORTD |= (1<<PD4);
	// 	}
	// }
}

void echo_LED(void)	{	// updates LEDs to reflect IR status
	if(IR_PULSE)	{
		PORTD |= 1<<PD6;	// set LED on PD6 if IR pulse is present
		PORTD &= ~(1<<PD4);	// clear LED on PD4 if IR pulse is present
	}
	else	{
		PORTD &= ~(1<<PD6);	// clear LED on PD6 if no IR pulse is present
		PORTD |= 1<<PD4;  	// set LED on PD4 if no IR pulse is present
	}
}

char measure_dark(void)	{
	int temp;
	temp = TIMER;	// store current timer value
	/* wait for pulse of until 4ms (a gap that long means over) */
	while(!(GOT_PULSE) && ( !(temp & 0x7000)))
	while(!(IR_PULSE) && (!(temp & 0x4000)))	{
		USB_run();	// send serial data over USB
		temp = TIMER;	// store current timer value
	}
	dark_gap = temp;	// get timer value when pulse started
	TIMER = 0;
	TIMER = 0;
	last_pulse_time = 0;  // start of pulse train
	CLEAR_PULSE;
	return(dark_gap < 0x3FFF);    // return false if pattern is over
}

void measure_burst()	{
	int temp;
	char was_IR_PULSE;
	was_IR_PULSE = 1;
	count = 1;

	temp = TIMER;
	temp -=  last_pulse_time;
	if(temp > 100)	{
		PORTD = 0xFF;
		while(1);
	}
	while(temp < 50)	{ // a gap of 50 microseconds means no pulse is coming
		echo_LED();	// update LEDs to reflect IR status
		// if(GOT_PULSE)
		if(IR_PULSE)	{  
			// last_pulse_time = ICR1;
			last_pulse_time = TIMER;
			if(!was_IR_PULSE) count++;
			CLEAR_PULSE;
		}
		temp = TIMER;
		temp -= last_pulse_time;
		was_IR_PULSE = IR_PULSE;
	}
	count++;
	TIMER = 50;  //when we get here we are 50 microseconds into the gap
}

void USB_init(void) {
	wdt_disable();     // Make sure the Watchdog doesn't reset us
	USB_Init();  // Lufa library call to initialize USB
	/* Create a stream for the interface */
	CDC_Device_CreateBlockingStream(&VirtualSerial_CDC_Interface,&USBSerialStream);
	stdin=&USBSerialStream;  // By setting stdin and stdout to point to the stream we
	stdout=&USBSerialStream; // can use regular printf and scanf calls
	GlobalInterruptEnable();      // interrupts need to be enabled
}

void wait_for_connect(void)	{	// does nessisary tasks to connect serial over USB
	while(!CONNECTED) {
		USB_run();	// send serial data over USB
		echo_LED();	// update LEDs to reflect IR status
	}
}

void USB_run(void)	{	// sends serial data over USB
	CDC_Device_USBTask(&VirtualSerial_CDC_Interface);
	USB_USBTask();
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
