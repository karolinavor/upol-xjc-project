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
    matice nova_matice;

    // kontrola nulove a zaporne velikosti matice
    if (m <= 0 || n <= 0) {
        chyba = CHYBA_TYPU;
        return nova_matice;
    }

    // dynamicka alokace pameti pro data
    float **data;

    data = malloc(m * sizeof(float *));
    if (!data) {
        chyba = CHYBA_ALOKACE;
        return nova_matice;
    }

    for (int i = 0; i < m; i++)
    {
        data[i] = (float *)malloc(n * sizeof(float));
        if (!(data[i]))
        {
            chyba = CHYBA_ALOKACE;
            return nova_matice;
        }
    }

    // naplneni matice 
    nova_matice.m = m;
    nova_matice.n = n;
    nova_matice.data = data;

    chyba = BEZ_CHYBY;
    return nova_matice;
}

// funkce vytvorı jednotkovou matici typu m × n
matice jednotkova(int m, int n) {
    matice nova_matice;

    // kontrola nulove a zaporne velikosti matice
    if (m <= 0 || n <= 0)
    {
        chyba = CHYBA_TYPU;
        return nova_matice;
    }

    nova_matice = inicializace(m, n);
    if (chyba != BEZ_CHYBY) {
        return nova_matice;
    }

    // naplneni matice
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                nova_matice.data[i][j] = 1;
            }
            else
            {
                nova_matice.data[i][j] = 0;
            }
        }
    }

    chyba = BEZ_CHYBY;
    return nova_matice;
}

// funkce vytvorı nulovou matici typu m × n
matice nulova(int m, int n) {
    matice nova_matice;

    // kontrola nulove a zaporne velikosti matice
    if (m <= 0 || n <= 0)
    {
        chyba = CHYBA_TYPU;
        return nova_matice;
    }

    nova_matice = inicializace(m, n);
    if (chyba != BEZ_CHYBY)
    {
        return nova_matice;
    }

    // naplneni matice
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            nova_matice.data[i][j] = 0;
        }
    }

    chyba = BEZ_CHYBY;
    return nova_matice;
}

// funkce pro vypis matice do konzole
void vypis(matice mat) {
    // kontrola matice
    if (!mat.data)
    {
        chyba = CHYBA_JINA;
        return;
    }

    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
        {
            printf("%f ", mat.data[i][j]);
        }
        printf("\n");
    }

    chyba = BEZ_CHYBY;
}

// funkce, ktera dealokuje pamet alokovanou pro matici mat
void odstran(matice mat) {
    if (!mat.data)
    {
        chyba = CHYBA_JINA;
        return;
    }

    for (int i = 0; i < mat.m; i++)
    {
        free(mat.data[i]);
    }
    free(mat.data);
    chyba = BEZ_CHYBY;
}

// funkce, ktera nastavı prvek matice mat v i-tem radku a j-tem sloupci na hodnotu hodnota
void nastav_prvek(matice mat, int i, int j, float hodnota) {
    if (!mat.data)
    {
        chyba = CHYBA_JINA;
        return;
    }

    if (i < 0 || i > mat.m) {
        chyba = CHYBA_TYPU;
        return;
    }

    if (j < 0 || j > mat.n) {
        chyba = CHYBA_TYPU;
        return;
    }

    if (!hodnota) {
        chyba = CHYBA_JINA;
        return;
    }

    mat.data[i][j] = hodnota;
    chyba = BEZ_CHYBY;
}

// funkce, ktera vracı matici, ktera vznikla transpozicı matice mat
matice transpozice(matice mat) {
    matice trans_matice;

    if (!mat.data)
    {
        chyba = CHYBA_JINA;
        return trans_matice;
    }

    trans_matice = inicializace(mat.n, mat.m);

    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++) {
            trans_matice.data[j][i] = mat.data[i][j];
        }
    }

    chyba = BEZ_CHYBY;
    return trans_matice;
}

