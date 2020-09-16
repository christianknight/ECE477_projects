#define LED0 1<<DDB0
#define OUTPUT LED0

#define DOT 500	// time, in ms, to delay for 1 unit
#define DASH 1500 //time, in ms, to delay for 3 units



//A
if(input == (letters[0] || big_letters[0]))
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

//B
if(letters[1] || big_letters[1])
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

//C
if(letters[2]|| big_letters[2])
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
	
//D	
if(letters[3]|| big_letters[3])
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//E
if(letters[4]|| big_letters[4])
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//F
if(letters[5]|| big_letters[5])
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);	
	
//G
if(letters[6]|| big_letters[6])	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
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
		
//H
if(letters[7]|| big_letters[7])
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//I	
if(letters[8]|| big_letters[8])
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//J
if(letters[9]|| big_letters[9])
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
	
//K	
if(letters[10]|| big_letters[10])	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);	
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//L
if(letters[11]|| big_letters[11])
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//M 
if(letters[12]|| big_letters[12])
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//N	
if(letters[13]|| big_letters[13])	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//O
if(letters[14]|| big_letters[14])	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)		
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
	
//P
if(letters[15]|| big_letters[15])	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)		
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);	
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);
	
//Q
if(letters[16]|| big_letters[16])	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)		
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//R	
if(letters[17]|| big_letters[17])	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);	
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//S	
if(letters[18]|| big_letters[18])	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);	
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//T	
if(letters[19]|| big_letters[19])	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//U
if(letters[20]|| big_letters[20])	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//V
if(letters[21]|| big_letters[21])	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//W
if(letters[22]|| big_letters[22])	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//X
if(letters[23]|| big_letters[23])	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//Y
if(letters[24]|| big_letters[24])	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);

//Z
if(letters[25]|| big_letters[25])	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DASH
	PORTB |= OUTPUT;
	_delay_ms(DASH);
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT DOT or DASH
	PORTB &= ~OUTPUT;
	_delay_ms(DOT)	
	//ONE DOT
	PORTB |= OUTPUT;
	_delay_ms(DOT);		
	//NEXT LETTER
	PORTB &= ~OUTPUT;
	_delay_ms(DASH);


















	