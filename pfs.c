#include <stdio.h>
#include <string.h>
int nbr_de_taches = 0;
int id = 1;

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
        printf("\n========Entrer %d tache ========   \n", i + 1);

        printf("Entrer le titre : ");
        scanf(" %[^\n]", listtaches[i].titre);

        printf("Entrer le discription : ");
        scanf(" %[^\n]", listtaches[i].discription);

        printf("Entrer le status : ");
        scanf(" %[^\n]", listtaches[i].status);

        printf("Entrer le deadline dd-hh-mm : \n");
        scanf("%d-%d-%d", &dead_line_list[i].day, &dead_line_list[i].hour, &dead_line_list[i].minutes);
        listtaches[i].id = id;
        id++;
    }
}

void afficher()
{
    ToDo swap;

    for (int i = 0; i < nbr_de_taches; i++)
    {
        for (int j = i + 1; j < nbr_de_taches; j++)
        {
            if (strcmp(listtaches[i].titre, listtaches[j].titre) > 0)
            {
                swap = listtaches[i];
                listtaches[i] = listtaches[j];
                listtaches[j] = swap;
            }
        }
    }
    // for (int i = 0; i < nbr_de_taches; i++)
    // {
    //     for (int j = i + 1; j < nbr_de_taches; j++)
    //     {
    //         if ()
    //         {
    //             swap = listtaches[i];
    //             listtaches[i] = listtaches[j];
    //             listtaches[j] = swap;
    //         }
    //     }
    // }
    for (int i = 0; i < nbr_de_taches; i++)
    {

        printf("\n================ la %d taches est : ================ \n", i + 1);
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
    for (int i = 0; i < nbr_de_taches; i++)
    {
        if (search == listtaches[i].id)
        {
            printf("Entrer le titre : ");
            scanf("%s \n", listtaches[i].titre);

            printf("Entrer le discription : ");
            scanf("%s \n", listtaches[i].discription);

            printf("Entrer le status : ");
            scanf("%s \n", listtaches[i].status);
        }
    }
}
void chercher()
{
    int chercherindex;
    printf("Entrez le id de tache a chercher : ");
    scanf("%d", &chercherindex);
    for (int i = 0; i < nbr_de_taches; i++)
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

void supprimer()
{
    int s;
    printf("Entrez le numero de tache a supprimer : ");
    scanf("%d", &s);
}

void menu()
{
    int choix;
    do
    {
        printf("\n ================================================================================================================================================================================ ");
        printf("\n  \t \t \t \t \t \t  \t \t \n Menu d'application \n");
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
            // update();
        }
        else if (choix == 4)
        {
            chercher();
        }
        else if (choix == 5)
        {
        }
    } while (choix != 6);
}

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}
