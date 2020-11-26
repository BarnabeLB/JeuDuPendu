#include <stdio.h>
#include <stdlib.h>
#include "lireCaractere.h"
#include "trouverLettre.h"
#include "gagnerPartie.h"
#include <string.h>
#include "dessin.h"
#define TAILLE_MAX 1000





int main(int argc, char* argv[])
{

    char motMystere[TAILLE_MAX] = "";
    int* lettreTrouvee = NULL; /* un pointeur qu'on utilisera comme tableau de Booleens*/
    char lettreCHoisie = 0;
    long i = 0;
    long tailleMot = 0; //pq taille mot marche pas quand initialisé <7 ?
    long nombreCoups = 0;
    char test[TAILLE_MAX] = "";

    if(!trouverMot(motMystere))
    {
        exit(0);
    }

    /*if(!trouverMot(test))
    {
        exit(0);
    }*/
    printf("%s\n", test);   // A QUOI CA SERT ? Pourquoi c'est nécéssaire à l'éxécution?

   lettreTrouvee = malloc(20 * sizeof(int));// allocation à 20 car tailleMot ne fonctionne pas
    if(lettreTrouvee == NULL)
    {
        exit(0);
    }

    printf(" Bienvenu dans le jeu du pendu !\n");

printf("      ______________\n");
printf("      |   /        |\n");
printf("      |  /         |\n");
printf("      | /          |\n");
printf("      |/           ~\n");
printf("      |          <°_°>\n");
printf("      |          __|__\n");
printf("      |          | | |\n");
printf("      |            |\n");
printf("      |           / \\\n");
printf("      |          /   \\\n");
printf("      |\n");
printf("      |\n");
printf("     /|\n");
printf("    / |\n");
printf("___/__|_____________\n");




    tailleMot = strlen(motMystere);
    nombreCoups = tailleMot;

    while(nombreCoups > 0 && !gagnerPartie(lettreTrouvee, tailleMot))
    {

        for(i = 0; i<tailleMot; i++)
        {
            if(lettreTrouvee[i])
                {

                    printf("%c", motMystere[i]);

                }
            else
                printf("*");
        }

        /*for(i=0;i<tailleMot;i++)
        {
            printf("%d", lettreTrouvee[i]);
        }*/

        printf("\nChoisis une lettre pour découvrir le mot mystère : \n");
        lettreCHoisie = lireCaractere();

        if(!trouverLettre(lettreCHoisie, motMystere, lettreTrouvee))
        {
        nombreCoups--;
        printf("\nPerdu ! Plus que %ld coups restants\n", nombreCoups);
        dessin(nombreCoups);

        }
        else
        {
        printf("\nTu as trouvé une lettre, il te reste %ld coups à jouer\n", nombreCoups);
        }


    }

        if(gagnerPartie(lettreTrouvee, tailleMot))
            {
            printf("Bravo le bon mot était effectivement %s\n", motMystere);
            }
        else
            {
            printf("Tu as perdu, le motMystère était : %s\n", motMystere);
            }

    free(lettreTrouvee);



    return 0;
}
