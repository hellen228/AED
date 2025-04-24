#include <stdio.h>
#include "set.h"

int main() {
    //gcc -c set.c
    //gcc -c main.c
    //gcc set.o main.o -o set
    //si se cambia algo en el código solo poner make en la terminal, los archivos ya están enlazados.
    //para correr el programa primero ejecutar make y luego escribir en la terminal ./set

    Set conjunto1, conjunto2, conjunto3;
    int option, element;

    // Inicializamos los conjuntos
    printf("Primer conjunto\n");
    init(&conjunto1);
    printf("Segundo conjunto\n");
    init(&conjunto2);

    while (1) {
        printf("\nMenu de operaciones con conjuntos:\n");
        printf("1. Agregar elemento a conjunto 1\n");
        printf("2. Agregar elemento a conjunto 2\n");
        printf("3. Mostrar conjunto 1\n");
        printf("4. Mostrar conjunto 2\n");
        printf("5. Realizar union de conjuntos\n");
        printf("6. Realizar intersección de conjuntos\n");
        printf("7. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Ingresa un elemento para agregar al conjunto 1: ");
                scanf("%d", &element);
                addition(&conjunto1, element);
                break;
            case 2:
                printf("Ingresa un elemento para agregar al conjunto 2: ");
                scanf("%d", &element);
                addition(&conjunto2, element);
                break;
            case 3:
                printf("Conjunto 1: ");
                print(conjunto1);
                break;
            case 4:
                printf("Conjunto 2: ");
                print(conjunto2);
                break;
            case 5:
                unionS(&conjunto1, &conjunto2, &conjunto3);
                printf("Union de conjunto 1 y conjunto 2: ");
                print(conjunto3);
                break;
            case 6:
                intersection(&conjunto1, &conjunto2, &conjunto3);
                printf("Interseccion de conjunto 1 y conjunto 2: ");
                print(conjunto3);
                break;
            case 7:
                printf("Saliendo...\n");
                return 0;
            default:
                printf("Opción no válida. Intenta nuevamente.\n");
        }
    }

    return 0;
}
