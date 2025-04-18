#include <stdio.h>

void addition(int num1, int num2){
    printf("Resultado: %d\n\n", num1 + num2);
}

void subtraction(int num1, int num2){
    printf("Resultado: %d\n\n", num1 - num2);
}

void multiplication(int num1, int num2){
    printf("Resultado: %d\n\n", num1 * num2);
}

void division(int num1, int num2){
    printf("Resultado: %d\n\n", num1 / num2);
}

void menu(){
    printf("------------------- MENU -------------------\n");
    printf("1) Addition\n");
    printf("2) Subtraction\n");
    printf("3) Multiplication\n");
    printf("4) Division\n");
    printf("5) Exit\n");
    printf("--------------------------------------------\n");
}

int main(){
    int option;
    do {
        menu();
        printf("Choose an option: ");
        scanf("%d", &option);

        int num1, num2;

        if(option >= 1 && option <= 4){
            printf("Number1: ");
            scanf("%d", &num1);
            printf("Number2: ");
            scanf("%d", &num2);
        }

        switch (option){
        case 1:
            addition(num1, num2);
            break;
        case 2:
            subtraction(num1, num2);
            break;
        case 3:
            multiplication(num1, num2);
            break;
        case 4:
            division(num1, num2);
            break;
        case 5:
            printf("Leaving...\n");
            break;
        default:
            printf("Invalid option. Try again.\n\n");
            break;
        }

    } while (option != 5);

    return 0;    
}