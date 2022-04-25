#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/**
 * This function removes the ending white space from an inputted string
 * and then returns the length of the string after the whitespace is removed.
 * 
 * routine: RemoveEndingWhiteSpace
 * 
 * return type: int
 * 
 * parameters: 
 * char givenString[] - the string to remove the whitespace from
 * 
 * @author Nicholas Caplette
 * @since 3/29/22
 */
int RemoveEndingWhiteSpace(char givenString[]);

/**
 * This function reads in an integer value from a file and then returns
 * the integer value. It reads in the value as a string, then removes the
 * ending white space and then converts the string to an integer.
 * 
 * routine: InputInteger
 * 
 * return type: int
 * 
 * parameters: 
 * FILE* inFile - the file to read the integer from
 * char inIntString[] - the string to store the integer value in
 * int maxLength - the maximum length of the string
 * 
 * @author Nicholas Caplette
 * @since 3/29/22
 */
int InputInteger(FILE* inFile, char inIntString[], int maxLength);

/**
 * This function reads in a float value from a file and then returns
 * the float value. It reads in the value as a string, then removes the
 * ending white space and then converts the string to a float.
 * 
 * routine: InputFloat
 * 
 * return type: float
 * 
 * parameters: 
 * FILE* inFile - the file to read the float from
 * char inFloatString[] - the string to store the float value in
 * int maxLength - the maximum length of the string
 * 
 * @author Nicholas Caplette
 * @since 3/29/22
 */
float InputFloat(FILE* inFile, char inFloatString[], int maxLength);

/**
 * This function reads in a string from a file and then stores
 * the string in the given string. The string then has its ending
 * whitespace removed.
 * 
 * routine: InputString
 * 
 * return type: void
 * 
 * parameters: 
 * FILE* inFile - the file to read the string from
 * char inString[] - the string to store the string in
 * int maxLength - the maximum length of the string
 * 
 * @author Nicholas Caplette
 * @since 3/29/22
 */
void InputString(FILE* inFile, char inString[], int maxLength);

/**
 * This function reads in a car from a given input file and then stores its 
 * given attributes in the given parameters. It reads in the car's make, 
 * model, year, VIN, number of doors, and rear configuration. For the 
 * parameters that are not strings, it reads in the value as a string, 
 * then removes the ending white space and then converts the string to 
 * its specified type.
 * 
 * routine: InputCar
 * 
 * return type: void
 * 
 * parameters: 
 * FILE* inFile - the file to read the car from
 * int maxLength - the maximum length of the string
 * char make[] - the string to store the car's make in
 * char model[] - the string to store the car's model in
 * int* year - the integer to store the car's year in
 * char yearString[] - the string to store the car's year in
 * char vin[] - the string to store the car's VIN in
 * int* numDoors - the integer to store the car's number of doors in
 * char numDoorsString[] - the string to store the car's number of doors in
 * char rearConfig[] - the string to store the car's rear configuration in
 * 
 * @author Nicholas Caplette
 * @since 3/29/22
 */
void InputCar(FILE* inFile, int maxLength, char make[], char model[], int* year, char yearString[], 
char vin[], int* numDoors, char numDoorsString[], char rearConfig[]);

/**
 * This function reads in a truck from a given input file and then stores its
 * given attributes in the given parameters. It reads in the truck's make,
 * model, year, VIN, number of doors, and towing capacity. For the parameters
 * that are not strings, it reads in the value as a string, then removes the
 * ending white space and then converts the string to its specified type.
 * 
 * routine: InputTruck
 * 
 * return type: void
 * 
 * parameters: 
 * FILE* inFile - the file to read the truck from
 * int maxLength - the maximum length of the string
 * char make[] - the string to store the truck's make in
 * char model[] - the string to store the truck's model in
 * int* year - the integer to store the truck's year in
 * char yearString[] - the string to store the truck's year in
 * char vin[] - the string to store the truck's VIN in
 * int* numDoors - the integer to store the truck's number of doors in
 * char numDoorsString[] - the string to store the truck's number of doors in
 * int* towCap - the integer to store the truck's towing capacity in
 * char towCapString[] - the string to store the truck's towing capacity in
 * 
 * @author Nicholas Caplette
 * @since 3/29/22
 */
