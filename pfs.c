#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
int nbr_de_taches = 0;
int nb = 0;
// int id = 1;

typedef struct Deadline
{
    int day;
    int hour;
    int minutes;
} Deadline;
typedef struct ToDo
{
    int id;
    char titre[100];
    char discription[1000];
    char status[100];
    Deadline deadl;
} ToDo;

ToDo listtaches[50];
ToDo swap;
ToDo deadlineswap;
void ajouter()
{

    printf("Entrer nombres de taches:");
    scanf("%d", &nbr_de_taches);

    for (int i = 0; i < nbr_de_taches; i++)
    {
        printf("\n========Entrer tache ========   \n");

        printf("Entrer le titre : ");
        scanf(" %[^\n]", listtaches[nb].titre);

        printf("Entrer le discription : ");
        scanf(" %[^\n]", listtaches[nb].discription);

        printf("Entrer le status(do, doing, done) : ");
        scanf(" %[^\n]", listtaches[nb].status);

        printf("Entrer le deadline dd-hh-mm : \n");
        scanf("%d-%d-%d", &listtaches[nb].deadl.day, &listtaches[nb].deadl.hour, &listtaches[nb].deadl.minutes);

        listtaches[nb].id = nb + 1;
        nb++;
    }
}

void afficher_alphabetique()
{
    for (int i = 0; i < nb - 1; i++)
    {
        for (int j = i + 1; j < nb; j++)
        {
            if (strcasecmp(listtaches[i].titre, listtaches[j].titre) > 0)
            {
                swap = listtaches[i];
                listtaches[i] = listtaches[j];
                listtaches[j] = swap;
            }
        }
    }
    for (int x = 0; x < nb; x++)
    {
        printf("\n========================= TACHE ========================= \n");
        printf("\n Id: %d", listtaches[x].id);
        printf("\n Titre: %s", listtaches[x].titre);
        printf("\n Discription: %s", listtaches[x].discription);
        printf("\n Status: %s ", listtaches[x].status);
        printf("\n deadline: %d-%d-%d \n \n", listtaches[x].deadl.day, listtaches[x].deadl.hour, listtaches[x].deadl.minutes);
    }
}
void afficher_deadline()
{
    for (int i = 0; i < nb - 1; i++)
    {
        for (int j = i + 1; j < nb; j++)
        {
            if (listtaches[i].deadl.day > listtaches[j].deadl.day)
            {
                deadlineswap = listtaches[i];
                listtaches[i] = listtaches[j];
                listtaches[j] = deadlineswap;
            }
        }
    }
    for (int x = 0; x < nb; x++)
    {
        printf("\n========================= TACHE ========================= \n");
        printf("\n Id: %d", listtaches[x].id);
        printf("\n Titre: %s", listtaches[x].titre);
        printf("\n Discription: %s", listtaches[x].discription);
        printf("\n Status: %s ", listtaches[x].status);
        printf("\n deadline: %d-%d-%d \n \n", listtaches[x].deadl.day, listtaches[x].deadl.hour, listtaches[x].deadl);
    }
}

void afficher_trio_jour()
{
    for (int i = 0; i < nbr_de_taches; i++)
    {
        if (listtaches[i].deadl.day < 3)
        {
            printf("\n========================= TACHE ========================= \n");
            printf("\n Id: %d", listtaches[i].id);
            printf("\n Titre: %s", listtaches[i].titre);
            printf("\n Discription: %s", listtaches[i].discription);
            printf("\n Status: %s ", listtaches[i].status);
            printf("\n deadline: %d-%d-%d \n \n", listtaches[i].deadl.day, listtaches[i].deadl.hour, listtaches[i].deadl);
        }
    }
}

void afficher()
{

    int afichchiox;
    printf("\n\n [1] si vous souhaitez Trier les taches par ordre alphabetique : \n");
    printf("\n [2] si vous souhaitez Trier les taches deadline : \n");
    printf("\n [3] si vous souhaitez afficher les taches dont le deadline est dans 3 jours ou moins : \n");
    scanf("%d", &afichchiox);

    if (afichchiox == 1)
    {
        afficher_alphabetique();
    }
    if (afichchiox == 2)
    {
        afficher_deadline();
    }
    if (afichchiox == 3)
    {
        afficher_trio_jour();
    }
}

