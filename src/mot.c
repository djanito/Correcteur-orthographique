#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/mot.h"
#include "../include/listeDeMot.h"

Mot Un_mot()
{
    Mot mot;
    mot.contenu = malloc(sizeof(char));
    mot.contenu[0] = '\0';
    mot.longueur = 0;

    return mot;
}

char *Mot_obtenirContenu(Mot mot)
{
    return mot.contenu;
}

unsigned int Mot_longueur(Mot mot)
{
    return mot.longueur;
}

Mot Mot_genererMot(char *chaine)
{
    Mot mot = Un_mot();
    mot.contenu = chaine;
    mot.longueur = strlen(chaine);

    return mot;
}

unsigned int Mot_sontEgaux(Mot mot1, Mot mot2)
{
    if (mot1.longueur != mot2.longueur)
        return 0;
    else
        return (strcmp(mot1.contenu, mot2.contenu) == 0);
}