void InputTruck(FILE* inFile, int maxLength, char make[], char model[], int* year, char yearString[],
char vin[], int* numDoors, char numDoorsString[], double* towCap, char towCapString[]);

/**
 * This function reads in a boat from a given input file and then stores its 
 * given attributes in the given parameters. It reads in the boat's make,
 * model, year, VIN, and motor type. For the parameters that are not strings,
 * it reads in the value as a string, then removes the ending white space and
 * then converts the string to its specified type.
 * 
 * routine: InputBoat
 * 
 * return type: void
 * 
 * parameters: 
 * FILE* inFile - the file to read the boat from
 * int maxLength - the maximum length of the string
 * char make[] - the string to store the boat's make in
 * char model[] - the string to store the boat's model in
 * int* year - the integer to store the boat's year in
 * char yearString[] - the string to store the boat's year in
 * char vin[] - the string to store the boat's VIN in
 * char motorType[] - the string to store the boat's motor type in
 * 
 * @author Nicholas Caplette
 * @since 3/29/22
 */
void InputBoat(FILE* inFile, int maxLength, char make[], char model[], int* year, char yearString[], 
char vin[], char motorType[]);

/**
 * This function outputs information about a car to a given output file. It
 * outputs the car's make, model, year, VIN, number of doors, and rear
 * configuration. All of the parameters used as input will be read in 
 * through the InputCar function.
 * 
 * routine: OutputCar
 * 
 * return type: void
 * 
 * parameters:
 * FILE* outFile - the file to output the car to
 * char make[] - the string containing the car's make
 * char model[] - the string containing the car's model
 * int year - the integer containing the car's year
 * char vin[] - the string containing the car's VIN
 * int numDoors - the integer containing the car's number of doors
 * char rearConfig[] - the string containing the car's rear configuration
 * 
 * @author Nicholas Caplette
 * @since 3/29/22
 */
void OutputCar(FILE* outFile, char make[], char model[], int year, char vin[], int numDoors, char rearConfig[]);

/**
 * This function outputs information about a truck to a given output file. It
 * outputs the truck's make, model, year, VIN, number of doors, and towing
 * capacity. All of the parameters used as input will be read in through the
 * InputTruck function.
 * 
 * routine: OutputTruck
 * 
 * return type: void
 * 
 * parameters:
 * FILE* outFile - the file to output the truck to
 * char make[] - the string containing the truck's make
 * char model[] - the string containing the truck's model
 * int year - the integer containing the truck's year
 * char vin[] - the string containing the truck's VIN
 * int numDoors - the integer containing the truck's number of doors
 * double towCap - the double containing the truck's towing capacity
 * 
 * @author Nicholas Caplette
 * @since 3/29/22
 */
void OutputTruck(FILE* outFile, char make[], char model[], int year, char vin[], int numDoors, double towCap);

/**
 * This function outputs information about a boat to a given output file. It
 * outputs the boat's make, model, year, VIN, and motor type. All of the
 * parameters used as input will be read in through the InputBoat function.
 * 
 * routine: OutputBoat
 * 
 * return type: void
 * 
 * parameters:
 * FILE* outFile - the file to output the boat to
 * char make[] - the string containing the boat's make
 * char model[] - the string containing the boat's model
 * int year - the integer containing the boat's year
 * char vin[] - the string containing the boat's VIN
 * char motorType[] - the string containing the boat's motor type
 * 
 * @author Nicholas Caplette
 * @since 3/29/22
 */
void OutputBoat(FILE* outFile, char make[], char model[], int year, char vin[], char motorType[]);