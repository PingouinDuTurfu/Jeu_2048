#include "Jeu2048.h"


/*

 0    |   j+
      |
 -----+-----
      |
 i+   |
  
*/

void remisAZero(Grille** grille, int taille)
{
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
            grille[i][j].deja=0;
        }
    }
}


int jouer_haut(Grille** grille, int* score, int taille)
{
        int k=0;
        int deplacement=0;
        
        for(int j=0; j<taille; j++){
            for(int i=1; i<taille; i++){
                
                if(grille[i][j].valeur != VIDE && grille[i-1][j].valeur == VIDE)
                {
                    
                    k=0;
                    while(i-1-k >= 0 && (grille[i-1-k][j].valeur == VIDE || (grille[i-k][j].valeur == grille[i-1-k][j].valeur && grille[i-1-k][j].deja == 0))){
                        
                        if(grille[i-1-k][j].valeur == VIDE){
                            grille[i-1-k][j].valeur = grille[i-k][j].valeur;
                            grille[i-k][j].valeur = VIDE;
                        }   
                            else {
                                *score += 2*grille[i-1-k][j].valeur;
                                grille[i-1-k][j].valeur *=2;
                                grille[i-1-k][j].deja++;
                                grille[i-k][j].valeur = VIDE;
                                k=1000;
                        }
                        deplacement++;
                        k++;
                    }
                    
                }   else {   
                        if(grille[i][j].valeur!=VIDE && grille[i][j].valeur == grille[i-1][j].valeur && grille[i-1][j].deja == 0){
                            deplacement++;
                            *score += 2*grille[i][j].valeur;
                            grille[i][j].valeur = VIDE;
                            grille[i-1][j].deja++;
                            grille[i-1][j].valeur *= 2;
                        }
                    }
            }
        }
    remisAZero(grille, taille);
    return(deplacement);
}

int jouer_bas(Grille** grille, int* score, int taille)
{
        int k=0;
        int deplacement=0;
        
        for(int j=0; j<taille; j++){
            for(int i=taille-2; i>=0; i--){
                if(grille[i][j].valeur != VIDE && grille[i+1][j].valeur == VIDE)
                {
                    k=0;
                    while(i+1+k <= taille-1 && (grille[i+1+k][j].valeur == VIDE || (grille[i+k][j].valeur == grille[i+1+k][j].valeur && grille[i+1+k][j].deja == 0))){
                        
                        if(grille[i+1+k][j].valeur == VIDE){
                            grille[i+1+k][j].valeur = grille[i+k][j].valeur;
                            grille[i+k][j].valeur = VIDE;
                        }   
                            else {
                                *score += 2*grille[i+1+k][j].valeur;
                                grille[i+1+k][j].valeur *=2;
                                grille[i+1+k][j].deja++;
                                grille[i+k][j].valeur = VIDE;
                                k=1000;
                            }
                        deplacement++; 
                        k++;
                    }
                } else {
                        if(grille[i][j].valeur!=VIDE && grille[i][j].valeur == grille[i+1][j].valeur){
                            deplacement++;
                            *score += 2*grille[i][j].valeur;
                            grille[i][j].valeur = VIDE;
                            grille[i+1][j].deja++;
                            grille[i+1][j].valeur *= 2;
                        }
                }
            }
        }
    remisAZero(grille, taille);
    
    return(deplacement);
}

int jouer_gauche(Grille** grille, int* score, int taille)
{
        int k=0;
        int deplacement=0;
        
        for(int i=0; i<taille; i++){
            for(int j=1; j<taille; j++){
                
                if(grille[i][j].valeur != VIDE && grille[i][j-1].valeur == VIDE)
                {
                    k=0;
                    while(j-1-k >= 0 && (grille[i][j-1-k].valeur == VIDE || (grille[i][j-k].valeur == grille[i][j-1-k].valeur && grille[i][j-1-k].deja == 0))){
                        
                        if(grille[i][j-1-k].valeur == VIDE){
                            grille[i][j-1-k].valeur = grille[i][j-k].valeur;
                            grille[i][j-k].valeur = VIDE;
                        }   
                            else {
                                *score += 2*grille[i][j-1-k].valeur;
                                grille[i][j-1-k].valeur *=2;
                                grille[i][j-1-k].deja++;
                                grille[i][j-k].valeur = VIDE;
                                k=1000;
                        }
                        deplacement++;
                        k++;
                    }
                    
                }   else {   
                        if(grille[i][j].valeur!=VIDE && grille[i][j].valeur == grille[i][j-1].valeur && grille[i][j-1].deja == 0){
                            deplacement++;
                            *score += 2*grille[i][j].valeur;
                            grille[i][j].valeur = VIDE;
                            grille[i][j-1].deja++;
                            grille[i][j-1].valeur *= 2;
                        }
                    }
            }
        }
    remisAZero(grille, taille);
    
    return(deplacement);
}

