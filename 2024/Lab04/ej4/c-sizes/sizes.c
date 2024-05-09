#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {
    data_t *p = NULL;

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi.name),sizeof(messi.age),sizeof(messi.height),sizeof(messi));
    p = &messi;
    printf("*Las siguientes direciones de memoria estan en el formato Decimal seguido de su formato hexadecimal\n");
    printf("name-size  : Address: %lu , %p \n",(uintptr_t) &(p->name),(void *) &p->name);
    printf("age-size   : Address: %lu , %p \n",(uintptr_t) &p->age,(void *) &p->age);
    printf("height-size: Address: %lu , %p \n",(uintptr_t) &p->height,(void *) &p->height);
    printf("data_t-size: Address: %lu , %p \n",(uintptr_t) p,(void *) p);
    return EXIT_SUCCESS;
}

