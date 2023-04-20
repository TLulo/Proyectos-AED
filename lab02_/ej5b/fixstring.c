#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
unsigned int counter = 0;
for (unsigned int i = 0; s[i] != '\0'; i++){
    counter = counter + 1;
}
return counter;
}

bool fstring_eq(fixstring s1, fixstring s2) {
  bool rst = true;
  if (fstring_length(s1) != fstring_length(s2)){
    rst = false;
  }
  for(unsigned int i = 0; i < fstring_length(s1) && rst; i++){
    rst = rst && s1[i] == s2[i];
  }
  return rst;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool rst = true;
    unsigned int strlength = (fstring_length(s1) < fstring_length(s2)) ? fstring_length(s1) : fstring_length(s2); 
    if (fstring_eq(s1, s2)){
        rst = false;
    }
    for(unsigned int i = 0; i < strlength && rst; i++){
    if (s1[i] < s2[i]){
        rst = true;
        break;
    }
    if (s1[i] > s2[i]){
        rst = false;
    }
    if (s1[i] == s2[i] && i == strlength - 1){
        rst = (fstring_length(s1) < fstring_length(s2)) ? true : false;
    }
  }
return rst;
}


void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);
}


