#include <stdio.h>
#include "matrix.h"

int main() {
    //si se cambia algo en el código solo poner make en la terminal, los archivos ya están enlazados.
    //para correr el programa escribir en la terminal ./matriz

    Matrix matriz1, matriz2, matriz3, matriz4;
    int option;

    printf("Inicializando la primera matriz:\n");
    init(&matriz1);
    
    printf("Inicializando la segunda matriz:\n");
    init(&matriz2);

    do {
        printf("\nElige una opción:\n");
        printf("1. Imprimir matriz 1\n");
        printf("2. Imprimir matriz 2\n");
        printf("3. Multiplicar matriz 1 y matriz 2\n");
        printf("4. Transponer matriz 1\n");
        printf("5. Transponer matriz 2\n");
        printf("6. Salir\n");
        printf("Opción: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Matriz 1:\n");
                print(matriz1);
                break;

            case 2:
                printf("Matriz 2:\n");
                print(matriz2);
                break;

            case 3:
                // Verificamos si las matrices tienen las dimensiones adecuadas para multiplicarse
                if (matriz1.col == matriz2.row) {
                    mult(&matriz1, &matriz2, &matriz3);
                    printf("Resultado de la multiplicación:\n");
                    print(matriz3);
                } else {
                    printf("Las matrices no se pueden multiplicar. Las dimensiones no coinciden.\n");
                }
                break;

            case 4:
                printf("Matriz 1 transpuesta:\n");
                transposed(&matriz1, &matriz3); // Usamos matriz3 como destino
                print(matriz3);
                break;

            case 5:
                printf("Matriz 2 transpuesta:\n");
                transposed(&matriz2, &matriz4); // Usamos matriz4 como destino
                print(matriz4);
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida. Por favor, elige una opción válida.\n");
        }

    } while(option != 6);

    return 0;
}
