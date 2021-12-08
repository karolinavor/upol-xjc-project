/**
* @file    matice.h
* @author  Karolina Vorlickova <vorlka00@upol.cz>
* @date    1.12.2021
* @brief   Projekt Matice
*
* Modul pro praci s maticemi
**/

struct matrix
{
    /** @brief ID objektu */
    int id;
    /** @brief Souřadnice X */
    int m;
    /** @brief Souřadnice Y */
    int n;
};

/**
 * @brief  Inicializuje matici.
 *
 * @param c1 ukazatel na první objekt
 * @param c2 ukazatel na druhý objekt
 * @return vraci matici
*/
float init_matrix(float c1, float c2);

/**
 * @brief Hlavní funkce programu, spouští se jako první.
 * @param argc počet argumentů příkazové řádky
 * @param argv pole argumentů příkazové řádky
 *
 * @return při úspěšném ukončení vrací 0, při neúspěšném -1
 */
int main(int argc, char *argv[]);