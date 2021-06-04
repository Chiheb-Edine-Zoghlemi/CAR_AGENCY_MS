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
int nc = 0;

void affichage_clients()
{
    printf("\n_______________________\n");
    printf("\nAffichage  des Clients");
    printf("\n_______________________\n");
    for (int i = 0; i < nc; i++)
    {
        printf("\n----------------------------------------\n");
        printf("\x1B[36m\t#Client %d \x1B[0m", i + 1);
        printf("\n----------------------------------------\n");
        printf("| Nom                   | %s \n", tc[i].nom);
        printf("_____________________________________\n");
        printf("| Prénom                | %s\n", tc[i].prenom);
        printf("_____________________________________\n");
        printf("| CIN                   | %d\n", tc[i].cin);
        printf("----------------------------------------\n");
    }
}

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
void ajouter_client()
{
    int x;
    for (int i = nc; i < 50; i++)
    {
        printf("\n\x1B[36m #Client %d \x1B[0m\n", i + 1);
        struct client nv_person;
        printf("- Veuillez saisir votre Nom. \n");
        printf("-> ");
        scanf("%s", nv_person.nom);
        printf("- Veuillez saisir votre Prénom . \n");
        printf("-> ");
        scanf("%s", nv_person.prenom);
        printf("- Veuillez saisir votre numéro CIN. \n");
        printf("-> ");
        scanf("%d", &nv_person.cin);
        nc++;
        printf("Voulez ajouter une autre Client ? ( choix = 0 -> Non , choix != 0 -> Oui)\n");
        printf("Votre choix -> ");
        scanf("%d", &x);
        tc[i] = nv_person;
        if (x == 0)
        {
            nc = i + 1;
            break;
        }
    }
    if (nc == 50)
    {
        printf("\x1B[33m Le list de clients est plein  :( \x1B[0m\n");
    }
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

//question 5
int seek_voiture_client(struct client Cl, char NUMERO[10])
{
    if (strlen(*Cl.tcv) < 10)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < strlen(*Cl.tcv); i++)
        {
            char *sub_string[10];
            for (int j = i; j < i + 10; j++)
            {
                sub_string[j] = Cl.tcv[j];
            }

            if (strlen(*sub_string) < 10)
            {
                return -1;
            }
            else
            {
                if (strcmp(NUMERO, *sub_string) == 0)
                {
                    return i;
                }
            }
        }
        return -1;
    }
}

//question 6
void delete_voiture_client(struct client Cl, int pos)
{
    if (strlen(*Cl.tcv) < pos)
    {
        printf("\x1B[33m\nPostion est unvalide");
    }
    else
    {
        for (int i = pos; i < pos + 10; i++)
        {
            Cl.tcv[i] = "";
        }
    }
}
// affichage de menu
void Menu()
{
    printf("\e[31m\n");
    printf("=======================================\n");
    printf("\t    MENU\n");
    printf("=======================================\n");
    printf("Location d'une voiture        || 1\n");
    printf("Retour d'une voiture          || 2\n");
    printf("Etat d'une voiture            || 3\n");
    printf("Etat du parc de voitures      || 4\n");
    printf("Affichage des voitures        || 5\n");
    printf("Affichage des clinets         || 6\n");
    printf("Ajouter un clinet             || 7\n");
    printf("Sortir                        || 0\n");
    printf("=======================================\n");
    printf("\e[0m");
}
//copyrights section
void Credit()
{
    printf("\e[31m");
    printf("====================================================================\n");
    printf("\tDevelopé par Amen Allah Zoghlemi & xxxxxxxxxxx \n");
    printf("====================================================================\n");
    printf("\e[0m");
}

