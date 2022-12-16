#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "../include/correcteurOrthographique.h"
#include "../include/dictionnaire.h"
#include "../include/listeDeMot.h"
#include "../include/levenshtein.h"
#include "../include/utils.h"
#include "../include/mot.h"

int count = 0;

// ---------------- BK-TREE ----------------

void Dictionnaire_initialiserNoeud(Node **node, char *str)
{
    strcpy((*node)->word, str);
    memset((*node)->children, '\0', sizeof((*node)->children)); // set al children to NULL
}

void Dictionnaire_ajouter(Node **node, char *str)
{
    if (*node == NULL)
    {
        *node = malloc(sizeof(Node));
        Dictionnaire_initialiserNoeud(node, str);
        return;
    }

    int ld = damerau_levenshtein((*node)->word, str);

    if (ld != 0) // if distance == 0, then the word already exists
        Dictionnaire_ajouter(&((*node)->children[ld]), str);
}

unsigned int Dictionnaire_creer(const char *filename, Node **arbre)
{
    FILE *fp = fopen(filename, "r");

    if (!fp)
    {
        printf("Could not open this dictionary !");
        return 0;
    }
    else
    {
        char mot[MAX_WORD_SIZE];

        while (fgets(mot, sizeof(mot), fp))
        {
            mot[strcspn(mot, "\n")] = 0;
            Dictionnaire_ajouter(arbre, strToLower(mot));
            count++;
        }

        fclose(fp);

        // loaded
        return 1;
    }
}

void Dictionnaire_sauvegarderR(Node **node, FILE *fichier)
{
    if (*node == NULL)
        fprintf(fichier, "%s", "# ");
    else
    {
        fprintf(fichier, "%s ", (*node)->word);
        for (int i = 0; i < MAX_CHILDREN; i++)
            Dictionnaire_sauvegarderR(&((*node)->children[i]), fichier);
    }
}

unsigned int Dictionnaire_sauvegarder(const char *filename, Node **arbre)
{
    FILE *fichier = fopen(filename, "w");

    if (fichier != NULL)
        Dictionnaire_sauvegarderR(arbre, fichier);
    fclose(fichier);

    return fichier != NULL;
}

void Dictionnaire_chargerR(Node **node, FILE *fichier)
{
    char *mot = malloc(MAX_WORD_SIZE * sizeof(char));
    size_t n = 0;
    char c;

    while ((c = fgetc(fichier)) != EOF)
    {
        if (c == ' ')
        {
            mot[n] = '\0';
            if (strcmp(mot, "#") > 0)
            {
                if (*node == NULL)
                {
                    *node = malloc(sizeof(Node));
                    Dictionnaire_initialiserNoeud(node, mot);
                    free(mot);

                    count++;
                }
                for (int i = 0; i < MAX_CHILDREN; i++)
                    Dictionnaire_chargerR(&((*node)->children[i]), fichier);
                return;
            }
            else
            {
                free(mot);
                return;
            }
        }
        else
        {
            mot[n++] = c;
        }
    }
}

unsigned int Dictionnaire_charger(const char *filename, Node **arbre)
{
    FILE *fichier = fopen(filename, "r");

    if (fichier != NULL)
        Dictionnaire_chargerR(arbre, fichier);
    fclose(fichier);

    return fichier != NULL;
}

unsigned int Dictionnaire_estPresent(Node **arbre, Mot mot)
{
    // check if a word exists = search for word with tolerance 0
    return ListeDeMot_longueur(Correcteur_corriger(arbre, mot, 0)) == 1;
}

unsigned int Dictionnaire_longueur(void)
{
    return count;
}

void Dictionnaire_libererEnfants(Node *current)
{
    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        if (current->children[i] != NULL)
        {
            Dictionnaire_libererEnfants(current->children[i]);
        }
    }
    free(current);
}

unsigned int Dictionnaire_liberer(Node *arbre)
{
    // pointer to memory
    Node *fre = arbre;

    // int to keep track of chil number we are at
    int tra = 0;
    for (tra = 0; tra < MAX_CHILDREN; tra++)
    {
        if (fre->children[tra] != NULL)
        {
            Dictionnaire_libererEnfants(fre->children[tra]);
        }
    }
    return 1;
}
