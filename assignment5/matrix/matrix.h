#ifndef MATRIX_H
#define MATRIX_H
#define MAX 100

typedef struct matrix{
    int row, col;
    int M[MAX][MAX];
}Matrix;

void init(Matrix *matriz);
void print(Matrix matriz);
void mult(Matrix *matriz1, Matrix *matriz2, Matrix *matriz3);
void transposed(Matrix *matriz1, Matrix *matriz2);
#endif