/**
 * \file affichage.h
 * \brief Fonctions utiles pour l'affichage
 * \version 1.0
 */

#ifndef __AFFICHAGE_H__
#define __AFFICHAGE_H__

/**
* \fn void afficherAide();
* \brief Affiche l'aide du programme
* \author Yigit Djan
*/
void afficherAide();

/**
* \fn void afficherErreur(int erreur); 
* \brief Affiche le type d'erreur rencontrée
* \param int erreur : l'erreur rencontrée ( > 0 )
* \author Yigit Djan
*/
void afficherErreur(int erreur);

#endif // __AFFICHAGE_H__