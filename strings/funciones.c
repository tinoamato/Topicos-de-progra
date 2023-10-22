#include "funciones.h"

size_t my_strlen(const char* s)
{
    int cant_caracteres = 0;

    while(*s)
    {
        cant_caracteres++;
        s++;
    }
    return cant_caracteres;
}
char *my_strstr(const char *s1, const char *s2)
{
    int flag,contador=0;
    if(!my_strlen(s2))
        return (char*)s1;

    while(*s1 && *s2)
    {

        while(*s1 && *s2 && !flag)
        {


            if(*s1 != *s2)
                flag = 1;
            s1++;
            s2++;
            contador++;
        }
        if(!*s2 && !flag)
            return (char*)s1-contador;
            flag = 0;
        s2-=contador;
        contador = 0;

    }

    return NULL;

}

char *my_strcpy(char *s1, const char *s2)
{
    char* ini = s1;

    while(*s2)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *(s1) = '\0';

    return ini;

}


