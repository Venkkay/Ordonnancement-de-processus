/*!
    \file defines.h
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fichier de définitions
*/

#ifndef DEFINES_H
#define DEFINES_H

/*!
    \def MALLOC(type)
    \param type Type pour lequel la mémoire est alloué
*/
#define MALLOC(type)((type *) malloc(sizeof(type)))

#endif