#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
long i=0;
char lireCaractere()
{
    char caractere=0;
     caractere = getchar();
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas d�j�
    // On lit les autres caract�res m�moris�s un � un jusqu'� l'\n (pour les effacer)
    while (getchar() != '\n') ;
    return caractere; // On retourne le premier caract�re qu'on a lu
}
void gagne(char motMystere[],long tailleTableau,char motTrouve[])
{
   char lettreTapee=0;
   printf("Quel est le mot secret? ");
   printf("%s\n",motTrouve);
   printf("Proposez une lettre :");
   lettreTapee=lireCaractere();
   for(i=0;i<tailleTableau;i++)
   {
       if(lettreTapee==motMystere[i])
       {
           motTrouve[i]=motMystere[i];
       }
   }
}
