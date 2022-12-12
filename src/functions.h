/*!
    \file functions.h
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fichier d'en tête des fonctions de fonctions.c
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

PtrList createNode(Process p, PtrList next);
void ajout_activite(PtrList *ordonnanceurHead,  PtrList *ordonnanceurTail, Process processus);
void step(PtrList *ordonnanceurHead, PtrList *ordonnanceurTail);
void run(PtrList ordonnanceurHead, PtrList ordonnanceurTail);
void AffListe(PtrList liste);
Process registerProcess(char *name, int execution_time, int priority);

#endif