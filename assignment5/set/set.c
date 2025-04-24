#include "set.h"
#include <stdio.h>
#include <assert.h>

int exist(Set *conjunto, int x){
    for(int i=0; i < conjunto->size; i++){
        if(conjunto->S[i]==x)return 1;
    }
    return 0;
}

void init(Set *conjunto) {
    printf("Valores para el conjunto. Ingrese tamaño: ");
    scanf("%d", &conjunto->size);  

    for(int i = 0; i < conjunto->size; i++) {
        printf("%d: ", i + 1);
        scanf("%d", &conjunto->S[i]);  
    }
}

void addition(Set *conjunto, int x) {
    if (!exist(conjunto, x)) {
        if (conjunto->size < 100) {
            conjunto->S[conjunto->size] = x;
            conjunto->size++;
        }
    } else {
        printf("El elemento ya se encuentra en el conjunto.\n");
    }
}

void print(Set conjunto){
    printf("Elementos del conjunto: {");
    for(int i = 0; i < conjunto.size; i++){
        printf("%d ", conjunto.S[i]);
    }
    printf("}\n");
}

void unionS(Set *conjunto1, Set *conjunto2, Set * conjunto3){
    assert(conjunto1->size > 0 && conjunto2->size > 0);
    
    conjunto3->size = 0;

    for(int i=0; i< conjunto1->size; i++){
        conjunto3->S[i] = conjunto1->S[i];
    }
    conjunto3->size = conjunto1->size;
    for(int j=0; j<conjunto2->size; j++){
        if(!exist(conjunto3, conjunto2->S[j])){
            conjunto3->S[conjunto3->size] = conjunto2->S[j];
            conjunto3->size++;
        }
    }
}

void intersection(Set* conjunto1, Set* conjunto2, Set* conjunto3) {
    assert(conjunto1->size >= 0 && conjunto2->size >= 0);
    conjunto3->size = 0;

    for (int i = 0; i < conjunto1->size; i++) {
        for (int j = 0; j < conjunto2->size; j++) {
            if (conjunto1->S[i] == conjunto2->S[j]) {
                if (!exist(conjunto3, conjunto1->S[i])) {
                    conjunto3->S[conjunto3->size] = conjunto1->S[i];
                    conjunto3->size++;
                }
            }
        }
    }
}
