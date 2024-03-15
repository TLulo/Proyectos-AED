#include <stdio.h>
#include <assert.h>

int N,res;

void imprimeEntero(int a,char let){
    printf("El valor de %c es: %d\n",let,a);
}

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

int suma_hasta(int n){
    int sumatoria = (n*(n+1))/2;

    return sumatoria;
}

int main(void){

    N = pedirEntero('x');

    assert(N>=0);

    res = suma_hasta(N);
    printf("La sumatoria es:\n");
    imprimeEntero(res,'S');
}



/*---------------------------------- ASI LO HICE YO--------------------------------------------- */

#include<stdio.h>
#include<assert.h>

int pedirNatural(void){
    int i;
    assert (i > 0);
    printf("Introduzca el numero:\n");
    scanf("%d",&i);
    return i;
}

int suma_hasta(int num) {
  int i, res;
  i = 0;
  res = 0;
  while(i < num ){
    res = res + i;
    i = i + 1;
}   return res;
}


int main() {
    int resultado, n;
    n = pedirNatural();
    
    resultado = suma_hasta(n);
    printf("La suma de los naturales hasta N sin incluir N es: %d \n", resultado);
}
