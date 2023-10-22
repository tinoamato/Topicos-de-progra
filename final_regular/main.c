#include <stdio.h>
#include <stdlib.h>
#include "examen.h"
#define ARCHFRASES              "frases.txt"
#define ARCHPALABRASMASLARGAS   "palabrasMasLargas.txt"
#define FALLOLOTEPRUEBA         100
#define FALLOPALABRAMASLARGAS   101

#define RENDIREXAMEN
#ifdef RENDIREXAMEN
    #define palabrasMasLargas           palabrasMasLargasMIO
    #define crearLotePruebaTxtFrasesSim crearLotePruebaTxtFrasesSimMIO
#endif //


int main()
{


    if(!crearLotePruebaTxtFrasesSim(ARCHFRASES)){
        puts("No se ha podido crear archivo lote de prueba");
        return FALLOLOTEPRUEBA;
    }

    if(!palabrasMasLargas(ARCHFRASES, ARCHPALABRASMASLARGAS)){
        puts("No se ha podido procesar el archivo");
        return FALLOPALABRAMASLARGAS;
    }


    //remove(ARCHFRASES);
    return 0;
}