// affichage de voitures
void affichage()
{
    printf("\n_______________________\n");
    printf("\nAffichage  des voitures");
    printf("\n_______________________\n");
    for (int i = 0; i < nv; i++)
    {
        printf("\n----------------------------------------\n");
        printf("\x1B[36m\t#Voiture %d \x1B[0m", i + 1);
        printf("\n----------------------------------------\n");
        printf("| Modèle                   | %s \n", tv[i].modele);
        printf("_____________________________________\n");
        printf("| Numéro d'immatriculation | %s\n", tv[i].numMat);
        printf("_____________________________________\n");
        printf("| Kilométrage              | %d\n", tv[i].km);
        printf("_____________________________________\n");
        printf("| État                     | %d\n", tv[i].etat);
        printf("----------------------------------------\n");
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
        printf("\x1B[33m Le Voiture n'exist Pas :( \x1B[0m\n");
    }
    else
    {
        if (tv[pos].etat == 1)
        {
            printf("\x1B[33m Le Voiture est deja loué  :( \x1B[0m\n");
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
                nc++;
                tc[nc] = new_client;
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
        printf("\x1B[33mLa voiture n'existe pas !\x1B[0m");
    }
    else
    {
        int km;
        printf("- kilomètres effectués . \n");
        printf("-> ");
        scanf("%d", &km);
        tv[pos_v].km = tv[pos_v].km + km;
        tv[pos_v].etat = 0;
        int pos_p = seek_personne(cin);
        if (pos_p == -1)
        {
            printf("\x1B[33mLe Client avec le CIN %d n'existe pas !\x1B[0m", cin);
        }
        else
        {

            delete_voiture_client(tc[pos_p], seek_voiture_client(tc[pos_p], num));
        }
    }
}

void stat()
{
    printf("\n_______________________\n");
    printf("\nLocation de voiture");
    printf("\n_______________________\n");
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
    printf("\n=================================================================");
    printf("\n||-> le nombre total de voitures %d ", nv);
    printf("\n||-> le nombre de voitures en location %d ", total_nd);
    printf("\n||-> le nombre de voitures disponible %d ", total_d);
    printf("\n||-> le kilométrage moyen de l'ensemble des voitures %d ", total_km / nv);
    printf("\n=================================================================");
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
        printf("\x1B[33mla voiture n'existe pas !\x1B[0m");
    }
    else
    {
        printf("\n----------------------------\n");
        printf("| Modèle                   | %s \n", tv[pos_v].modele);
        printf("| Numéro d'immatriculation | %s \n", tv[pos_v].numMat);
        printf("| Kilométrage              | %d \n", tv[pos_v].km);
        printf("| État                     | %d \n", tv[pos_v].etat);
        printf("----------------------------\n");
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
    int x;
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
        int km;
        printf("- kilométrage\n-> ");
        while (1)
        {
            scanf("%d", &km);
            if (km < 0)
            {
                printf("\x1B[33mkilométrage est non valide -- il faut saisir un entier positive\x1B[0m");
                printf("-> ");
            }
            else
            {
                nv_voitur.km = km;
                break;
            }
        }

        int etat;
        printf("- état (0 : disponible ou 1 : en cours de location)  \n-> ");
        while (1)
        {
            scanf("%d", &etat);
            if (etat == 0 || etat == 1)
            {
                nv_voitur.etat = etat;
                break;
            }
            else
            {
                printf("\x1B[33m\nétat non valide -- il faut taper  (0 : disponible ou 1 : en cours de location)\x1B[0m\n");
                printf("-> ");
            }
        }

        printf("Voulez ajouter une autre voiture ? ( choix = 0 -> Non , choix != 0 -> Oui)\n");
        printf("Votre choix -> ");
        scanf("%d", &x);
        tv[i] = nv_voitur;
        if (x == 0)
        {
            nv = i + 1;
            break;
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
            case 5:
                affichage();
                break;
            case 6:
                affichage_clients();
                break;
            case 7:
                ajouter_client();
                break;
            default:
                printf("\n\x1B[33m Choix est unvalidé, Il faut choisi un enter enter 0 -- 7 \x1B[0m\n ");
                break;
            }
        }
    }
    return 0;
}