int jouer_droit(Grille** grille, int* score, int taille)
{
        int k=0;
        int deplacement=0;
        
        for(int i=0; i<taille; i++){
            for(int j=taille-2; j>=0; j--){
                if(grille[i][j].valeur != VIDE && grille[i][j+1].valeur == VIDE)
                {
                    k=0;
                    while(j+1+k <= taille-1 && (grille[i][j+1+k].valeur == VIDE || (grille[i][j+k].valeur == grille[i][j+1+k].valeur && grille[i][j+1+k].deja == 0))){
                        
                        if(grille[i][j+1+k].valeur == VIDE){
                            grille[i][j+1+k].valeur = grille[i][j+k].valeur;
                            grille[i][j+k].valeur = VIDE;
                        }   
                            else {
                                *score += 2*grille[i][j+1+k].valeur;
                                grille[i][j+1+k].valeur *=2;
                                grille[i][j+1+k].deja++;
                                grille[i][j+k].valeur = VIDE;
                                k=1000;
                            }
                        deplacement++;
                        k++;
                    }
                } else {
                        if(grille[i][j].valeur!=VIDE && grille[i][j].valeur == grille[i][j+1].valeur && grille[i][j+1].deja == 0){
                            deplacement++;
                            *score += 2*grille[i][j].valeur;
                            grille[i][j+1].deja++;
                            grille[i][j].valeur = VIDE;
                            grille[i][j+1].valeur *= 2;
                        }
                }
            }
        }
    
    remisAZero(grille, taille);
    
    return(deplacement);
}



Grille** genererGrille(int taille)
{
    Grille** grille = (Grille**) malloc(taille*sizeof(Grille*));
    for( int i = 0; i < taille ; i++){
        grille[i] = (Grille*) malloc (taille*sizeof(Grille));
        for(int j = 0; j<taille; j++){
            grille[i][j].valeur = VIDE;
            
        }
    }
    
    remisAZero(grille, taille);
    
    return(grille);
}

void ajouterValeurAleatoire(Grille** grille, int taille)
{

    int x;
    int y;
    
    do {
        x = rand()%taille;
        y = rand()%taille;
        
    } while(grille[x][y].valeur != VIDE);
       
    grille[x][y].valeur = 2*(1+rand()%2);    
}

Grille** grilleInitiale(int taille)
{   
    
    Grille** grille = genererGrille(taille);
    
    ajouterValeurAleatoire(grille, taille);
    ajouterValeurAleatoire(grille, taille);
    
    return(grille);
}


int saisie(Grille** grille, int* score, int taille){
    
    int verif = 0;
    
    SDL_Event event;
    SDL_WaitEvent(&event);
    
    switch(event.type){
        case SDL_QUIT:
                SDL_Quit();
                verif=-1;
                break;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym) {
                    case SDLK_UP: // FlÃ¨che haut
                        verif = jouer_haut(grille, score, taille);
                        break;
                    case SDLK_DOWN: // FlÃ¨che bas
                        verif = jouer_bas(grille, score, taille);
                        break;
                    case SDLK_RIGHT: // FlÃ¨che droite
                        verif = jouer_droit(grille, score, taille);
                        break;
                    case SDLK_LEFT: // FlÃ¨che gauche
                        verif = jouer_gauche(grille, score, taille);
                        break;
                        
                    default:
                        break;
                } 
            break;
            
        default: 
            break;
    }
    
    return(verif);
}


int fin(Grille** grille, int taille)
{
    int compteur=0;
    int deplacement=1;
    
    
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
            if(grille[i][j].valeur != VIDE){
                compteur++;
            }
        }
    }
    
    if(compteur==taille*taille){
        
        deplacement = 0;
        
        for(int i=1; i<taille-1; i++){
            for(int j=1; j<taille-1; j++){
                if(grille[i][j].valeur == grille[i+1][j].valeur || grille[i][j].valeur == grille[i-1][j].valeur || grille[i][j].valeur == grille[i][j+1].valeur || grille[i][j].valeur == grille[i][j-1].valeur){
                    deplacement++;
                }
            }
        }

        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                if(grille[(taille-1)*i][j*(taille-1)].valeur == grille[(taille-1)*i+(i*(-2)+1)][j*(taille-1)].valeur ||grille[(taille-1)*i][j*(taille-1)].valeur == grille[(taille-1)*i][j*(taille-1)+(j*(-2)+1)].valeur){
                    deplacement++;
                }
            }
        }
    }
    
    return(deplacement);
}

void jouer(Grille** grille, int taille, int scoreInitial)
{
    int fini = fin(grille, taille);   
    int verif =42;
    int score = scoreInitial;
    
    while( fini!=0 && verif !=-1){
        
        SauvegardePartieEnCours(grille, taille, score);
        do {
           verif = saisie(grille, &score, taille); 
        } while(verif==0);
        
        ajouterValeurAleatoire(grille, taille);

        
        
        fini = fin(grille, taille);
        
        if(verif != -1) {
            afficher(grille, taille, score);
        }
        
        
   
        printf("votre score : %d\n", score);
    }
        
    if(fini == 0){
        printf("perdu\n");
    }
}





