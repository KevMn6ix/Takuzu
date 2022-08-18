//
// Created by kevmu on 08/04/2022.
//

#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

int** creer_mat(int taille) // creation d'une matrice dynamique
{
    int **mat = (int**)malloc(taille * sizeof (int*));
    for(int i = 0;i< taille;i++)
    {
        mat[i] = (int*)malloc(taille * sizeof (int));
    }
    return mat;
}

void remplir_matrice_basique(int** mat, int taille) // saisir manuellement des elements pour la matrice masque
{
    int i,j;
    printf("Matrice masque \n");
    for(i = 0;i < taille;i++)
    {
        for(j = 0; j < taille;j++)
        {
            printf("[%d][%d] :",i,j);
            scanf("%d",&mat[i][j]);
            do {
                printf("[%d][%d] :",i,j);
                scanf("%d",&mat[i][j]);
            }while(mat[i][j] != 0 && mat[i][j]!= 1);
        }
    }
}

void liberer_mat(int** mat, int size) // liberer l'espace mémoire
{
    for(int i = 0; i<size; i++)
    {
        free(mat[i]);
        mat[i] = NULL;
    }
}