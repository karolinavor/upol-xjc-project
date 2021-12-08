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
    if (m == 0 || n == 0) {
        //ERROR
    }

    matice *nova_matice = calloc(1, sizeof(*nova_matice));
    nova_matice->m = m;
    nova_matice->n = n;

    nova_matice->data = calloc(nova_matice->m, sizeof(*nova_matice->data));
    for(int i = 0; i < nova_matice->m; ++i) {
        nova_matice->data[i] = calloc(nova_matice->n, sizeof(**nova_matice->data));
    }

    /*
    if (!nova_matice.data || !nova_matice) //?
    {
        //free(nova_matice);
        //free(nova_matice.data);
        //ERROR
    }
    */

    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            nova_matice->data[i][j] = 0;
        }
    }

    for (int i = 0; i < nova_matice->m; i++)
    {
        for (int j = 0; j < nova_matice->n; j++)
        {
            printf("%f ", nova_matice->data[i][j]);
        }
        printf("\n");
    }

    return nova_matice;
};

/*

// funkce vytvorı nulovou matici typu m × n
matice* nulova(int m, int n) {
    matice* nova_matice = inicializace(m, n);

    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            nova_matice->data[i][j] = 0;
        }
    }

    return nova_matice;
};

// funkce vytvorı jednotkovou matici typu m × n
matice* jednotkova(int m, int n) {
    matice* nova_matice = inicializace(m, n);

    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                nova_matice->data[i][j] = 1;
            } else {
                nova_matice->data[i][j] = 0;
            }
        }
    }

    return nova_matice;
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
};

// funkce, ktera dealokuje pamet alokovanou pro matici mat
void odstran(matice mat) {
    for (int i = 0; i < mat.m; i++)
    {
        free(mat.data[i]);
    }
    free(mat.data);
    free(mat);
};

// funkce, ktera vracı soucet matic mat1 a mat2
matice plus(matice mat1, matice mat2) {

};

// funkce, ktera vracı rozdıl matic mat1 a mat2
matice minus(matice mat1, matice mat2) {

};

// funkce, ktera vracı matici, ktera vznikla z matice mat vynasobenım skalarem skalar
matice nasobeni(matice mat, float skalar) {

};

// funkce, ktera vracı matici, ktera vznikla transpozicı matice mat
matice transpozice(matice mat) {

};

// funkce, ktera vracı soucin matic mat1 a mat2
matice krat(matice mat1, matice mat2) {

};

// funkce, ktera vracı matici, ktera je ulozena v souboru soubor. Kazdy radek souboru reprezentuje radek matice a jednotlive prvky matice jsou oddeleny mezerou.
matice nacti_ze_souboru(const char *soubor) {
    if (soubor == NULL)
        //ERROR
    }

    obsah = fopen(soubor, "r");

    obsah = fclose(soubor);


};

// funkce, ktera ulozı matici mat do souboru soubor (ve stejnem formatu, jako v predchozım bodu)
matice uloz_do_souboru(matice mat, const char *soubor) {
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

// funkce, ktera vracı velikost matice v dimenzi dimenze
int velikost(matice mat, int dimenze) {
    if (dimenze == 0) {
        return mat.m;
    } else if (dimenze == 1) {
        return mat.n;
    } else {
        //ERROR
    }

    return;
};

// funkce, ktera vracı prvek matice mat v i-tem radku a j-tem sloupci
float prvek(matice mat, int i, int j) {
    return mat.data[i][j];
};

// funkce, ktera nastavı prvek matice mat v i-tem radku a j-tem sloupci na hodnotu hodnota
void nastav_prvek(matice mat, int i, int j, float hodnota) {
    mat.data[i][j] = hodnota;
    return;
};

*/