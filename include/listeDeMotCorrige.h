/**
 * \file listeDeMotCorrige.h
 * \brief Implantation du TAD ListeDeMotCorrige
 * \version 1.0
 */
#ifndef __LISTE_DE_MOT_CORRIGE_H__
#define __LISTE_DE_MOT_CORRIGE_H__

#include "motCorrige.h"

typedef struct ListeDeMotCorrige
{
    MotCorrige *tableau;
    unsigned int longueur;
} ListeDeMotCorrige;

/**
 * \fn ListeDeMotCorrige ListeDeMotCorrige_liste();
 * \brief Crée une Liste de MotCorrige initialisée
 * \return une ListeDeMotCorrige
 */
ListeDeMotCorrige ListeDeMotCorrige_liste();

/**
 * \fn int ListeDeMotCorrige_estVide(ListeDeMotCorrige liste);
 * \brief Permet de savoir si une Liste de MotCorrige ne contient aucun MotCorrige
 * \param ListeDeMotCorrige liste : la liste à étudier
 * \return int : vrai si elle ne contient rien, faux sinon
 */
int ListeDeMotCorrige_estVide(ListeDeMotCorrige liste);

/**
 * \fn int ListeDeSuperMot_longueur(ListeDeMotCorrige liste);
 * \brief Renvoi la longueur d'une Liste de MotCorrige
 * \param ListeDeMotCorrige liste : la liste à étudier
 * \return int : La longueur de la Liste de MotCorrige
 */
unsigned int ListeDeMotCorrige_longueur(ListeDeMotCorrige liste);

/**
 * \fn void ListeDeMotCorrige_ajouter(ListeDeMotCorrige *liste, MotCorrige mot);
 * \brief Ajoute un Mot à la fin d'une liste de MotCorrige
 * \param ListeDeMotCorrige *liste : le pointeur de la liste à laquelle on veut ajouter un MotCorrige
 * \param MotCorrige motCorrige : le MotCorrige que l'on veut ajouter
 */
void ListeDeMotCorrige_ajouter(ListeDeMotCorrige *liste, MotCorrige motCorrige);

/**
 * \fn Mot ListeDeMotCorrige_obtenir(ListeDeMotCorrige liste, int indice);
 * \brief Renvoi le MotCorrige de la liste à un indice donné
 * \param ListeDeMotCorrige liste : la liste à fouiller
 * \param int indice : l'indice auquel on souhaite récupérer le MotCorrige
 * \return MotCorrige : le MotCorrige trouvé
 * \warning assert(0 <= indice && indice < ListeDeSuperMot_longueur(liste));
 */
MotCorrige ListeDeMotCorrige_obtenir(ListeDeMotCorrige liste, unsigned int indice);

/**
 * \fn void ListeDeMotCorrige_inserer(ListeDeMotCorrige *liste, MotCorrige motCorrige, int i);
 * \brief Inserer un motCorrige dans la liste à un indice donné
 * \param ListeDeMotCorrige liste : la liste que l'on veut modifier
 * \param SuperMot motCorrige : le motCorrige que l'on veut inserer
 * \param int indice : l'indice auquel on souhaite inserer le motCorrige
 * \warning assert(0 <= indice && indice < ListeDeSuperMot_longueur(*liste) + 1);
 */
void ListeDeMotCorrige_inserer(ListeDeMotCorrige *liste, MotCorrige motCorrige, unsigned int i);

/**
 * \fn void ListeDeMotCorrige_supprimer(ListeDeSuperMot *liste, SueprMot motCorrige, int i);
 * \brief Supprime un motCorrige dans la liste à un indice donné
 * \param ListeDeMotCorrige liste : la liste que l'on veut modifier
 * \param int indice : l'indice auquel on souhaite supprimer le motCorrige
 * \warning assert(0 <= indice && indice < ListeDeSuperMot_longueur(liste));
 */
void ListeDeMotCorrige_supprimer(ListeDeMotCorrige *liste, unsigned int i);

/**
 * \fn void ListeDeMotCorrige_liberer(ListeDeMot *liste);
 * \brief Libère la mémoire d'une liste de super mots
 * \param ListeDeMotCorrige liste : La liste en question
 */
void ListeDeMotCorrige_liberer(ListeDeMotCorrige *liste);

#endif
