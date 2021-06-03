#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//question 1
struct voiture
{
    char modele[30];
    char numMat[10];
    int km;
    int etat;
};

//question 2
struct client
{
    char nom[20];
    char prenom[20];
    int cin;
    char *tcv[50];
};
struct voiture tv[50];
struct client tc[50];
int nv;
int nc;

struct client create_person(int cin)
{
    struct client nv_person;
    nv_person.cin = cin;
    printf("- Veuillez saisir votre Nom. \n");
    printf("-> ");
    scanf("%s", nv_person.nom);
    printf("- Veuillez saisir votre Prénom . \n");
    printf("-> ");
    scanf("%s", nv_person.prenom);
    return nv_person;
}
//question 3
int seek_personne(int cin)
{
    for (int i = 0; i < nc; i++)
    {
        if (tc[i].cin == cin)
        {
            return i;
        }
    }
    return -1;
}

//question 4
int seek_voiture(char NUMERO[10])
{
    for (int i = 0; i < nv; i++)
    {
        if (strcmp(tv[i].numMat, NUMERO) == 0)
        {
            return i;
        }
    }
    return -1;
}
/*
//question 5
char* substr (char**  ch[], int i , int j ){
char ch2[strlen(ch)]; 
int o = 0 ; 
for (int x = i;x<j+1;x++){
    ch2[o]=ch[x];
    o++;
}
return ch2;
}
int seek_voiture_client(struct client Cl, char NUMERO[10])
{
    for (int i = 0; i < strlen(Cl.tcv); i++)
    {
        char * sub_string = substr(Cl.tcv, i, 10);
        if ( (sizeof(sub_string)/sizeof(sub_string[0]))  < 10)
        {
            return -1;
        }
        else
        {
            if (strcmp(NUMERO,sub_string) == 0)
            {
                return i;
            }
        }
    }
}*/
//question 6
void delete_voiture_client(struct client Cl, int pos)
{
    if ((sizeof(Cl.tcv) / sizeof(Cl.tcv[0])) < pos)
    {
        printf("Postion est unvalide");
    }
    else
    {
        for (int i = pos; i < 11; i++)
        {
            Cl.tcv[i] = "";
        }
    }
}
// affichage de menu
void Menu()
{
    printf("\e[31m");
    printf("\t=======================================\n");
    printf("\t\t    MENU\n");
    printf("\t=======================================\n");
    printf("\tLocation d'une voiture        || 1\n");
    printf("\tRetour d'une voiture          || 2\n");
    printf("\tEtat d'une voiture            || 3\n");
    printf("\tEtat du parc de voitures      || 4\n");
    printf("\tAffichage des voitures        || 5\n");
    printf("\tSortir                        || 0\n");
    printf("\t=======================================\n");
    printf("\e[0m");
}
//copyrights section
void Credit()
{
    printf("\e[31m");
    printf("\t====================================================================\n");
    printf("\tDevelopé par Amen Allah Zoghlemi & xxxxxxxxxxx \n");
    printf("\t====================================================================\n");
    printf("\e[0m");
}

// affichage de voitures
void affichage()
{
    for (int i = 0; i < nv; i++)
    {
        /* code */
    }
}
// choix 1
void location()
{
    printf("\n_______________________\n");
    printf("\nLocation de voiture");
    printf("\n_______________________\n");
    char num[10];
    printf("- Veuillez saisir le numéro d’immatriculation  de la voiture à louer. \n");
    printf("-> ");
    scanf("%s", num);
    int pos = seek_voiture(num);
    if (pos == -1)
    {
        printf("Le Voiture n'exist Pas :( \n");
    }
    else
    {
        if (tv[pos].etat == 1)
        {
            printf("Le Voiture est deja loué  :( \n");
        }
        else
        {
            int cin;
            printf("- Veuillez saisir votre numéro CIN. \n");
            printf("-> ");
            scanf("%d", &cin);
            int pos_person = seek_personne(cin);
            if (pos_person == -1)
            {
                printf("Bienvenu chez Nous \n");
                struct client new_client = create_person(cin);
                // code to add car into client cars
            }
            else
            {
                struct client old_client;
                old_client = tc[pos_person];
                printf("Bienvenu %s %s chez Nous \n", old_client.nom, old_client.prenom);
                // code to add car into client cars
            }
        }
    }
}
// choix 2
void retour()
{
    int cin;
    printf("- Veuillez saisir votre numéro CIN. \n");
    printf("-> ");
    scanf("%d", &cin);
    char num[10];
    printf("- Veuillez saisir le numéro d’immatriculation  de la voiture. \n");
    printf("-> ");
    scanf("%s", num);
    int pos_v = seek_voiture(num);
    if (pos_v == -1)
    {
        printf("la voiture n'existe pas !");
    }
    else
    {
        int km;
        printf("- kilomètres effectués . \n");
        printf("-> ");
        scanf("%d", &km);
        tv[pos_v].km = tv[pos_v].km + km;
        tv[pos_v].etat = 1;
        int pos_p = seek_personne(cin);
        if (pos_p == -1)
        {
            printf("le Client avec le CIN %d n'existe pas !", cin);
        }
        else
        {
            // code de delete the car from the client list of cars
        }
    }
}

