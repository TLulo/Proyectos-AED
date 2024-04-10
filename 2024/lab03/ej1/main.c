#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

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
    char temp;
    while (!feof(file) && i < max_size)
    {
        fscanf(file, "%u", &indexes[i]);
        if (indexes[i] > max_size)
        {
            return max_size+1;
            break;
        }
        
        fscanf(file, "%c", &temp);

        if (temp == '*')
        {
            fscanf(file, "%c", &letters[i]);
            i++;
            fscanf(file, "%c", &temp);
        }
    }
    return (i-1);
    fclose(file);
}

static void rebuild(unsigned int indexes[],
        char letters[],
        unsigned int max_size,char array[])
{
    for (unsigned int i = 0; i < (max_size); i++)
    {
        array[indexes[i]] = letters[i];
    }
            
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {

        unsigned int indexes[MAX_SIZE];
        char letters[MAX_SIZE];
        char sorted[MAX_SIZE];
        unsigned int length = 0;
        //  .----------^
        //  :
        // Debe guardarse aqui la cantidad de elementos leidos del archivo

        /* -- completar -- */
        length = data_from_file(argv[1], indexes, letters, MAX_SIZE);
        if (length > MAX_SIZE)
        {
            printf("Error el archivo tiene demasiados elementos\n");
        }else{
            rebuild(indexes,letters,length,sorted);

            dump(sorted, length);

            return EXIT_SUCCESS;
        }
    }
}
