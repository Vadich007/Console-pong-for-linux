FLAGS = -Wall -Werror -Wextra
all: pong
pong: main.o main_functions.o
	gcc main.o main_functions.o -o pong
main.o: main.c
	gcc -c main.c -o main.o
main_functions.o: main_functions.c
	gcc -c main_functions.c -o main_functions.o
clean: rm *.o rm pong
rebuild: clean all