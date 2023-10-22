#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "examen.h"
typedef struct
{
    char palabra[64];
    int cantLetras;
} tPalabra;
int crearLotePruebaTxtFrasesSimMIO(const char* nomArch)
{

    FILE *pf;
    char texto1[512] = "Estudio Ingenieria en Informatica en la Universidad Nacional De La Matanza, la carrera esta orientada a programar.\nMi materia favorita es Topicos de programacion y Arquitectura de Computadoras.\nUn desarrollador tiene que tener caracteristicas especificas como creatividad y resolutividad.\n";

    pf = fopen(nomArch,"wt");
    if(!pf)
    {
        puts("\nError al crear el archivo de pruebas");
        exit(1);
    }

    fwrite(texto1,512,1,pf);

    fclose(pf);
    return 1;
}
int cmp (void* a, void*b)
{
    tPalabra* auxA = (tPalabra*)a;
    tPalabra* auxB = (tPalabra*)b;
    return (auxA->cantLetras-auxB->cantLetras);
}
void intercambio_generico(void*a, void* b,int tam)
{
    char aux;
    int i;

    for(i=0; i<tam; i++)
    {
        aux = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = aux;
        a++;
        b++;

    }
}
void *buscarMenor(void* vec, int ce, int tam, int cmp(void*,void*))
{
    void* menor;
    int i;

    menor = vec;
    vec+=tam;
    for(i=0; i<(ce-1); i++)
    {
        if(cmp(menor,vec)<0)
        {
            menor = vec;
        }
        vec+=tam;
    }
    return menor;
}
void ordenamiento(void* vec, int ce, int tam, int cmp(void*,void*))
{
    void* menor;
    int i;
    int ceaux = ce;

    for(i=0; i<ce; i++)
    {
        menor = buscarMenor(vec,ceaux,tam,cmp);
        if(menor!=vec)
        {
            intercambio_generico(menor,vec,tam);
        }
        ceaux--;
        vec+=tam;
    }
}
int crearVectorPalabras(tPalabra **vec, int ce)
{
    *vec = (tPalabra*)malloc(sizeof(tPalabra)*ce);
    if(!vec)
        return 1;
    return 0;
}
void escribirEnVector(tPalabra *vec,int ce, FILE*pf)
{
    int i;
    for(i=0; i<ce; i++)
    {
        fprintf(pf,"PALABRA: %s LETRAS: %d\n",vec->palabra,vec->cantLetras);
        vec++;
    }
}
void agregarTab(char*cad, int ce)
{
    while(ce)
    {
        cad++;
        ce--;
    }
    *cad = '\0';
}
int cmpCantLetras (void* a,void* b)
{
    tPalabra* auxA = (tPalabra*)a;
    tPalabra* auxB = (tPalabra*)b;

    return auxA->cantLetras - auxB->cantLetras;

}

int buscarMenorInt(tPalabra* vec,int ce)
{
    int menor;
    int i;
    menor = vec->cantLetras;
    vec++;
    for(i=0; i<ce-1; i++)
    {
        if(vec->cantLetras < menor)
        {
            menor = vec->cantLetras;
        }
        vec++;

    }
    return menor;
}
int buscarPalabra(tPalabra *vec,int ce, char* buscado)
{
    int i;
    for(i=0; i<ce; i++)
    {
        if(strcmp(vec->palabra,buscado)==0)
        {
            return 0;
        }
        vec++;

    }
    return 1;
}

int palabrasMasLargasMIO(const char* archEntrada, const char* archSalida)
{

    FILE *pe,*ps;
    char linea[512];
    tPalabra *vec; ///almacena las palabras
    int contAux;
    int minLetras = 0;
    char *letra;
    char auxPal[64];
    int cantPalabrasCargadas=0;



    pe = fopen(archEntrada,"rt");
    ps = fopen(archSalida,"wt");
    if(!pe || !ps)
    {
        puts("\nError al abrir algun archivo");
        exit(2);
    }

    if(crearVectorPalabras(&vec,15)!=0)
    {
        puts("Error al asignar memoria");
        exit(3);
    }

    while(fgets(linea,512,pe) != NULL)
    {
        letra = linea;
        while(*letra!= '\n')
        {
            contAux=0;
            while(isalpha(*letra))
            {
                letra++;
                contAux++;
            }


            if(contAux > minLetras && cantPalabrasCargadas<15)
            {
                letra-=contAux;
                strncpy(auxPal,letra,contAux);
                agregarTab(auxPal,contAux);

                if(buscarPalabra(vec,cantPalabrasCargadas,auxPal)==1)
                {


                    strncpy(vec->palabra,auxPal,contAux);

                    agregarTab(vec->palabra,contAux);
                    vec->cantLetras = contAux;
                    letra+=contAux;
                    //minLetras = contAux;
                    cantPalabrasCargadas++;

                    vec-=(cantPalabrasCargadas-1);
                    minLetras = buscarMenorInt(vec,cantPalabrasCargadas);
                    vec+=cantPalabrasCargadas;

                }


            }

            letra++;
        }
    }



    vec-=cantPalabrasCargadas;

    ordenamiento(vec,cantPalabrasCargadas,sizeof(tPalabra),cmpCantLetras);
    escribirEnVector(vec,15,ps);


    free(vec);
    return 1;
}
