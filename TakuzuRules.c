//
// Created by kevmu on 28/04/2022.
//

#include "TakuzuRules.h"
#include "Partie1.h"
#include "Partie3.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fonctions.h"
#include <time.h>
#include <windows.h>

/*------ Rules number 1 ------*/

/*----- Verification à droite d’une série de deux 0/deux 1, il ne peut y avoir qu’un 1/0------*/
int droite(int** M, int taille, int lig, int col,int val)
{
    if((M[lig][col+1] == M[lig][col+2]) && M[lig][col+1] == val)
    {
        printf("Mauvais coup car la regle suivante n'a pas ete respectee :\na droite d'une serie de deux 0/deux1, il ne peut y avoir qu'un 1/0 \n\n");
        return 0;
    }
    else
        return 1;
}

/*----- Verification à gauche d’une série de deux 0/deux 1, il ne peut y avoir qu’un 1/0 ------*/
int gauche(int** M, int taille, int lig, int col,int val)
{
    if((M[lig][col-1] == M[lig][col-2]) && (M[lig][col-1] == val))
    {
        printf("Mauvais coup car la regle suivante n'a pas ete respectee :\na gauche d'une serie de deux 0/deux 1, il ne peut y avoir qu'un 1/0 \n\n"); // à fixer
        return 0;
    }
    else
        return 1;
}

/*--- Verification en dessous d’une série de deux 0/deux 1, il ne peut y avoir qu’un 1/0 -----*/
int dessous(int** M, int taille, int lig, int col,int val)
{
    if((M[lig+1][col] == M[lig+2][col]) && (M[lig+1][col] == val))
    {
        printf("Mauvais coup car la regle suivante n'a pas ete respectee :\nen dessous d'une serie de deux 0/deux 1, il ne peut y avoir qu'un 1/0 \n\n");
        return 0;
    }
    else
        return 1;
}

/*---- Verification au dessus d’une série de deux 0/deux 1, il ne peut y avoir qu’un 1/0 ---*/
int dessus(int** M, int taille, int lig, int col,int val)
{
    if((M[lig-1][col] == M[lig-2][col]) && M[lig-1][col] == val)
    {
        printf("Mauvais coup car la regle suivante n'a pas ete respectee :\nau dessus d'une série de deux 0/deux 1, il ne peut y avoir qu'un 1/0 \n\n");
        return 0;
    }
    else
        return 1;
}

/*---- Verticalement Entre deux 0/deux 1, il ne peut y avoir qu’un 1/0 ----*/
int verifverticale(int** M, int taille, int lig, int col,int val)
{
    if((M[lig-1][col] == M[lig+1][col]) && (M[lig-1][col] == val))
    {
        printf("Mauvais coup car la regle suivante n'a pas ete respectee :\nVerticalement Entre deux 0/deux 1, il ne peut y avoir qu'un 1/0 \n\n");
        return 0;
    }
    else
        return 1;
}

/*---- horizontalement, Entre deux 0/deux 1, il ne peut y avoir qu’un 1/0 ----*/
int verifhorizontale(int** M, int taille, int lig, int col,int val)
{
    if((M[lig][col-1] == M[lig][col+1]) && (M[lig][col-1] == val))
    {
        printf("Mauvais coup car la regle suivante n'a pas ete respectee :\nHorizontalement Entre deux 0/deux 1, il ne peut y avoir qu'un 1/0 \n\n");
        return 0;
    }
    else
        return 1;
}

/*----- Rules to verify if there are as many 0 as 1 -----*/
int compteur0ou1h(int** M, int taille, int lig, int col,int val)
{
    int cpt = 0;
    int i = lig;
    for(int j = 0;j< taille;j++)
        if(M[i][j] == val)
            cpt++;
    if(cpt >= (taille/2))
    {
        printf("Mauvais coup car la regle suivante n'a pas ete respectee :\nDans une ligne ou une colonne, il ne peut y avoir plus de deux 0 ou deux 1 a la suite \n");
        printf("En effet il y a %d de fois le chiffre %d\n\n",cpt,val);
        return 0;
    }
    else
        return 1;
}
/* la meme chose ici */
int compteur0ou1v(int** M, int taille, int lig, int col,int val)
{
    int cpt = 0;
    int j = col;
    for(int i = 0;i< taille;i++)
        if(M[i][j] == val)
            cpt++;
    if(cpt >= (taille/2))
    {
        printf("Mauvais coup car la regle suivante n'a pas ete respectee :\nDans une ligne ou une colonne, il ne peut y avoir plus de deux 0 ou deux 1 a la suite \n");
        printf("En effet il y a %d de fois le chiffre %d\n\n",cpt,val);
        return 0;
    }
    else
        return 1;
}

int parite0et1(int** M, int taille, int lig, int col,int val) // fonction qui verifie la parité des nombres entre eux
{
    if(compteur0ou1v(M,taille,lig,col,val) && compteur0ou1h(M,taille,lig,col,val))
        return 1;
    else
        return 0;
}

/* Fonction qui assemble la fonctions left, right, asmany0as1*/
int gauche_et_droite(int** M, int taille, int lig, int col,int val) // quand le nom de la fonction est longue il beug jsp prq
{
    if(gauche(M,taille,lig,col,val) && droite(M,taille,lig,col,val) && parite0et1(M,taille,lig,col,val))
        return 1;
    else
        return 0;
}

/* Fonction qui assemble la fonctions verifhorizontale et  verifverticale */
int entredeuxverticalhorizontale(int** M, int taille, int lig, int col,int val)
{
    if(verifhorizontale(M,taille,lig,col,val)&& verifverticale(M,taille,lig,col,val))
        return 1;
    else
        return 0;
}

/* fonction qui verifie si la grille jeu est en adéquation avec la grille solution*/
int egalite_matrice(int** grille_jeu, int solution[8][8], int taille)
{
    int a = 1;
    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < taille; j++)
        {
            if(solution[i][j] != grille_jeu[i][j])
            {
                a = 0;
                break;
            }
        }
    }
    if(a)
        return 1;
    else
        return 0;
}