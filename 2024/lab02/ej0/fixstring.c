#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s)
{
    unsigned int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

bool fstring_eq(fixstring s1, fixstring s2)
{
    bool equal = false;
    unsigned int i = 0;
    if (fstring_length(s1) == fstring_length(s2))
    {
        equal = true;
        while (s1[i] != '\0' && equal)
        {
            equal = s1[i] == s2[i];
            i++;
        }
    }
    return equal; // ES VALIDO USAR ESTA FUNCION PARA LESS_EQ? o GASTO DEMASIADOS RECUROS LLAMANDOLA NUEVAMENTE?
}

bool fstring_less_eq(fixstring s1, fixstring s2)
{
    unsigned int strlength = (fstring_length(s1) < fstring_length(s2)) ? fstring_length(s1) : fstring_length(s2);
    unsigned int i = 0;
    bool men = true;
    while (i < strlength && men)
    {
        if (s1[i] < s2[i])
        {
            men = true;
            break;
        }
        else if (s1[i] > s2[i])
        {
            men = false;
        }
        else if (s1[i] == s2[i] && i+1 == strlength)
        {
            men = (fstring_length(s1) < fstring_length(s2)) ? true : false;
        }
        i++;
    }
    return men;
}
