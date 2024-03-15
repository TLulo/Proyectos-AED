#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    //funciones check_bound
    bool upper,lower;
    upper = true;
    lower = true;
    for (unsigned int i = 0 ; i < length; i++){
        if (upper){
                upper = value >= arr[i];
        }
        if (lower){
                lower = value <= arr[i];
        }
        if (value == arr[i]){
                res.exists = true;
                res.where = i;
        }
    res.is_upperbound = upper;
    res.is_lowerbound = lower;
    }
    //
    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    //Entrada de datos (arreglo de logitud 4)
     for (unsigned int i = 0; i<ARRAY_SIZE; i++){
        printf("ingrese el valor de la posicion %d del arreglo: ",i);
        scanf("%d",&a[i]);
     }
     printf("Ingrese el valor que desea verificar: ");
     scanf("%d",&value);
    //
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    if(result.is_upperbound){
        if(result.exists){
                printf("El Valor es un maximo\n");
                printf("y se encuentra en la posicion: %d\n",result.where);
        }
        else{
                printf("El Valor es cota superior\n");
        }
    }
    else if( result.is_lowerbound){
        if(result.exists){
                printf("El Valor es un minimo\n");
                printf("y se encuentra en la posicion: %d\n",result.where);
        }
        else{
                printf("El Valor es cota Inferior\n");
        }
    }
    else{
        printf("El valor pertenece al intervalo\n");
    }
    //printf("%d", result.is_upperbound); // Imprime 1
    //printf("%d", result.is_lowerbound); // Imprime 0
    //printf("%u", result.exists);        // Imprime 1
    //printf("%u", result.where);         // Imprime 2

    return EXIT_SUCCESS;
}
