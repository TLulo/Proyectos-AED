#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 40

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.'};
    char *filtered=NULL;
    unsigned int len = 0;
    char *p = NULL;
    
    fgets(user_input,MAX_LENGTH,stdin);
    len = string_length(user_input);
    user_input[len-1]='\0';

    filtered = string_filter(user_input, ignore_chars[0]);
    for (unsigned int i=0; i < SIZEOF_ARRAY(ignore_chars); i++) {
        p = filtered;
        filtered = string_filter(filtered, ignore_chars[i]);
        destroy_str(p);
    }

    printf("El texto:\n\n"
            "\"%s\" \n\n"
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");
    
    destroy_str(filtered);
    return EXIT_SUCCESS;
}

