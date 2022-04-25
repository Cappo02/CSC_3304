prog6.exe : prog6.o prog6_functions.o
	gcc -o prog6.exe prog6.o prog6_functions.o

prog6.o : prog6.c prog6_functions.h
	gcc -Wall -c prog6.c

prog6_functions.o : prog6_functions.c prog6_functions.h
	gcc -Wall -c prog6_functions.c

clean : 
	rm *.o prog6.exe