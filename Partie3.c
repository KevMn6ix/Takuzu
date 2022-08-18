//
// Created by kevmu on 10/04/2022.
//

#include "Partie3.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fonctions.h"
#include <time.h>
#include <windows.h>

int nb_aleatoire_0_2()
{
    return ((rand() % 3) );
}

int nb_aleatoire_3_5()
{
    return ((rand() % 3+ 3));
}

int conversion_bin4x4(int T[4], int n)
{
    int j = 0;
    for(int i = 3; i >=0; i--)
    {
        if(n - pow(2, i) < 0)
        {

            T[j] = 0;
            j++;
        }
        else
        {
            T[j] = 1;
            n = n - pow(2, i);
            j++;
        }
    }
    return T;
}

void afficher_matrice(int** T, int size)
{
    if(size == 4)
        printf("   A B C D\n");
    else
        printf("   A B C D E F G H \n");
    for(int i = 0; i<size; i++)
    {
        printf("%d. ",i+1);
        for(int j = 0; j<size; j++)
        {
            if(T[i][j] == -1)
            {
                Color(0,0);
                printf("%d ",T[i][j]);
                Color(7,0);
            }
            else
            {
                printf("%d ",T[i][j]);
            }
        }
        printf("\n");
    }
}

void display_tab(int T[8],int taille)
{
    for(int i = 0;i<taille;i++)
    {
        printf("%d ", T[i]);
    }
    printf("\n");
}

void gen4x4(int taille)
{
    int a,b,c,d;
    int A[6] = {3,5,6,9,10,12};
    int T[4];
    srand(time(NULL));
    a = nb_aleatoire_0_2();
    b = nb_aleatoire_3_5();

    if(((6-a-1) == b) || (a==b) )
    {
        if(b == 3)
            b++;
        a++;
    }
    c = 6-a-1;
    d = 6-b-1;
    printf("Voici la matrice generée aleatoirement en 4x4");
    printf("   A B C D\n");
    conversion_bin4x4(T,A[a]);
    printf("1. ");
    display_tab(T,taille);

    conversion_bin4x4(T,A[b]);
    printf("2. ");
    display_tab(T,taille);

    conversion_bin4x4(T,A[c]);
    printf("3. ");
    display_tab(T,taille);

    conversion_bin4x4(T,A[d]);
    printf("4. ");
    display_tab(T,taille);
}

int nb_aleatoire_0_23()
{
    int min = 0;
    int max = 22;
    return (rand() % (max - min + 1)) + min;
}

int nb_aleatoire_23_46()
{
    int min = 24;
    int max = 43;
    return (rand() % (max - min + 1)) + min;
}

int conversion_bin8x8(int T[8], int n)
{
    int j = 0;
    for(int i = 7; i >=0; i--)
    {
        if(n - pow(2, i) < 0)
        {

            T[j] = 0;
            j++;
        }
        else
        {
            T[j] = 1;
            n = n - pow(2, i);
            j++;
        }
        //printf("%d ",n);
    }
    return T;
}

void gen8x8(int taille)
{
    int A[46]={37,41,43,45,51,53,73,74,75,77,82,
                 83,85,86,89,90,91,101,102,105,106,
                 107,109,146,148,149,150,153,154,164,165,
                 166,169,170,172,173,178,180,181,182,202,
                 204,210,212,214,218};

    int a,b,c,d,e,f,g,h;
    int T[8];
    srand(time(NULL));
    a = nb_aleatoire_0_23();
    b = nb_aleatoire_0_23();
    c = nb_aleatoire_23_46();
    d = nb_aleatoire_23_46();

    e = 46-a-1;
    f = 46-b-1;
    g = 46-c-1;
    h = 46-d-1;

    printf("Voici la matrice generée aleatoirement en 8x8");

    printf("   A B C D E F G H\n");

    conversion_bin8x8(T,A[a]);
    printf("1. ");
    display_tab(T,taille);

    conversion_bin8x8(T,A[e]);
    printf("2. ");
    display_tab(T,taille);

    conversion_bin8x8(T,A[b]);
    printf("3. ");
    display_tab(T,taille);

    conversion_bin8x8(T,A[f]);
    printf("4. ");
    display_tab(T,taille);

    conversion_bin8x8(T,A[c]);
    printf("5. ");
    display_tab(T,taille);

    conversion_bin8x8(T,A[g]);
    printf("6. ");
    display_tab(T,taille);

    conversion_bin8x8(T,A[d]);
    printf("7. ");
    display_tab(T,taille);

    conversion_bin8x8(T,A[h]);
    printf("8. ");
    display_tab(T,taille);
}
