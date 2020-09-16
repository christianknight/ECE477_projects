void dec2tri(int dec, char* board);	// function declaration to convert decimal to trinary (base 3) & store result in board array
int checkwin(char c, char* board);	// checks whether there is a winning board combination for either 'X' or 'O', given as argument. Returns 1 if win is found
int checkstate(char* board);	// checks what the current state of the board is

const char base_digits[3] = {' ','X','O'};	// trinary digits for tic tac toe

void dec2tri(int dec, char* board)	// converts decimal given as argument to trinary and stores result in board array
{
	int num_to_convert = dec;
	int converted_num[9];
	for (int index = 0; index < 9; index++)
	{
	 	converted_num[index] = num_to_convert % 3;
	 	board[8-index] = base_digits[converted_num[index]];
		num_to_convert = num_to_convert / 3;
	}
}

int checkwin(char c, char* board)
{
	if (((board[0] == board[1]) && (board[0] == board[2]) && (board[0] == c)) ||
			((board[3] == board[4]) && (board[3] == board[5]) && (board[3] == c)) ||
			((board[6] == board[7]) && (board[6] == board[8]) && (board[6] == c)) ||
			((board[0] == board[3]) && (board[0] == board[6]) && (board[0] == c)) ||
			((board[1] == board[4]) && (board[1] == board[7]) && (board[1] == c)) ||
			((board[2] == board[5]) && (board[2] == board[8]) && (board[2] == c)) ||
			((board[0] == board[4]) && (board[0] == board[8]) && (board[0] == c)) ||
			((board[2] == board[4]) && (board[2] == board[6]) && (board[2] == c)))
		return 1;
	else 
		return 0;
}

int checkstate(char* board)
{
	int Xcount, Ocount, emptycount, gamestate;
	Xcount = Ocount = emptycount = gamestate = 0;
	for (int i = 0; i < 9; i++)	// count repeated X's & O's on board
	{
		if (board[i] == 'X')	// count X's on board
			Xcount++;	
		else if (board[i] == 'O')	// count O's on board
			Ocount++;
		emptycount = 9 - Xcount - Ocount;
	}
	if (((Xcount == Ocount) || (Xcount == Ocount + 1)))	// check if number of X's & O's makes sense
	{
		if (checkwin('X',board) && (checkwin('O',board) == 0) && (Xcount == Ocount + 1))
			gamestate = 2;
		else if (checkwin('O',board) && (checkwin('X',board) == 0) && (Xcount == Ocount))
			gamestate = 3;
		else if ((emptycount == 0) && (gamestate == 0) && (checkwin('X',board) == 0) && (checkwin('O',board) == 0))	// check if there's no winner
			gamestate = 4;
		else if ((emptycount != 0) && (gamestate == 0) && (checkwin('X',board) == 0) && (checkwin('O',board) == 0))	// check if game is still in progress
			gamestate = 1;
	}
	return gamestate;
}
