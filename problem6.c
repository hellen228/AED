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
        printf("%d ", M[i]);
    }
    printf("\n");
}

int exists(int arr[], int size, int val) {
    for (int i = 0; i < size; i++)
        if (arr[i] == val) return 1;
    return 0;
}

int intersection(int A[], int n1, int B[], int n2, int result[]) {
    int count = 0;
    for (int i = 0; i < n1; i++) {
        if (exists(B, n2, A[i]) && !exists(result, count, A[i])) {
            result[count++] = A[i];
        }
    }
    return count;
}

int unionn(int A[], int n1, int B[], int n2, int result[]) {
    int count = 0;
    for (int i = 0; i < n1; i++)
        if (!exists(result, count, A[i]))
            result[count++] = A[i];
    for (int i = 0; i < n2; i++)
        if (!exists(result, count, B[i]))
            result[count++] = B[i];
    return count;
}

int difference(int A[], int n1, int B[], int n2, int result[]) {
    int count = 0;
    for (int i = 0; i < n1; i++) {
        if (!exists(B, n2, A[i]) && !exists(result, count, A[i])) {
            result[count++] = A[i];
        }
    }
    return count;
}

int main(){
    int number1, number2;

    printf("N° de elementos 1era lista: ");
    scanf("%d", &number1);
    int M[number1];
    in(number1, M);

    printf("N° de elementos 2era lista: ");
    scanf("%d", &number2);
    int N[number2];
    in(number2, N);

    int W[number1 + number2];
    int size = intersection(M, number1, N, number2, W);
    printf("The intersection is: ");
    print(size, W);

    int X[number1 + number2];
    int size2 = unionn(M, number1, N, number2, X);
    printf("The union is: ");
    print(size2, X);

    int Y[number1 + number2];
    int size3 = difference(M, number1, N, number2, Y);
    printf("The difference is: ");
    print(size3, Y);

    return 0;
}