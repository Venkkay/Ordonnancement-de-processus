/*!
    \file functions.c
    \author Lucas Velay
    \date 10 décembre 2022
    \brief fichier des fontions du programme
*/

// inclusion des librairies
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

// inclusion des fichiers d'en tête
#include "structures.h"
#include "defines.h"
#include "functions.h"

/*!
    \fn PtrList createNode(Process p, PtrList next)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction créant un noeud de la file de procesus
    \param p processus ajouté à la file
    \param next valeur suivante de la liste chainé
    \return le noeud créé
*/
PtrList createNode(Process p, PtrList next){
    PtrList node;
    if((node = MALLOC(List)) == NULL){
        fprintf(stderr, "Error memory allocation");
        exit(1);
    }
    node->processus = p;
    node->next = next;
    return node;
}

/*!
    \fn ajout_activite(PtrList *ordonnanceurHead,  PtrList *ordonnanceurTail, Process processus)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fontion ajoutant un processus à la file
    \param ordonnanceurHead pointeur sur la tête de la file
    \param ordonnanceurTail pointeur sur la queue de la file
    \param processus processus ajouté
*/
void ajout_activite(PtrList *ordonnanceurHead,  PtrList *ordonnanceurTail, Process processus){
    PtrList node = createNode(processus, NULL);
    if(*ordonnanceurTail){
        (*ordonnanceurTail)->next = node;
    }   
    else{
        *ordonnanceurHead = node;
    }
    *ordonnanceurTail = node;
}

/*!
    \fn step(PtrList *ordonnanceurHead, PtrList *ordonnanceurTail)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fontion qui execute et defile un processus 
    \param ordonnanceurHead pointeur sur la tête de la file
    \param ordonnanceurTail pointeur sur la queue de la file
*/
void step(PtrList *ordonnanceurHead, PtrList *ordonnanceurTail){
    PtrList node = *ordonnanceurHead;
    Process processus;
    if(!node){
        printf("Ordonnanceur vide");
    }
    else{
        *ordonnanceurHead = node->next;
        if(*ordonnanceurTail == node){
            *ordonnanceurTail = NULL;
        }
        processus = node->processus;
        free(node);
        printf("%s \t %d\n", processus.name, processus.execution_time);
        sleep(processus.execution_time);
    }
}

/*!
    \fn run(PtrList ordonnanceurHead, PtrList ordonnanceurTail)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fontion execute les processus les uns après les autres avec la fonction step
    \param ordonnanceurHead pointeur sur la tête de la file
    \param ordonnanceurTail pointeur sur la queue de la file
*/
void run(PtrList ordonnanceurHead, PtrList ordonnanceurTail){
    if(ordonnanceurHead){
        printf("\nProcessus \t Execution time\n");
        while(ordonnanceurHead){
            step(&ordonnanceurHead, &ordonnanceurTail);
        }
        printf("Execution des processus fini\n");
    }
    else{
        printf("Aucun processus en attente");
    }
}

/*!
    \fn AffListe(PtrList list)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fontion affichant la file des processus
    \param list File des processus
*/
void AffListe(PtrList list){
    if (!list)
        printf("Liste vide");
    else{
        printf("Name processus \t Time \t Priority\n");
        while(list){
            printf("%s \t %d \t %d\n", list->processus.name, list->processus.execution_time, list->processus.priority);
            list = list->next;
        }
    }
}

/*!
    \fn registerProcess(char *name, int execution_time, int priority)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fontion créant un une variable de type Process avec les donnés que l'on veut
    \param name Nom du processus
    \param execution_time Temps d'execution du processus
    \param priority Priorité du processus
*/
Process registerProcess(char *name, int execution_time, int priority){
    Process processus;
    processus.name = name;
    processus.execution_time = execution_time;
    processus.priority = priority;
    return processus;
}