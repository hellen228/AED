#include <stdio.h>

int compare(char str1[], char str2[]) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0; 
    } else if (str1[i] == '\0') {
        return -1; 
    } else {
        return 1; 
    }
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

    printf("Cadena 1: ");
    in(M);
    printf("Cadena 2: ");
    in(N);

    int resultado = compare(M, N);

    /*
    if (resultado == 0) {
        printf("Las cadenas son iguales\n");
    } else if (resultado < 0) {
        printf("La primera cadena es menor\n");
    } else {
        printf("La primera cadena es mayor\n");
    }*/

   printf("%d\n", resultado);

    return 0;
}

