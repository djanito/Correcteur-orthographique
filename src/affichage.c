#include <stdio.h>
#include <stdlib.h>

#include "../include/affichage.h"

void afficherAide()
{
    printf("Aide du correcteur :\n");
    printf("   correcteur -h : cette aide\n");
    printf("   correcteur -d dico : correction de l'entree standard a l'aide du dictionnaire dico\n");
    printf("   correcteur -d dico -f fic : completer le dictionnaire dico a l'aide des mots du fichier fic (un mot par ligne)\n");
}

void afficherErreur(int erreur)
{
    switch (erreur)
    {
    case 1:
        printf("Impossible de charger le fichier");
        break;
    case 2:
        printf("Impossible de generer l'arbre");
        break;
    case 3:
        printf("Impossible de lire l'entrée standard");
        exit(1);
        break;
    default:
        printf("erreur par défaut");
    }
}