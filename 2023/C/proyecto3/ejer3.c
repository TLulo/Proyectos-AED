#include <stdio.h>
#include <stdbool.h>
int x,y,resa,resb1,resb2,resc1,resc2;

int funa(int a)
{
    a = 5;
    printf("Fun a!\n");
    printf("El estado final de x es: %d\n",a);
    return 0;
}
int funb(int a, int b)
{
    a = a + b;
    b = 2*b;
    printf("Fun b!\n");
    printf("El estado final de x es: %d\n",a);
    printf("El estado final de y es: %d\n",b);
    return 0;
}
int func(int a, int b)
{
    b = 2*b;
    a = b + a;
    printf("Fun c!\n");
    printf("El estado final de x es: %d\n",a);
    printf("El estado final de y es: %d\n",b);
    return 0;
}
int main(void)
{
    printf("Ingrese el valor de x: ");
    scanf("%d",&x);
    printf("Ingrese el valor de y: ");
    scanf("%d",&y);

    funa(x);
    funb(x,y);
    func(x,y);

}
/*programa                    estado inicial de usuario                    salida/estado final
1.a 1era ejec                  x->7                                             x -> 5
1.a 2da ejec                   x -> 3                                           x -> 5
1.a 3era ejec                  x -> -1                                          x -> 5
1.b 1era ejec                  x -> 7       y -> 4                         x -> 11      y -> 8
1.b 2da ejec                   x -> 3       y -> 9                         x -> 12      y -> 18
1.b 3ra ejec                   x -> -1      y -> 6                         x -> 5       y -> 12     
1.c 1era ejec                  x -> 7       y -> 4                         x -> 15      y -> 8
1.c 2da ejec                   x -> 3       y -> 9                         x -> 21     y -> 18
1.c 3ra ejec                   x -> -1      y -> 6                         x -> 11     y -> 12
*/