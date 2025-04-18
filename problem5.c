#include <stdio.h>

void in(int number, int M[]){
    for(int i = 0; i<number; i++){
        int numbers;
        scanf("%d", &numbers);
        M[i] = numbers;
    }
}

void print(int number, int M[]){
    for(int i=0; i < number; i++){
        printf("%d, ", M[i]);
    }
    printf("\n");
}

int small(int num, int M[]){
    int number = 1000;
    for(int i = 0; i < num; i++){
        if(M[i] < number){
            number = M[i];
        }
    }
    return number;
}

int big(int num, int M[]){
    int number = 0;
    for(int i = 0; i < num; i++){
        if(M[i] > number){
            number = M[i];
        }
    }
    return number;
}

void difference(int number, int M[]){
    int smallest = small(number, M);
    int biggest = big(number, M);
    int dif = biggest - smallest;
    printf("Absolute difference is = %d\n", dif);
}

int main(){
    int number;
    printf("N° de elementos: ");
    scanf("%d", &number);
    
    int M[number];

    in(number, M);
    print(number, M);
    difference(number, M);
    return 0;
}