#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
long i=0;
char lireCaractere()
{
    char caractere=0;
     caractere = getchar();
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
    // On lit les autres caractères mémorisés un à un jusqu'à l'\n (pour les effacer)
    while (getchar() != '\n') ;
    return caractere; // On retourne le premier caractère qu'on a lu
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
