#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED
#define TAM 1025

char* obtenerFrase(char* frase);
void mostrar5MasLargas();
void insertarOrdenadoPorTam(char matriz[][TAM], char * frase, int *ce, int tamMax);
int compararLongitud(char* cad1, char* cad2);

#endif // EXAMEN_H_INCLUDED
