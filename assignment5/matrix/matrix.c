#include "matrix.h"
#include <stdio.h>
#include <assert.h>

void init(Matrix *matriz){
    printf("Cantidad de filas: ");
    scanf("%d",&matriz->row);
    printf("Cantidad de columnas: ");
    scanf("%d",&matriz->col);

    int number;
    for(int i=0; i<matriz->row; i++){
        for(int j=0; j<matriz->col; j++){
            printf("[%d][%d]: ",i , j);
            scanf("%d", &number);
            matriz->M[i][j] = number;
        }
    }
}
void print(Matrix matriz){
    for(int i=0; i<matriz.row; i++){
        for(int j=0; j<matriz.col; j++){
            printf("%d ", matriz.M[i][j]);
        }
        printf("\n");
    }
}

void mult(Matrix *matriz1, Matrix *matriz2, Matrix *matriz3){
    assert(matriz1->col == matriz2->row);
    
    for(int i = 0; i < matriz1->row; i++) {
        for(int j = 0; j < matriz2->col; j++) {
            matriz3->M[i][j] = 0; 
        }
    }//Inicializa toda la triz con ceros.

    for(int i = 0; i < matriz1->row; i++) {
        for(int j = 0; j < matriz2->col; j++) {
            for(int k = 0; k < matriz1->col; k++) {
                matriz3->M[i][j] += matriz1->M[i][k] * matriz2->M[k][j];
            }
        }
    }//Multiplica ambas matrices.
}


void transposed(Matrix *matriz1, Matrix *matriz2){
    matriz2->row = matriz1->col;
    matriz2->col = matriz1->row;

    for(int i=0; i<matriz1->row; i++){
        for(int j=0; j<matriz1->col; j++){
            matriz2->M[j][i] = matriz1->M[i][j];
        }
    }
}