void update()
{
    int search;
    printf("Entrez le numero de tache a modifier : ");
    scanf("%d", &search);
    for (int i = 0; i < nb; i++)
    {
        if (search == listtaches[i].id)
        {

            printf("Entrer le discription : ");
            scanf(" %[^\n]", listtaches[i].discription);

            printf("Entrer le status : ");
            scanf(" %[^\n]", listtaches[i].status);

            printf("Entrer le deadline dd-hh-mm : \n");
            scanf("%d-%d-%d", &listtaches[i].deadl.day, &listtaches[i].deadl.hour, &listtaches[i].deadl.minutes);
        }
    }
}
void chercher()
{
    int chercherindex;
    char cherchertitre[100];
    int choixCher;
    printf(" \n \t \t \t \t    **************** \n \n");
    printf("\n[1] si vous souhaitez effectuer une recherche avec le id : \n");
    printf("[2] si vous souhaitez effectuer une recherche avec le titre : \n \n");
    scanf(" %d", &choixCher);
    if (choixCher == 1)
    {
        printf("Entrez le id de tache a chercher : ");
        scanf("%d", &chercherindex);
        for (int i = 0; i < nbr_de_taches; i++)
        {
            if (choixCher == 1)
            {
                if (chercherindex == listtaches[i].id)
                {
                    printf("\n Titre: %s", listtaches[i].titre);
                    printf("\n Discription: %s", listtaches[i].discription);
                    printf("\n Status: %s ", listtaches[i].status);
                    printf("\n deadline: %d-%d-%d \n \n", listtaches[i].deadl.day, listtaches[i].deadl.hour, listtaches[i].deadl.minutes);
                }
            }
        }
    }
    if (choixCher == 2)
    {
        printf("Entrez le titre de tache a chercher :");
        scanf("%s", &cherchertitre);
        for (int i = 0; i < nbr_de_taches; i++)
        {
            if (strcmp(cherchertitre, listtaches[i].titre) == 0)
            {
                printf("\n Titre: %s", listtaches[i].titre);
                printf("\n Discription: %s", listtaches[i].discription);
                printf("\n Status: %s ", listtaches[i].status);
                printf("\n deadline: %d-%d-%d \n \n", listtaches[i].deadl.day, listtaches[i].deadl.hour, listtaches[i].deadl.minutes, listtaches[i].deadl);
            }
        }
    }
}

void supprimer()
{
    int s;
    printf("Entrez le id de tache a supprimer : ");
    scanf("%d", &s);
    for (int i = s - 1; i < nb - 1; i++)
    {
        listtaches[i] = listtaches[i + 1];
        nb--;
    }
}

void statique()
{
    char resulta[50] = "done";
    int count = 0, index = 0, i;

    printf("\n Le nombre total des taches est: %d", nb);
    for (i = 0; i < nb; i++)
    {

        if (strcasecmp(listtaches[i].status, resulta) == 0)
        {
            count++;
        }
    }
    printf("\n Le nombre total des taches completes : %d", count);
    for (int j = 0; j < nb; j++)
    {
        if (strcasecmp(listtaches[j].status, resulta) > 0 || strcasecmp(listtaches[j].status, resulta) < 0)
        {
            index++;
        }
    }
    printf("\n Le nombre total des taches incompletes : %d", index);
}

void menu()
{
    int choix;
    do
    {
        printf("\n ================================================================================================================================================================================ ");
        printf("\n  \t \t \t \t \t \t  \t \t  Menu d'application \n");
        printf("\n ================================================================================================================================================================================\n");
        printf("\n\t\t[1] Ajouter une Tache \n");
        printf("\n\t\t[2] Afficher les Taches \n");
        printf("\n\t\t[3] Modifier une Tache \n");
        printf("\n\t\t[4] Rechercher une Tache \n");
        printf("\n\t\t[5] Supprimer une Tache \n");
        printf("\n\t\t[6] Statistiques \n");
        printf("\n\t\t[7] Quitter \n");
        printf("\n ================================================================================================================================================================================\n");
        scanf("\t \t \t %d", &choix);
        if (choix == 1)
        {
            ajouter();
        }
        else if (choix == 2)
        {
            afficher();
        }
        else if (choix == 3)
        {
            update();
        }
        else if (choix == 4)
        {
            chercher();
        }
        else if (choix == 5)
        {
            supprimer();
        }
        else if (choix == 6)
        {
            statique();
        }
    } while (choix != 7);
}

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}