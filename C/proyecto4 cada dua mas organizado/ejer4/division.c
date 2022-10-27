#include <stdio.h>
#include <assert.h>

int a,b;

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

struct div_t{
    int cociente;
    int resto;
};

struct div_t division(int x, int y){
    struct div_t res;
    res.cociente = x / y;
    res.resto = x % y;
    return res;
}

void imprime_res(struct div_t p){
    printf("El Cociente es: %d\nEl resto es: %d.\n",p.cociente,p.resto);
}

int main(void){
    printf("A continuacion se le pediran los valores del dividendo y divisor respectivamente.\n");
    a = pedirEntero('x');
    b = pedirEntero('y');

    assert(a>0 && b>0);

    imprime_res(division(a,b));
    
}


//-------------------------------------------ESTA VEZ FUE SIN ROBARTE-------------------------------

#include <stdio.h>

int pedirEntero(void){
    int i;
    printf("Introduzca el numero:\n");
    scanf("%d",&i);
    return i;
}

struct div_t {
int cociente;
int resto;
};

struct div_t division(int x, int y){
    struct div_t res;
    res.cociente= x/y;
    res.resto= x%y;
    
    return res;
}


int main() {
    int x,y;
    struct div_t div;
    x = pedirEntero();
    y = pedirEntero();
    while (y==0){
        printf("El entero que ingreso no es valido\n");
        pedirEntero();
    }
    div = division(x,y);
    printf("El Cociente es: %d\nEl resto es: %d.\n",div.cociente, div.resto);
    
}

