#include <stdio.h>
#include <stdlib.h>
#include "class.h"

int main() {
    Class grupo;

    init(&grupo);
    printf("\nNotas registradas:\n");
    print(grupo);

    int mayor = high_note(&grupo);
    printf("\nLa nota más alta es: %d\n", mayor);

    free(grupo.notas);

    return 0;
}
