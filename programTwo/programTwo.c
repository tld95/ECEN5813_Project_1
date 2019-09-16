#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

void displayASCII(uint8_t ascii);

int main(int argc, char *argv[])
{
	uint8_t ascii = atoi(argv[1]);
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
