//
// Created by kevmu on 23/04/2022.
//

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

void matsolution(int M[8][8], int taille) // fonction qui affiche la matrice solution
{
    printf("Voici la matrice solution : \n");
    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < taille; j++)
        {
            Color(10,0); // affichage en vert
            printf("[%d]",M[i][j]);
            Color(7,0); // la couleur redevient noire
        }
        printf("\n");
    }
}

void auto_masque(int** mat,int taille) // fonction qui rempli automatiquement une grille masque
{
    int val;
    srand(time(NULL));
    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < taille; j++)
        {
            val = ((rand() % 2) );
            mat[i][j] = val;
        }
    }
}

void init_grille_jeu(int **grille_jeu,int solution[8][8],int **masque, int taille) // fonction  qui met en place la grille jeu
{
    for(int i = 0; i< taille; i++)
    {
        for(int j = 0; j < taille; j++)
        {
            if(masque[i][j] == 1)
            {
                grille_jeu[i][j] = solution[i][j];
            }
            else
            {
                grille_jeu[i][j] = -1;
            }
        }
    }
}

void ajout_affichage_et_verif(int** grille_jeu,int M[8][8],int taille, int lig, int col,int val ) // fonction verifiant la validité du coup
{
    grille_jeu[lig][col] = val;
    afficher_matrice(grille_jeu,taille);
    if(M[lig][col] == grille_jeu[lig][col])
    {
        printf("Le coup est correct !\n\n");
    }
    else
    {
        printf("Coup valide mais incorrect ! \n\n");
    }
}


void jeupartie1(int solution[8][8], int** masque, int** grille_jeu,int taille,int vies) // contenu de la partie 1
{
    do
    {

        printf("Il vous reste %d vies ! \n\n",vies);
        int lig, col, val;
        do
        {
            do
            {
                printf("Saisir ligne : \n");
                scanf("%d", &lig);
            }while((lig <= 0) || (taille < lig));

            do
            {
                printf("Saisir col : \n");
                scanf("%d", &col);
            }while((col <= 0) || (taille < col));

            do
            {
                printf("Saisir val : \n");
                scanf("%d", &val);
            }while((val != 0) && (val != 1));
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
                    ajout_affichage_et_verif(grille_jeu,solution, taille, lig, col, val );
                }
                else
                    vies--;
            }
            else if (lig == 0) // si la ligne est egale a 0
            {
                if (dessous(grille_jeu, taille, lig, col, val) && gauche_et_droite(grille_jeu, taille, lig, col, val) && verifhorizontale(grille_jeu, taille, lig, col, val))
                {
                    ajout_affichage_et_verif(grille_jeu,solution, taille, lig, col, val );
                }
                else
                    vies--;
            }
            else
            {
                if (dessous(grille_jeu,taille, lig, col, val) && gauche_et_droite(grille_jeu,taille, lig, col, val) && entredeuxverticalhorizontale(grille_jeu, taille, lig, col, val))
                {
                    ajout_affichage_et_verif(grille_jeu,solution, taille, lig, col, val );
                }
                else
                    vies--;
            }
        }
        else // dans le cas ou col = 2 ou 3 car on ne peut pas voir les col +1
        {
            if (((lig == (taille-1)) && (col == 0)) || ((lig == (taille-1)) && (col == (taille-1)))) // dans le cas ou on est dans les coins du bas de la matrice
            {
                if (dessus(grille_jeu, taille, lig, col, val) && gauche_et_droite(grille_jeu, taille, lig, col, val))
                {
                    ajout_affichage_et_verif(grille_jeu,solution, taille, lig, col, val );
                }
                else
                    vies--;

            }
            else if (lig == (taille-1)) // si la ligne saisie est la derniere de la grille
            {
                if (gauche_et_droite(grille_jeu, taille, lig, col, val) && dessus(grille_jeu, taille, lig, col, val) && verifhorizontale(grille_jeu, taille, lig, col, val))
                {
                    ajout_affichage_et_verif(grille_jeu,solution, taille, lig, col, val );
                }
                else
                    vies--;
            }
            else
            {
                if (gauche_et_droite(grille_jeu, taille, lig, col, val) && dessus(grille_jeu, taille, lig, col, val) && entredeuxverticalhorizontale(grille_jeu, taille, lig, col, val))
                {
                    ajout_affichage_et_verif(grille_jeu,solution,taille, lig, col, val );
                }
                else
                    vies--;
            }
        }
    }while((vies > 0) && !egalite_matrice(grille_jeu, solution,taille) ); // tant que sa vie n'est pas a vide ou qu'il n' a pas remplie la totalité de la matrice, il continue a jouer


    if(vies)
        printf("Bravo vous avez complete la grille %d x %d en ayant %d vie(s) restant(s)\n",taille,taille,vies);
    else
        printf("Perdu mon ami ! \n");
    liberer_mat(masque,taille);
    liberer_mat(grille_jeu,taille);
}


