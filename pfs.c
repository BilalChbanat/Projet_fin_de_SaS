#include <stdio.h>
#include <string.h>
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
} ToDo;

ToDo listtaches[50];
Deadline dead_line_list[50];

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

        printf("Entrer le status : ");
        scanf(" %[^\n]", listtaches[nb].status);

        printf("Entrer le deadline dd-hh-mm : \n");
        scanf("%d-%d-%d", &dead_line_list[nb].day, &dead_line_list[nb].hour, &dead_line_list[nb].minutes);

        listtaches[nb].id = nb + 1;
        nb++;
    }
}

void afficher()
{
    // ToDo swap;

    // for (int i = 0; i < nbr_de_taches; i++)
    // {
    //     for (int j = i + 1; j < nbr_de_taches; j++)
    //     {
    //         if (strcmp(listtaches[i].titre, listtaches[j].titre) > 0)
    //         {
    //             swap = listtaches[i];
    //             listtaches[i] = listtaches[j];
    //             listtaches[j] = swap;
    //         }
    //     }
    // }
    for (int i = 0; i < nb; i++)
    {
        printf("\n========================= TACHE ========================= \n");
        printf("\n Id: %d", listtaches[i].id);
        printf("\n Titre: %s", listtaches[i].titre);
        printf("\n Discription: %s", listtaches[i].discription);
        printf("\n Status: %s ", listtaches[i].status);
        printf("\n deadline: %d-%d-%d \n \n", dead_line_list[i].day, dead_line_list[i].hour, dead_line_list[i].minutes);
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
            scanf("%d-%d-%d", &dead_line_list[i].day, &dead_line_list[i].hour, &dead_line_list[i].minutes);
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
                    printf("\n deadline: %d-%d-%d \n \n", dead_line_list[i].day, dead_line_list[i].hour, dead_line_list[i].minutes);
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
                printf("\n deadline: %d-%d-%d \n \n", dead_line_list[i].day, dead_line_list[i].hour, dead_line_list[i].minutes);
            }
        }
    }
}

void supprimer()
{
    char null[10] = {"\0"};
    int s;
    printf("Entrez le id de tache a supprimer : ");
    scanf("%d", &s);
    for (int i = s - 1; i < nb - 1; i++)
    {
        listtaches[i] = listtaches[i + 1];
        nb--;
    }
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
        printf("\n\t\t[6] Quitter \n");
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
    } while (choix != 6);
}

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}
