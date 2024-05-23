CFLAGS = -Wall -Werror -Wextra -std=c99
CC = gcc
ARG = clone_ptr.c
OBJ = $(ARG:.c=.o)

TEMPS = $(OBJ) main



compile:$(ARG)
		$(CC) $(CFLAGS) -c $(ARG)

compile_obj:$(ARG)
			$(CC) $(CFLAGS) -o main $(OBJ)

debug:$(ARG)
		$(CC) $(CFLAGS) -c -g $(ARG)
		$(CC) $(CFLAGS) -g -o main $(OBJ)

memoryleaks:
			valgrind --leak-check=full ./main

clean:
		rm -f $(TEMPS)
.PHONY: clean 