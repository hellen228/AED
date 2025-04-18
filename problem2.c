#include <stdio.h>

int esCapicua(int n) {
    int original = n;
    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }

    return original == reversed;
}

int main() {
    int numero;
    printf("Enter a number: ");
    scanf("%d", &numero);

    if (esCapicua(numero)) {
        printf("The number is capicua.\n");
    } else {
        printf("The number isn't capicua.\n");
    }

    return 0;
}