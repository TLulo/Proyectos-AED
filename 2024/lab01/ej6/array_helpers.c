#include <stdio.h>
#include <stdbool.h>
#include "array_helpers.h"


unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    //Edicion del estudiante
    FILE * archivo;
    archivo = fopen(filepath, "r");
    
    fscanf(archivo,"%ud", &max_size);
    for(unsigned int i = 0;i< max_size;i++){
        fscanf(archivo,"%d",&array[i]);
    }
    fclose(archivo);
    //edicion del estudiante
    return max_size;
}

void array_dump(int a[], unsigned int length) {
    printf("[");
    for(unsigned int i = 0; i < length;i++){
        printf("%d, ",a[i]);
    }
    if(length>0){
        printf("\b\b]\n");
    }else{
        printf("]\n");
    }
}

bool array_is_sorted(int a[],unsigned int length){
    bool sorted = true;
    for (unsigned int i = 0; (i < length-1) && sorted; i++){
        if (a[i] <= a[i+1]){
            sorted = true;
        }else{
            sorted = false;
        }
    }
    return sorted;
}

void array_swap(int a[], unsigned int i, unsigned int j){
    int reserva = 0;
    reserva = a[i];
    a[i] = a[j];
    a[j] = reserva;
}