/**
* @file    matice.h
* @author  Karolina Vorlickova <vorlka00@upol.cz>
* @date    1.12.2021
* @brief   Projekt Matice
*
* Modul pro praci s maticemi
**/

/* Chybove kody */

#define BEZ_CHYBY 0
#define CHYBA_ALOKACE -1
#define CHYBA_OTEVRENI -2
#define CHYBA_ZAVRENI -3
#define CHYBA_TYPU -4
#define CHYBA_JINA -5

/* Globalni promenne */

// uchovava, zda v poslednı operaci nedoslo k nejake chybe
int chyba;

/* Definice struktury */

typedef struct {
    // radky
    int m;
    // sloupce
    int n;
    // prvky matice v dvourozmernem poli
    float** data;
} matice;

/* Definice funkci */

matice* inicializace(int m, int n);
matice* nulova(int m, int n);
matice* jednotkova(int m, int n);
void odstran(matice* mat);
void vypis(matice* mat);
matice* plus(matice* mat1, matice* mat2);
matice* minus(matice* mat1, matice* mat2);
matice* nasobeni(matice* mat, float skalar);
matice* transpozice(matice* mat);
matice* krat(matice* mat1, matice* mat2);
matice* nacti_ze_souboru(const char *soubor);
matice* uloz_do_souboru(matice* mat, const char *soubor);
int velikost(matice* mat, int dimenze);
float prvek(matice* mat, int i, int j);
void nastav_prvek(matice* mat, int i, int j, float hodnota);
int kontrolaChyb();