/**
 * \file motCorrige.h
 * \brief Implantation du TAD motCorrige
 * \version 1.0
 */

#ifndef __MOT_CORRIGE_H__
#define __MOT_CORRIGE_H__

#include "mot.h"
#include "listeDeMot.h"

typedef struct MotCorrige
{
    Mot mot;
    ListeDeMot corrections;
} MotCorrige;

/**
* \fn Un_motCorrige
* \brief initialise un motCorrige vide
* \return MotCorrige : Le motCorrige vide
* \author De crescenzo Ambre
*/
MotCorrige Un_motCorrige();

/**
* \fn MotCorrige_obtenirMot
* \brief obtenir le mot du motCorrige
* \param MotCorrige motCorrige : le motCorrige dont on veut le mot
* \return Mot : le mot du motCorrige
* \author De crescenzo Ambre
*/
Mot MotCorrige_obtenirMot(MotCorrige motCorrige);

/**
* \fn MotCorrige_fixerMot
* \brief fixe mot dans motCorrige
* \param MotCorrige motCorrige : le motCorrige à modifier
* \param Mot mot : le mot à fixer
* \author De crescenzo Ambre
*/
void MotCorrige_fixerMot(MotCorrige *motCorrige, Mot mot);

/**
* \fn MotCorrige_obtenirCorrections
* \brief Obtenir la liste de corrections (listeDeMot) affectée à un motCorrige
* \param MotCorrige motCorrige : le motCorrige concerné
* \return ListeDeMot : liste contenant les corrections
* \author De crescenzo Ambre
*/
ListeDeMot MotCorrige_obtenirCorrections(MotCorrige motCorrige);

/**
* \fn MotCorrige_fixerCorrections
* \brief fixe les corrections (listeDeMot) d'un motCorrige
* \param MotCorrige motCorrige : le motCorrige à modifier
* \param ListeDeMot corrections : les corrections à fixer
* \author De crescenzo Ambre
*/
void MotCorrige_fixerCorrections(MotCorrige *motCorrige, ListeDeMot corrections);

#endif
