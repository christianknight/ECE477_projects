//  timer_func.c

//  Required functions for interfacing with 8253 timer.

//  Christian Knight, Nikko Noble
//  ECE 477 Lab 3
//  2/24/17

#include <stdio.h>
#include <sys/io.h>

// get value of port
int inp(int port)
{	
	int val;
    if(ioperm(port,1,1) != 0) { // get I/O permissions
    	perror("ioperm"); 
    	return(-1);
    }
    val=inb(port);  // read port
    return(val);    // return port value
}

// set value to port
int outp(int port, int val)
{
    if(ioperm(port,1,1) != 0) { // get I/O permissions
    	perror("ioperm");
    	return(-1);
    }
    outb(val,port);     // write given value to port
    return(0);
}