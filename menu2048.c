#include "menu2048.h"


void menu(int argc, char** argv)
{

	int taillePlateau = 4;

	
    int choix=1;
    
    do{
        affichageMenu(taillePlateau);
        choix = choixMenu(&taillePlateau);
        
    } while(choix == 1);
    
    int tailleEcran;
    Grille** grille;
    int score = 0;
	switch(choix) {
        
		case 2 :
            grille = grilleInitiale(taillePlateau);
            break;

            
		case 3 :
            grille = recupererPartieEnCours(&taillePlateau, &score);
			break;
            
		default :
			break;
    }
    tailleEcran = 100 + 100*taillePlateau;
    if(tailleEcran > 900) {
        tailleEcran = 900;
    }
    SDL_Quit();
    SDL_Init(SDL_INIT_VIDEO);
    glutInitWindowSize(tailleEcran, tailleEcran*1.1);
    SDL_WM_SetCaption("2048", NULL);
    SDL_SetVideoMode(tailleEcran, tailleEcran*1.1, 32, SDL_OPENGL);
    SDL_Surface* icone = IMG_Load("Texture/Logo.png");
    SDL_WM_SetIcon(icone, NULL);    
    glEnable(GL_LINE_SMOOTH);
         
    afficher(grille, taillePlateau, score);
    jouer(grille, taillePlateau, score);
}





void affichageMenu(int taillePlateau)
	
{
	GLuint textureMenu = chargerTexture("Texture/menu_2048.png");
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureMenu);
	glMatrixMode( GL_MODELVIEW );
    glClear(GL_COLOR_BUFFER_BIT) ;
    glLoadIdentity();

	glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
		glTexCoord2d(1, 0);  glVertex2d(1, 1);
		glTexCoord2d(1, 1);  glVertex2d(1, -1);
		glTexCoord2d(0, 1);  glVertex2d(-1, -1);
		glTexCoord2d(0, 0);  glVertex2d(-1, 1);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	
	char chaine[5];	

    glColor3ub(0, 0, 0);
    sprintf(chaine, "%d", taillePlateau);
    vBitmapOutput(-0.01f, 0.f,  chaine, GLUT_BITMAP_TIMES_ROMAN_24);	
	
	glFlush();
    SDL_GL_SwapBuffers();
}


int choixMenu(int* taillePlateau)
{
	int choix = 0;

	double x;
	double y;
	SDL_Event event;
	while(choix == 0) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_QUIT : 
				SDL_Quit();
				exit(EXIT_SUCCESS);
				break;

			case SDL_MOUSEBUTTONDOWN :
				if(event.button.button == SDL_BUTTON_LEFT) {
					x = ((double)event.button.x) / ((double)WIDTH);
					y = ((double)event.button.y) / ((double)HEIGHT);
				}
				break;

			default :
				break;
		}
		if(x >= 0.25 && x <= 0.38 && y >= 0.43 && y <= 0.58) {
			choix = 1;
            if(*taillePlateau > 3){
                *taillePlateau-=1;
                
            }
		}
		
		if(x >= 0.62 && x <= 0.75 && y >= 0.43 && y <= 0.58) {
			choix = 1;
            if(*taillePlateau < 10){
                *taillePlateau+=1;
            }
		}

		if(x >= 0.25 && x <= 0.75 && y >= 0.62 && y <= 0.77) {
			choix = 2;
		}
		if(x >= 0.25 && x <= 0.75 && y >= 0.80 && y <= 0.95) {
			choix = 3;
		}
	}
	return(choix);
}
