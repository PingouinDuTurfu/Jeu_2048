#include "Main_2048.h"
#include "Jeu2048.h"
#include "menu2048.h"
#include "sauvegarde2048.h"




void vBitmapOutput(double x, double y, char *string, void *font)
{
	int len,i; // len donne la longueur de la chaîne de caractères

	glRasterPos2f(x,y); // Positionne le premier caractère de la chaîne
	len = (int) strlen(string); // Calcule la longueur de la chaîne
	for (i = 0; i < len; i++) glutBitmapCharacter(font,string[i]); // Affiche chaque caractère de la chaîne
}

void vStrokeOutput(GLfloat x, GLfloat y, char *string, void *font)
{
	char *p;

	glPushMatrix();	// glPushMatrix et glPopMatrix sont utilisées pour sauvegarder 
			// et restaurer les systèmes de coordonnées non translatés
	glTranslatef(x, y, 0); // Positionne le premier caractère de la chaîne
	for (p = string; *p; p++) glutStrokeCharacter(font, *p); // Affiche chaque caractère de la chaîne
	glPopMatrix();
}


void couleurCase(int x)
{
    switch(x){
        
        case 0:
            glColor3ub(205, 193, 180);
        break;
        
        case 2:
            glColor3ub(238, 228, 218);
        break;
        
        case 4:
            glColor3ub(237, 224, 200);
        break;
        
        case 8:
            glColor3ub(242, 177, 121);
        break;
        
        case 16:
            glColor3ub(245, 149, 99);
        break;
        
        case 32:
            glColor3ub(246, 124, 95);
        break;
        
        case 64:
            glColor3ub(246, 94, 59);
        break;
        
        case 128:
            glColor3ub(237, 207, 115);
        break;
        
        case 256:
            glColor3ub(237, 204, 97);
        break;
        
        case 512:
            glColor3ub(237, 200, 80);
        break;
        
        case 1024:
            glColor3ub(100, 0, 255);
        break;
        
        case 2048:
            glColor3ub(255, 0, 255);
        break;
        
        default:
            glColor3ub(0, 0, 0);
        break;
    }
}

void afficherGrille(Grille** grille, int taille)
{
    glColor3ub(200, 173, 127);
    glBegin(GL_QUADS);
                    glVertex2d(-1, 1);
                    glVertex2d(1, 1);
                    glVertex2d(1, 0.818);
                    glVertex2d(-1, 0.818);
                glEnd();
    
    
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
                couleurCase(grille[i][j].valeur);
                glBegin(GL_QUADS);
                    glVertex2d(-1+2*(float)j/(float)taille, 0.818-1.818*(float)i/(float)taille);
                    glVertex2d(-1+2*(float)j/(float)taille, 0.818-1.818*(float)(i+1)/(float)taille);
                    glVertex2d(-1+2*(float)(j+1)/(float)taille, 0.818-1.818*(float)(i+1)/(float)taille);
                    glVertex2d(-1+2*(float)(j+1)/(float)taille, 0.818-1.818*(float)i/(float)taille);
                glEnd();
        }
    }
    
	
	

	glColor3ub(0, 0, 0);
	for(int i = 0; i < taille-1; i++) {
		glBegin(GL_QUADS);
			glVertex2d(-1, 1.818*(float)(i+1)/(float)(taille) -1 -EPAISSEUR_LIGNE);
			glVertex2d(1, 1.818*(float)(i+1)/(float)(taille) -1 -EPAISSEUR_LIGNE);
			glVertex2d(1, 1.818*(float)(i+1)/(float)(taille) -1 +EPAISSEUR_LIGNE);
			glVertex2d(-1, 1.818*(float)(i+1)/(float)(taille) -1 +EPAISSEUR_LIGNE);

			glVertex2d(2*(float)(i+1)/(float)(taille) -1 -EPAISSEUR_LIGNE, -1);
			glVertex2d(2*(float)(i+1)/(float)(taille) -1 -EPAISSEUR_LIGNE, 0.818);
			glVertex2d(2*(float)(i+1)/(float)(taille) -1 +EPAISSEUR_LIGNE, 0.818);
			glVertex2d(2*(float)(i+1)/(float)(taille) -1 +EPAISSEUR_LIGNE, -1);
		glEnd();
	}
}







void afficherNombres(Grille** grille, int taille, int score)
{
	char chaine[30];
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
            if( grille[i][j].valeur != 0){
                
                if( grille[i][j].valeur < 8){
                    glColor3ub(0, 0, 0);
                } else {
                    glColor3ub(255, 255, 255);
                }
                sprintf(chaine, "%d", grille[i][j].valeur);
                vBitmapOutput(-1 + (float)j/(float)taille *2 +0.9/(float)taille, 0.818 + (float)(i+1)/(float)taille *(-1.818) + 0.818/(float)taille,  chaine, GLUT_BITMAP_TIMES_ROMAN_24);
            }
		}
	}
	glColor3ub(0, 0, 0);
	sprintf(chaine, "Score :  %d", score);
    vBitmapOutput(-0.8, 0.9,  chaine, GLUT_BITMAP_TIMES_ROMAN_24);
	
	

}



void afficher(Grille** grille, int taille, int score)
{
	glMatrixMode( GL_MODELVIEW );
    glClear(GL_COLOR_BUFFER_BIT) ;
	glLoadIdentity();
	afficherGrille(grille, taille);
 	afficherNombres(grille, taille, score);
	glFlush();
    SDL_GL_SwapBuffers();
}

int main(int argc, char** argv)
{
    srand(time(NULL));
    
	SDL_Init(SDL_INIT_VIDEO);
	glutInit(&argc, argv);
	glutInitWindowSize(WIDTH, HEIGHT);
    SDL_WM_SetCaption("2048", NULL);
    SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);
    SDL_Surface* icone = IMG_Load("Texture/Logo.png");
    SDL_WM_SetIcon(icone, NULL);
    glEnable(GL_LINE_SMOOTH);

    menu(argc, argv);
    

	SDL_Quit();
	return 0;
}
