CFLAGS = -Wall -Werror -Wextra -std=c99
CC = gcc


TEMPS = main main_ptr clone_ptr.o clone.o



compile_Noptr:$(ARG) #compile clone.c
		$(CC) $(CFLAGS) -c clone.c
		$(CC) $(CFLAGS) -o main clone.o

compile_ptr:$(ARG) #compile clone_ptr.c
			$(CC) $(CFLAGS) -c clone_ptr.c
			$(CC) $(CFLAGS) -o main_ptr clone_ptr.o


memoryleaks:
			valgrind --leak-check=full ./main

clean:
		rm -f $(TEMPS)
.PHONY: clean 