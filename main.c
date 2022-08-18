#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "Partie3.h"
#include <conio.h>
#include <time.h>
#include "Partie1.h"
#include "Partie2.h"
#include <windows.h>
#include "TakuzuRules.h"


int main() {
    printf("Salut mon ami !\n");
    int choix,taille; // initialisation du choix et de sa taille
    do
    {
        printf("Voulez vous jouer avec une grille 4x4 ou 8x8 ? \n(Entrez 1 for 4x4, Entrez 2 for 8x8) \n");
        scanf("%d",&choix);
    }
    while((choix!= 1) && (choix!= 2)); // tant que l'utilisateur ne saisis pas 1 ou 2 le programme lui redemandera de saisir un nombre

    if(choix == 1)
        taille = 4;
    else
        taille = 8;

    int menu;

    do
    {
        printf("Selectionner votre choix : \n1. Resoudre manuellement une grille de jeu\n");
        printf("2. Resoudre automatiquement une grille de jeu\n3. Generer une grille de jeu \n");
        scanf("%d",&menu);
    }while((menu < 1) || (menu> 3)); // tant que l'utilisateur ne saisis pas 1,2 ou 3 le programme lui redemandera de saisir un nombre

    switch (menu)
    {
        case 1:
        {
            int vies = 3; // initialisation des vies
            int sous_menu;  // initialisation du sous menu
            int solution[8][8] = {{1,1,0,0,1,0,0,1},
                                  {0,1,1,0,0,1,1,0},
                                  {1,0,0,1,1,0,1,0},
                                  {0,0,1,1,0,1,0,1},
                                  {0,1,1,0,1,1,0,0},
                                  {1,0,0,1,0,0,1,1},
                                  {1,0,1,1,0,0,1,0},
                                  {0,1,0,0,1,1,0,1}
            }; // initialisation de la matrice solution
            int** masque = creer_mat(taille); // creation de la matrice masque
            do
            {
                printf("Comment voulez vous saisir votre masque : \n1. Saisir manuellement un masque\n2. Generer automatiquement un masque\n");
                printf("3. Jouer directement (par consequent, le masque est saisi automatiquement)\n");
                scanf("%d", &sous_menu); // saisie du choix
            }while(sous_menu < 1 || 3 < sous_menu); // saisie sécurisée pour le sous menu

            if(sous_menu == 1)
            {
                remplir_matrice_basique(masque,taille); // sasie manuelle de la grille masque
                matsolution(solution,taille); // affichage de la matrice solution
                printf("Voici la matrice masque : \n");
                afficher_matrice(masque,taille); // affichage de la matrice masque
            }
            else if(sous_menu == 2)
            {
                auto_masque(masque,taille); // saisie automatique de la grille solution
                matsolution(solution,taille); // affichage de la matrice solution
                printf("Voici la matrice masque : \n");
                afficher_matrice(masque,taille); // affichage de la matrice masque
            }
            else
                auto_masque(masque,taille); // saisie automatique de la grille solution

            int** grille_jeu = creer_mat(taille); // Creation de la grille de jeu
            init_grille_jeu(grille_jeu,solution,masque,taille); // mise en place de la grille de jeu
            printf("Voici la matrice jeu : \n");
            afficher_matrice(grille_jeu, taille); // affichage de la grille jeu
            jeupartie1(solution, masque, grille_jeu, taille, vies); // mise en place du jeu
            break;
        }
        case 2:
        {
            int vies = 3; // initialisation des vies
            int sous_menu; // initialisation du sous menu
            int solution[8][8] = {{1,1,0,0,1,0,0,1},
                                  {0,1,1,0,0,1,1,0},
                                  {1,0,0,1,1,0,1,0},
                                  {0,0,1,1,0,1,0,1},
                                  {0,1,1,0,1,1,0,0},
                                  {1,0,0,1,0,0,1,1},
                                  {1,0,1,1,0,0,1,0},
                                  {0,1,0,0,1,1,0,1}
            }; // initialisation de la matrice solution

            int** masque = creer_mat(taille); // creation de la matrice masque

            do
            {
                printf("Comment voulez vous saisir votre masque : \n1. Saisir manuellement un masque\n2. Generer automatiquement un masque\n");
                printf("3. Jouer directement (par consequent, le masque est saisi automatiquement)\n");
                scanf("%d", &sous_menu);
            }while(sous_menu < 1 || 3 < sous_menu); // saisie securisée

            if(sous_menu == 1) // creation manuelle de la grille masque et affichage de la grille masque et solution
            {
                remplir_matrice_basique(masque,taille);
                matsolution(solution,taille);
                printf("Voici la matrice masque : \n");
                afficher_matrice(masque,taille);
            }
            else if(sous_menu == 2) // creation automatique de la grille masque et affichage de la grille masque et solution
            {
                auto_masque(masque,taille);
                matsolution(solution,taille);
                printf("Voici la matrice masque : \n");
                afficher_matrice(masque,taille);
            }
            else
                auto_masque(masque,taille); // creation automatique et affichage de la grille masque


            int** grille_jeu = creer_mat(taille); // Creation de la grille de jeu
            init_grille_jeu(grille_jeu,solution,masque,taille); // mise en place de la grille de jeu

            printf("Voici la matrice jeu : \n");
            afficher_matrice(grille_jeu, taille); // affichage de la matrice jeu

            jeupartie2(solution, masque, grille_jeu, taille, vies); // mise en place du jeu

            break;
        }
        case 3:
        {
            if(taille == 4)
                gen4x4(taille);
            else
                gen8x8(taille);
            break;
        }
    }
    return 0;
}
