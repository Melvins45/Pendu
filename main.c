#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MIN 1
#define TAILLE_MAX 1000
#define COUPS 9

void gagne(char motMystere[],long tailleTableau,char motTrouve[]);
int main()
{
    long i=0;
    printf("Hello world!\n");
    printf("Bienvenue dans le Pendu\n Par Melvins Group\n");
    FILE* fichier=NULL;
    long nbreMotsDict=0;
    fichier=fopen("dictionnaire.txt","r");
    char caractereActuel=0;

    if (fichier!=NULL)
    {
       do
       {
         caractereActuel = fgetc(fichier);
         if(caractereActuel == '\n')
         {
             nbreMotsDict++;
         }
       }while(caractereActuel!=EOF);
       rewind(fichier);
       fclose(fichier);
    }
    FILE* fichier2=NULL;
    fichier2=fopen("dictionnaire.txt","r");
    const int MAX=nbreMotsDict;
    long numeroLigne=0;
    srand(time(NULL));
    numeroLigne = (rand() % (MAX - MIN + 1)) + MIN;

    char mot[TAILLE_MAX] = "" ;
    if(fichier2 != NULL)
    {
        do
        {
            caractereActuel=getc(fichier2);

            if (caractereActuel == '\n')
            {
              numeroLigne--;
            }
        }while(numeroLigne>0);
        fgets(mot,TAILLE_MAX,fichier2);

        fclose(fichier2);
    }
    long nombreDeLettres=0;
    nombreDeLettres=strlen(mot);
    char *motMystere=NULL;
    motMystere=malloc(nombreDeLettres * sizeof(long));
    strcpy(motMystere,mot);
    char *motTrouvee=NULL;
    motTrouvee=malloc(nombreDeLettres * sizeof(long));
for(i=0;i<nombreDeLettres;i++)
   {
       motTrouvee[i]='*';
   }
motTrouvee[nombreDeLettres-1]=motMystere[nombreDeLettres-1];
char *motInstant=NULL;
motInstant=malloc(nombreDeLettres * sizeof(long));
 long coupsRestants=COUPS,coupPerdu=0;
 while(strcmp(motMystere,motTrouvee)!=0 && coupsRestants!=0)
    {
     strcpy(motInstant,motTrouvee);
     if(coupsRestants>1)
     {
         printf("Il vous manque %ld  coups avant une mort certaine\n",coupsRestants);
         gagne(motMystere,nombreDeLettres,motInstant);
     }
     else
     {
        printf("UN COUP RESTANT.C'est l'heure du BRAINSTORMING.\n");
        gagne(motMystere,nombreDeLettres,motInstant);
     }
    if(strcmp(motInstant,motTrouvee)==0)
   {
       coupPerdu=1;
       coupsRestants=coupsRestants-coupPerdu;
   }
   else
   {
       coupPerdu=0;
       coupsRestants=coupsRestants-coupPerdu;
   }
   strcpy(motTrouvee,motInstant);

 }

 if(strcmp(motTrouvee,motMystere) == 0)
   {
       printf("Gagne!!!!!Le mot secret etait bien :%s .",motMystere);
   }
 else
 {
     printf("PENDU!!!!!Vous gagnerez une prochaine fois.\nLe mot secret etait %s\n",motMystere);
 }
    return 0;
}
