/**
 * \file mot.h
 * \brief Implantation du TAD Mot
 * \version 1.0
 */

#ifndef __MOT_H__
#define __MOT_H__

typedef struct Mot
{
    char *contenu;
    unsigned int longueur;
} Mot;

/**
 * \fn Mot Un_mot();
 * \brief Crée un Mot vide
 * \return retourne un Mot "vide"
 */
Mot Un_mot();

/**
 * \fn char* Mot_obtenirContenu(Mot mot);
 * \brief Retourne le contenu (les lettres) d'un Mot
 * \param Mot mot : le mot concerné
 * \return Le contenu du mot
 */
char *Mot_obtenirContenu(Mot mot);

/**
 * \fn unsigned int Mot_longueur(Mot mot);
 * \brief Retourne la longueur d'un mot
 * \param Mot mot : le mot concernÃ©
 * \return la taille du mot
 */
unsigned int Mot_longueur(Mot mot);

/**
 * \fn  Mot Mot_genererMot(char * chaine);
 * \brief Génère un mot à partir d'une chaine de caractère
 * \param char* chaine : la chaine à partir de laquelle on veut obtenir un mot
 * \return le mot à partir de la chaine
 */
Mot Mot_genererMot(char *chaine);

/**
 * \fn unsigned int Mot_sontEgaux(Mot mot1, Mot mot2);
 * \brief Indique si 2 Mots sont égaux (même contenu, de même taille)
 * \param Mot mot1 : le premier mot concerné
 * \param Mot mot2 : le deuxième mot concerné
 * \return vrai si les mots sont égaux, faux sinon
 */
unsigned int Mot_sontEgaux(Mot mot1, Mot mot2);

#endif
