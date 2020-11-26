#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char lireCaractere()
{

char lettre = 0;

lettre = getchar();
lettre = toupper(lettre);

while(getchar() != '\n');

return lettre;
}
