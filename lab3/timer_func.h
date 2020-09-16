//  timer_func.h

//  Required function prototypes for interfacing with 8253 timer.

//  Christian Knight, Nikko Noble
//  ECE 477 Lab 3
//  2/24/17

int inp(int port);              // get value of port
int outp(int port, int val);    // set value to port
