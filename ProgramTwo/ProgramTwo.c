/* 
 * PES Project One Program Two source code implementation
 *	Tristan Duenas
 *	GCC C99 compiler
 */

#include "ProgramTwo.h"

int main(int argc, char *argv[])
{
	uint8_t ascii = atoi(argv[ASCII_CODE_ARGUMENT_NUMBER]);
	displayASCII(ascii);

	return 0;	
}

void displayASCII(uint8_t ascii)
{
	if (islower(ascii))
	{
		printf("Code:%d	Type: Lower Case	ASCII Char:%c\n", ascii, ascii);
	}
	else if (isupper(ascii))
	{
		printf("Code:%d	Type: Upper Case	ASCII Char:%c\n", ascii, ascii);
	}
	else if (isdigit(ascii))
	{
		printf("Code:%d   Type: Digit   ASCII Char:%c\n", ascii, ascii);
	}
	else if (isspace(ascii) || iscntrl(ascii))
	{
		if (isprint(ascii))
		{
			printf("Code:%d   Type: White Space   ASCII Char:%c\n", ascii, ascii);
		}
		else
		{
			printf("Code:%d   Type: White Space   ASCII Char:\n", ascii);
		}
	}
	else if (ispunct(ascii))
	{
		if (isprint(ascii))
		{
			printf("Code:%d   Type: Special Character   ASCII Char:%c\n", ascii, ascii);
		}
		else
		{
			printf("Code:%d   Type: Special Character   ASCII Char:\n", ascii);
		}
	}
	else
	{
		printf("Input code is not a valid ascii character.");
	}
}
