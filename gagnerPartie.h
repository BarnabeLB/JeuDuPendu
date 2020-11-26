#include <stdio.h>
#include <stdlib.h>

long gagnerPartie(int lettreTrouvee[], long tailleMot)
{

    int gagner = 1;
    long i = 0;


    for(i = 0; i<tailleMot; i++)
    {
        if(lettreTrouvee[i] == 0)
            gagner = 0;

    }


        return gagner;
}
