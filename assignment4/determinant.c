#include <stdio.h>

float determinant(int M[3][3]){
    float det;
    det = M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1])
        - M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0])
        + M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]);
    
    return det;
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
    int M[3][3];
    in(3 ,3, M);
    print(3, 3, M);
    int deter = determinant(M);    
    printf("Determinant: %d\n", deter);
    return 0;
}