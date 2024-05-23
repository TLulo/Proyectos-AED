#include "arrayhelpers.h"

void destroy_array(stack_elem *array){
    free(array);
}