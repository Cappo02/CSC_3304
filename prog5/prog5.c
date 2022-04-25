#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "prog5_functions.h"

#define MAX_LENGTH 100

int main(int argc, char const *argv[]) {
	
	int index, inStringsLen;
	char **inStrings;
	char bufStr[MAX_LENGTH];
	int bufStrLen;
	FILE* inFile;
	FILE* outFile;

	inFile = fopen("./TestInput.txt", "r");
	outFile = fopen("./out.txt", "w");
	index = 0;
	inStringsLen = 10;
	inStrings = (char **) malloc(sizeof(char*) * inStringsLen);

	while(fgets(bufStr, MAX_LENGTH, inFile) != NULL) {

		if(index == inStringsLen) {

			inStringsLen += 10;
			inStrings = (char **) realloc(inStrings, sizeof(char *) * inStringsLen);

		}

		bufStrLen = RemoveEndingWhiteSpace(bufStr);
		inStrings[index] = (char *) malloc(sizeof(char) * bufStrLen);
		strcpy(inStrings[index], bufStr);
		index++;

	}

	bubbleSort(inStrings, index - 1);

	for (int i = 0; i < index; i++) {
    	fprintf(outFile, "%s\n", inStrings[i]);
	}

	for(int i = 0; i <= index; i++) {

		free(inStrings[i]);

	}

	free(inStrings);

	fclose(inFile);
	fclose(outFile);

	return 0;

}
