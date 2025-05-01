#include <stdio.h>
#include <stdlib.h>

typedef struct cub{
    int m, n, k;
    double *vec;
}Cube;


void init(Cube *cubo) {
    printf("Dimensiones m - n - k: ");
    scanf("%d %d %d", &cubo->m, &cubo->n, &cubo->k);

    int total = cubo->m * cubo->n * cubo->k;
    cubo->vec = malloc(total * sizeof(double));

    for (int i = 0; i < cubo->m; i++) {
        for (int j = 0; j < cubo->n; j++) {
            for (int l = 0; l < cubo->k; l++) {
                int index = i * (cubo->n * cubo->k) + j * cubo->k + l;
                printf("Elemento [%d][%d][%d]: ", i, j, l);
                scanf("%lf", &cubo->vec[index]);
            }
        }
    }
}

void print(Cube cubo) {
    for (int l = 0; l < cubo.k; l++) {
        printf("Capa k = %d:\n", l + 1);
        for (int i = 0; i < cubo.m; i++) {
            for (int j = 0; j < cubo.n; j++) {
                int index = i * (cubo.n * cubo.k) + j * cubo.k + l;
                printf("%.2f\t", cubo.vec[index]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void free_cube(Cube *cubo) {
    free(cubo->vec);
}

int main() {
    Cube cubo;

    init(&cubo);
    printf("\nValores del cubo:\n");
    print(cubo);

    free_cube(&cubo);
    return 0;
}