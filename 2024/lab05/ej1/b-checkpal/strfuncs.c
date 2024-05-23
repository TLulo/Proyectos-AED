#include "strfuncs.h"
#include <stdlib.h>

long int string_length(const char *str){
    unsigned int i = 0;
    while (str[i] != '\0')
    {
        i ++;
    }
    return i;
}

char *string_filter(const char *str, char c){
    
    char *str_cp;
    unsigned int j = 0;
    unsigned int length_orig = 0;
    unsigned int length_cp = 0;
    while (str[length_orig] != '\0')
    {
        if (str[length_orig] != c)
        {
            length_cp ++;
        }
        length_orig ++;
    }
    str_cp = malloc(sizeof(char) * length_cp);
    for (unsigned int i = 0; i < length_orig; i++)
    {
        if (str[i] != c)
        {
            str_cp[j] = str[i]; 
            j ++;
        }
    }
    str_cp[length_cp] = '\0';
    return str_cp;
}

bool string_is_symmetric(const char *str){
    unsigned int length = string_length(str);
    bool res = true;
    for (unsigned int i = 0; i < length/2; i++)
    {
        if (str[i] != str[length-1])
        {
            res = false;
        }
        length --;
    }
    return res;
}

void destroy_str(char *str){
    free(str);
}