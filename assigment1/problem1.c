#include <stdio.h>

void property(int number){
    int half1 = number / 100;
    int half2 = number % 100;
    int result = half1 + half2;

    printf("%d + %d = %d\n",half1, half2, result);

    if(result * result == number){
        printf("%d\nThe number satisfies the propierty.\n", result * result);
    }else{
        printf("%d\nThe number doesn't satisfies the property.\n",  result * result);
    }
}

int main(){
    int num;
    scanf("%d", &num);
    if(num > 9999 || num <1000){
        printf("Only numbers with 4 digits.\n");
    }else{
        property(num);
    }
    return 0;
}
