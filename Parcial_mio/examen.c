#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "examen.h"

int my_isalpha(int c)
{
    if((c>='A' && c<='Z')|| (c>='a' && c<='z'))
    {
        return 1;
    }
    else
        return 0;
}
int my_strcmp(const char* cad1, const char *cad2)
{
    int val=0;
    while (*cad1!=0 && *cad2!=0)
    {
        if((*cad1-*cad2)!=0)
        {
            return *cad1-*cad2;
        }
        cad1++;
        cad2++;
    }

    if(*cad1==0 && *cad2!=0)
    {
        return -1;
    }
    if(*cad1!=0 && *cad2==0)
    {
        return 1;
    }
    return val;
}


int _contarPalabras(const char* nomArc, char* palMasLarga, int* cantVeces)
{
    FILE* pf;
    char linea[1024];
    char *letra_act;

    unsigned apariciones;
    char max_pal[100];
    int max_letras = 0;

    int aux_letras;

    unsigned total_palabras = 0;



    pf = fopen(nomArc,"rt");
    if(!pf)
        return -1;

    while(fgets(linea,1024,pf)!=NULL) ///cada linea
    {
        letra_act = linea;

        while(*letra_act != '\0')
        {
            while(!isalpha(*letra_act))   ///avanzo los espacios
                letra_act++;

            aux_letras = 0; //reinicio letras


            while(isalpha(*letra_act)) ///nueva palabra
            {
                aux_letras++;
                letra_act++;

            }


                total_palabras++;

            if(aux_letras > max_letras) ///nuevo max
            {
                max_letras = aux_letras;
                strncpy(max_pal,letra_act-aux_letras,aux_letras);
                apariciones =1;
            }
            else if(strncmp(max_pal,letra_act-aux_letras,aux_letras) == 0)  ///aparicion del max
                apariciones++;



        }




    }

    strncpy(palMasLarga,max_pal,max_letras);
    *cantVeces = apariciones;

    return total_palabras;


}



void* _bbinaria(const void *clave, const void *vec, size_t ce, size_t tam, int cmp(const void *, const void *))
{
    int medio = (ce/2);
    void* mid = (char*)vec + (tam*medio);
    int compare = (cmp(clave,mid));

    if(compare == 0)
        return mid;
    else if(medio == 0)
        return NULL;
    else if(compare < 0)
        return _bbinaria(clave,vec,medio,tam,cmp);
    else
        return _bbinaria(clave, (char*)vec+(tam*(medio+1)),ce-medio-1,tam,cmp);



}


int _sumTrianDerEntreDiag(int mat[][MAX_COL], int filas)
{
    return 0;
}

int _sumTrianInfEntreDiag(int mat[][MAX_COL], int filas)
{



    return 0;
}
