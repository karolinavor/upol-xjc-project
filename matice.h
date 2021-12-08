/**
* @file    matice.h
* @author  Karolina Vorlickova <vorlka00@upol.cz>
* @date    1.12.2021
* @brief   Projekt Matice
*
* Modul pro praci s maticemi
**/

/* Konstanty */

#define BEZ_CHYBY "Bez chyby.\n";
#define CHYBA_ALOKACE "Chyba alokace.\n";
#define CHYBA_OTEVRENI "Chyba otevreni.\n";
#define CHYBA_ZAVRENI "Chyba zavreni.\n";
#define CHYBA_TYPU "Chyba typu.\n";
#define CHYBA_JINA "Chyba jina.\n";

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
void odstran(matice mat);
void vypis(matice* mat);
matice plus(matice mat1, matice mat2);
matice minus(matice mat1, matice mat2);
matice nasobeni(matice mat, float skalar);
matice transpozice(matice mat);
matice krat(matice mat1, matice mat2);
matice nacti_ze_souboru(const char *soubor);
matice uloz_do_souboru(matice mat, const char *soubor);
int velikost(matice mat, int dimenze);
float prvek(matice mat, int i, int j);
void nastav_prvek(matice mat, int i, int j, float hodnota);