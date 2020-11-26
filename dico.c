#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 1000
#include <time.h>


#include "dico.h"

int trouverMot(char* mot)
{
 FILE* dico = NULL;
 char recupMot[TAILLE_MAX] = "";
 int nombreMot = 0;
 int i = 0;
 int prendreHasard = 0;
 const int MIN = 1;
 char motChoisi[TAILLE_MAX] ="";

 dico = fopen("dico.txt","r+");
if(dico != NULL)
{
 while(fgets(recupMot,TAILLE_MAX,dico)!= NULL)/* fgets s'arrête à chaque \n, on compte donc le nombre de boucle
                                                faites jusqu'au NULL, pour savoir le nombre de mot */
    {
    nombreMot++;
    }

                          /* On fait revenir le curseur au début du fichier*/

srand(time(NULL));                            /*On choisit au hasard un nombre entre 1 et le
                                                    le nombre de mot de la liste*/

prendreHasard = (rand()%(nombreMot - MIN + 1)) +MIN;




rewind(dico);                       /*curseur remis au début du fichier*/

while(prendreHasard>0)                  /*fichier parcouru, tant que la variable n'est pas retournée à 0*/
{
    fgets(mot,TAILLE_MAX,dico);
    prendreHasard--;
}

mot[strlen(mot)-1] = '\0';          /*le caractère '\n' est retiré pour pas faire buger le pendu*/

fclose(dico);

}
return 1;


}
