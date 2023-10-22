#include <stdio.h>
#include <string.h>
#include "examen.h"
#define TAM 1025

void mostrar5masLargas()
{
    int i, ce = 0;
    char frases[5][TAM];
    char frase[TAM];


    while(obtenerFrase(frase))
    {
        insertarOrdenadoPorTam(frases, frase, &ce, 5);
    }

    for(i=0; i<5; i++)
    {
        printf("\n%d) %s (%d caracteres) ", i+1, frases[i], strlen(frases[i]));
    }
}

void insertarOrdenadoPorTam(char matriz[][TAM], char * frase, int *ce, int tamMax)
{
    int i=0,j;

            if(*ce == 0)
            {
                strcpy(matriz[0], frase);
                (*ce)++;
            }

            else
            {
                while(i<*ce && compararLongitud(frase, matriz[i])<0)
                    i++;

                for(j=tamMax-1;j>i;j--)
                {
                    strcpy(matriz[j], matriz[j-1]);
                }

                strcpy(matriz[j], frase);

                if(*ce < tamMax)
                    (*ce) ++;
            }


}

int compararLongitud(char* cad1, char* cad2)
{
    return strlen(cad1) - strlen(cad2);
}
