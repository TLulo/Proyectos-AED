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
    res.exists =  false;
    res.where = 1000000;
    for (unsigned int i = 0; i < length; i++){
        if (value == arr[i]){
            res.exists = true;
            res.where = i;
        }
        if (value > arr[i]){
            res.is_lowerbound = false;
            res.is_upperbound = true;
        }
        if (value < arr[i]){
            res.is_upperbound = false;
            res.is_lowerbound = true; 
        }
    }
    return res;
}

void pedirArray(int a[], int n_max){
    for (int i = 0; i < n_max; i++){
        printf("En la posicion %d introduzca el valor del array: \n", i);
        scanf("%d", &a[i]);
}
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    pedirArray(a, ARRAY_SIZE);
    printf("Ingrese un valor: ");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);
    
    if (result.exists){
        if (result.is_upperbound){
        printf("El valor ingresado es maximo.\n");
        } 
        else if (result.is_lowerbound){
        printf("El valor ingresado es minimo.\n");
        }
    printf("El valor ingresado se encuentra en la posicion %u del arreglo.\n", result.where);
    }
    else {
        if (result.is_upperbound){
        printf("El valor ingresado es cota superior.\n");
        } 
        else if (result.is_lowerbound){
        printf("El valor ingresado es cota inferior.\n");
        }
    }
    return EXIT_SUCCESS;
}

