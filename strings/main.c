#include "funciones.h"

int main()
{
    char cad[]="Hola como estas";
    char buscar[]="como";

    int letras,letras2;

    letras = my_strlen(cad);
    letras2 = my_strlen(cad);

    ///------------------------------------------------------///


    if(my_strstr(cad,buscar)!=NULL)
        puts(my_strstr(cad,buscar));
    else
        puts("NULL");

    if(strstr(cad,buscar)!=NULL)
        puts(strstr(cad,buscar));
    else
        puts("NULL");

    ///------------------------------------------------------///


    return 0;
}
