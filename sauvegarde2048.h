#ifndef __SAUVEGARDE_H__
#define __SAUVEGARDE_H__

#include "Main_2048.h"


void SauvegardePartieEnCours(Grille** grille, int taille, int score);
Grille** recupererPartieEnCours(int* taille, int* score);


#endif
