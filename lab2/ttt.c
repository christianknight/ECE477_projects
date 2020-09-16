//	TTT.c

//	Identifies all leagal tic tac toe boards and prints them into a .csv file.
//	Takes filename as argument ("XXXX.csv"), or prints to command line if no argument
//	is given.

//	Christian Knight, Nikko Noble
//	ECE 477 Lab 2
//	2/10/17

#include <stdio.h>
#include "ttt_func.h"

int main(int argc, char *argv[])
{
	FILE *fp;	// sets up object for file stream
	if (argc > 1)
 		fp = fopen(argv[1],"w+");	// opens file stream with given filename from input argument
 	else
 		fp = stdout;	// output to command line if no argument is given

	const char *outcomes[4] = {"Game in Progress", "X wins", "O wins", "No winner"};	// strings printed to describe board
 	int gamestate;	// integer to hold value corresponding to outcome
 	char board[9];	// array to hold the trinary values for each board space
	for (int i = 0; i < 19683; i++)	// loop through all possible board combinations
	{
		gamestate = 0;	// integer coresponding to state of game (1 = in progress, 2 = X win, 3 = O win, 4 = no winner)
		dec2tri(i, board);	// convert unique board combination to trinary representation
       	gamestate = checkstate(board);	// analyze board and determine outcome
		if (gamestate != 0)	// if the board is legal, print to output with outcome
			fprintf(fp,"%c,%c,%c,%c,%c,%c,%c,%c,%c,%d,%s \n",board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8],gamestate,outcomes[gamestate-1]);	// write trinary representation of legal board to .csv file
	}
	fclose(fp);	// closes file stream
	return 0;
}
