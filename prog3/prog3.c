/**
* This program computes the volume (in liters) of a six-pack of
* soda cans and the total volume of a six-pack of a two-liter
* bottle.
*
* CSC 3304 Programming project No 1
*
* @author Nichoals Caplette
* @since 3/5/2022
*
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	enum vehicle {car, truck, boat};
	enum vehicle type;
	char inStr[51];
	FILE* vehicleFile;
	FILE* outFile;
	char make[51];
	char model[51];
	int year;
	char yearString[51];
	char vin[51];
	int numDoors;
	char numDoorsString[51];
	char rearConfig[51];
	double towCap;
	char towCapString[51];
	char motorType[51];

	vehicleFile = fopen("./TestInput.txt", "r");
	outFile = fopen("./out.txt", "w");

	while(fgets(inStr, 50, vehicleFile) != NULL) {
		
		if(!strcmp(inStr, "car\n")) {
			type = car;
		} else if(!strcmp(inStr, "truck\n")) {
			type = truck;
		} else {
			type = boat;
		}

		fgets(make, 51, vehicleFile);
		make[strlen(make) - 1] = '\0';
		fgets(model, 51, vehicleFile);
		model[strlen(model) - 1] = '\0';
		fgets(yearString, 51, vehicleFile);
		year = atoi(yearString);
		fgets(vin, 51, vehicleFile);
		vin[strlen(vin) - 1] = '\0';

		switch(type) {

			case 0:
				fgets(numDoorsString, 51, vehicleFile);
				numDoors = atoi(numDoorsString);
				fgets(rearConfig, 51, vehicleFile);
				if(isspace(rearConfig[strlen(rearConfig) - 1])) {
					rearConfig[strlen(rearConfig) - 1] = '\0';
				}
				fprintf(outFile, "%d %s %s\n", year, make, model);
				fprintf(outFile, "VIN: %s\n", vin);
				fprintf(outFile, "Doors: %d\n", numDoors);
				fprintf(outFile, "Rear Configuration: %s\n\n", rearConfig);
				break;

			case 1:
				fgets(numDoorsString, 51, vehicleFile);
				numDoors = atoi(numDoorsString);
				fgets(towCapString, 51, vehicleFile);
				if(isspace(towCapString[strlen(towCapString) - 1])) {
					towCapString[strlen(towCapString) - 1] = '\0';
				}
				sscanf(towCapString, "%lf", &towCap);
				fprintf(outFile, "%d %s %s\n", year, make, model);
				fprintf(outFile, "VIN: %s\n", vin);
				fprintf(outFile, "Doors: %d\n", numDoors);
				fprintf(outFile, "Max Towing Capacity: %.1lf\n\n", towCap);
				break;

			case 2:
				fgets(motorType, 51, vehicleFile);
				if(isspace(motorType[strlen(motorType) - 1])) {
					motorType[strlen(motorType) - 1] = '\0';
				}
				fprintf(outFile, "%d %s %s\n", year, make, model);
				fprintf(outFile, "VIN: %s\n", vin);
				fprintf(outFile, "Motor: %s\n\n", motorType);
				break;

		}

	}

	fclose(vehicleFile);
	fclose(outFile);

	return 0;

}
