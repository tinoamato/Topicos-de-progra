#include "examen.h"
void mostrar_vec_letras(t_letra *vec,int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        printf("\nLETRA %c ; APARICIONES: %d",vec->letra,vec->cant);
        vec++;
    }
}
int compLetra(const void* a, const void* b)
{
    t_letra* arg1 = (t_letra*)a;
    t_letra* arg2 = (t_letra*)b;

    return arg1->cant - arg2->cant;
}
int compINT(const void* a, const void* b)
{
    int* arg1 = (int*)a;
    int* arg2 = (int*)b;

    return *arg1 - *arg2;
}

void intercambio_gen (const void* a, const void* b,size_t tam)
{
    int i;
    char aux;

    for(i=0; i<0; i++)
    {
        aux = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = aux;

        a++;
        b++;
    }
}

void* buscar_menor(void* vec, size_t tam, int ce,int cmp(const void*, const void*))
{
    void* menor;
    int i;

    menor = vec;
    vec+=tam;

    for(i=0; i<ce-1; i++)
    {
        if(cmp(menor,vec)<0)
        {
            menor = vec;
        }
        vec+=tam;


    }
    return menor;
}
void ordenamiento(void* vec, size_t tam, int ce,int cmp(const void*, const void*))
{
    int i, ceaux=ce;;
    void *menor;
    for(i=0; i<(ce-1); i++)
    {
        menor = buscar_menor(vec, tam, ceaux, cmp);
        if(vec!=menor)
        {
            intercambio_gen(vec, menor, tam);
        }
        ceaux--;
        vec+=tam;
    }


}
int insertar_en_vec_ordenado(void* vec,void*elem,int tam,int *ce,int cap,int cmp(const void*,const void*))
{
    void* ini = vec;
    void* fin = vec + (*ce*tam);
    int lleno = 0;

    if(*ce == cap)
        lleno = 1;

    while( ini <= fin && cmp(elem,ini)<0)
        ini+=tam;



    memmove(ini+tam,ini,fin-(lleno*tam)-ini+tam);
    memcpy(ini,elem,tam);

    if(lleno == 0)
        *ce+=1;

    return 1;


    return 0;
}
void buscar_5_max(int* vec,int ce)
{


    t_letra vect[5];
    t_letra *vector = vect;
    t_letra aux;
    int ceV = 0,i;

    for(i=0; i<26; i++)
    {
        aux.cant = *vec;
        aux.letra = (i+97);



        insertar_en_vec_ordenado(vector,&aux,sizeof(int),&ceV,5,compLetra);
        vec++;
    }
    puts("\n MAX APARICIONES \n");

    mostrar_vec_letras(vector,ce);
}

void mostrar_vec(int* vec,int ce)
{
    int i;
    for(i=0; i<ce; i++)
    {
        printf ("\nLETRA %c : %d",(i+97),*vec);
        vec++;
    }
}

void inicializar_en_cero(int* vec,int ce)
{
    int i;
    for(i=0; i<ce; i++)
    {
        *vec = 0;
        vec++;
    }
}
void iniciales_mas_apariciones(int* vec)
{

    char frase[1024];
    char *letra_act;

    while(obtenerFrase(frase) != NULL)
    {
        letra_act = frase;

        while(*letra_act != '\0')
        {
            while(!isalpha(*letra_act))
                letra_act++;                ///borro espacios

            while(isalpha(*letra_act))
            {
                ///asignacion de pos
                *letra_act = tolower(*letra_act);

                *(vec + (*letra_act-97))+=1;

                letra_act++;

            }

        }


    }
}
