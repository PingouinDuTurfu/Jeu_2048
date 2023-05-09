#ifndef __MAIN_2048_H__
#define __MAIN_2048_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#define WIDTH 1200
#define HEIGHT 900
#define VIDE 0
#define EPAISSEUR_LIGNE 0.003

typedef struct{
    int x;
    int y;
} Coord;

typedef struct {
    int valeur;
    int deja;
} Grille;

void sleep(int);


void vBitmapOutput(double x, double y, char *string, void *font);
void vStrokeOutput(GLfloat x, GLfloat y, char *string, void *font);
void afficher(Grille** grille, int taille, int score);

#include "Chargement_Images_Textures.h"
#include "Jeu2048.h"
#include "menu2048.h"
#include "sauvegarde2048.h"



#endif
