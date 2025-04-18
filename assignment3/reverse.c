#include <stdio.h>

void reverse(char str[]){
    int size = 0;
    int i=0;
    while(str[i] != '\0'){
        size++;
        i++;
    }

    for(int i = size; i>=0; i--){
        printf("%c", str[i]);
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

int main(){
    char M[100];
    in(M);
    reverse(M);

    return 0;
}