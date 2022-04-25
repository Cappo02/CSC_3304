/**
 * Implementation of "prog6_functions.h" functions
 * 
 * @author Nicholas Caplette
 * @since 3/29/22
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "prog6_functions.h"

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

void InputString(FILE* inFile, char inString[], int maxLength) {

	fgets(inString, maxLength, inFile);
	RemoveEndingWhiteSpace(inString);

}

int InputInteger(FILE* inFile, char inIntString[], int maxLength) {

	fgets(inIntString, maxLength, inFile);
	RemoveEndingWhiteSpace(inIntString);

	return atoi(inIntString);

}

float InputFloat(FILE* inFile, char inFloatString[], int maxLength) {

	fgets(inFloatString, maxLength, inFile);
	RemoveEndingWhiteSpace(inFloatString);

	return atof(inFloatString);

}

void InputCar(FILE* inFile, int maxLength, char make[], char model[], int* year, char yearString[],
char vin[], int* numDoors, char numDoorsString[], char rearConfig[]) {

	InputString(inFile, make, maxLength);
	InputString(inFile, model, maxLength);
	*year = InputInteger(inFile, yearString, maxLength);
	InputString(inFile, vin, maxLength);
	*numDoors = InputInteger(inFile, numDoorsString, maxLength);
	InputString(inFile, rearConfig, maxLength);

}

void InputTruck(FILE* inFile, int maxLength, char make[], char model[], int* year, char yearString[],
char vin[], int* numDoors, char numDoorsString[], double* towCap, char towCapString[]) {

	InputString(inFile, make, maxLength);
	InputString(inFile, model, maxLength);
	*year = InputInteger(inFile, yearString, maxLength);
	InputString(inFile, vin, maxLength);
	*numDoors = InputInteger(inFile, numDoorsString, maxLength);
	*towCap = InputFloat(inFile, towCapString, maxLength);


}

void InputBoat(FILE* inFile, int maxLength, char make[], char model[], int* year, char yearString[], 
char vin[], char motorType[]) {

	InputString(inFile, make, maxLength);
	InputString(inFile, model, maxLength);
	*year = InputInteger(inFile, yearString, maxLength);
	InputString(inFile, vin, maxLength);
	InputString(inFile, motorType, maxLength);

}

void OutputCar(FILE* outFile, char make[], char model[], int year, char vin[], int numDoors, char rearConfig[]) {

	fprintf(outFile, "%d %s %s\n", year, make, model);
	fprintf(outFile, "VIN: %s\n", vin);
	fprintf(outFile, "Doors: %d\n", numDoors);
	fprintf(outFile, "Rear Configuration: %s\n\n", rearConfig);

}

void OutputTruck(FILE* outFile, char make[], char model[], int year, char vin[], int numDoors, double towCap) {

	fprintf(outFile, "%d %s %s\n", year, make, model);
	fprintf(outFile, "VIN: %s\n", vin);
	fprintf(outFile, "Doors: %d\n", numDoors);
	fprintf(outFile, "Max Towing Capacity: %.1lf\n\n", towCap);

}

void OutputBoat(FILE* outFile, char make[], char model[], int year, char vin[], char motorType[]) {

	fprintf(outFile, "%d %s %s\n", year, make, model);
	fprintf(outFile, "VIN: %s\n", vin);
	fprintf(outFile, "Motor: %s\n\n", motorType);

}

void swap(VehicleTypes *veh1, VehicleTypes *veh2) {

	VehicleTypes temp;

	temp = *veh1;
	*veh1 = *veh2;
	*veh2 = temp;

}

void bubbleSort(VehicleTypes **vehList, int vehListLen) {

	for(int i = 0; i < vehListLen; i++) {

		for(int j = 0; j < vehListLen - i; j++) {
			
			if(vehList[j]->year > vehList[j + 1]->year) {

				swap(vehList[j], vehList[j + 1]);

			}

		}

	}

}