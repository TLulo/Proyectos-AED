#include <stdio.h>

int x,y,z;

void imprimeEntero(int a,char let){
    printf("El valor de %c es: %d\n",let,a);
}

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

void fun2(int a,int b,int c){
    int xaux,yaux;
    xaux = a;
    a = b;
    yaux = b;
    b = b + xaux + c;
    c = xaux + yaux;

    imprimeEntero(a,'x');
    imprimeEntero(b,'y');
    imprimeEntero(c,'z');
}

int main(void){
    x = pedirEntero('x');
    y = pedirEntero('y');
    z = pedirEntero('z');

    fun2(x,y,z);
}