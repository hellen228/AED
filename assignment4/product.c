#include <stdio.h>
#include <assert.h>

void mul(int row1, int col1, int row2, int col2, int M[row1][col1], int N[row2][col2], int R[row1][col2]){
    assert(col1 == row2);
    for(int i=0; i<row1; i++){
        for(int j=0; j<col2; j++){
            R[i][j]=0;
            for(int k=0; k<col1; k++){
                R[i][j] += M[i][k] * N[k][j];
            }
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
    int M[3][3]={
        {3, 2, 1},
        {1, 1, 3},
        {0, 2, 1},
    };
    int N[3][2]={
        {2, 1},
        {1, 0},
        {3, 2},
    };
    printf("First matrix: \n");
    print(3, 3, M);
    printf("\nSecond matrix: \n");
    print(3, 2, N);

    int K[100][100];
    printf("\nResult: \n");
    mul(3,3,3,2,M,N,K);

    print(3, 2, K);

    return 0;
}