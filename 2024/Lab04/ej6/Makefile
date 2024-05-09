CFLAGS = -Wall -Werror -Wextra -std=c99
CC = gcc

ARG = counter.c main.c
OBJ = $(ARG:.c=.o)

TEMPS = $(OBJ) main

compile_obj:$()
		$(CC) $(CFLAGS) -c $(ARG)

compile_wobj:$()
		$(CC) $(CFLAGS) -o main $(OBJ)

compile_g:$()
		$(CC) $(CFLAGS) -g -c *.c
		$(CC) $(CFLAGS) -g -o main *.o

clean:
		rm -f $(TEMPS)
		ls
.PHONY: clean 