
#include "Main_2048.h"

void SauvegardePartieEnCours(Grille** grille, int taille, int score)
{
	char Sauvegarde[40] = "Sauvegarde/sauvegarde_Partie_En_Cours";
	FILE* p_File = NULL;
	p_File = fopen(Sauvegarde, "w");
	if(p_File == NULL) {
		fprintf(stderr, "Impossible de sauvegarder\n");
	} else {
		char chaine[10];
		sprintf(chaine, "%d\n", taille);
		fputs(chaine, p_File);
        sprintf(chaine, "%d\n", score);
		fputs(chaine, p_File);
		for(int i = 0; i < taille; i++) {
			for(int j = 0; j < taille; j++) {
					sprintf(chaine, "%d\n", grille[i][j].valeur);
					fputs(chaine, p_File);
			}
// 			fputs("\n", p_File);
		}
		fclose(p_File);
	}
}


Grille** recupererPartieEnCours(int* taille, int* score)
{
	char Sauvegarde[40] = "Sauvegarde/sauvegarde_Partie_En_Cours";
	FILE* p_File = NULL;
    Grille** grille;
    
	p_File = fopen(Sauvegarde, "r");
	if(p_File == NULL) {
		fprintf(stderr, "Impossible de sauvegarder\n");
	} else {
		char chaine[10];
		fgets(chaine, 9, p_File);
		*taille = (int) strtol(chaine, NULL, 10);
        fgets(chaine, 9, p_File);
		*score = (int) strtol(chaine, NULL, 10);
        printf("%d\n", *taille);
        
        grille = grilleInitiale(*taille);
		
		int nb;
		for(int i = 0; i < *taille; i++) {
			for(int j = 0; j < *taille; j++) {
					fgets(chaine, 9, p_File);
					nb = (int) strtol(chaine, NULL, 10);
					grille[i][j].valeur = nb;
                    printf("case %d %d -- %d\n",i ,j, nb);
			}
		}
	}
	fclose(p_File);

	return(grille);
}
