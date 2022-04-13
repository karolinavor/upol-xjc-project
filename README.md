# xjc-project

#### Build and run project

``` 
gcc main.c matice.c -o main && ./main 
```


Naprogramujte modul (bez funkce main()) pro praci s maticemi, jejichz prvky jsou realna
cisla (cisla typu float). Modul se bude skladat ze zdrojoveho kodu (soubor matice.c)
a z hlavickoveho souboru (soubor matice.h).

V modulu musi byt definovan strukturovany datovy typ matice. Struktura si bude uchovavat
informaci o sve velikosti (int m a int n). Prvky matice budou ulozeny v dvourozmernym
poli data.

Dale modul obsahuje nasledujici funkce:

  * matice inicializace(int m, int n) { funkce vytvori matici typu m x n, vcetne
        alokovani pole pro prvky matice }
        
  * matice nulova(int m, int n) { funkce vytvori nulovou matici typu m x n }

  * matice jednotkova(int m, int n) { funkce vytvori jednotkovou matici typu m x n }
  
  * void odstran(matice mat) { funkce, ktera dealokuje pamet alokovanou pro matici
        mat }

  * void vypis(matice mat) { funkce pro vypis matice do konzole }

  * matice plus(matice mat1, matice mat2) { funkce, kteraa vraci soucet matic mat1
        a mat2 }

  * matice minus(matice mat1, matice mat2) { funkce, ktera vraci rozdil matic mat1
        a mat2 }

  * matice nasobeni(matice mat, float skalar) { funkce, ktera vraci matici, ktera
        vznikla z matice mat vynasobenim skalarem skalar }

  * matice transpozice(matice mat) { funkce, ktera vraci matici, ktera vznikla trans-
        pozici matice mat }

  * matice krat(matice mat1, matice mat2) { funkce, ktera vraci soucin matic mat1
        a mat2 }

  * matice nacti ze souboru(const char *soubor) { funkce, ktera vraci matici, ktera
        je ulozena v souboru soubor. Kazdy radek souboru reprezentuje radek matice a jed-
        notlive prvky matice jsou oddeleny mezerou }
        
  * void uloz do souboru(matice mat, const char *soubor) { funkce, ktera ulozi ma-
        tici mat do souboru soubor (ve stejnem formatu, jako v predchozim bodu).

Dale obsahuje funkce pro praci s maticemi (abychom s nimi nemuseli pracovat primo):

  * int velikost(matice mat, int dimenze) { funkce, ktera vraci velikost matice v di-
        menzi dimenze.

  * float prvek(matice mat, int i, int j) { funkce, ktera vraci prvek matice mat
        v i-tem radku a j-tem sloupci.

  * void nastav prvek(matice mat, int i, int j, float hodnota) { funkce, ktera
        nastavi prvek matice mat v i-tem radku a j-tem sloupci na hodnotu hodnota.

Globalni promennou chyba, ktera bude uchovavat, zda v posledni operaci nedoslo k
        nejake chybe.

Definujte symbolicke konstanty pro ruzne chyby:

  * BEZ CHYBY - pokud ve funkci nedoslo k zadne chybe.

  * CHYBA ALOKACE - chyba pri alokaci pameti

  * CHYBA OTEVRENI - chyba pri otevirani souboru

  * CHYBA ZAVRENI - chyba pri zavirani souboru

  * CHYBA TYPU - chyba pri provadeni operaci s nespravnou velikosti matice

  * CHYBA JINA - ostatni chyby

Modul muze obsahovat i dalsi pomocne funkce.