void stat()
{
    /*
    • le nombre total de voitures,
    • le nombre de voitures en location et leur numéro d'immatriculation,
    • le nombre de voitures disponible et leur numéro d'immatriculation,
    • le kilométrage moyen de l'ensemble des voitures. 
    */
    int total_km = 0;
    int total_d = 0;
    int total_nd = 0;
    for (int i = 0; i < nv; i++)
    {
        if (tv[i].etat)
        {
            total_d++;
        }
        else
        {
            total_nd++;
        }
        total_km = total_km + tv[i].km;
    }
    printf("\n===============================================================================");
    printf("\n||-> le nombre total de voitures %d ", nv);
    printf("\n||-> le nombre de voitures en location %d ", total_nd);
    printf("\n||-> le nombre de voitures disponible %d ", total_d);
    printf("\n||-> le kilométrage moyen de l'ensemble des voitures %d ", total_km / nv);
    printf("\n===============================================================================\n");
}
void car_status()
{
    char num[10];
    printf("- Veuillez saisir le numéro d’immatriculation  de la voiture. \n");
    printf("-> ");
    scanf("%s", num);
    int pos_v = seek_voiture(num);
    if (pos_v == -1)
    {
        printf("la voiture n'existe pas !");
    }
    else
    {
        printf("\n----------------------------\n");
        printf("| Modèle | %s |", tv[pos_v].modele);
        printf("| Numéro d'immatriculation | %s |", tv[pos_v].numMat);
        printf("| Kilométrage | %d |", tv[pos_v].km);
        printf("| État | %d |", tv[pos_v].etat);
        printf("\n----------------------------\n");
    }
}
// fonction main

int main()
{

    printf("\e[31m===========================\n");
    printf("    Location de voitures\n");
    printf("===========================\e[0m\n");
    printf("\n_______________________\n");
    printf("\nAjouter vos voitures");
    printf("\n_______________________\n");
    for (int i = 0; i < 50; i++)
    {
        printf("\n\x1B[36m #Voiture %d \x1B[0m\n", i + 1);
        struct voiture nv_voitur;
        printf("- Modele de voiture \n");
        printf("-> ");
        scanf("%s", nv_voitur.modele);
        printf("- numéro d’immatriculation  \n");
        printf("-> ");
        scanf("%s", nv_voitur.numMat);
        printf("- kilométrage\n-> ");
        scanf("%d", &(nv_voitur.km));
        printf("- état (0 : disponible ou 1 : en cours de location)  \n-> ");
        scanf("%d", &nv_voitur.etat);
        int x = atoi(nv_voitur.numMat);
        if (x < 0)
        {
            nv = i;
            break;
        }
        else
        {
            tv[i] = nv_voitur;
        }
    }

    int choix = 1;
    while (choix)
    {
        Menu();
        printf("\nVotre choix => ");
        scanf(" %d", &choix);
        if (choix == 0)
        {
            Credit();
            break;
        }
        else
        {

            switch (choix)
            {
                // choix 1
            case 1:
                location();
                break;
                // choix 2
            case 2:
                retour();
                break;
                // choix 3
            case 3:
                car_status();
                break;
                // choix 4
            case 4:
                stat();
                break;

            default:
                printf("\n Unvalid Choice \n ");
                break;
            }
        }
    }
    return 0;
}