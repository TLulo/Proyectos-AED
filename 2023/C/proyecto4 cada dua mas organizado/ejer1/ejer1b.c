// FUncion lulo Asserts puestos
#include <stdio.h>
#include <assert.h>

int x, y, z, min, absoluto;

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

void imprimeEntero(int x,char let){
    printf("El valor de %c es: %d\n",let,x);
}

int minimo(int a, int b){
    assert(a == x && b == y);
    int res;
    if (a <= b){
        res = a;
    }
    else if (a > b){
        res = b;
    }
    assert(res == x || res == y);
    return res; 
}

int valor_Absoluto(int a){
    assert(a == x);
    int res;
    if (a >= 0){
        res = a;
    }
    else if (a < 0){
        res = -a;
    }
    assert(res == x || res == -x);
    return res;
}

void intercambio(int a, int b,int c){
    assert(a == x && b == y && c == z);
    int aAux,bAux,cAux;
    aAux= a;
    bAux = b;
    cAux = c;
    assert(aAux == x && bAux == y && cAux = z);
    a= bAux;
    b = cAux;
    c = aAux;
    assert(a == y && b == z && c == x);
    imprimeEntero(a,'x');
    imprimeEntero(b,'y');
    imprimeEntero(c,'z');
}

int main(void){
    x = pedirEntero('x');
    y = pedirEntero('y');
    z = pedirEntero('z');

    min = minimo(x,y);
    printf("El resultado del minimo entre x e y se mostrara a continuacion.\n");
    imprimeEntero(min,'x');
    absoluto = valor_Absoluto(x);
    printf("El resultado del Valor Absoluto de x se mostrara a continuacion.\n");
    imprimeEntero(absoluto,'x');
    printf("Los intercambios son:\n");
    intercambio(x,y,z);
}


//----------------------------------- ASI LO RESUELVE AL 1 B UN GIGACHAD DE VERDAD ----------------------------------------------------------
#include<stdio.h>
#include<assert.h>


int pedirEntero(void){
    int i;
    assert (i>0 || i< 0);
    printf("Introduzca el numero:");
    scanf("%d",&i);
    return i;
}

int imprimeEntero(int x, char let){
    printf("El valor de %c es: %d\n",let,x);
}

int minimo (int a, int b) {
    int res;
    if (a > b) {
        res = b;
    } else {
        res = a;
    }    
    return res;
}

int valorAbsoluto(int a) {
    int res;
    if (a >= 0) {
        res = a;
    } else {
        res = (-1)* a;
    }
    return res;
}

int intercambioVar(int a, int b, int c) {
    int auxA, auxB, auxC;
    auxA= a;
    auxB = b;
    auxC = c;
    a= auxB;
    b = auxC;
    c = auxA;
    printf("El intercambio de variables es el siguiente;\n");
    imprimeEntero(a,'x');
    imprimeEntero(b,'y');
    imprimeEntero(c,'z');
}

int main(void) {
    int x,y,z,min,absoluto;
    printf("Introduzca los dos enteros a comparar para obtener el minimo a continuacion: \n");
    x = pedirEntero();
    y = pedirEntero();
    printf("Introduzca el entero para obtener su valor absoluto: \n");
    z = pedirEntero();
    absoluto = valorAbsoluto(z);
    min= minimo(x,y);
    printf("El minimo entre %d y %d es %d\n", x, y, min);
    absoluto = valorAbsoluto(z);
    printf("El valor absoluto de %d es: %d\n", z, absoluto);
    intercambioVar(x , y ,z);
    assert (min>0 || min< 0);
}
