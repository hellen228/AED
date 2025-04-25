#include "class.h"
#include <stdio.h>
#include <stdlib.h>

void init(Class *number){
    printf("Ingrese la cantidad de estudiantes: ");
    scanf("%d", &number->n);

    number->notas = (int *)malloc(number->n * sizeof(int));

    for(int i = 0; i < number->n; i++){
        printf("Nota del estudiante %d: ", i + 1);
        scanf("%d", &number->notas[i]);
    }
}

int high_note(Class *number){
    int high = number->notas[0]; 
    for(int i = 1; i < number->n; i++){
        if(number->notas[i] > high){
            high = number->notas[i];
        }
    }
    return high;
}

void print(Class number){
    for(int i = 0; i < number.n; i++){
        printf("Estudiante %d: %d\n", i + 1, number.notas[i]);
    }
}