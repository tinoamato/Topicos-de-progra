#include "examen.h"
void mostrar_vec (t_frase *vec, int ce)
{
    int i;

    printf("5 FRASES MAS LARGAS\n");
    for (i=0; i<ce; i++)
    {
        printf ("\n(%d) %s\t(%d caracteres)",i+1,vec->frase,vec->cant_letras);
        vec++;
    }
    puts("\n\n");
}

int compInt(const void*a,const void*b)
{
    int* A = (int*)a;
    int* B = (int*)b;
    return *A-*B;
}

int insertar_en_vec_ordenado(void* vec,int *ce,size_t tam,int cap,void* elem,int cmp(const void*, const void*))
{
    void* ini = vec;
    void* fin = vec +(tam * (*ce-1));
    int lleno=0;

    if(*ce == cap)
        lleno=1; ///lleno

    while(ini <= fin && cmp(elem,ini)<0)
        ini+=tam;

    if(ini <= fin || cmp(elem,ini)<0)
    {
        memmove(ini+tam,ini,((fin-(lleno*tam))-ini)+tam); ///lleno es 0 si no esta lleno o 1 si esta lleno;
        memcpy(ini,elem,tam);

        if(lleno ==0)
        {
            *ce+=1;
            return 1;
        }
    }

    return 0; ///perdio datos
}

void frases_mas_largas()
{
    t_frase vec_largas[5];
    t_frase *vec = vec_largas;
    int ce=0;
    t_frase frase;

    int cant_letras;

    while( obtenerFrase(frase.frase)!=NULL  )
    {
        cant_letras = strlen(frase.frase);
        frase.cant_letras = cant_letras;

        insertar_en_vec_ordenado(vec,&ce,sizeof(t_frase),5,&frase.cant_letras,compInt);
    }


    mostrar_vec(vec_largas,ce);
}
