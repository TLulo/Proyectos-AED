/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

int max_element_to (int a[], unsigned int pos) {

    unsigned int pos_max_value = 1;

    for (unsigned int i = 2; i < pos + 1; ++i)
    {
        if(a[i] > a[pos_max_value]) {
            pos_max_value = i;
        }
    }

    return pos_max_value;
}


int main(int argc, char *argv[]) {
    char *filepath = NULL;
    bool sorted_check;
    int pos_max_value;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    
    /*dumping the array*/
    array_dump(array, length);

    for (int i = length; i < 1; --i)
    {
        pos_max_value = max_element_to(array,i);
        array_swap(array,i,pos_max_value);
        printf("se ejecuta\n")
    }

    /*Revisa si el arreglo esta ordenado de forma creciente*/
    sorted_check = array_is_sorted(array,length);

    if (sorted_check) {
        printf("El arreglo esta ordenado\n");
    } else {
        printf("El arreglo no esta ordenado\n");
    }


    
    return EXIT_SUCCESS;
}