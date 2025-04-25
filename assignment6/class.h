#ifndef CLASS_H
#define CLASS_H

typedef struct clase{
    int n;
    int *notas;
}Class;

void init(Class *number);
int high_note(Class *number);
void print(Class number);

#endif