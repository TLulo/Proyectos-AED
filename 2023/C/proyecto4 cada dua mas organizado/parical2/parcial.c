#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int x,y;
bool z;

int pedirEntero(char let){
    int res;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&res);
    return res;
}
bool pedirBooleano(void){
    int zbool,reserva;
    printf("Ingrese el valor de verdad de z: ");
    scanf("%d",&reserva);
    zbool = reserva;
    return zbool;
}
void imprimeBooleano(bool x){
    if (x){
        printf("El valor de verdad de z es True\n");
    }
    else{
        printf("el valor de verdad de z es False\n");
    }
}
void imprimeEntero(int x,char let){
    printf("El valor de %c es: %d\n",let,x);
}
void fun_1(int a,int b,bool c){
    int xaux,yaux;
    xaux = a;
    yaux = b;
    a = (xaux*xaux)+(yaux*yaux);
    b = xaux + yaux;
    c = xaux > yaux;
    assert((a == (x*x)+(y*y)) && (b == x+y )&& (c == (x > y)));
    imprimeEntero(a,'x');
    imprimeEntero(b,'y');
    imprimeBooleano(c);
}
int main(void){
    x=pedirEntero('x');
    y= pedirEntero('y');
    z = pedirBooleano();
    assert(x==x && y == y && z == z && x > 0);
    fun_1(x,y,z);
    /*El assert del post esta en la funcion.*/
}