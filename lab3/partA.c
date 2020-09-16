//	partA.c

//	Measures time using channel 2 of the 8253 timer. Tests the accuracy of the usleep() function by
//	comparing expected versus actual delay for delays ranging from 1 microsecond to 2000 microseconds. 
//	Logs the expected and actual delays to a .csv file.

//	Christian Knight, Nikko Noble
//	ECE 477 Lab 3
//	2/24/17

#include <stdio.h>
#include <unistd.h>
#include "timer_func.h"

int main(void)
{
	int reg_init;			// starting 0x61 register value
	int counter = 0x0000;	// starting timer value
	double us;	// calculated time, in microseconds
	int i, j;	// just some indexing variables

	FILE *fp = fopen("partA.csv", "w+");		// open file 'partA.csv' to log measured time
	if (fp == NULL) {
		puts("Couldn't open \"partA.csv\"");	// error check for file read
		return 1;
	}

	fprintf(fp, "Expected delay, Actual delay\n");	// column labels for .csv

	for (i = 1; i <= 2000; i++) {			// delay values to test from 1 to 2000 microseconds
		for (j = 0; j < 10; j++) {			// take 10 measurements for each delay value
			reg_init = inp(0x61);			// read the current value from register 0x61
			outp(0x61, reg_init & (~0x01));	// clear the LSB of reg. 0x61 to disable counter
			outp(0x43, 0xB4);				// set channel 2 timer control byte to mode 2 (counting down)
			outp(0x42, 0xFF);				// set lower timer byte high
			outp(0x42, 0xFF);				// set upper timer byte high
			outp(0x61, reg_init | 0x01);	// set the LSB of reg. 0x61 to enable counter

			usleep(i);		// wait 'i' microseconds

			outp(0x61, reg_init & (~0x01));		// stop the counter

			counter = inp(0x42);					// read lower byte of counter reg.
			counter = ((inp(0x42) << 8) | counter);	// read upper byte of counter reg.

			counter = 0xFFFF - counter;	 // calculate number of ticks during elapsed time

			us = counter / 1.19;	// calculate time from number of ticks based on counter frequency
			fprintf(fp, "%d, %lf\n", i, us);	// output expectd and acutal elapsed time to file
		}
	}
	fclose(fp);	// close file
	return 0;
}
