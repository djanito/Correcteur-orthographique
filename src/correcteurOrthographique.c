#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/dictionnaire.h"
#include "../include/levenshtein.h"
#include "../include/mot.h"
#include "../include/listeDeMot.h"

ListeDeMot Correcteur_corrigerR(Node **n, const char *s, int tolerance, ListeDeMot *solutions)
{
    if (*n == NULL)
        return *solutions;

    // calculating edit distance of s from root
    int dist = damerau_levenshtein((*n)->word, s);

    // if dist is less than tolerance value
    // add it to similar words
    if (dist <= tolerance)
    {
        Mot mot = Mot_genererMot((*n)->word); // génere le mot a partir de la string
        ListeDeMot_ajouter(solutions, mot);   // ajoute le mot à la liste des solutions trouvées
    }

    // iterate over the string having tolerance
    // in range (dist-TOL , dist+TOL)
    for (int i = MAX(0, dist - tolerance); i < MIN(MAX_CHILDREN, dist + tolerance + 1); i++)
    {
        if (ListeDeMot_longueur(*solutions) < MAX_SIMILAR_WORDS)
        {
            Correcteur_corrigerR(&(*n)->children[i], s, tolerance, solutions);
        }
    }

    return *solutions;
}

ListeDeMot Correcteur_corriger(Node **arbre, Mot mot, int tolerance)
{
    ListeDeMot corrections = ListeDeMot_liste();
    return Correcteur_corrigerR(arbre, Mot_obtenirContenu(mot), tolerance, &corrections);
}