// funkce, ktera vracı soucet matic mat1 a mat2
matice plus(matice mat1, matice mat2) {
    matice sectena_matice;

    if (!mat1.data || !mat2.data)
    {
        chyba = CHYBA_JINA;
        return sectena_matice;
    }

    sectena_matice = inicializace(mat1.m, mat1.n);
    if (chyba != BEZ_CHYBY)
    {
        return sectena_matice;
    }

    for (int i = 0; i < mat1.m; i++) {
        for (int j = 0; j < mat1.n; j++) {
            sectena_matice.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }
    chyba = BEZ_CHYBY;
    return sectena_matice;
}

// funkce, ktera vracı rozdıl matic mat1 a mat2
matice minus(matice mat1, matice mat2) {
    matice odectena_matice;

    if (!mat1.data || !mat2.data)
    {
        chyba = CHYBA_JINA;
        return odectena_matice;
    }

    odectena_matice = inicializace(mat1.m, mat1.n);
    if (chyba != BEZ_CHYBY)
    {
        return odectena_matice;
    }

    for (int i = 0; i < mat1.m; i++) {
        for (int j = 0; j < mat1.n; j++) {
            odectena_matice.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
        }
    }
    chyba = BEZ_CHYBY;
    return odectena_matice;
}

// funkce, ktera vracı matici, ktera vznikla z matice mat vynasobenım skalarem skalar
matice nasobeni(matice mat, float skalar) {
    matice vynasobena_matice = inicializace(mat.m, mat.n);
    if (chyba != BEZ_CHYBY)
    {
        return vynasobena_matice;
    }

    if (!mat.data || !skalar)
    {
        chyba = CHYBA_JINA;
        return vynasobena_matice;
    }

    for (int i = 0; i < mat.m; i++) {
        for (int j = 0; j < mat.n; j++) {
            vynasobena_matice.data[i][j] = mat.data[i][j] * skalar;
        }
    }
    chyba = BEZ_CHYBY;
    return vynasobena_matice;
}

// funkce, ktera vracı soucin matic mat1 a mat2
matice krat(matice mat1, matice mat2) {
    matice vynasobena_matice = inicializace(mat1.m, mat2.n);
    if (chyba != BEZ_CHYBY)
    {
        return vynasobena_matice;
    }

    if (!mat1.data || !mat2.data)
    {
        chyba = CHYBA_JINA;
        return vynasobena_matice;
    }

    if (mat1.m == mat2.m || mat1.n == mat2.n) {
        chyba = CHYBA_TYPU;
        return vynasobena_matice;
    }

    for (int i = 0; i < mat1.m; i++) {
        for (int j = 0; j < mat2.n; j++) {
            for (int k = 0; k < mat1.n; k++)
            {
                vynasobena_matice.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }
    chyba = BEZ_CHYBY;
    return vynasobena_matice;
}

// funkce, ktera vracı velikost matice v dimenzi dimenze
int velikost(matice mat, int dimenze) {
    if (!mat.data) {
        chyba = CHYBA_JINA;
        return -1;
    }

    if (dimenze == 0) {
        return mat.m;
    } else if (dimenze == 1) {
        return mat.n;
    } else {
        chyba = CHYBA_JINA;
        return -1;
    }
}

// funkce, ktera vracı prvek matice mat v i-tem radku a j-tem sloupci
float prvek(matice mat, int i, int j) {
    if (!mat.data)
    {
        chyba = CHYBA_JINA;
        return -1;
    }

    if (i < 0 || i > mat.m)
    {
        chyba = CHYBA_TYPU;
        return -1;
    }

    if (j < 0 || j > mat.n)
    {
        chyba = CHYBA_TYPU;
        return -1;
    }

    return mat.data[i][j];
}

// funkce, ktera vracı matici, ktera je ulozena v souboru soubor. Kazdy radek souboru reprezentuje radek matice a jednotlive prvky matice jsou oddeleny mezerou.
matice nacti_ze_souboru(const char *soubor) {
    matice nova_matice;

    if (!soubor)
    {
        chyba = CHYBA_JINA;
        return nova_matice;
    }

    FILE *otevreny_soubor;
    otevreny_soubor = fopen(soubor,"r");
    if (otevreny_soubor == NULL || !otevreny_soubor) {
        chyba = CHYBA_OTEVRENI;
        return nova_matice;
    }

    int rows = 0;
    int cols = 0;
    char ch;
    float f;

    while(!feof(otevreny_soubor)) {
        ch = fgetc(otevreny_soubor);
        if(ch == '\n')
        {
            rows++;
        }
    }

    rewind(otevreny_soubor);

    while(!feof(otevreny_soubor)) {
        fscanf(otevreny_soubor, "%f", &f);
        cols++;
    }

    cols = cols/rows;

    nova_matice = inicializace(rows, cols);
    if (chyba != BEZ_CHYBY)
    {
        return nova_matice;
    }

    rewind(otevreny_soubor);

    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            fscanf (otevreny_soubor, "%f", &f);
            nova_matice.data[i][j] = f;
        }
    }

    if (!(fclose(otevreny_soubor) == 0)) {
        chyba = CHYBA_ZAVRENI;
        return nova_matice;
    }

    chyba = BEZ_CHYBY;
    return nova_matice;
}

// funkce, ktera ulozı matici mat do souboru soubor (ve stejnem formatu, jako v predchozım bodu)
matice uloz_do_souboru(matice mat, const char *soubor) {
    if (!soubor)
    {
        chyba = CHYBA_JINA;
        return mat;
    }

    FILE *otevreny_soubor;
    otevreny_soubor = fopen(soubor,"w");
    if (otevreny_soubor == NULL) {
        chyba = CHYBA_OTEVRENI;
        return mat;
    }

    for (int i = 0; i < mat.m; i++) {
        for (int j = 0; j < mat.n; j++) {
            fprintf(otevreny_soubor,"%f",mat.data[i][j]);
            fprintf(otevreny_soubor,"%s"," ");
        }
        fprintf(otevreny_soubor,"%s","\n");
    }

    if (!(fclose(otevreny_soubor) == 0)) {
        chyba = CHYBA_ZAVRENI;
        return mat;
    }

    chyba = BEZ_CHYBY;
    return mat;
}