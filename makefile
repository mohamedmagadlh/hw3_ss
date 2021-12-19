CC=gcc
AR=ar
FLAGS=-g -Wall

all: stringProg


libmystring.a:functions.o 
	$(AR) -rcs libmystring.a functions.o 

functions.o: functions.c functions.h
	$(CC) $(FLAGS) -c functions.c 


stringProg: main.o libmystring.a
	$(CC) $(FLAGS) -o stringProg main.o libmystring.a

main.o: main.c functions.h
	$(CC) $(FLAGS) -c main.c



.PHONY: clean all

clean:
	rm -f *.o *.a *.so main functions
 