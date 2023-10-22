#include "examen.h"



/*
Obtenga de la funcion "obtenerFrase" una frase distinta en cada invocacion. La funcion retorna
NULL cuando ya no tiene frases. Muestre por pantalla las 5 frases mas largas del total otorgado por
la funcion. Se asegura que ninguna frase supera los 1024 caracteres.


NOTA:
1.No asuma que existe una cantidad de frases, pueden ser menos, igual a 5 o cientos de miles
las devueltas por la funcion, solo muestre las 5 mas largas. Piense que en un sistema real la informacion
obtenida (en este caso simulada por la funcion) puede ser enorme y no existir capacidad de almacenamiento.
Piense la solucion en esos terminos. Se valora posivamente la genericidad en partes de la solucion.

2.El programa corre unicamente sobre compilador MINGW 64 bits, configure su entorno para poder correrlo.
*/

int main()
{
    int vec_letras[26];
    int* vec = vec_letras;

    inicializar_en_cero(vec,26);
    iniciales_mas_apariciones(vec);
    mostrar_vec(vec,26);

    //ordenamiento(vec,sizeof(int),26,compINT);

    //puts("\n\nORDENADO\n");

    //mostrar_vec(vec,26);
    buscar_5_max(vec,26);


    //La funcion obtenerFrase le dara una frase en cada invocacion y finalmente NULL cuando
    //no tenga mas frases para entregar. Analice el prototipo para evaluar como llamarla.


    return 0;

}
