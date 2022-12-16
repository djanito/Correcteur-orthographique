/**
 * \file dictionnaire.h
 * \brief Implémentation du TAD Dictionnaire
 * \version 1.0
 */

#ifndef __DICTIONNAIRE_H__
#define __DICTIONNAIRE_H__

#include "mot.h"
#include "listeDeMot.h"

// taille maximale d'un mot
// (e.g., anticonstitutionnellement)
#define MAX_WORD_SIZE 30

// Distance maximale autorisée entre une branche et ses sous-branches
#define MAX_CHILDREN 26

// Nombre de mots proches maximaux autorisées
#define MAX_SIMILAR_WORDS 6

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct Node // structure du noeud
{
    struct Node *children[MAX_CHILDREN];
    char word[MAX_WORD_SIZE];
} Node;

/**
 * \fn unsigned int Dictionnaire_creer(const char *dictionary, Node **arbre);
 * \brief Crée l'arbre bk-tree correspondant au fichier dictionnary
 * \param const char *dictionary : le fichier contenant les mots à ajouter à l'arbre
 * \param Node **arbre : l'arbre en question
 * \return unsigned int : 1 si l'arbre a pu être créé, 0 sinon
 */
unsigned int Dictionnaire_creer(const char *dictionary, Node **arbre);

/**
 * \fn unsigned int Dictionnaire_sauvegarder(const char *filename, Node **arbre);
 * \brief Sauvegarde l'arbre dans le fichier filename
 * \param const char *filename : le fichier qui va contenir la sauvegarde de l'arbre
 * \param Node **arbre : l'arbre en question
 * \return unsigned int : 1 si l'arbre a pu être sauvegardé, 0 sinon
 */
unsigned int Dictionnaire_sauvegarder(const char *filename, Node **arbre);

/**
 * \fn unsigned int Dictionnaire_charger(const char *filename, Node **arbre);
 * \brief Charge un arbre depuis le fichier filename
 * \param const char *filename : le fichier contenant la sérialisation de l'arbre
 * \param Node **arbre : l'arbre a désérialiser
 * \return unsigned int : 1 si l'arbre a pu être chargé, 0 sinon
 */
unsigned int Dictionnaire_charger(const char *filename, Node **arbre);

/**
 * \fn unsigned int Correcteur_estPresent(Node **arbre, Mot mot);
 * \brief Détermine si un mot est présent dans un arbre
 * \param Node **arbre : La liste en question
 * \param Mot mot : le mot en question
 * \return unsigned int : 1 si le mot est présent dans l'arbre, 0 sinon
 */
unsigned int Dictionnaire_estPresent(Node **arbre, Mot mot);

/**
 * \fn unsigned int Dictionnaire_longueur(void);
 * \brief Renvoie la longueur d'un dictionnaire
 * \return int : Le nombre de mot dans le dictionnaire
 */
unsigned int Dictionnaire_longueur(void);

/**
 * \fn unsigned int Dictionnaire_liberer(Node *abre);
 * \brief Libère la mémoire d'un arbre n-aire
 * \param Node *abre : L'arbre en question
 * \return unsigned int : 1 si l'arbre a ete libéré, 0 sinon
 */
unsigned int Dictionnaire_liberer(Node *abre);

#endif // __DICTIONNAIRE_H__
