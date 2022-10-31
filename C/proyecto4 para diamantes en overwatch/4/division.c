#include <stdio.h>
int dividendo, divisor;
struct div_t {
int cociente;
int resto;
};

struct div_t division(int x, int y)
{
struct div_t rst;
rst.cociente = x / y;
rst.resto = x % y;
return rst;
};
void print_division(struct div_t rst){
printf("El cociente es: %d\n", rst.cociente);
printf("EL resto es: %d\n", rst.resto);
}

int main(void)
{
printf("Ingrese el valor del dividendo:\n");
scanf("%d",&dividendo);
printf("Ingrese el valor de divisor:\n");

scanf("%d",&divisor);
while (divisor == 0){printf("No se puede dividir por 0\n");
printf("Ingrese el valor de divisor:\n");

scanf("%d",&divisor);}

print_division(division(dividendo, divisor));


}
