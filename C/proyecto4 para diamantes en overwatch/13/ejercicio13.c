#include <stdio.h>

int esPrimo(int n){
int i;
int N;
i = n - 1;
N = n;
while(n > 0){
if (n == 1){//no es primo
return 0;}
else if ((N % i) != 0 && (N % N) == 0 && (N % 1 == 0)) {//sigue
i--;
n--;}
else if ((i == 1) && ((N % N) == 0)){// es primo
n=0;
return 1;}
else if ((N % i) == 0){// no es primo
n = 0;
return 0;}}}

int nesimo_primo(int N){
int i, x, rst;
i = N;
x = 1;
while (N > 0){
if (esPrimo(x)){
rst = x;
x++;
N--;
}
else {x++;}
}
printf("El primo numero %d es: %d", i, rst);
return 0;
}

int main(void){
int y;
printf("Ingrese un numero positivo:\n");
scanf("%d", &y);
while (y <= 0) {
printf("Error :: Ingrese un entero positivo:\n");
scanf("%d", &y);
}
nesimo_primo(y);
}