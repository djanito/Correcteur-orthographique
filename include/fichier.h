/**
 * \file fichier.h
 * \brief Implantation du TAD FichierTexte avec la SDD FichierTexte
 * \version 1.0
 */

#ifndef __FICHIER__
#define __FICHIER__

#include <stdio.h>

typedef enum
{
    LECTURE,
    ECRITURE
} Mode;

typedef struct Fichier
{
    FILE *file;
    char *nom;
    Mode mode;
} Fichier;

Fichier FichierTexte_fichierTexte(char *nomDuFichier);

unsigned int FichierTexte_estOuvert(Fichier fichier);

void FichierTexte_ouvrir(Fichier *fichier, Mode mode);

void FichierTexte_fermer(Fichier *fichier);

Mode FichierTexte_mode(Fichier fichier);

unsigned int FichierTexte_finFichier(Fichier fichier);

void FichierTexte_ecrireChaine(Fichier *fichier, char *chaine);

char *FichierTexte_lireChaine(Fichier fichier);

void FichierTexte_ecrireCaractere(Fichier *fichier, char caractere);

char FichierTexte_lireCaractere(Fichier fichier);

void FichierTexte_deplacementCurseurMoinsUn(Fichier *fichier);

unsigned int FichierTexte_existe(char *emplacement);

unsigned int FichierTexte_nombreDeCaractere(Fichier fichier);

unsigned int FichierTexte_estUnRetourChariot(char caractere);

#endif