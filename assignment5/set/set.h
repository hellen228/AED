#ifndef SET_H
#define SET_H
typedef struct set{
    int size;
    int S[100];
}Set;

void init(Set *conjunto);
void addition(Set *conjunto, int x);
void print(Set conjunto);
void unionS(Set *conjunto1, Set *conjunto2, Set * conjunto3);
void intersection(Set *conjunto1, Set *conjunto2, Set * conjunto3);
#endif