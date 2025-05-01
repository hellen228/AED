#include <stdio.h>
#include <stdlib.h>

typedef struct vec{
    int n;
    int *vec;
}Vector;

void init(Vector *list){
    printf("Cantidad de números a ingresar: ");
    scanf("%d", &list->n);

    list->vec=malloc(list->n * sizeof(int));

    for(int i=0; i<list->n; i++){
        printf("Número: ");
        scanf("%d", &list->vec[i]);
    }
}

void print(Vector list){
    for(int i=0; i<list.n; i++){
        printf("%d ", list.vec[i]);
    }
    printf("\n");
}

void positivo(Vector list1, Vector *resultado){
    int count=0;
    for(int i=0; i<list1.n; i++){
        if(list1.vec[i] > 0){
            count++;
        }
    }

    resultado->n = count;
    resultado->vec = malloc(resultado->n * sizeof(int));

    int index = 0;
    for (int i = 0; i < list1.n; i++) {
        if (list1.vec[i] > 0) {
            resultado->vec[index++] = list1.vec[i];
        }
    }

}

int main(){
    Vector vector, positivos;
    init(&vector);

    positivo(vector, &positivos);
    printf("Vector con positivos: ");
    print(positivos);

    free(vector.vec);
    free(positivos.vec);
}