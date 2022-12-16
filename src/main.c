#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "../include/dictionnaire.h"
#include "../include/correcteurOrthographique.h"
#include "../include/listeDeMotCorrige.h"
#include "../include/motCorrige.h"
#include "../include/mot.h"
#include "../include/utils.h"
#include "../include/affichage.h"

// Taille maximale de l'entrée standard
#define MAX_STDIN_LENGTH 200

char *lireEntreeStandard()
{
    char *phrase = malloc(MAX_STDIN_LENGTH * sizeof(char));

    fgets(phrase, MAX_STDIN_LENGTH, stdin);
    phrase[strcspn(phrase, "\n")] = 0;

    return phrase;
}

ListeDeMotCorrige separerPhrase(char *phrase)
{
    ListeDeMotCorrige listeRetour;
    Mot motTemp;
    MotCorrige motCorrigeTemp;

    motTemp = Un_mot();
    listeRetour = ListeDeMotCorrige_liste();

    char *mot;
    mot = strtok(phrase, " ,'.-");

    while (mot != NULL)
    {
        motTemp = Mot_genererMot(mot);
        MotCorrige_fixerMot(&motCorrigeTemp, motTemp);
        ListeDeMotCorrige_ajouter(&listeRetour, motCorrigeTemp);
        motTemp = Un_mot();
        mot = strtok(NULL, " ,'.-");
    }

    free(mot);

    return listeRetour;
}

void corrigerListeDeMots(ListeDeMotCorrige *listeDeMotsCorrige, Node *arbre)
{
    MotCorrige motCorrigeTemp;

    for (int i = 0; i < ListeDeMotCorrige_longueur(*listeDeMotsCorrige); i++)
    {
        motCorrigeTemp = ListeDeMotCorrige_obtenir(*listeDeMotsCorrige, i);

        MotCorrige_fixerCorrections(&motCorrigeTemp, Correcteur_corriger(&arbre, MotCorrige_obtenirMot(motCorrigeTemp), 1) /* LISTE DE CORRECTIONS */);
        ListeDeMotCorrige_supprimer(listeDeMotsCorrige, i);
        ListeDeMotCorrige_inserer(listeDeMotsCorrige, motCorrigeTemp, i);
    }
}

void afficherCorrection(ListeDeMotCorrige listeDeMotsCorrige, Node *arbre)
{
    MotCorrige motCorrigeTemp;
    int position = 1;

    for (int i = 0; i < ListeDeMotCorrige_longueur(listeDeMotsCorrige); i++)
    {
        motCorrigeTemp = ListeDeMotCorrige_obtenir(listeDeMotsCorrige, i);

        // Si le mot courant est bien orthographie
        if (Dictionnaire_estPresent(&arbre, MotCorrige_obtenirMot(motCorrigeTemp)))
        {
            printf("*");
        }
        else
        {
            printf("& %s %d %d : ",
                   Mot_obtenirContenu(MotCorrige_obtenirMot(motCorrigeTemp)),
                   ListeDeMot_longueur(MotCorrige_obtenirCorrections(motCorrigeTemp)), position);
            ListeDeMot_listeDeMotEnChaine(MotCorrige_obtenirCorrections(motCorrigeTemp));
        }
        position += Mot_longueur(MotCorrige_obtenirMot(motCorrigeTemp)) + 1;
        printf("\n");
    }
}

void corriger(char *chaine, Node *arbre)
{
    ListeDeMotCorrige listeDeMotsCorrige;

    listeDeMotsCorrige = ListeDeMotCorrige_liste();
    listeDeMotsCorrige = separerPhrase(chaine);

    corrigerListeDeMots(&listeDeMotsCorrige, arbre);
    afficherCorrection(listeDeMotsCorrige, arbre);

    free(chaine);
    ListeDeMotCorrige_liberer(&listeDeMotsCorrige);
}

int main(int argc, char *argv[])
{
    Node *arbre = NULL;

    int dFlag = 0, fFlag = 0;
    int opt;
    char *dico, *fic;

    /* gestion des options */
    while ((opt = getopt(argc, argv, "hd:f:")) != -1)
        switch (opt)
        {
        case 'd':
            dFlag = 1;
            dico = optarg;
            break;
        case 'f':
            fFlag = 1;
            fic = optarg;
            break;
        case 'h':
        case ':':
        case '?':
        default:
            afficherAide();
            break;
        }

    if (dFlag)
    {
        if (fFlag)
        {
            if (Dictionnaire_creer(fic, &arbre))
            {
                Dictionnaire_sauvegarder(dico, &arbre);
            }
            else
            {
                afficherErreur(2);
            }
        }
        else
        {
            if (Dictionnaire_charger(dico, &arbre))
            {
                char *phrase = lireEntreeStandard();

                if (phrase == NULL)
                    afficherErreur(3);
                else
                    corriger(strToLower(phrase), arbre);
                free(phrase);
            }
            else
            {
                afficherErreur(1);
            }
        }
    }

    free(dico);
    free(fic);
    Dictionnaire_liberer(arbre);
    return 0;
}