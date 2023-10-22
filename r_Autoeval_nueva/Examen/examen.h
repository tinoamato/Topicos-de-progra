#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED
#define TAM 1024

typedef struct
{
    int cant_letras;
    char frase[1025];
}t_frase;

void mostrar_vec (t_frase* vec, int ce);
int compInt(const void*a,const void*b);
int insertar_en_vec_ordenado(void* vec,int *ce,size_t tam,int cap,void* elem,int cmp(const void*, const void*));
char* obtenerFrase(char* frase);
void frases_mas_largas();


#endif // EXAMEN_H_INCLUDED
