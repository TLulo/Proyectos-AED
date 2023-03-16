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
    res.is_lowerbound = 1;
    res.is_upperbound = 1;
    res.exists = 0;
    int tam = length;
    while(i<=tam){
      if ((arr[i]==value)){
        res.exists = 1;
        res.is_lowerbound = 1 && res.is_lowerbound;
        res.is_upperbound = 1 && res.is_upperbound;
        res.where = i;
      }
      if((arr[i]>value)){
        res.is_lowerbound = 1 && res.is_lowerbound;
        res.is_upperbound = 0 && res.is_upperbound;
      }else if((arr[i]<value)){
        res.is_upperbound = 1 && res.is_upperbound;
        res.is_lowerbound = 0 && res.is_lowerbound;
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
    int value;
    printf("Ingrese un value:");
    scanf("%d",&value);
    int array[ARRAY_SIZE];
    pedirArreglo(array,ARRAY_SIZE);
    struct bound_data result; 
    result = check_bound(value, array, ARRAY_SIZE);

    printf("%d\n", result.is_upperbound); 
    printf("%d\n", result.is_lowerbound); 
    printf("%d\n", result.exists);        
    printf("%d\n", result.where);         

    return EXIT_SUCCESS;
}
