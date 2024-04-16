#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * Each line must contain the name of a player"
           " without spaces followed by a three-letter country"
           " code, the rank of the player, his age, his atp points"
           " and the number of tournaments played during the year.\n"
           " * Values must be separated by one or more spaces.\n"
           " * Numeric values must be natural numbers.\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

static void dump(char a[], unsigned int length)
{
    printf("\"");
    for (unsigned int j = 0u; j < length; j++)
    {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path,
                            unsigned int indexes[],
                            char letters[],
                            unsigned int max_size)
{
    unsigned int i = 0;
    FILE *file;
    file = fopen(path, "r");
    char temp1,tmp2,tmp3,tmp4,tmp5,tmp6;

    while (!feof(file) && i < max_size)
    {
        if (fscanf(file, "%u", &indexes[i]) != -1)
        {
            if (indexes[i] <= MAX_SIZE)
            {
                int min = fscanf(file, "%c" "%c" "%c" "%c" "%c" "%c" "%c", &temp1, &tmp2, &tmp3, &tmp4 , &tmp5 , &letters[i], &tmp6);
                if (min == 7 && temp1 == ' ' && tmp2 == '-' && tmp3 == '>' && tmp4 == ' ' && tmp5 == '*' && tmp6 == '*')
                {
                    i++;
                }else{
                    printf("Error formato no valido");
                    break;
                }
            }else{
                i = MAX_SIZE + 1;
                break;
            }  
        }
    }
    fclose(file);
    return i;
}

static void rebuild(unsigned int indexes[],
                    char letters[],
                    unsigned int max_size, char array[])
{
    for (unsigned int i = 0; i < (max_size); i++)
    {
        array[indexes[i]] = letters[i];
    }
}

int main(int argc, char *argv[])
{
    char *filepath = NULL;
    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length = 0;
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo

    length = data_from_file(filepath, indexes, letters, MAX_SIZE);
    if (length > MAX_SIZE)
    {
        printf("Error el archivo tiene demasiados elementos\n");
        return EXIT_FAILURE;
    }
    else
    {
        rebuild(indexes, letters, length, sorted);

        dump(sorted, length);

        return EXIT_SUCCESS;
    }
}
