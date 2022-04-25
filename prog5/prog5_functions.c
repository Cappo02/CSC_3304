#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "prog5_functions.h"

int RemoveEndingWhiteSpace(char givenString[]) {

	//Counter variable used to keep track of which index is being checked
	int i = 0;
	//Integer used store the last non-whitespace character's index
	int index = -1;

	while(givenString[i] != '\0') {
		
		if(givenString[i] != ' ' && givenString[i] != '\t' && givenString[i] != '\n') { 

			index = i;

		}

		i++;

	}

	givenString[index + 1] = '\0';

	return strlen(givenString);

}

void swap(char *string1, char *string2) {

	char temp[100];

	strcpy(temp, string1);
	strcpy(string1, string2);
	strcpy(string2, temp);


}

void bubbleSort(char **inStrings, int inStringsLen) {

	for(int i = 0; i < inStringsLen; i++) {

		for(int j = 0; j < inStringsLen - i; j++) {

			if(strcmp(inStrings[j], inStrings[j + 1]) > 0) {

				swap(inStrings[j], inStrings[j + 1]);

			}

		}

	}

}