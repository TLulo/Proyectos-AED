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
    
    int i = 0;
    struct bound_data res;
    res.is_lowerbound = true;
    res.is_upperbound = true;
    res.exists = false;
    int tam = length;
    while(i<tam){
      if ((arr[i]==value)){
        res.exists = true;
        res.is_lowerbound = true && res.is_lowerbound;
        res.is_upperbound = true && res.is_upperbound;
        res.where = i;
      }else if((arr[i]>value)){
        res.is_lowerbound = true && res.is_lowerbound;
        res.is_upperbound = false && res.is_upperbound;
      }else if((arr[i]<value)){
        res.is_upperbound = true && res.is_upperbound;
        res.is_lowerbound = false && res.is_lowerbound;
      } 
      i = i + 1;
    }
    return res;
}

int pedirEntero () {
  int a;
  printf("Ingrese un entero:");
  scanf("%d",&a);
  return a;
}

void pedirArreglo(int a[], int n_max){

  int i;
  i = 0;
  while (i < n_max)
  {
    printf("Ingrese el valor del arreglo en la posicion %d: ", i+1);
    scanf("%d",&a[i]);
    i = i+1;
  }
  

}

int main(void) {
    
    //Declaracion de variables y pedir al usuario los elementos del array
    
    int value;
    printf("Ingrese un value:");
    scanf("%d",&value);
    int array[ARRAY_SIZE];
    pedirArreglo(array,ARRAY_SIZE);
    struct bound_data result; 
    result = check_bound(value, array, ARRAY_SIZE);

    //Printea los resultados de la funcion check_bound

    if (result.is_upperbound){
        printf("El value es mayor o igual que todos los elementos del array\n");
    }else {
        printf("El value no es mayor o igual que todos los elementos del array\n");
    } 
    
    if (result.is_lowerbound){
        printf("El value es menor o igual que todos los elementos del array (%s)\n", (result.is_lowerbound)? "True": "False");
    }else {
        printf("El value no es menor o igual que todos los elementos del array\n");
    }
    
    if (result.exists){
        printf("El value es igual a un elemento del array, se halla en la posicion %d\n", result.where);
    } else {
        printf("El value no se halla en el arreglo\n");
    }

    return EXIT_SUCCESS;
}
