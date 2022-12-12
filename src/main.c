/*!
    \file main.c
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Main program
*/

// inclusion des librairies
#include <stdio.h>
#include <stdlib.h>

// inclusion des fichiers d'en tête
#include "structures.h"
#include "defines.h"
#include "functions.h"

/*!
    \fn int main(int argc, char const *argv[])
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Main function
    \param argc nombre d'arguments en entrée
    \param argv valeurs des arguments en entrée
    \return 0 si tout s'est bien passé
*/
int main(int argc, char const *argv[])
{
    PtrList ordonnanceurHead = NULL;
    PtrList ordonnanceurTail = NULL;

    // Création de la file de processus
    ajout_activite(&ordonnanceurHead, &ordonnanceurTail, registerProcess("Processus 1", 5, 3));
    ajout_activite(&ordonnanceurHead, &ordonnanceurTail, registerProcess("Processus 2", 2, 4));
    ajout_activite(&ordonnanceurHead, &ordonnanceurTail, registerProcess("Processus 3", 7, 2));
    ajout_activite(&ordonnanceurHead, &ordonnanceurTail, registerProcess("Processus 4", 10, 2));
    ajout_activite(&ordonnanceurHead, &ordonnanceurTail, registerProcess("Processus 5", 2, 1));

    // Affichage de la file de processus
    AffListe(ordonnanceurHead);

    // "Execution" des processus
    run(ordonnanceurHead, ordonnanceurTail);

    return 0;
}
