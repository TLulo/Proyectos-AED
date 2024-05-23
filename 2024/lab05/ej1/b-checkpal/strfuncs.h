#ifndef _STRFUNCS_H
#define _STRFUNCS_H
#include <stdbool.h>

long int string_length(const char *str);

char *string_filter(const char *str, char c);

bool string_is_symmetric(const char *str);

void destroy_str(char *str);

#endif