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
matice inicializace(int m, int n) {

    matice nova_matice = malloc(sizeof(matice));

    if (nova_matice == NULL)
    {
        return NULL;
    }

    nova_matice.m = m;
    nova_matice.n = n;
    nova_matice.data = malloc(sizeof(float) * m * n);

    if (nova_matice.data == NULL)
    {
        free(nova_matice);
        return NULL;
    }

    return nova_matice;
};

// funkce vytvorı nulovou matici typu m × n
matice nulova(int m, int n) {
    matice *nova_matice = inicializace(m, n);

    if (!nova_matice || !nova_matice.data) {
        return 1;
    }

    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            nova_matice.data[i][j] = 0.0f;
        }
    }

    return nova_matice;
    */
};

// funkce vytvorı jednotkovou matici typu m × n
matice jednotkova(int m, int n) {
    matice nova_matice = inicializace(m, n);
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            nova_matice.data[i][j] = 1.0f;

    return nova_matice;
};

// funkce, ktera dealokuje pamet alokovanou pro matici mat
void odstran(matice mat) {
    /*
     * free(mat->elem);
	free(mat);
     *
    for (unsigned int i = 0; i < matice->rows; i++)
    {
        free(matice->matrix[i]);
    }
    free(matice->matrix);
    */
};

// funkce pro vypis matice do konzole
void vypis(matice mat) {
    /*
  for (int r = 0; r < mat->m; r++)
  {
    for (unsigned int s = 0; s < mat->n; s++)
    {
      printf("%d ", mat->data[r][s]);
    }
    printf("\n");
  }
    */
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
    /*
    // otevreni 1. souboru a nacteni ukazatele na soubor
  soubor1 = fopen(params.zdroj1, "r");
  if (soubor1 == NULL)
  { // soubor se nepodarilo otevrit
    printMsg(EFOPEN);
    return EXIT_FAILURE;
  }
  // nacteni 1. matice ze souboru
  stav = loadMatrix(soubor1, &m1);
  if (stav != EOK)
  { // nastala chyba
    printMsg(stav);
    return EXIT_FAILURE;
  }
  // uzavreni 1. souboru
  stav = fclose(soubor1);
  if (stav == EOF)
  { // soubor se nepodarilo uzavrit
    // pokracuji dale, na funkcnost to nema vliv
    // printMsg(EFCLOSE);
    // freeMatrix(&m1)
    // return EXIT_FAILURE;
  }
    */
};

// funkce, ktera ulozı matici mat do souboru soubor (ve stejnem formatu, jako v predchozım bodu)
matice uloz_do_souboru(matice mat, const char *soubor) {

};

// funkce, ktera vracı velikost matice v dimenzi dimenze
int velikost(matice mat, int dimenze) {

};

// funkce, ktera vracı prvek matice mat v i-tem radku a j-tem sloupci
float prvek(matice mat, int i, int j) {
    /*
    return mat->data[i][j];
    */
};

// funkce, ktera nastavı prvek matice mat v i-tem radku a j-tem sloupci na hodnotu hodnota
void nastav_prvek(matice mat, int i, int j, float hodnota) {
    /*
    mat->data[i][j] = hodnota;
    */
};