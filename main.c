/**
* @file    main.c
* @author  Karolina Vorlickova <vorlka00@upol.cz>
* @date    1.12.2021
* @brief   Projekt Matice
*
* Modul pro praci s maticemi
**/

#include <stdio.h> 
#include <stdlib.h>
#include "matice.h"

int main()
{
    matice *mat1, *mat2, *mat3, *mat4, *mat5, *mat6, *mat7;

    mat1 = jednotkova(3, 4);
    if (!(kontrolaChyb() == BEZ_CHYBY)) {
        exit(1);
    }

    nastav_prvek(mat1, 0, 1, 2);
    nastav_prvek(mat1, 0, 2, 3);
    nastav_prvek(mat1, 0, 3, 4);
    nastav_prvek(mat1, 1, 0, 5);
    nastav_prvek(mat1, 2, 3, 1);

    if (!(kontrolaChyb() == BEZ_CHYBY)) {
        exit(1);
    }

    printf("Matice mat1: \n");
    if (kontrolaChyb() == BEZ_CHYBY) {
        vypis(mat1);
    } else {
        exit(1);
    }
    printf("\n");

    printf("Velikost matice mat1 v dimenzi 0 (radky): \n");
    printf("%d",velikost(mat1, 0));
    if (!(kontrolaChyb() == BEZ_CHYBY)) {
        exit(1);
    }
    printf("\n\n");

    printf("Velikost matice mat1 v dimenzi 1(sloupce): \n");
    printf("%d",velikost(mat1, 1));
    if (!(kontrolaChyb() == BEZ_CHYBY)) {
        exit(1);
    }
    printf("\n\n");

    printf("Prvek matice mat1 na pozici[0][1]: \n");
    printf("%f",prvek(mat1, 0, 1));
    if (!(kontrolaChyb() == BEZ_CHYBY)) {
        exit(1);
    }
    printf("\n\n");

    mat2 = transpozice(mat1);
    printf("Transpozice matice mat1: \n");
    if (kontrolaChyb() == BEZ_CHYBY) {
        vypis(mat2);
    }
    printf("\n\n");

    mat3 = plus(mat1, mat1);
    printf("Soucet matic mat1 + mat1: \n");
    if (kontrolaChyb() == BEZ_CHYBY) {
        vypis(mat3);
    }
    printf("\n\n");

    mat4 = nasobeni(mat1, 3);
    printf("Matice mat1 vynasobena 3: \n");
    if (kontrolaChyb() == BEZ_CHYBY) {
        vypis(mat4);
    }
    printf("\n\n");

    mat5 = krat(mat1, mat2);
    printf("Matice mat1 vynasobena transponovanou matici mat1: \n");
    if (kontrolaChyb() == BEZ_CHYBY) {
        vypis(mat5);
    }
    printf("\n\n");

    mat6 = krat(mat1, mat1);
    printf("Matice mat1 vynasobena matici mat1: \n");
    if (kontrolaChyb() == BEZ_CHYBY) {
        vypis(mat6);
    }
    printf("\n\n");

    printf("Matice mat1: \n");
    vypis(mat1);
    printf("\n");

    printf("Zmena hodnoty prvku matice mat1 na pozici[0][1] na 10: \n");
    nastav_prvek(mat1, 0, 1, 10.0);
    if (kontrolaChyb() == BEZ_CHYBY) {
        vypis(mat1);
    }
    printf("\n\n");

    printf("Matice nactena ze souboru soubor.txt: \n");
    char *soubor = "./soubor.txt";
    mat7 = nacti_ze_souboru(soubor);
    if (kontrolaChyb() == BEZ_CHYBY) {
        vypis(mat7);
    }
    printf("\n\n");

    printf("Matice mat1 ulozena do souboru soubor2.txt\n");
    char *soubor2 = "./soubor2.txt";
    uloz_do_souboru(mat1,soubor2);
    if (kontrolaChyb() == BEZ_CHYBY) {
        printf("OK.");
    }
    printf("\n");

    odstran(mat1);
    odstran(mat2);
    odstran(mat3);
    odstran(mat4);
    odstran(mat5);
    odstran(mat6);
    odstran(mat7);

    return 0;
}