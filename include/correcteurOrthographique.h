/**
 * \file correcteurOrthographique.h
 * \brief prototypes des fonctions du correcteur orthographique.
 * \version 1.0
 */

#ifndef __CORRECTEUR_ORTHOGRAPHIQUE_H__
#define __CORRECTEUR_ORTHOGRAPHIQUE_H__

#include "mot.h"
#include "listeDeMot.h"
#include "dictionnaire.h"

/**
 * \fn ListeDeMot Correcteur_corriger(Node **arbre, Mot mot, int tolerance);
 * \brief Recupère une ListeDeMot contenant les corrections possibles pour un mot
 * \param Node **arbre : L'arbre dans lequel effectuer la recherche
 * \param Mot mot : Le mot que l'on souhaite corriger
 * \param int tolerance : La tolerance de la recherche
 * \return ListeDeMot : les corrections
 */
ListeDeMot Correcteur_corriger(Node **arbre, Mot mot, int tolerance);

#endif // __CORRECTEUR_ORTHOGRAPHIQUE_H__
