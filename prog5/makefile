prog5.exe : prog5.o prog5_functions.o
	gcc -o prog5.exe prog5.o prog5_functions.o

prog5.o : prog5.c prog5_functions.h
	gcc -Wall -c prog5.c

prog5_functions.o : prog5_functions.c prog5_functions.h
	gcc -Wall -c prog5_functions.c

clean : 
	rm *.o prog5.exe