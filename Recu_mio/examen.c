#include <stdio.h>
#include "examen.h"

int my_strcmp(const char *cad1,const char*cad2)
{
    const char *p1=cad1;
    const char *p2=cad2;

    while(*p1!=0 && *p2!=0)
    {
        if(*p1!=*p2)
            return *p1-*p2;
        p1++;
        p2++;
    }
    if(*p1==0 && *p2!=0)
        return -1;
    if(*p1!=0 && *p2==0)
        return 1;

    return 0;
}

void intercambio_generica (void *a, void*b,unsigned tam)
{
    char aux;
    int i;
    for(i=0;i<tam;i++)
    {
        aux = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = aux;

        a++;
        b++;
    }
}


void *buscarMen(void *vec, unsigned ce, unsigned tam, int cmp(const void*, const void*))
{
    void* menor;
    int i;

    menor = vec;
    vec+=tam;

    for(i=0; i<(ce-1); i++)
    {
        if(cmp(menor, vec) > 0)
        {
            menor = vec;
        }
        vec+=tam;
    }
    return menor;
}

void* _ordenarSeleccion(void* vec, int ce, unsigned tam, int cmp(const void*, const void*)){

    int i, ceaux;
    void *menor;
    ceaux=ce;
    for(i=0; i<(ce-1); i++)
    {
        menor = buscarMen(vec, ceaux, tam, cmp);
        if(menor!=vec)
        {
            intercambio_generica(vec,menor,tam);
        }
        ceaux--;
        vec+=tam;
    }

return NULL;

}
int _cmpEmpleadoNombre(const void* a, const void* b){

    int comparacion;

    tEmpleado *auxA = (tEmpleado*)a;
    tEmpleado *auxB = (tEmpleado*)b;


    comparacion=my_strcmp(auxA->nomYAp,auxB->nomYAp);
    return comparacion;
}


int _cmp_enteros(const void* a, const void* b){

    int *auxA = (int*)a;
    int *auxB = (int*)b;

    return *auxA - *auxB;
}

int _cmp_str(const void* a, const void* b){
//strcmp
    return -1;
}

char* _mstrstr(const char *s1, const char *s2){
    return NULL;
}

int _contarCelulasVivasEnVecindario(int mat[][MAX_COL], int filas, int columnas, int fila, int columna){

    int i,j;
    int contaux=0;
    int cont=0;
    i=fila;
    j=columna;

    //ARRIBA
    if((i-1)>=0)
    {
        i--;
        if(mat[i][j]==1)
        {
            cont++;
        }
    }
    //IZQ
    if((j-1)>=0)
    {
        j--;
        if(mat[i][j]==1)
        {
            cont++;
        }
    }
    //ABAJO
    while((i+1)<filas-1 && contaux<2) //filas-1?
    {
        i++;
        if(mat[i][j]==1)
        {
            cont++;
        }
        contaux++;
    }
    contaux=0;
    //DERECHA
    while((j+1)<columnas-1 && contaux<2)
    {
        j++;
        if(mat[i][j]==1)
        {
            cont++;
        }
        contaux++;
    }

    contaux=0;
    //ARRIBA2
     while((i-1)>=0 && contaux<2)
    {
        i--;
        if(mat[i][j]==1)
        {
            cont++;
        }
        contaux++;
    }


    return cont;
}

