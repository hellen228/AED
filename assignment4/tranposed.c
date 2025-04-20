#include <stdio.h>
void tranposed(int row, int col, int M[][col], int T[][col]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            T[j][i] = M[i][j];
        }
    }
}

void in(int row, int col, int M[][col]){
    int number;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("[%d][%d]: ",i , j);
            scanf("%d", &number);
            M[i][j] = number;
        }
    }
}

void print(int row, int col, int M[][col]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int size;
    printf("Size: ");
    scanf("%d", &size);

    int M[size][size];
    in(size, size, M);

    int T[size][size];
    tranposed(size, size, M, T);

    printf("Real matrix:\n");
    print(size, size, M);
    printf("Tranposed matrix:\n");
    print(size, size, T);
}