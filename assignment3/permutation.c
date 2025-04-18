#include <stdio.h>

int permutation(int row, int col, int M[][col]){
    for(int i=0; i<row; i++){
        int countRow = 0;
        int countCol = 0;
        for(int j=0; j<col; j++){
            countRow += M[i][j];   
            countCol += M[j][i];   
        }
        if(countRow != 1 || countCol != 1){
            return 0;
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
    int M[4][4]={
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0},
        {0, 0, 1, 0},
    };

    print(4, 4, M);
    int contador = permutation(4, 4, M);
    if(contador == 1){
        printf("It is a permutation matrix\n");
    }else{
        printf("It isn't a permutation matrix\n");
    }

    return 0;
}