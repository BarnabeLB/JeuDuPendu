#include <stdio.h>
#include <stdlib.h>


int trouverLettre(char lettreChoisie, char motMystere[], int lettreTrouvee[])

{
    char lettreValide = 0;
    long i = 0;


    for(i = 0; motMystere[i] != '\0'; i++)
    {
    if(lettreChoisie == motMystere[i])
        {
            lettreValide = 1;
            lettreTrouvee[i] = 1;
        }
    }


    return lettreValide;
}
