#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "../include/listeDeMot.h"
#include "../include/mot.h"

void ListeDeMot_decalerADroite(ListeDeMot *liste, unsigned int indice)
{
    for (int i = liste->longueur - 1; i >= indice; i--)
    {
        liste->mots[i] = liste->mots[i - 1];
    }
}

void ListeDeMot_decalerAGauche(ListeDeMot *liste, unsigned int indice)
{
    for (int i = indice - 1; i < liste->longueur; i++)
    {
        liste->mots[i] = liste->mots[i + 1];
    }
}

ListeDeMot ListeDeMot_liste()
{
    ListeDeMot l;
    l.mots = NULL;
    l.longueur = 0;

    return l;
}

int ListeDeMot_estVide(ListeDeMot liste)
{
    return (liste.longueur == 0);
}

unsigned int ListeDeMot_longueur(ListeDeMot liste)
{
    return liste.longueur;
}

void ListeDeMot_ajouter(ListeDeMot *liste, Mot mot)
{
    liste->longueur = liste->longueur + 1;
    liste->mots = realloc(liste->mots, sizeof(Mot) * liste->longueur);
    liste->mots[liste->longueur - 1] = mot;
}

Mot ListeDeMot_obtenir(ListeDeMot liste, unsigned int indice)
{
    assert(0 <= indice && indice < ListeDeMot_longueur(liste));

    return liste.mots[indice];
}

void ListeDeMot_supprimer(ListeDeMot *liste, unsigned int indice)
{
    assert(0 <= indice && indice < ListeDeMot_longueur(*liste));

    ListeDeMot_decalerADroite(liste, indice + 1);
    liste->longueur = liste->longueur - 1;
    liste->mots = realloc(liste->mots, sizeof(Mot) * liste->longueur);
}

void ListeDeMot_inserer(ListeDeMot *liste, Mot mot, unsigned int indice)
{
    assert(0 <= indice && indice < ListeDeMot_longueur(*liste) + 1);

    liste->longueur = liste->longueur + 1;
    liste->mots = realloc(liste->mots, sizeof(Mot) * liste->longueur);
    ListeDeMot_decalerAGauche(liste, indice + 1);
    liste->mots[indice] = mot;
}

void ListeDeMot_listeDeMotEnChaine(ListeDeMot liste)
{
    // ordre décroissant pour meilleurs résultats
    for (int i = ListeDeMot_longueur(liste) - 1; i >= 0; i--)
    {
        printf("%s ", Mot_obtenirContenu(ListeDeMot_obtenir(liste, i)));
    }
}

void ListeDeMot_liberer(ListeDeMot *liste)
{
    free(liste->mots);
}

unsigned int ListeDeMot_estPresent(ListeDeMot liste, Mot mot)
{
    unsigned int i = 1;
    unsigned int res = 0;

    while (!res && i <= ListeDeMot_longueur(liste))
    {
        res = Mot_sontEgaux(ListeDeMot_obtenir(liste, i), mot);
        i++;
    }

    return res;
}
