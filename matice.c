/**
* @file    matice.c
* @author  Karolina Vorlickova <vorlka00@upol.cz>
* @date    1.12.2021
* @brief   Projekt Matice
*
* Modul pro praci s maticemi
**/

#include <stdio.h> 
#include <stdlib.h>
#include "matice.h"

// funkce vytvori matici typu m × n, vcetne alokovanı pole pro prvky matice
matice* inicializace(int m, int n) {
    // kontrola nenulove matice
    if (m == 0 || n == 0) {
        chyba = CHYBA_TYPU;
        return NULL;
    }

    matice* nova_matice = calloc(1, sizeof(*nova_matice));
    nova_matice->m = m;
    nova_matice->n = n;

    // dynamicka alokace pameti
    nova_matice->data = calloc(nova_matice->m, sizeof(*nova_matice->data));
    for(int i = 0; i < nova_matice->m; ++i) {
        nova_matice->data[i] = calloc(nova_matice->n, sizeof(**nova_matice->data));
    }

    // kontrola alokace
    if (!nova_matice || !nova_matice->data) //?
    {
        odstran(nova_matice);
        chyba = CHYBA_ALOKACE;
        return NULL;
    }

    chyba = BEZ_CHYBY;
    return nova_matice;
};

// funkce vytvorı jednotkovou matici typu m × n
matice* jednotkova(int m, int n) {
    matice* nova_matice = inicializace(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                nova_matice->data[i][j] = 1;
            } else {
                nova_matice->data[i][j] = 0;
            }
        }
    }
    chyba = BEZ_CHYBY;
    return nova_matice;
};

// funkce vytvorı nulovou matici typu m × n
matice* nulova(int m, int n) {
    matice* nova_matice = inicializace(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            nova_matice->data[i][j] = 0;
        }
    }
    chyba = BEZ_CHYBY;
    return nova_matice;
};

// funkce, ktera dealokuje pamet alokovanou pro matici mat
void odstran(matice* mat) {
    for (int i = 0; i < mat->m; i++)
    {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
    chyba = BEZ_CHYBY;
};

// funkce pro vypis matice do konzole
void vypis(matice* mat) {
    for (int i = 0; i < mat->m; i++)
    {
        for (int j = 0; j < mat->n; j++)
        {
            printf("%f ", mat->data[i][j]);
        }
        printf("\n");
    }
    chyba = BEZ_CHYBY;
};

// funkce, ktera nastavı prvek matice mat v i-tem radku a j-tem sloupci na hodnotu hodnota
void nastav_prvek(matice* mat, int i, int j, float hodnota) {
    if (!(0 <= i <= mat->m) || !(0 <= j <= mat->n)) {
        chyba = CHYBA_TYPU;
        return;
    }

    mat->data[i][j] = hodnota;
    chyba = BEZ_CHYBY;
    return;
};

// funkce, ktera vracı matici, ktera vznikla transpozicı matice mat
matice* transpozice(matice* mat) {
    matice* trans_matice = inicializace(mat->n, mat->m);
    for (int i = 0; i < mat->m; i++) {
        for (int j = 0; j < mat->n; j++) {
            trans_matice->data[j][i] = mat->data[i][j];
        }
    }
    chyba = BEZ_CHYBY;
    return trans_matice;
};

// funkce, ktera vracı soucet matic mat1 a mat2
matice* plus(matice* mat1, matice* mat2) {
    matice* sectena_matice = inicializace(mat1->m, mat1->n);
    for (int i = 0; i < mat1->m; i++) {
        for (int j = 0; j < mat1->n; j++) {
            sectena_matice->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    chyba = BEZ_CHYBY;
    return sectena_matice;
};

// funkce, ktera vracı rozdıl matic mat1 a mat2
matice* minus(matice* mat1, matice* mat2) {
    matice* odectena_matice = inicializace(mat1->m, mat1->n);
    for (int i = 0; i < mat1->m; i++) {
        for (int j = 0; j < mat1->n; j++) {
            odectena_matice->data[i][j] = mat1->data[i][j] - mat2->data[i][j];
        }
    }
    chyba = BEZ_CHYBY;
    return odectena_matice;
};

// funkce, ktera vracı matici, ktera vznikla z matice mat vynasobenım skalarem skalar
matice* nasobeni(matice* mat, float skalar) {
    matice* vynasobena_matice = inicializace(mat->m, mat->n);
    for (int i = 0; i < mat->m; i++) {
        for (int j = 0; j < mat->n; j++) {
            vynasobena_matice->data[i][j] = mat->data[i][j] * skalar;
        }
    }
    chyba = BEZ_CHYBY;
    return vynasobena_matice;
};

// funkce, ktera vracı soucin matic mat1 a mat2
matice* krat(matice* mat1, matice* mat2) {
    matice* vynasobena_matice = inicializace(mat1->m, mat2->n);
    for (int i = 0; i < mat1->m; i++) {
        for (int j = 0; j < mat2->n; j++) {
            for (int k = 0; k < mat1->n; k++)
            {
                vynasobena_matice->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
            }
        }
    }
    chyba = BEZ_CHYBY;
    return vynasobena_matice;
};

// funkce, ktera vracı velikost matice v dimenzi dimenze
int velikost(matice* mat, int dimenze) {
    if (dimenze == 0) {
        return mat->m;
    } else if (dimenze == 1) {
        return mat->n;
    } else {
        chyba = JINA_CHYBA;
        return;
    }
};

// funkce, ktera vracı prvek matice mat v i-tem radku a j-tem sloupci
float prvek(matice* mat, int i, int j) {
    if (!(0 <= i <= mat->m) || !(0 <= j <= mat->n)) {
        chyba = CHYBA_TYPU;
        return;
    }

    return mat->data[i][j];
};

/*

// funkce, ktera vracı matici, ktera je ulozena v souboru soubor. Kazdy radek souboru reprezentuje radek matice a jednotlive prvky matice jsou oddeleny mezerou.
matice* nacti_ze_souboru(const char *soubor) {
    if (soubor == NULL)
        //ERROR
    }

    obsah = fopen(soubor, "r");

    obsah = fclose(soubor);


};

// funkce, ktera ulozı matici mat do souboru soubor (ve stejnem formatu, jako v predchozım bodu)
matice* uloz_do_souboru(matice* mat, const char *soubor) {
    if (soubor == NULL)
        //ERROR
    }

    obsah = fopen(soubor, "w");

    obsah = fclose(soubor);

    if (obsah == EOF)
    {
        //ERROR
    }
};
 */