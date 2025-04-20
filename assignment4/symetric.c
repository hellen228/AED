#include <stdio.h>

int symetric(int row, int col, int M[][col]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(M[i][j]!=M[j][i]){
                return 0;
            }
        }
    }
    return 1;
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
    int matrix[4][4]={
        {1, 2, 3, 4},
        {2, 4, 5, 6},
        {3, 5, 8, 1},
        {4, 6, 1, 4},
    };

    print(4, 4, matrix);
    int option = symetric(4,4, matrix);
    if(option == 0){
        printf("The matrix is not symmetrical\n");
    }else{
        printf("The matrix is symmetrical\n");
    }
    return 0;
}