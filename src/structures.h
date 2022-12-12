/*!
    \file structures.h
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fichier de structures
*/

#ifndef STRUCTURES_H
#define STRUCTURES_H


/*!
    \struct Process
    \brief Structure d'un processus
*/
typedef struct defProcess{
    char *name;         /*!< Nom du processus */
    int execution_time; /*!< Temps du processus */
    int priority;       /*!< Priorité du processus */
}Process;

/*!
    \struct List
    \brief Structure d'une liste chaîné de processus
*/
typedef struct defList{
    Process processus;      /*!< Elément de la liste chainée de type Process */
    struct defList *next;   /*!< Pointeur sur le noeud suivant de la liste chaîné */
}List;

typedef List* PtrList;

#endif