#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "examen.h"

#define RENDIR_EXAMEN_UNAHORA
#define RENDIR_EXAMEN_DOSHORAS
//#define RENDIR_EXAMEN_TRESHORAS

#ifdef RENDIR_EXAMEN_UNAHORA
    #define ordenarSeleccion                _ordenarSeleccion
    #define cmpEmpleadoNombre               _cmpEmpleadoNombre
    #define cmp_enteros                     _cmp_enteros
    #define cmp_str                         _cmp_str
#endif

#ifdef RENDIR_EXAMEN_DOSHORAS
    #define contarCelulasVivasEnVecindario  _contarCelulasVivasEnVecindario

#endif


#ifdef RENDIR_EXAMEN_TRESHORAS
    #define mstrstr _mstrstr
#endif



MU_TEST(test_OrdenamientoEnteros){
    int vecDes[] = {7,33,99,5,165,16,18,3};
    int vecOrd[sizeof(vecDes)];//Resuelve en tiempo de compilacion no es VLA

    memcpy(vecOrd, vecDes, sizeof(vecDes));

    qsort(vecOrd, sizeof(vecDes)/sizeof(vecDes[0]), sizeof(vecDes[0]), cmp_enteros);
    ordenarSeleccion(vecDes, sizeof(vecDes)/sizeof(vecDes[0]), sizeof(vecDes[0]), cmp_enteros);

    mu_assert( memcmp(vecDes, vecOrd, sizeof(vecDes))==0 , "Los vectores no son iguales");

}

MU_TEST(test_OrdenamientoEmpleados){
    tEmpleado vecDes[] = {  {6, "Gerd Muller", 200.0},
                            {3, "Eusebio", 100.1},
                            {16,"Zinedine Zidane", 200.0},
                            {9, "Franz Beckenbauer", 300.0},
                            {18,"Carlos Valderrama",300.0},
                            {15,"Johan Cruyff", 600.0},
                            {12,"Alfredo Di Stefano", 500.0},
                     };

    tEmpleado vecOrd[sizeof(vecDes)];

    memcpy(vecOrd, vecDes, sizeof(vecDes));

    qsort(vecOrd, sizeof(vecDes)/sizeof(vecDes[0]), sizeof(vecDes[0]), cmpEmpleadoNombre);
    ordenarSeleccion(vecDes, sizeof(vecDes)/sizeof(vecDes[0]), sizeof(vecDes[0]), cmpEmpleadoNombre);

    mu_assert( memcmp(vecDes, vecOrd, sizeof(vecDes))==0 , "Los vectores no son iguales");
}

MU_TEST(test_OrdenamientoEnteros2){
    int vecDes[] = {6};
    int vecOrd[] = {6};

    qsort(vecOrd, sizeof(vecDes)/sizeof(vecDes[0]), sizeof(vecDes[0]), cmpEmpleadoNombre);
    ordenarSeleccion(vecDes, sizeof(vecDes)/sizeof(vecDes[0]), sizeof(vecDes[0]), cmp_enteros);
    mu_assert( memcmp(vecDes, vecOrd, sizeof(vecDes))==0 , "Los vectores no son iguales");
}




MU_TEST(test_celulas01){
    const int filas       = 6;
    const int columnas    = 8;
    int mat[][MAX_COL] = {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}

    };

    mu_assert(contarCelulasVivasEnVecindario(mat, filas, columnas, 0, 0)==0, "Matriz error 01.01");
    mu_assert(contarCelulasVivasEnVecindario(mat, filas, columnas, 5, 7)==0, "Matriz error 01.02");
    mu_assert(contarCelulasVivasEnVecindario(mat, filas, columnas, 3, 3)==0, "Matriz error 01.03");
}

MU_TEST(test_celulas02){
    const int filas       = 6;
    const int columnas    = 8;
    int mat[][MAX_COL] = {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,0,0},
        {0,0,0,1,1,0,0,0},
        {0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0}

    };

    mu_assert(contarCelulasVivasEnVecindario(mat, filas, columnas, 3, 3)==3, "Matriz error 02.01");
    mu_assert(contarCelulasVivasEnVecindario(mat, filas, columnas, 2, 5)==2, "Matriz error 02.02");
    mu_assert(contarCelulasVivasEnVecindario(mat, filas, columnas, 5, 7)==1, "Matriz error 02.03");
}

MU_TEST(test_strstr01){

    char str[]    =  "el anana";
    char substr[]  =   "ana";
    mu_assert( mstrstr(str, substr)==strstr(str, substr) , "Error test 01 strstr");

}

MU_TEST(test_strstr02){

    char str[]    =  "el anana";
    char substr[]  = "nada";
    mu_assert( mstrstr(str, substr)==strstr(str, substr) , "Error test 02 strstr");
}

MU_TEST(test_strstr03){

    char str[]    =  "el anana";
    char substr[]  = "";
    mu_assert( mstrstr(str, substr)==strstr(str, substr) , "Error test 03 strstr");
}

MU_TEST(test_strstr04){

    char str[]    =  "";
    char substr[]  = "estas?";
    mu_assert( mstrstr(str, substr)==strstr(str, substr) , "Error test 04 strstr");
}

MU_TEST(test_strstr05){

    char str[]    =  "El ciudadano Kane";
    char substr[]  = "ciudadano";
    mu_assert( mstrstr(str, substr)==strstr(str, substr) , "Error test 05 strstr");
}




MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_OrdenamientoEnteros);
    MU_RUN_TEST(test_OrdenamientoEmpleados);
    MU_RUN_TEST(test_OrdenamientoEnteros2);

    MU_RUN_TEST(test_OrdenamientoEnteros);
    MU_RUN_TEST(test_OrdenamientoEmpleados);
    MU_RUN_TEST(test_OrdenamientoEnteros2);

    MU_RUN_TEST(test_celulas01);
    MU_RUN_TEST(test_celulas02);

    MU_RUN_TEST(test_strstr01);
    MU_RUN_TEST(test_strstr02);
    MU_RUN_TEST(test_strstr03);
    MU_RUN_TEST(test_strstr04);
    MU_RUN_TEST(test_strstr05);
}





int main()
{
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
