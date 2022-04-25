/**
* This program reads in text from a given input file that contains information about
* several types of vehicles and outputs the information in a formatted manner to a 
* given output file. The program will output certain specific information depending 
* on which type of vehicle is being input.
*
* CSC 3304 Programming project No 4
*
* @author Nicholas Caplette
* @since 3/29/22
*
*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "prog4_functions.h"

#define MAX_LENGTH 51

int main(int argc, char const *argv[]) {
	
	//Enumeration of the different types of vehicles
	enum vehicle {car, truck, boat};
	enum vehicle type;
	//File used to read in information from
	FILE* vehicleFile;
	//File used to output information to
	FILE* outFile;
	//String used to check which type of vehicle is being input
	char inStr[MAX_LENGTH];
	//String used to store the car's make
	char make[MAX_LENGTH];
	//String used to store the car's model
	char model[MAX_LENGTH];
	//Integer used to store the car's year
	int year;
	//String used to store the car's year for use in InputInteger
	char yearString[MAX_LENGTH];
	//String used to store the car's VIN
	char vin[MAX_LENGTH];
	//Integer used to store the car's number of doors
	int numDoors;
	//String used to store the car's number of doors for use in InputInteger
	char numDoorsString[MAX_LENGTH];
	//String used to store the car's rear configuration
	char rearConfig[MAX_LENGTH];
	//Double used to store the truck's towing capacity
	double towCap;
	//String used to store the truck's towing capacity for use in InputDouble
	char towCapString[MAX_LENGTH];
	//String used to store the boat's motor type
	char motorType[MAX_LENGTH];

	//Opens the input and output files
	vehicleFile = fopen("./TestInput.txt", "r");
	outFile = fopen("./out.txt", "w");

	//Checks to see if you are at the end of the file
	while(fgets(inStr, MAX_LENGTH, vehicleFile) != NULL) {

		//If statement tree used to see which type of vehicle is being read in
		if(!strcmp(inStr, "car\n")) {

			//If the read in string is "car", the type is set to car
			type = car;

		} else if(!strcmp(inStr, "truck\n")) {

			//If the read in string is "truck", the type is set to truck
			type = truck;

		} else if(!strcmp(inStr, "boat\n")) {

			//If the read in string is "boat", the type is set to boat
			type = boat;

		}

		switch(type) {

			case 0:
				//If the type is car, the car's make, model, year, VIN, number of doors, and rear configuration are read in
				//and stored in the appropriate variables. The car's information is then output to the output file in a 
				//formatted manner.
				InputCar(vehicleFile, MAX_LENGTH, make, model, &year, yearString, vin, &numDoors, 
				numDoorsString, rearConfig);
				OutputCar(outFile, make, model, year, vin, numDoors, rearConfig);
				break;

			case 1:
				//If the type is truck, the truck's make, model, year, VIN, number of doors, and towing capacity are read in 
				//and stored in the appropriate variables. The truck's information is then output to the output file in a 
				//formatted manner.
				InputTruck(vehicleFile, MAX_LENGTH, make, model, &year, yearString, vin, &numDoors, 
				numDoorsString, &towCap, towCapString);
				OutputTruck(outFile, make, model, year, vin, numDoors, towCap);
				break;

			case 2:
				//If the type is boat, the boat's make, model, year, VIN, and motor type are read in and stored in the
				//appropriate variables. The boat's information is then output to the output file in a formatted manner.
				InputBoat(vehicleFile, MAX_LENGTH, make, model, &year, yearString, vin, 
				motorType);
				OutputBoat(outFile, make, model, year, vin, motorType);
				break;

		}

	}

	//Closes the input and output files
	fclose(vehicleFile);
	fclose(outFile);

	return 0;
}
