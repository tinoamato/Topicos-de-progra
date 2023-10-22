#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED
#define TAM 1024

typedef struct
{
    int cant;
    char letra;
}t_letra;


int compINT(const void* a, const void* b);
void intercambio_gen (const void* a, const void* b,size_t tam);
void* buscar_menor(void* vec, size_t tam, int ce,int cmp(const void*, const void*));
void ordenamiento(void* vec, size_t tam, int ce,int cmp(const void*, const void*));
void mostrar_vec(int* vec,int ce);
void inicializar_en_cero(int* vec,int ce);
void buscar_5_max(int* vec,int ce);
char* obtenerFrase(char* frase);
void iniciales_mas_apariciones(int* vec);


#endif // EXAMEN_H_INCLUDED
