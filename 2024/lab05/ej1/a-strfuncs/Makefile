CFLAGS = -Wall -Werror -Wextra -std=c99
CC = gcc

ARG = *.c
OBJ = $(ARG:.c=.o)

TEMPS = $(OBJ) main



compile:$(ARG)
		$(CC) $(CFLAGS) -c *.c

compile_obj:$(ARG)
			$(CC) $(CFLAGS) -o main *.o

compile_g:$(ARG)
		$(CC) $(CFLAGS) -c -g *.c
		$(CC) $(CFLAGS) -g -o main *.o

clean:
		rm -f $(TEMPS)
.PHONY: clean 