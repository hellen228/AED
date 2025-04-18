#include <stdio.h>

void swap(int num1, int num2){
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
    printf("%d %d\n", num1, num2);
}

int main(){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    swap(num1, num2);

    return 0;   
}

/*En C se puede intercambiar el contenido de dos variables sin la creación de una tercera variable, 
  pero se necesita realizar operaciones lógicas para conseguirlo a diferencia de Python.
*/