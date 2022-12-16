/**
 * \file levenshtein.h
 * \brief Implantation de la mesure de distance entre deux mots
 * \version 1.0
 */

#ifndef __LEVENSHTEIN_H__
#define __LEVENSHTEIN_H__

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

/**
* \fn unsigned int levenshtein(const char *mot1, const char *mot2);
* \brief Mesure de la distance entre deux mots
* \return unsigned int: La distance de levenshtein entre mot1 et mot2 
* \author Yigit Djan
*/
unsigned int levenshtein(const char *mot1, const char *mot2);

/**
* \fn int damerau_levenshtein(const char *a, const char *b);
* \brief Mesure de la distance entre deux mots
* \return unsigned int: La distance de Damerau entre mot1 et mot2 
* \author Yigit Djan
*/
unsigned int damerau_levenshtein(const char *mot1, const char *mot2);

#endif // LEVENSHTEIN_H