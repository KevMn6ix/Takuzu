//
// Created by kevmu on 29/04/2022.
//

#include "Partie2.h"

#include "Partie1.h"
#include "Partie3.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fonctions.h"
#include <time.h>
#include <windows.h>
#include "TakuzuRules.h"

void jeupartie2(int solution[8][8], int** masque, int** grille_jeu,int taille,int vies) // dans cette partie rien ne differe de la partie 1
{
    do
    {
        printf("Il vous reste %d vies ! \n\n",vies);
        int lig, col, val;
        do
        {
            // Les lignes et colonnes sont desormais saisies automatiquement c'est la seule chose qui change de la partie 1
            srand(time(NULL));
            lig = rand()% taille+1;
            printf("La ligne : %d\n",lig);
            Sleep(1000);

            srand(time(NULL));
            col = rand()%taille+1;
            printf("La col : %d\n",col);
            Sleep(1000);

            srand(time(NULL));
            val = rand()%2;
            printf("La val : %d\n",val);
            Sleep(1000);

            lig--;
            col--;
        }
        while(grille_jeu[lig][col] != -1);

        if ((lig == 0) || (lig == 1)) // dans le cas ou ligne = 0 ou 1 car on ne peut pas voir les lignes -1
        {
            if (((lig == 0) && (col == 0)) || ((lig == 0) && (col == taille))) // dans le cas ou on est dans les coins du haut de la matrice
            {
                if (dessous(grille_jeu, taille, lig, col, val) && gauche_et_droite(grille_jeu, taille, lig, col, val))
                {
                    Sleep(500);
                    ajout_affichage_et_verif(grille_jeu,solution, taille, lig, col, val );
                }
                else
                    vies--;
            }
            else if (lig == 0)
            {
                if (dessous(grille_jeu, taille, lig, col, val) && gauche_et_droite(grille_jeu, taille, lig, col, val) && verifhorizontale(grille_jeu, taille, lig, col, val))
                {
                    Sleep(500);
                    ajout_affichage_et_verif(grille_jeu,solution, taille, lig, col, val );
                }
                else
                    vies--;
            }
            else
            {
                if (dessous(grille_jeu, taille, lig, col, val) && gauche_et_droite(grille_jeu, taille, lig, col, val) && entredeuxverticalhorizontale(grille_jeu, taille, lig, col, val))
                {
                    Sleep(500);
                    ajout_affichage_et_verif(grille_jeu,solution, taille, lig, col, val );
                }
                else
                    vies--;
            }
        }
        else // dans le cas ou col = size-1 ou size car on ne peut pas voir les col +1
        {
            if (((lig == (taille-1)) && (col == 0)) || ((lig == (taille-1)) && (col == (taille-1)))) // dans le cas ou on est dans les coins du bas de la matrice
            {
                if (dessus(grille_jeu, taille, lig, col, val) && gauche_et_droite(grille_jeu, taille, lig, col, val))
                {
                    Sleep(500);
                    ajout_affichage_et_verif(grille_jeu,solution, taille, lig, col, val );
                }
                else
                    vies--;

            }
            else if (lig == (taille-1))
            {
                if (gauche_et_droite(grille_jeu, taille, lig, col, val) && dessus(grille_jeu, taille, lig, col, val) && verifhorizontale(grille_jeu, taille, lig, col, val))
                {
                    Sleep(500);
                    ajout_affichage_et_verif(grille_jeu,solution, taille, lig, col, val );
                }
                else
                    vies--;
            }
            else
            {
                if (gauche_et_droite(grille_jeu, taille, lig, col, val) && dessus(grille_jeu, taille, lig, col, val) && entredeuxverticalhorizontale(grille_jeu, taille, lig, col, val))
                {
                    Sleep(500);
                    ajout_affichage_et_verif(grille_jeu,solution, taille, lig, col, val );
                }
                else
                    vies--;
            }
        }
    }
    while((vies > 0) && !egalite_matrice(grille_jeu, solution,taille) );

    if(vies)
        printf("Bravo vous avez complete la grille %d x %d en ayant %d vie(s) restant(s)\n",taille,taille,vies);
    else
        printf("Perdu mon ami ! \n");
    liberer_mat(masque,taille);
    liberer_mat(grille_jeu,taille);
}
