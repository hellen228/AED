#include <stdio.h>

void copy(char str1[], char str2[]) {
    int i = 0;
    while(str1[i] != '\0') {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0'; 
}

void print(char M[]) {
    int i = 0;
    while(M[i] != '\0') {
        printf("%c", M[i]);
        i++;
    }
    printf("\n");
}

void in(char M[]) {
    char g;
    int size = 0;
    while(1){
        scanf("%c", &g);
        if (g == '\n') {
            break;
        }
        M[size] = g;
        size++;
    }
    M[size] = '\0'; 
}

int main() {
    char M[100];
    char N[100];

    in(M);
    copy(M, N);

    printf("Cadena copiada: ");
    print(N);

    return 0;
}
