#ifndef __JEU_2048_H__
#define __JEU_2048_H__

#include "Main_2048.h"

#define VIDE 0

void Jeu_2048(int new, int taille);
Grille** grilleInitiale(int taille);
void jouer(Grille** grille, int taille, int scoreInitial);

#endif
