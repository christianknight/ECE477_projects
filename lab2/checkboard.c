//	checkboard.c

//	Takes a .csv file with Tic Tac Toe board layout as the first argument 
//	and checks the state of the game, printing the result to another .csv if given
//	as the second argument, and printing to the command line otherwise.

//	Christian Knight, Nikko Noble
//	ECE 477 Lab 2 Part B
//	2/10/17

#include <stdio.h>
#include <string.h>
#include "ttt_func.h"

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;	// sets up objects for file stream I/O
	if (argc > 1)
 		fp1 = fopen(argv[1],"r");	// opens file stream to read from
 	else
 	{
 		printf("No file given, closing...\n");
 		return 0;	// close program if no file is gien
 	}
 	if (argc > 2)
 		fp2 = fopen(argv[2],"w+");	// opens file to write results to if given
 	else
 		fp2 = stdout;	// output to command line if no argument is given

 	const char *outcomes[5] = {"Board not legal", "Game in progress", "X wins", "O wins", "No winner"};	// strings printed to describe board
	char board[9];	// array to hold the trinary values for each board space
	char line[20];	// buffer to hold string read in from .csv
 	int gamestate;
 	while (fgets(line,sizeof(line),fp1) != NULL)	// read in .csv
 	{
    	if(sscanf(line, "%c,%c,%c,%c,%c,%c,%c,%c,%c", &board[0], &board[1], &board[2], &board[3], &board[4], &board[5], &board[6], &board[7], &board[8]) == 9);
    	{
			gamestate = 0;	// integer coresponding to state of game (1 = in progress, 2 = X win, 3 = O win, 4 = no winner)
			fprintf(fp2,"%c,%c,%c,%c,%c,%c,%c,%c,%c, ",board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8]);
       		gamestate = checkstate(board);	// analyze board and determine outcome
			fprintf(fp2, "%s\n",outcomes[gamestate]);	// write trinary representation of board to .csv file
    	}
 	}
 	fclose(fp1);	// close file streams
 	fclose(fp2);
 	return 0;

}
