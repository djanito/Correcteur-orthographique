#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/listeDeMotCorrige.h"
#include "../include/motCorrige.h"

void ListeDeMotCorrige_decalerADroite(ListeDeMotCorrige *liste, unsigned int indice)
{
    unsigned int i;

    for (i = liste->longueur - 1; i >= indice; i--)
    {
        liste->tableau[i] = liste->tableau[i - 1];
    }
}

void ListeDeMotCorrige_decalerAGauche(ListeDeMotCorrige *liste, unsigned int indice)
{
    unsigned int i;

    for (i = indice - 1; i < liste->longueur; i++)
    {
        liste->tableau[i] = liste->tableau[i + 1];
    }
}

ListeDeMotCorrige ListeDeMotCorrige_liste()
{
    ListeDeMotCorrige l;

    l.tableau = NULL;
    l.tableau = malloc(sizeof(MotCorrige));
    l.longueur = 0;

    return l;
}

int ListeDeMotCorrige_estVide(ListeDeMotCorrige liste)
{
    return (liste.longueur == 0);
}

unsigned int ListeDeMotCorrige_longueur(ListeDeMotCorrige liste)
{
    return liste.longueur;
}

void ListeDeMotCorrige_ajouter(ListeDeMotCorrige *liste, MotCorrige motCorrige)
{
    liste->longueur = liste->longueur + 1;
    liste->tableau = realloc(liste->tableau, sizeof(MotCorrige) * liste->longueur);
    liste->tableau[liste->longueur - 1] = motCorrige;
}

MotCorrige ListeDeMotCorrige_obtenir(ListeDeMotCorrige liste, unsigned int indice)
{
    assert(0 <= indice && indice < ListeDeMotCorrige_longueur(liste));

    return liste.tableau[indice];
}

void ListeDeMotCorrige_inserer(ListeDeMotCorrige *liste, MotCorrige motCorrige, unsigned int indice)
{
    assert(0 <= indice && indice < ListeDeMotCorrige_longueur(*liste) + 1);

    liste->longueur = liste->longueur + 1;
    liste->tableau = realloc(liste->tableau, sizeof(MotCorrige) * liste->longueur);
    ListeDeMotCorrige_decalerADroite(liste, indice + 1);
    liste->tableau[indice] = motCorrige;
}

void ListeDeMotCorrige_supprimer(ListeDeMotCorrige *liste, unsigned int indice)
{
    assert(0 <= indice && indice < ListeDeMotCorrige_longueur(*liste));

    ListeDeMotCorrige_decalerAGauche(liste, indice + 1);
    liste->longueur = liste->longueur - 1;
    liste->tableau = realloc(liste->tableau, sizeof(MotCorrige) * liste->longueur);
}

void ListeDeMotCorrige_liberer(ListeDeMotCorrige *liste)
{
    free(liste->tableau);
}
