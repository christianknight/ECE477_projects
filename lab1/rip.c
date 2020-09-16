//	rip.c

//	Prompts user for date of birth, calculates random date of death within 
//	100 years of birth. Prints tombstone with date of death in ASCII art.

//	Christian Knight, Nikko Noble
//	ECE 477 Lab 1 Part B
//	2/3/17

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	printf("Enter your birth year (yyyy): ");	// prompt user for DOB
	int dob;
	scanf("%d",&dob);	// store user's DOB as int
	srand(time(NULL));	// init for rand() function
	
	// print ASCII art for tombstone
    printf("_.---,._,' \n");
    printf("/' _.--.< \n");
    printf(" /'     `' \n");
    printf("/' _.---._____ \n");
    printf("\'   ___, .-'` \n");
    printf("   /'    /               . \n");
    printf(" /'       `-.          -|- \n");
    printf("|                       | \n");
    printf("|                   .-'~~~`-. \n");
    printf("|                 .'         `. \n");
    printf("|                 | %02d/%02d/%d| \n",(rand() %11)+1,(rand() %27)+1,dob+(rand() %100));
	printf("|                 |           | \n");
	printf("|                 |  R. I. P. | \n");
	printf(" \\               \\|           |/ \n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n");
	
	return 0;
}