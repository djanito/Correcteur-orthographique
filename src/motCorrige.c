/* Ce commentaire est utilisé pour forcer la conversion en ISO */
#include <stdio.h>
#include <stdlib.h>
#include "../include/motCorrige.h"
#include "../include/mot.h"
#include "../include/listeDeMot.h"

MotCorrige Un_motCorrige()
{
    MotCorrige motCorrige;

    motCorrige.mot = Un_mot();
    motCorrige.corrections = ListeDeMot_liste();

    return motCorrige;
}

Mot MotCorrige_obtenirMot(MotCorrige motCorrige)
{
    return motCorrige.mot;
}

void MotCorrige_fixerMot(MotCorrige *motCorrige, Mot mot)
{
    (*motCorrige).mot = mot;
}

ListeDeMot MotCorrige_obtenirCorrections(MotCorrige motCorrige)
{
    return motCorrige.corrections;
}

void MotCorrige_fixerCorrections(MotCorrige *motCorrige, ListeDeMot corrections)
{
    (*motCorrige).corrections = corrections;
}