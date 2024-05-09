CFLAGS = -Wall -Werror -Wextra -std=c99
CC = gcc

ARG = *.c
OBJ = $(ARG:.c=.o)

TEMPS = $(OBJ) main


only_compile_obj:$()
		$(CC) $(CFLAGS) -c *.c

only_compile_c:
		$(CC) $(CFLAGS) -g -o main abs2.c  

compile:$()
		$(CC) $(CFLAGS) -c *.c
		$(CC) $(CFLAGS) -o main *.o

compile_g:$()
		$(CC) $(CFLAGS) -g -c *.c
		$(CC) $(CFLAGS) -g -o main *.o

clean:
		rm -f $(TEMPS)
		ls
.PHONY: clean 